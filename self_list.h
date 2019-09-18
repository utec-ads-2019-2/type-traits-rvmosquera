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
        } else if (size >= 2
        && this->head->next->data == data){
            //count method increment
            auto node_1 = this->head;
            auto node_2 = node_1->next;
            auto node_3 = node_2->next;

            node_1->next = nullptr;
            this->head = node_2;
            this->head->next = node_1;
            if(node_3)
                node_1->next = node_3;
        }

        switch (method) {
            case Method::Count : {

            }
                break;

            case Method::Move : {
                return moveMethod(data);
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


    bool moveMethod(T data) {
        Node<T> **doublePointer= nullptr;

        if ( !find_1(data, doublePointer) ) {
            return false;
        } else {
            auto aux = *doublePointer;
            *doublePointer = (*doublePointer)->next;

            aux->next = this->head;
            this->head = aux;

            return true;
        }
    }

    bool transpMethod(T data, int size) {
        bool condition;
        Node<T> *node_1 = nullptr;
        Node<T> *node_2 = nullptr;
        Node<T> *node_3 = nullptr;

        switch (size) {
            case 2: {
                node_1 = this->head;
                node_2 = node_1->next;

                if ( node_2->data == data)
                    condition = true;
                else
                    return false;

                this->head = node_2;
                this->head->next = node_1;

            } break;

            default: {
                node_1 = this->head;
                node_2 = node_1->next;
                node_3 = node_2->next;

                condition = false;
                while (node_3->next != nullptr) {
                    if (node_3->data == data) {
                        node_2->next = node_3->next;
                        node_3->next = node_2;
                        node_1->next = node_3;
                        condition = true;
                        break;
                    }
                    node_1 = node_1->next;
                    node_2 = node_2->next;
                    node_3 = node_3->next;
                }
            } break;

        }

        return condition;
    }

    void countMethod() {

    }

    ~SelfList() {
        head->killSelf();
    }
};

#endif