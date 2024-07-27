#pragma once
#include <vector>
#include <climits>
#include <stdlib.h>
#include <unordered_map>

template <typename K, typename V>
class SkipListNode
{
public:
    K key;                                 // 键
    V value;                               // 值
    std::vector<SkipListNode<K, V> *> next;   // 下一个节点指针数组
    
    // SkipListNode构造函数，初始化节点的键、值和下一个节点指针数组
    SkipListNode(K k, V val, int level) : key(k), value(val), next(level, nullptr) {}
};

template <typename K, typename V>
class SkipList
{
private:
    int maxLevel;                           // 跳表的最大层数
    int currentLevel;                       // 当前跳表的层数
    SkipListNode<K, V> *head;               // 虚拟头节点
    std::unordered_map<K, SkipListNode<K, V> *> kvMap;  // 键值对映射表

public:
    SkipList(int maxLvl);                   // 构造函数
    int randomLevel();                      // 随机生成节点的层数
    void insert(K key, V value);            // 插入键值对到跳表中
    bool search(K key);                     // 在跳表中搜索给定键
    void remove(K key);                     // 从跳表中删除给定键的节点
};