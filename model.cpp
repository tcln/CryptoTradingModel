#include "model.h"

#include <memory>
#include <iostream>
#include <string>

#include "analytics.h"
#include "dataReader.h"
#include "strategy.h"
#include "wallet.h"

InvestmentModel::InvestmentModel(const std::string& datafile, const std::string& assetCode, const std::string& outfile, const std::string& strategy)
    : asset_(assetCode), dataReader_(datafile), outfile_(outfile)
{
    if (strategy == "ema8")
        strategy_ = std::make_unique<EMA8Derivate>();
    else if (strategy == "ema20")
        strategy_ = std::make_unique<EMA20Derivate>();
    else if (strategy == "ema50")
        strategy_ = std::make_unique<EMA50Derivate>();
    else if (strategy == "buyhold")
        strategy_ = std::make_unique<BuyAndHold>();

    wallet_.AddDollarBalance(initialValue_);
}

InvestmentModel::~InvestmentModel()
{
    analytics_.SetInitialValue(initialValue_);
    analytics_.DumpData(outfile_);
}

void InvestmentModel::SimulateStrategy()
{
    strategy_->Setup(dataReader_);
    while (dataReader_.ReadNextRow()) {
        wallet_.SetCryptoPrice(dataReader_.GetClosePrice());
        Signal signal = strategy_->AnalyzeNextRow(dataReader_);
        if (!bought_ && signal == Signal::Buy)
            Buy();
        else if (bought_ && signal == Signal::Sell)
            Sell();
        analytics_.AddDailyData(dataReader_.GetDate(), wallet_.GetTotalBalanceInDollars(), dataReader_.GetClosePrice());
    }
    std::cout << "Finished simulation" << std::endl;
    std::cout << "Crypto balance: " << wallet_.GetCryptoBalance() << std::endl;
    std::cout << "Dollar balance: " << wallet_.GetDollarBalance() << std::endl;
    std::cout << "Total Dollar Value: " << wallet_.GetTotalBalanceInDollars() << std::endl;
}

void InvestmentModel::Buy()
{
    double dollars = wallet_.GetDollarBalance();
    double price = dataReader_.GetClosePrice();
    double crypto = dollars/price;
    wallet_.RemoveDollarBalance(dollars);
    wallet_.AddCryptoBalance(crypto);
    bought_ = true;

    std::cout << dataReader_.GetDate() << ": Bought " + std::to_string(crypto) + " crypto for " + std::to_string(dollars) + " dollars at price " << price << std::endl;
}

void InvestmentModel::Sell()
{
    double crypto = wallet_.GetCryptoBalance();
    double price = dataReader_.GetClosePrice();
    wallet_.SetCryptoPrice(price);
    double dollars = crypto * price;
    wallet_.AddDollarBalance(dollars);
    wallet_.RemoveCryptoBalance(crypto);
    bought_ = false;
    
    std::cout << dataReader_.GetDate() << ": Sold " + std::to_string(crypto) + " crypto for " + std::to_string(dollars) + " dollars at price " << price << std::endl;
}