#include <iostream>
#include "skiplist.cpp"
int main()
{
    SkipList<int, int> skipList(4);
    skipList.insert(3, 30);
    skipList.insert(6, 60);

    std::cout << "Search 6: " << (skipList.search(6) ? "Found" : "Not Found") << std::endl;

    skipList.remove(6);

    std::cout << "Search 6 after removal: " << (skipList.search(6) ? "Found" : "Not Found") << std::endl;

    return 0;
}
