#include <iostream>
#include <filesystem>
#include <fstream>
#include <unordered_map>
#include "tokenizer.hpp"

using Index = std::unordered_map<std::string, std::vector<std::string>>;

Index build_index(const std::string& folder) {
    Index index;
    for (auto& entry : std::filesystem::directory_iterator(folder)) {
        if (!entry.is_regular_file()) continue;
        std::ifstream file(entry.path());
        std::string word;
        while (file >> word) {
            index[word].push_back(entry.path().filename().string());
        }
    }
    return index;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: stlfind <folder> <word>";
        return 1;
    }

    auto index = build_index(argv[1]);
    auto it = index.find(argv[2]);

    if (it != index.end()) {
        std::cout << "Word '" << argv[2] << "' found in files:\n";
        for (auto& file : it->second) std::cout << " " << file << "\n";
    } else {
        std::cout << "Word not found.\n";
    }
}
