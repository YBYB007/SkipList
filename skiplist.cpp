#pragma once
#include "skiplist.h"
// SkipList构造函数，初始化跳表的最大层数、当前层数和虚拟头节点
SkipList::SkipList(int maxLvl) : maxLevel(maxLvl), currentLevel(0)
{
    head = new SkipListNode(INT_MIN, maxLevel);
}

// 随机生成节点的层数，用于插入新节点时确定其层数
int SkipList::randomLevel()
{
    int lvl = 1;
    while ((rand() & 1) && lvl < maxLevel)
        lvl++;
    return lvl;
}

// 插入新节点到跳表中
void SkipList::insert(int value)
{
    int level = randomLevel();
    SkipListNode *newNode = new SkipListNode(value, level);

    SkipListNode *current = head;
    for (int i = currentLevel; i >= 0; i--)
    {
        while (current->next[i] != nullptr && current->next[i]->value < value)
            current = current->next[i];
        if (i <= level)
        {
            newNode->next[i] = current->next[i];
            current->next[i] = newNode;
        }
    }

    if (level > currentLevel)
        currentLevel = level;
}

// 在跳表中搜索给定值，存在返回true，否则返回false
bool SkipList::search(int value)
{
    SkipListNode *current = head;
    for (int i = currentLevel; i >= 0; i--)
    {
        while (current->next[i] != nullptr && current->next[i]->value < value)
            current = current->next[i];
        if (current->next[i] != nullptr && current->next[i]->value == value)
            return true;
    }
    return false;
}

// 从跳表中删除给定值的节点
void SkipList::remove(int value)
{
    SkipListNode *current = head;
    std::vector<SkipListNode *> toUpdate(maxLevel, nullptr);

    for (int i = currentLevel; i >= 0; i--)
    {
        while (current->next[i] != nullptr && current->next[i]->value < value)
            current = current->next[i];
        toUpdate[i] = current;
    }

    if (current->next[0] != nullptr && current->next[0]->value == value)
    {
        SkipListNode *nodeToRemove = current->next[0];
        for (int i = 0; i <= currentLevel; i++)
        {
            if (toUpdate[i]->next[i] != nodeToRemove)
                break;
            toUpdate[i]->next[i] = nodeToRemove->next[i];
        }
        delete nodeToRemove;

        while (currentLevel > 0 && head->next[currentLevel] == nullptr)
            currentLevel--;
    }
}