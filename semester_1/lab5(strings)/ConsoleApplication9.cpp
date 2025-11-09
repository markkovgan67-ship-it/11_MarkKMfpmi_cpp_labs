#include <iostream>
#include <string>

int main() {
    std::cout << "Enter your string: ";
    std::string line;
    std::getline(std::cin, line);

    std::string result = "";
    std::string word = "";
    bool foundDigits = false;

    for (char c : line) {
        if (c == ' ') {
            if (!word.empty()) {
                if (isdigit(word[0])) foundDigits = true;
                if (foundDigits) result = word + " " + result;
                else result += word + " ";
                word = "";
            }
        }
        else {
            word += c;
        }
    }

    if (!word.empty()) {
        if (isdigit(word[0])) foundDigits = true;
        if (foundDigits) result = word + " " + result;
        else result += word + " ";
    }

    std::cout << "Answer: " << result << std::endl;
    return 0;
}