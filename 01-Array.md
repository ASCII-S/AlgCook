# Array

## 理论基础

## 二分查找

[二分查找题型与抽象模式](./note/01-Array/二分查找题型与抽象模式.md)

[704. 二分查找](.Reference/.CodeReference/704.二分查找.cpp)

[35. 搜索插入位置](.Reference/.CodeReference/35.搜索插入位置.cpp)

[34. 在排序数组中查找元素的第一个和最后一个位置](.Reference/.CodeReference/34.在排序数组中查找元素的第一个和最后一个位置.cpp)

> 启发：本题可用二分法分别查找target的左边界和右边界。通过两次二分，分别定位第一个等于target和最后一个等于target的位置，时间复杂度O(log n)。

[367. 有效的完全平方数](.Reference/.CodeReference/367.有效的完全平方数.cpp)

> 启发：本题要求判断一个数是否为完全平方数，直接枚举效率低。注意到平方数的单调性，可以将问题转化为在区间[1, num/2]中查找某个数的平方是否等于num，区间有序，适合用二分法。二分法的核心思想是每次排除一半不可能的区间，快速缩小查找范围，极大提升效率。

## 双指针法

[双指针题型与抽象模式](./note/01-Array/双指针题型与抽象模式.md)

### 滑动窗口

- [x] [209.长度最小的子数组](.Reference/.CodeReference/209.长度最小的子数组.cpp)

- [ ] [904.水果成篮](.Reference/.CodeReference/904.水果成篮.cpp)
    - [ ] [算法题中迭代器使用方法](./note/01-Array/算法题中迭代器使用方法.md)

- [x] [76.最小覆盖子串](.Reference/.CodeReference/76.最小覆盖子串.cpp)

## 模拟

[模拟题型与抽象模式](./note/01-Array/模拟题型与抽象模式.md)

- [ ] [59.螺旋矩阵II](.Reference/.CodeReference/59.螺旋矩阵-ii.cpp)