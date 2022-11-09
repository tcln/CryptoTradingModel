#include "analytics.h"

#include <fstream>
#include <string>

void Analytics::SetInitialValue(double initialValue)
{
    initialValue_ = initialValue;
}

void Analytics::AddDailyData(const std::string& date, double totalBalance, double assetPrice)
{
    data_.emplace_back(date, totalBalance, assetPrice);
}

void Analytics::DumpData(const std::string& fileName) const
{
    std::ofstream out(fileName);
    out << "day,balance,profit,profit(%),price" << std::endl;
    for (const auto& day : data_)
        out << day.date_ << "," << std::to_string(day.totalBalance_) << "," 
            << std::to_string(day.totalBalance_ - initialValue_) << ","
            << std::to_string((day.totalBalance_/initialValue_)*100) << ","
            << std::to_string(day.assetPrice_) << std::endl;
}