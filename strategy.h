#pragma once

#include "dataReader.h"

enum class Signal
{
    Buy,
    Sell,
    Hold
};

enum class DerivativeType
{
    Null,
    Positive,
    Negative
};

class Strategy
{
public:
    virtual void Setup(DataReader& reader) = 0;
    virtual Signal AnalyzeNextRow(DataReader& reader) = 0;
};

class BuyAndHold : public Strategy
{
public:
    void Setup(DataReader& reader) override;
    Signal AnalyzeNextRow(DataReader& reader) override;

private:
    bool bought_{false};
};

class EMA8Derivate : public Strategy
{
public:
    void Setup(DataReader& reader) override;
    Signal AnalyzeNextRow(DataReader& reader) override;

private:
    DerivativeType lastDerivative_{DerivativeType::Null};
    double lastEMAValue_{0};
};

class EMA20Derivate : public Strategy
{
public:
    void Setup(DataReader& reader) override;
    Signal AnalyzeNextRow(DataReader& reader) override;

private:
    DerivativeType lastDerivative_{DerivativeType::Null};
    double lastEMAValue_{0};
};

class EMA50Derivate : public Strategy
{
public:
    void Setup(DataReader& reader) override;
    Signal AnalyzeNextRow(DataReader& reader) override;

private:
    DerivativeType lastDerivative_{DerivativeType::Null};
    double lastEMAValue_{0};
};
