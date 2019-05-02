#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>

void constructContentAndIndex(std::vector<std::string>& content, std::map<std::string, std::set<size_t>>& index, std::ifstream& file) {
    std::string line;
    while (std::getline(file, line)) {
        content.push_back(line);

        std::istringstream is(line);
        std::string word;
        while(is >> word) {
            if (index.find(word) == index.end()) {
                index[word] = std::set<size_t>{content.size()-1};
            } else {
                index[word].insert(content.size()-1);
            }
        }
    }

    return;
}

std::vector<std::string> findWord(const std::vector<std::string>& content, const std::map<std::string, std::set<size_t>>& index, const std::string& word) {
    std::vector<std::string> data;

    if (index.find(word) == index.end()) {
        return data;
    } else {
        // 不可以使用index[word],因为其返回类型为引用，index为const类型
        auto lines = index.at(word);
        for (auto line : lines) {
            if (line < content.size()) {
                data.push_back(content[line]);
            }
        }
    }

    return data;
}

int main() {
    std::ifstream file("test");
    std::vector<std::string> content;
    std::map<std::string, std::set<size_t>> index;

    constructContentAndIndex(content, index, file);

    std::string target;
    while (std::cin >> target) {
        std::vector<std::string> res = findWord(content, index, target);
        for (auto line : res) {
            std::cout << line << std::endl;
        }
    }

    //for (auto line : content) {
    //    std::cout << line << std::endl;
    //}

    //for (auto it = index.begin(); it != index.end(); it++) {
    //    std::cout << it->first << " ";
    //    for (auto one : it->second) {
    //        std::cout << one << " ";
    //    }
    //    std::cout << std::endl;
    //}
}
