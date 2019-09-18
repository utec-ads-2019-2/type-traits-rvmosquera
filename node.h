#ifndef NODE_H
#define NODE_H

using namespace std;
template <typename T>
struct Node {
    T data;
    int count;
    Node<T>* next;
      
    Node(T data) : data(data) {
        next = nullptr;
        count = 0;
    }
      
    void killSelf();
};

template <typename T>
void Node<T>::killSelf() {
    if (next) {
        next->killSelf();
    }
    
    delete this;
}

#endif