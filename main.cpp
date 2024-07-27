#include <iostream>
#include "skiplist.cpp"
int main()
{
    SkipList skipList(4);
    skipList.insert(3);
    skipList.insert(6);
    skipList.insert(2);
    skipList.insert(9);

    std::cout << "Search 6: " << (skipList.search(6) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 5: " << (skipList.search(5) ? "Found" : "Not Found") << std::endl;

    skipList.remove(6);
    std::cout << "Search 6 after removal: " << (skipList.search(6) ? "Found" : "Not Found") << std::endl;

    return 0;
}
