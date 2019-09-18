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

    bool find(T data, Node<T> **&pointer) {
        bool resultBool = false;

        for (pointer = &head; *pointer != NULL; pointer = &(*pointer)->next) {
            if (data == (*pointer)->data) {
                if (method == Method::Count)
                    (*pointer)->count++;

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
        Node<T> **doublePointer= nullptr;

        if (find(data, doublePointer) ) {
            *doublePointer = (*doublePointer)->next;
            return true;
        } else {
            return false;
        }
    }

    bool find(T data) {
        int size = this->size();
        bool condition;

        if (size == 0) {
            return false;

        } else if (this->head->data == data) {
            if( method == Method::Count)
                this->head->count++;

            return true;

        } else if (size >= 2
        && this->head->next->data == data){

            if( method != Method::Count) {
                auto node_1 = this->head;
                auto node_2 = node_1->next;
                auto node_3 = node_2->next;

                node_1->next = nullptr;
                this->head = node_2;
                this->head->next = node_1;
                if(node_3)
                    node_1->next = node_3;
            }
        }

        switch (method) {
            case Method::Count : {
                condition = countMethod(data);
            }
                break;

            case Method::Move : {
                condition = moveMethod(data);
            }
                break;

            case Method::Transpose : {
                condition = transpMethod(data, size);
            }
                break;
        }

        return condition;
    }

    T operator[](int index) {
        int i=0;
        if ( index > this->size() - 1 )
            throw runtime_error("Index out of lenght");

        auto aux = this->head;

        while(aux->next != nullptr && index != 0) {

            if ( i == index) {
                break;
            } else {
                aux = aux->next;
                i++;
            }
        }
        return aux->data;
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

    bool moveMethod(T data) {
        Node<T> **doublePointer= nullptr;

        if ( !find(data, doublePointer) ) {
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

    bool countMethod(T data) {
        Node<T> **doublePointer= nullptr;
        Node<T> **doublePointer2= nullptr;

        int size = this->size();

        if ( !find(data, doublePointer) ) {
            return false;
        } else {
            auto aux = *doublePointer;

            *doublePointer = (*doublePointer)->next;

            for(doublePointer2 = &head; *doublePointer2 != NULL;
            doublePointer2 = &(*doublePointer2)->next) {
                auto *lp = *doublePointer2;
                if(aux->count > lp->count)
                {
                    aux->next = lp;
                    *doublePointer2 = aux;
                    break;
                }
            }

            /*while( size != 0 ){
                if ((*doublePointer)->count > aux->count ){
                    swap((*doublePointer)->data, aux->data);
                    swap((*doublePointer)->count, aux->count);
                    break;
                }
                aux = aux->next;
                size--;
            }*/
        }
    }

    ~SelfList() {
        head->killSelf();
    }
};

#endif