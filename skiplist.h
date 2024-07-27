#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>

template<typename KeyType, typename ValueType>
class SkipList {
private:
    // 跳表节点定义
    class Node {
    public:
        KeyType key;
        ValueType value;
        std::vector<Node*> forward;

        Node(KeyType key, ValueType value, int level) : key(key), value(value) {
            forward.resize(level + 1, nullptr); // 初始化多层指针数组
        }
    };

    // 跳表的头部节点，不存储实际数据
    Node* head;

    // 最大层数
    int maxLevel;

    // 当前层数
    int currentLevel;

    // 比较函数，用于比较两个键值
    bool compare(const KeyType& a, const KeyType& b) {
        return a < b;
    }

public:
    // 构造函数
    SkipList(int maxLevel) : maxLevel(maxLevel), currentLevel(0), head(new Node(0, 0, maxLevel)) {}

    // 析构函数
    ~SkipList() {
        // 递归删除所有节点
        deleteRecursive(head);
    }

    // 插入操作
    void insert(const KeyType& key, const ValueType& value) {
        // ...
    }

    // 删除操作
    bool remove(const KeyType& key) {
        // ...
    }

    // 搜索操作
    bool search(const KeyType& key, ValueType& value) {
        // ...
    }

    // 私有成员函数，用于递归删除节点
    void deleteRecursive(Node* node) {
        if (node == nullptr) return;
        for (auto n : node->forward) {
            deleteRecursive(n);
        }
        delete node;
    }

    // 其他跳表操作...
};

// 使用示例
int main() {
    SkipList<int, std::string> mySkipList(4); // 创建一个最大层数为4的跳表
    // 进行插入、删除、搜索等操作...
    return 0;
}