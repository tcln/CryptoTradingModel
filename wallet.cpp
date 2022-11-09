#include "wallet.h"

double Wallet::GetTotalBalanceInDollars() const
{
    return crypto_ * cryptoPrice_ + dollars_;
}

void Wallet::AddCryptoBalance(double amount)
{
    crypto_ += amount;
}

void Wallet::RemoveCryptoBalance(double amount)
{
    crypto_ -= amount;
}

void Wallet::SetCryptoPrice(double price)
{
    cryptoPrice_ = price;
}

double Wallet::GetCryptoBalance() const
{
    return crypto_;
}

void Wallet::AddDollarBalance(double amount)
{
    dollars_ += amount;
}

void Wallet::RemoveDollarBalance(double amount)
{
    dollars_ -= amount;
}

double Wallet::GetDollarBalance() const
{
    return dollars_;
}