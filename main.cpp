#include <iostream>
#include "skipList.cpp"

int main()
{
    Skiplist<int ,int> skiplist;
    skiplist.add(12,21);
    skiplist.add(12,21);
    skiplist.add(-1,21);
    skiplist.add(-3,21);
    skiplist.add(-3,21);
    skiplist.add(-3,21);
    skiplist.add(-3,21);
    skiplist.add(-3,21);
    skiplist.add(12,21);
    skiplist.add(12,21);
    skiplist.add(12,21);
    skiplist.add(13,21);
    skiplist.add(13,21);
    skiplist.add(13,21);
    skiplist.printSkiplist();
    return 0;
}
