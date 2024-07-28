#pragma once
#include <vector>
#include <iostream>

template <typename K, typename V>
struct Node
{
    // 向右向下指针
    Node *right;
    Node *down;
    K key;
    V value;
    Node(Node *right, Node *down, K key, V value)
        : right(right), down(down), key(key), value(value) {}
};

template <typename K, typename V>
class Skiplist
{
private:
    Node<K, V> *head;
    // 预先分配后，提升性能
    const static int MAX_LEVEL = 32;
    // 查找时临时使用的变量
    std::vector<Node<K, V> *> pathList;

public:
    Skiplist();
    bool search(const K &target);
    void add(const K &key, const V &value);
    bool erase(const K &key);
    void printSkiplist();
};

