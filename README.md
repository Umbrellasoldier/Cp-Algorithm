# Cp-Algorithm

这是一个面向算法竞赛的个人代码仓库，主要用来整理常用模板、保存做题代码，以及维护对拍脚本和部分学习资料索引。  
README 的目标是帮助自己和其他竞赛选手快速看懂仓库结构，并尽快定位到需要的代码。

## 仓库导航

### `Template/`

模板库主体，按专题分类整理，适合在比赛前复习或做题时直接检索复用。

- `Template/DataStructure/`：线段树、树状数组、并查集、Trie、Splay、莫队等
- `Template/Graph/`：最短路、LCA、最大流、最小费用流、强连通分量、2-SAT 等
- `Template/Math/`：筛法、快速幂、组合数、素性测试、Pollard-Rho、大整数等
- `Template/String/`：KMP、Manacher、后缀数组、AC 自动机、字符串哈希等
- `Template/Geometry/`：平面几何与极角排序
- `Template/Algebra/`：基础代数与数论小专题

### `Code/`

题目代码和临时实验区。

- `Code/algo.cpp`：C++ 通用做题模板
- `Code/algo.py`：Python 通用做题模板
- `Code/GO/`：Go 语言模板与简单测试
- `Code/ATC/`：按比赛或平台保存的题解代码

### `Pair beat/`

对拍脚本目录，用来生成随机数据并比较标准程序与暴力程序输出。

- `Pair beat/cpp/`：C++ 对拍
- `Pair beat/py/`：Python 对拍
- `Pair beat/check/`：样例输出校验脚本

### `Vidoe/`

视频资料目录。目录名当前保持仓库原样，不在 README 中展开详细内容。

## 如何查找代码

### 按专题找

优先从 `Template/` 的专题目录进入，例如想找网络流先看 `Template/Graph/`，想找字符串算法先看 `Template/String/`。

### 按关键词找

直接在仓库内搜索文件名关键词通常最快，例如：

- `Fenwick`
- `SegmentTree`
- `KMP`
- `MaxFlow`
- `Dijkstra`

### 按语言找

- `*.cpp`：C++ 模板最多，适合比赛主力代码
- `*.py`：Python 模板和部分题解
- `Code/GO/`：Go 版本练习代码

## 常用入口

- 想快速开题：从 `Code/algo.cpp` 或 `Code/algo.py` 开始
- 想补模板：从 `Template/` 按专题查看
- 想验证正确性：运行 `Pair beat/` 下的对拍脚本
- 想看 Go 测试：进入 `Code/GO/` 使用 `go test`

## 说明

- 仓库以“便于查找和复用”为优先，不追求统一教程式排版
- 大体积 PDF、ZIP、MP4 等资料默认不纳入 Git 管理
- 贡献和维护约定见根目录 `AGENTS.md`
