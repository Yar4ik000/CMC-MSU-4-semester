#include <string>


class BinaryNumber
{   
    std::string str;
public:
    BinaryNumber(const std::string &s) : str{s} {}
    operator std::string () const {
        return str;
    }
    const BinaryNumber &operator++() {
        if (str == "0") {
            str = "1";

        } else {
            size_t pos = str.rfind('0');
            if (pos == std::string::npos) {
                str = '1' + std::string(str.length(), '0');
            } else {
                int count = str.length() - pos - 1;
                str = str.erase(pos, str.length() - 1) + '1' + std::string(count, '0'); 
            }
        }
        return *this;
    }
};
