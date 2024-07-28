#pragma once 
#include "skipList.h"
template <typename K, typename V>
Skiplist<K, V>::Skiplist()
{
    // 初始化头结点
    head = new Node<K, V>(NULL, NULL, K(), V());
    pathList.reserve(MAX_LEVEL);
}

template <typename K, typename V>
bool Skiplist<K, V>::search(const K &target)
{
    Node<K, V> *p = head;
    while (p)
    {
        // 左右寻找目标区间
        while (p->right && p->right->key < target)
        {
            p = p->right;
        }
        // 没找到目标值，则继续往下走
        if (!p->right || target < p->right->key)
        {
            p = p->down;
        }
        else
        {
            // 找到目标值，结束
            return true;
        }
    }
    return false;
}

template <typename K, typename V>
void Skiplist<K, V>::add(const K &key, const V &value)
{
    // 从上至下记录搜索路径
    pathList.clear();
    Node<K, V> *p = head;
    // 从上到下去搜索 次小于key的 数字，等于就是另外一种实现里的 prevs
    // 把每一行的前置结点存储进来
    while (p)
    {
        // 向右找到次小于key的p
        while (p->right && p->right->key < key)
        {
            p = p->right;
        }
        pathList.push_back(p);
        p = p->down;
    }

    bool insertUp = true;
    Node<K, V> *downNode = NULL;

    // 从下至上搜索路径回溯，50%概率
    // 如果上升，就压出一个节点来插入到后面
    while (insertUp && pathList.size() > 0)
    {
        Node<K, V> *insert = pathList.back();
        pathList.pop_back();
        // 将节点插入到当前节点的后面，并且指向当前节点的后一个节点，下降节点为downNode
        insert->right = new Node<K, V>(insert->right, downNode, key, value);
        // 下降节点为当前节点
        downNode = insert->right;
        // 抛骰子，50的概率往上升。
        insertUp = (rand() % 2) == 0; // 50%概率
    }
    // 如果还要上升，那么整个跳表将提升高度
    if (insertUp)
    {
        // 创建一个头结点
        head = new Node<K, V>(new Node<K, V>(NULL, downNode, key, value), head, K(), V());
    }
}

template <typename K, typename V>
bool Skiplist<K, V>::erase(const K &key)
{
    Node<K, V> *p = head;
    bool seen = false;

    while (p)
    {
        while (p->right && p->right->key < key)
        {
            p = p->right;
        }

        if (!p->right || p->right->key > key)
        {
            p = p->down;
        }
        else
        {
            seen = true;
            p->right = p->right->right;
            p = p->down;
        }
    }

    return seen;
}
template <typename K, typename V>
void Skiplist<K, V>::printSkiplist()
{
    int level = 0;
    Node<K, V> *current = head;
    while (current != nullptr)
    {
        Node<K, V> *levelNode = current;
        std::cout << "Level " << level++ << ": ";
        while (levelNode != nullptr)
        {
            std::cout << "(" << levelNode->key << ", " << levelNode->value << ") ";
            levelNode = levelNode->right;
        }
        std::cout << std::endl;

        current = current->down;
    }
}