#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <string>
#include <vector>
#include <set>
#include <map>


template<typename Out>
void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));//https://www.cnblogs.com/yongqiang/p/6105865.html
    return elems;
}

class QueryResult;

class TextQuery {
    public:
    TextQuery(const std::string& path);
    ~TextQuery();
    QueryResult query(const std::string&);
    void print();
    private:
    std::shared_ptr<std::vector<std::string>> content;
    std::map<std::string, std::shared_ptr<std::set<unsigned long>>> index;
    std::string path;
    std::ifstream file;
};

class QueryResult {
    public:
    friend std::ostream& operator<<(std::ostream& os, const QueryResult& qr);
    QueryResult(const std::string& keyword, std::shared_ptr<std::vector<std::string>> content, std::shared_ptr<std::set<unsigned long>> lines);
    private:
    std::string keyword;
    std::shared_ptr<std::vector<std::string>> content;
    std::shared_ptr<std::set<unsigned long>> lines;
};

QueryResult::QueryResult(const std::string& keyword, std::shared_ptr<std::vector<std::string>> content, std::shared_ptr<std::set<unsigned long>> line): keyword(keyword), content(content), lines(line) {
}

std::ostream& operator<<(std::ostream& os, const QueryResult& qr) {
    os << qr.keyword << "occur " << qr.lines->size() << " in title" << std::endl;
    for (auto line : *qr.lines) {
        std::cout << line << " ";
        std::cout << qr.content->at(line) << std::endl;
    }
    return os;
}

TextQuery::TextQuery(const std::string& path):path(path), content(std::make_shared<std::vector<std::string>>()) {
    file.open(path);
    std::string line;
    while (std::getline(file, line)) {
        content->push_back(line);
        std::vector<std::string> words = split(line, ' ');
        for (auto it = words.begin(); it != words.end(); it++) {
            auto res = index.find(*it);
            if (res != index.end()) {
                index[*it]->insert(content->size()-1);
            } else {
                index[*it].reset(new std::set<unsigned long>{content->size()-1});
            }
        }
    }
}

QueryResult TextQuery::query(const std::string& key) {
    static std::shared_ptr<std::set<unsigned long>> nodata(new std::set<unsigned long>);

    auto& res = index[key];
    if (!res) {
        return QueryResult(key, content, nodata);
    } else {
        return QueryResult(key, content, res);
    }
}

void TextQuery::print() {
    for (auto line : *content) {
        std::cout << line << std::endl;
    }

    for (auto i : index) {
        std::cout << i.first << " : " ;
        for (auto s : *i.second) {
            std::cout << " " << s;
        }
        std::cout << std::endl;
    }
}

TextQuery::~TextQuery() {
    file.close();
}
int main() {
    TextQuery a("./test");
    //a.print();
    std::cout << a.query("a");
    return 0;
}
