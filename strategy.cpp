#include "strategy.h"

#include <string>
#include <iostream>

#include "dataReader.h"


void BuyAndHold::Setup(DataReader& reader)
{
}

Signal BuyAndHold::AnalyzeNextRow(DataReader& reader)
{
    if (bought_)
        return Signal::Hold;
    bought_ = true;
    return Signal::Buy;
}

void EMA8Derivate::Setup(DataReader& reader)
{
    bool emaFound = false;
    while (!emaFound) {
        reader.ReadNextRow();
        if (reader.GetRow()[5] != "NaN") {
            lastEMAValue_ = reader.GetEMA8();
            emaFound = true;
        }
    }
}

Signal EMA8Derivate::AnalyzeNextRow(DataReader& reader)
{
    DerivativeType curDerivative = lastDerivative_;
    double curEMAValue = reader.GetEMA8();
    if (curEMAValue > lastEMAValue_)
        curDerivative = DerivativeType::Positive;
    else if (curEMAValue < lastEMAValue_)
        curDerivative = DerivativeType::Negative;
    else
        curDerivative = DerivativeType::Null;

    Signal signal;
    if (lastDerivative_ != curDerivative) {
        if (curDerivative == DerivativeType::Negative)
            signal = Signal::Sell;
        else if (curDerivative == DerivativeType::Positive)
            signal = Signal::Buy;
        else if (curDerivative == DerivativeType::Null)
            signal = Signal::Hold;
    }
    else {
        if (curDerivative == DerivativeType::Negative)
            signal = Signal::Sell;
        else if (curDerivative == DerivativeType::Positive)
            signal = Signal::Hold;
        else if (curDerivative == DerivativeType::Null)
            signal = Signal::Hold;
    }
    lastEMAValue_ = curEMAValue;
    lastDerivative_ = curDerivative;
    return signal;
}

void EMA20Derivate::Setup(DataReader& reader)
{
    bool emaFound = false;
    while (!emaFound) {
        reader.ReadNextRow();
        if (reader.GetRow()[6] != "NaN") {
            lastEMAValue_ = reader.GetEMA20();
            emaFound = true;
        }
    }
}

Signal EMA20Derivate::AnalyzeNextRow(DataReader& reader)
{
    DerivativeType curDerivative = lastDerivative_;
    double curEMAValue = reader.GetEMA20();
    if (curEMAValue > lastEMAValue_)
        curDerivative = DerivativeType::Positive;
    else if (curEMAValue < lastEMAValue_)
        curDerivative = DerivativeType::Negative;
    else
        curDerivative = DerivativeType::Null;

    Signal signal;
    if (lastDerivative_ != curDerivative) {
        if (curDerivative == DerivativeType::Negative)
            signal = Signal::Sell;
        else if (curDerivative == DerivativeType::Positive)
            signal = Signal::Buy;
        else if (curDerivative == DerivativeType::Null)
            signal = Signal::Hold;
    }
    else {
        if (curDerivative == DerivativeType::Negative)
            signal = Signal::Sell;
        else if (curDerivative == DerivativeType::Positive)
            signal = Signal::Hold;
        else if (curDerivative == DerivativeType::Null)
            signal = Signal::Hold;
    }
    lastEMAValue_ = curEMAValue;
    lastDerivative_ = curDerivative;
    return signal;
}

void EMA50Derivate::Setup(DataReader& reader)
{
    bool emaFound = false;
    while (!emaFound) {
        reader.ReadNextRow();
        if (reader.GetRow()[7] != "NaN") {
            lastEMAValue_ = reader.GetEMA50();
            emaFound = true;
        }
    }
}

Signal EMA50Derivate::AnalyzeNextRow(DataReader& reader)
{
    DerivativeType curDerivative = lastDerivative_;
    double curEMAValue = reader.GetEMA50();
    if (curEMAValue > lastEMAValue_)
        curDerivative = DerivativeType::Positive;
    else if (curEMAValue < lastEMAValue_)
        curDerivative = DerivativeType::Negative;

    Signal signal;
    if (lastDerivative_ != curDerivative) {
        if (curDerivative == DerivativeType::Negative)
            signal = Signal::Sell;
        else if (curDerivative == DerivativeType::Positive)
            signal = Signal::Buy;
    }
    else {
        if (curDerivative == DerivativeType::Negative)
            signal = Signal::Sell;
        else if (curDerivative == DerivativeType::Positive)
            signal = Signal::Hold;
    }
    lastEMAValue_ = curEMAValue;
    lastDerivative_ = curDerivative;
    return signal;
}