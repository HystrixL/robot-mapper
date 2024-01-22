#include "iostream"
#include "robot_mapper.hpp"

using namespace rbmp;

enum class TargetClassify {
    BASE_DART,
    BASE_BOTTOM,
    BASE_TOP,
    OUTPOST_DART,
    OUTPOST_SPIN,

    HERO_1,
    ENGINEER_2,
    STANDARD_3,
    STANDARD_4,
    STANDARD_5,
    SENTRY,

    ENERGY
};

int main() {
    // 库测试
    std::cout << "Your S/N: " << ExecCmd("dmidecode -s system-serial-number") << std::endl << std::endl;

    std::cout << "All Valid Type:" << std::endl;
    auto types = enum_reflect::enum_names_v<TargetClassify>;
    for (auto&& type : types) {
        std::cout << type << std::endl;
    }
    std::cout << std::endl;

    std::cout << "robot_map Config:" << std::endl;
    auto map = GenerateMap();
    for (auto&& pair : map) {
        std::cout << pair.first << ":" << pair.second << std::endl;
    }
    std::cout << std::endl;

    // 使用例
    std::cout << "Your Type is:" << std::endl;
    auto type = GetMyRobotType<TargetClassify>();
    if (!type.has_value())
        std::cout << "UNKNOWN" << std::endl;
    else
        std::cout << enum_reflect::enum2string<TargetClassify>(type.value());
}
