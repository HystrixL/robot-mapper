# Robot Mapper

## 简介

通过统一的 `SN码<-->机器人` 映射文件，实现自适应的"当前NUC所在机器人"信息获取。

## 用途

读取设备S/N码，通过配置文件实现到机器人枚举的映射。

## 用法

```cpp
std::cout << "Your Type is:" << std::endl;
    auto type = rbmp::GetMyRobotType<TargetClassify>();
    if (!type.has_value())
        std::cout << "UNKNOWN" << std::endl;
    else
        std::cout << rbmp::enum_reflect::enum2string<TargetClassify>(type.value());
```

## API

```cpp
template <typename E, typename = typename std::enable_if<std::is_enum_v<E>, void>::type>
std::optional<E> GetMyRobotType();
```

模板参数E为枚举类型。

当配置文件中存在`当前设备S/N码`到`给定枚举类型中的值`的映射时，返回结果。否则返回`std::nullopt`。