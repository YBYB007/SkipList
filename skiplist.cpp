#include "skiplist.h"
template <typename K, typename V>
SkipList<K, V>::SkipList(int maxLvl) : maxLevel(maxLvl), currentLevel(0)
{
    head = new SkipListNode<K, V>(INT_MIN, V(), maxLevel);
}

template <typename K, typename V>
int SkipList<K, V>::randomLevel()
{
    int lvl = 1;
    while ((rand() & 1) && lvl < maxLevel)
        lvl++;
    return lvl;
}

template <typename K, typename V>
void SkipList<K, V>::insert(K key, V value)
{
    int level = randomLevel();
    SkipListNode<K, V> *newNode = new SkipListNode<K, V>(key, value, level);

    SkipListNode<K, V> *current = head;
    for (int i = currentLevel; i >= 0; i--)
    {
        while (current->next[i] != nullptr && current->next[i]->key < key)
            current = current->next[i];
        if (i <= level)
        {
            newNode->next[i] = current->next[i];
            current->next[i] = newNode;
        }
    }

    if (level > currentLevel)
        currentLevel = level;

    kvMap[key] = newNode;
}

template <typename K, typename V>
bool SkipList<K, V>::search(K key)
{
    if (kvMap.find(key) == kvMap.end())
        return false;
    
    return true;
}

template <typename K, typename V>
void SkipList<K, V>::remove(K key)
{
    if (kvMap.find(key) == kvMap.end())
        return;

    SkipListNode<K, V> *nodeToRemove = kvMap[key];
    
    for (int i = 0; i <= currentLevel; i++)
    {
        if (head->next[i] == nodeToRemove)
            head->next[i] = nodeToRemove->next[i];
        else 
        {
            SkipListNode<K,V>* current = head;
            while(current != nullptr && current->next[i] != nodeToRemove)
                current = current->next[i];
            
            if(current != nullptr)
                current->next[i] = nodeToRemove->next[i];
        }
    }

    delete nodeToRemove;

    while (currentLevel > 0 && head->next[currentLevel] == nullptr)
        currentLevel--;
}
