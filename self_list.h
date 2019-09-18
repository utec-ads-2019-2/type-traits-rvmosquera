#ifndef SELF_LIST_H
#define SELF_LIST_H

#include "node.h"

template<typename T>
class SelfList {
public:
    enum Method {
        Move, Count, Transpose
    };

protected:
    Node<T> *head;
    Method method;

    bool find_1(T data, Node<T> **&pointer) {
        bool resultBool = false;

        for (pointer = &head; *pointer != NULL; pointer = &(*pointer)->next) {
            if (data == (*pointer)->data) {
                resultBool = true;
                break;
            }
        }

        return resultBool;
    }

public:
    SelfList(Method method) : head(nullptr), method(method) {};

    bool insert(T data) {
        Node<T> *newNode = new Node<T>(data);

        if (!this->head) {
            this->head = newNode;
        } else {
            auto aux = this->head;
            while (aux->next != nullptr) {
                aux = aux->next;
            }
            aux->next = newNode;
        }
    }

    bool remove(T data) {
        // TODO
    }

    bool find(T data) {
        int size = this->size();
        if (size == 0) {
            return false;
        } else if (this->head->data == data) {
            //count method increment
            return true;
        }

        switch (method) {
            case Method::Count : {

            }
                break;

            case Method::Move : {

            }
                break;

            case Method::Transpose : {
                transpMethod(data, size);
            }
                break;
        }

        return true;
    }

    T operator[](int index) {
        // TODO
    }

    int size() {
        if (!this->head)
            return 0;

        auto aux = this->head;
        int n = 1;
        while (aux->next != nullptr) {
            aux = aux->next;
            n++;
        }

        return n;
    }

    void print() {
        // TODO
    }


    void moveMethod() {

    }

    void transpMethod(T data, int size) {
        Node<T> *node_1 = nullptr;
        Node<T> *node_2 = nullptr;
        Node<T> *node_3 = nullptr;

        switch (size) {
            case 2: {
                node_1 = this->head;
                node_2 = node_1->next;

                this->head = node_2;
                this->head->next = node_1;

            } break;

            default: {
                node_1 = this->head;
                node_2 = node_1->next;
                node_3 = node_2->next;

                while (node_3->next != nullptr) {
                    if (node_3->data == data) {
                        node_2->next = node_3->next;
                        node_3->next = node_2;
                        node_1->next = node_3;
                        break;
                    }
                    node_1 = node_1->next;
                    node_2 = node_2->next;
                    node_3 = node_3->next;
                }
            } break;

        }
    }

    void countMethod() {

    }

    ~SelfList() {
        // TODO
    }
};

#endif