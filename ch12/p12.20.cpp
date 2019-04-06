#include <fstream>
#include "p12.19.h"

int main() {
    std::ifstream ifs("./test");
    StrBlob sb;
    std::string s;

    while (std::getline(ifs, s)) {
        sb.push_back(s);
    }

    for (StrBlobPtr sbp = sb.begin(); sbp != sb.end(); sbp.incr()) {
        std::cout << sbp.deref() << std::endl;
    }

}
