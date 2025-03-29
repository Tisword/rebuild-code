#!/bin/bash

# 清理旧的构建文件
echo "Cleaning build directory..."
rm -rf build
mkdir build
cd build

# 生成新的构建配置
echo "Running CMake..."
cmake ..

# 编译代码
echo "Building project..."
make

# 返回上一级目录
cd ..