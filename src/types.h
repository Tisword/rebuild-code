#include <string>
#include <map>
#include <vector>
#include <stdexcept>

// 定义演出信息结构
struct Play {
    std::string name;
    std::string type;
};

// 定义单个表演记录
struct Performance {
    std::string playID;
    int audience;
};

// 定义发票数据
struct Invoice {
    std::string customer;
    std::vector<Performance> performances;
};

// 类型别名简化代码
using Plays = std::map<std::string, Play>;