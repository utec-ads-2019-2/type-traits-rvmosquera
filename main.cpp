#include <iostream>

#include "test/tester.h"

using namespace std;

int main(int argc, char const *argv[]) {
    //Tester::execute();
    SelfList<int> list(SelfList<int>::Transpose);

    list.insert(4);
    list.insert(14);
    list.insert(3);
    list.insert(9);
    list.insert(1);
    list.insert(100);
    list.insert(19);
    list.insert(17);

    list.find(9);
    list.find(9);
    list.find(9);
    list.find(9);
    list.find(9);

    return EXIT_SUCCESS;
}

