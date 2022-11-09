#pragma once

#include <memory>
#include <iostream>
#include <string>

#include "analytics.h"
#include "dataReader.h"
#include "strategy.h"
#include "wallet.h"

class InvestmentModel
{
public:
    InvestmentModel(const std::string& datafile, const std::string& assetCode, const std::string& outfile, const std::string& strategy);
    ~InvestmentModel();

    void SimulateStrategy();

private:
    void Buy();
    void Sell();

    std::string asset_;
    DataReader dataReader_;
    std::string outfile_;

    std::unique_ptr<Strategy> strategy_;
    Analytics analytics_;
    Wallet wallet_;

    bool bought_{false};
    const double initialValue_{1000.0};
};

