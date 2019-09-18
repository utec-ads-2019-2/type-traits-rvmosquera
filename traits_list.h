#ifndef TRAITS_LIST_H
#define TRAITS_LIST_H

#include "node.h"

template<typename Tr>
class TraitsList {
public:
    typedef typename Tr::T T;
    typedef typename Tr::Operation Operation;

private:
    Node<T> *head;
    Operation cmp;

    bool find(T data, Node<T> **&pointer) {
        bool resultBool = false;

        for (pointer = &head; *pointer != NULL; pointer = &(*pointer)->next) {
            //if((*lpp)->data == data) {
            if ( data == (*pointer)->data ) {
                *pointer = (*pointer)->next;
                resultBool = true;
                break;
            } else if (cmp(data, (*pointer)->data)) {
                *pointer = (*pointer)->next;
                resultBool = true;
            }
        }

        return resultBool;
    }

public:
    TraitsList() : head(nullptr) {};

    bool insert(T data) {
        Node<T> **doublePointer = nullptr;
        auto newNode = new Node<T>(data);

        if (!this->find(data, doublePointer)) {
            newNode->next = *doublePointer;
            *doublePointer = newNode;

            return true;
        } else {
            return false;
        }
    }

    bool remove(T data) {
        Node<T> **doublePointer = nullptr;

        if (this->find(data, doublePointer)) {

            return true;
        } else {
            return false;
        }
    }

    bool find(T data) {
        // TODO
    }

    T operator[](int index) {
        // TODO
    }

    int size() {
        int size = 0;
        Node<T> **pointer = nullptr;

        for (pointer = &head; *pointer != NULL; pointer = &(*pointer)->next) {
            size++;
        }

        return size;
    }

    void print() {
        cout << endl;
        next(this->head);
        cout << endl;
    }

    void next(Node<T> *node) {
        if(node) {
            cout << node->data << " ";
            next(node->next);
        }
    }

    ~TraitsList() {
        // TODO
    }
};

#endif