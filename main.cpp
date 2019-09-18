#include <iostream>

#include "test/tester.h"

using namespace std;

int main(int argc, char const *argv[]) {
    //Tester::execute();
    SelfList<int> list(SelfList<int>::Move);

    list.insert(4);
    list.insert(14);
    list.insert(3);
    list.insert(9);
    list.insert(1);
    list.insert(100);
    list.insert(19);
    list.insert(17);

    list.print();

    /*list.remove(9);
    list.remove(4);
    list.remove(19);
    list.remove(17);
    list.remove(9);
    list.print();
    list.find(9);
    list.find(9);
    list.find(9);
    list.find(9);
    list.find(9);*/

    return EXIT_SUCCESS;
}

