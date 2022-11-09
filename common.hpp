#pragma once

#include <string>
#include <vector>

inline void Tokenize(std::vector<std::string>& tokens, const std::string& str, char separator)
{
    tokens.clear();
    std::string token;
    for (auto c : str) {
        if (c != separator)
            token.push_back(c);
        else {
            tokens.push_back(token);
            token.clear();
        }
    }
    if (!token.empty())
        tokens.push_back(token);
}