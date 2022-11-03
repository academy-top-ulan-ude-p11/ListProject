#include <iostream>
#include "List.h"

int main()
{
    srand(time(nullptr));

    List list;

    /*list.Insert(1, 100);
    list.Insert(1, 200);
    list.Insert(1, 300);
    list.Insert(1, 400);
    list.Insert(2, 500);
    list.Insert(4, 600);*/

    for (int i = 0; i < 10; i++)
        list.PushEnd(10 + rand() % 90);

    std::cout << list << "\n";

    int key;
    std::cout << "input key: ";
    std::cin >> key;

    std::cout << "index of key: " << list.Contain(key) << "\n\n";
    
    list.Remove(list.Contain(key));

    std::cout << list << "\n";
    
}
