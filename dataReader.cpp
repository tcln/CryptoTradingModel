
#include "dataReader.h"

#include <string>

#include "common.hpp"

DataReader::DataReader(const std::string& fileName)
    : file_(fileName)
{
    std::getline(file_, line_);
}

bool DataReader::ReadNextRow()
{
    if (std::getline(file_, line_)) {
        Tokenize(row_, line_, ',');
        return true;
    }
    return false;
}

std::string DataReader::GetDate()
{
    return row_[0].substr(0, 10);
}

double DataReader::GetClosePrice()
{
    return std::stof(row_[4]);
}

double DataReader::GetEMA8()
{
    return std::stof(row_[5]);
}

double DataReader::GetEMA20()
{
    return std::stof(row_[6]);
}

double DataReader::GetEMA50()
{
    return std::stof(row_[7]);
}

const std::vector<std::string>& DataReader::GetRow()
{
    return row_;
}
    

