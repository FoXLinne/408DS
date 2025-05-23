cmake_minimum_required(VERSION 3.24)
project(408DS)

# 测试代码，参与构建
add_subdirectory(test)

# 笔记代码，仅供语义分析，排除编译流程
add_subdirectory(notes EXCLUDE_FROM_ALL)
