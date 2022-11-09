#pragma once

#include <string>
#include <vector>

struct DayData
{
    std::string date_;
    double totalBalance_;
    double assetPrice_;

    DayData(const std::string& date, double totalBalance, double assetPrice)
        : date_(date), totalBalance_(totalBalance), assetPrice_(assetPrice)
    {}
};

class Analytics
{
public:
    void SetInitialValue(double initialValue);
    void AddDailyData(const std::string& date, double totalBalance, double assetPrice);
    void DumpData(const std::string& fileName) const;

private:
    std::vector<DayData> data_;
    double initialValue_{1000.0};
};