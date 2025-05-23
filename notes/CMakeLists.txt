# 把所有 .cpp 文件作为 dummy target 的 source 添加进来
file(GLOB NOTE_SOURCES "*.cpp")

add_library(dummy_notes OBJECT ${NOTE_SOURCES})