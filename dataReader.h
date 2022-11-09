#pragma once

#include <fstream>
#include <string>
#include <vector>

class DataReader
{
public:
    DataReader(const std::string& fileName);

    bool ReadNextRow();
    
    std::string GetDate();
    double GetClosePrice();
    double GetEMA8();
    double GetEMA20();
    double GetEMA50();
    const std::vector<std::string>& GetRow();
    
private:
    std::ifstream file_;
    std::string line_;
    std::vector<std::string> row_;
};