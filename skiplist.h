#pragma once
#include <vector>
#include <climits>
#include <stdlib.h>

class SkipListNode
{
public:
    int value;
    std::vector<SkipListNode *> next;
    
    // SkipListNode构造函数，初始化节点的值和下一个节点指针数组
    SkipListNode(int val, int level) : value(val), next(level, nullptr) {}
};

class SkipList
{
private:
    int maxLevel;       // 跳表的最大层数
    int currentLevel;   // 当前跳表的层数
    SkipListNode *head; // 虚拟头节点

public:
    SkipList(int maxLvl);
    int randomLevel();
    void insert(int value);
    bool search(int value);
    void remove(int value);
};
