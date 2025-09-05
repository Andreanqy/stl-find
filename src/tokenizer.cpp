#include "tokenizer.hpp"
#include <sstream>

std::vector<std::string> tokenize(const std::string& text) {
    std::istringstream iss(text);
    std::vector<std::string> tokens;
    std::string word;
    while (iss >> word) tokens.push_back(word);
    return tokens;
}
