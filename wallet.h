#pragma once

class Wallet
{
public:
    double GetTotalBalanceInDollars() const;

    void AddCryptoBalance(double amount);
    void RemoveCryptoBalance(double amount);
    void SetCryptoPrice(double price);
    double GetCryptoBalance() const;

    void AddDollarBalance(double amount);
    void RemoveDollarBalance(double amount);
    double GetDollarBalance() const;

private:
    double crypto_;
    double cryptoPrice_;
    double dollars_;
};