/*
 *  Crypto Trading Model main.
 */

#include <iostream>
#include <string>

#include "model.h"

int main(int argc, char* argv[])
{
    bool dataFileFlag = false;
    bool coinFlag = false;
    bool outfileFlag = false;
    bool strategyFlag = false;

    std::string dataFile = "btcbusd_iso.csv";
    std::string coinCode = "BTC";
    std::string outfile = "results.csv";
    std::string strategy = "ema20";

    std::vector<std::string> args(argv, argv+argc);
    for (const auto& arg : args) {
        if (dataFileFlag) {
            dataFile = arg;
            dataFileFlag = false;
        }
        else if (coinFlag) {
            coinCode = arg;
            coinFlag = false;
        }
        else if (outfileFlag) {
            outfile = arg;
            outfileFlag = false;
        }
        else if (strategyFlag) {
            strategy = arg;
            strategyFlag = false;
        }
        else if (arg == "-strategy")
            strategyFlag = true;
        else if (arg == "-data")
            dataFileFlag = true;
        else if (arg == "-coin")
            coinFlag = true;
        else if (arg == "-out")
            outfileFlag = true;
    }
    
    std::cout << "Starting Crypto Trading Model!" << std::endl;

    std::string dataPath = "data/" + dataFile;
    InvestmentModel model(dataPath, coinCode, outfile, strategy);
    model.SimulateStrategy();

    return 0;
}