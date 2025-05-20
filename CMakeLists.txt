cmake_minimum_required(VERSION 3.31)
project(408DataStructure)

set(CMAKE_CXX_STANDARD 20)

add_executable(408DataStructure
        "dstemplete/3.2.2 链队列.cpp"
        "dstemplete/3.2 队列.cpp"
        "dstemplete/4.1 串的定义与内容实现.cpp"
        "dstemplete/4.2 kmp排序与next数组.cpp"
        "dstemplete/5.1 树的基本定义与性质.cpp"
        "dstemplete/5.2 二叉树的存储结构.cpp"
        "dstemplete/5.3.1 二叉树的先中后序遍历.cpp"
        "dstemplete/5.3.2 二叉树的层序遍历.cpp"
        "dstemplete/5.3.3 由遍历序列构造二叉树.cpp"
        "dstemplete/5.4.1 线索二叉树.cpp"
        "dstemplete/5.4.2 使用线索二叉树找前驱和后继.cpp"
        "dstemplete/5.5.1 树的存储结构.cpp"
        "dstemplete/5.5.2 对树和森林的遍历.cpp"
        "dstemplete/5.6 哈夫曼树.cpp"
        "dstemplete/5.7 并查集.cpp"
        "dstemplete/6.2.1 图的存储.cpp"
        "dstemplete/6.3.1 图的广度优先遍历.cpp"
        "dstemplete/6.3.2 图的深度优先遍历.cpp"
        "dstemplete/6.4.1 最小生成树.cpp"
        "dstemplete/6.4.2 最短路径问题.cpp"
        "dstemplete/6.4.3 有向无环图描述表达式.cpp"
        "dstemplete/6.4.4 有向无环图拓扑排序.cpp"
        "dstemplete/6.4.5 关键路径问题.cpp"
        "dstemplete/7.2.1 顺序查找.cpp"
        "dstemplete/7.2.2 折半查找 & 二分查找.cpp"
        "dstemplete/7.2.3 分块查找.cpp"
        dspractice/每日一题.cpp
        test.cpp
        "dstemplete/7.3.3 红黑树.cpp"
        "dstemplete/7.4.2 B+树.cpp"
        "dstemplete/7.5.3 散列表处理冲突的方法.cpp")
