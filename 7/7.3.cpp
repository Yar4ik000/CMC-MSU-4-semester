#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iostream>
#include <functional>
#include <algorithm>


class Factory
{
private:
    Factory() {}
    Factory(const Factory& other) = delete;
    Factory(Factory&& other) = delete;
    Factory& operator= (const Factory& other) = delete;
    Factory& operator= (Factory&& other) = delete;
    std::map<std::string, std::function<Figure* (std::string)>> create_func
    {
        { "R", Rectangle::make },
        { "C", Circle::make },
        { "S", Square::make },
    }; 
public:
    static Factory& factory_instance() {
        static Factory inst;
        return inst;
    }
    std::unique_ptr<Figure> create(const std::string& str) {
        std::istringstream input(str);
        std::string name, params;
        input >> name;
        std::getline(input, params);
        return static_cast<std::unique_ptr<Figure>>(create_func[name](params));
    }
};

int main(){     
    std::vector<std::unique_ptr<Figure>> figures;
    std::string str;
    while (std::getline(std::cin, str)) {
        std::unique_ptr<Figure> now_fig = Factory::factory_instance().create(str);
        figures.push_back(std::move(now_fig));
    }
    std::stable_sort(figures.begin(), figures.end(), 
    [](auto&& a, auto&& b) 
    {
        return a->get_square() < b->get_square();
    });
    for (auto& fig : figures) {
        std::cout << fig->to_string() << std::endl;
    }
    

}