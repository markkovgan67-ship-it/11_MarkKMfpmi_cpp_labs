#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::ifstream in("input.txt");
    if (!in.is_open()) {
        std::cout << "Can not open this file" << std::endl;
        return 1;
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(in, line)) {
        lines.push_back(line);
    }
    in.close();

    for (auto& current_line : lines) {
        if (current_line.empty()) continue;

        std::vector<std::string> words;
        std::stringstream ss(current_line);
        std::string word;

        while (ss >> word) {
            words.push_back(word);
        }

        if (words.size() < 2) continue;

        int max_idx = 0;
        int min_idx = 0;
        size_t max_len = words[0].size();
        size_t min_len = words[0].size();

        for (int i = 1; i < words.size(); i++) {
            size_t len = words[i].size();

            if (len >= max_len) {
                max_len = len;
                max_idx = i;
            }

            if (len <= min_len) {
                min_len = len;
                min_idx = i;
            }
        }

        if (max_idx != min_idx) {
            std::swap(words[max_idx], words[min_idx]);
        }

        current_line.clear();
        for (size_t i = 0; i < words.size(); i++) {
            current_line += words[i];
            if (i != words.size() - 1) current_line += " ";
        }
    }

    std::cout << "Result:" << std::endl;
    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }

    return 0;
}