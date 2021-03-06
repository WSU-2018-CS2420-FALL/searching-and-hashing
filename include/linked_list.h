#ifndef _LINKED_LIST_ADT_H
#define _LINKED_LIST_ADT_H
#include <iostream>

template <typename T>
struct Node {
    T info;
    Node<T>* link;
    Node(T info): info(info), link(nullptr){}
    ~Node() {}
};

template<typename T>
class LinkedListIterator{
public:
    LinkedListIterator(Node<T>* ptr): current(ptr){}
    LinkedListIterator<T>& operator++(){
        current = current->link;
        return *this;
    }
    T operator*(){ return current->info; }
    bool operator==(const LinkedListIterator<T>& rhs) const {
        return current == rhs.current;
    }
    bool operator!=(const LinkedListIterator<T>& rhs) const {
        return current != rhs.current;
    }
private:
    Node<T>* current;
};

template <typename T>
class LinkedListADT {
public:
    virtual void add(T info) = 0;
    virtual void remove(T info) = 0;
    virtual void print() = 0;
    virtual LinkedListIterator<T> sequentualSearch(T) = 0;
    virtual LinkedListIterator<T> begin() = 0;
    virtual LinkedListIterator<T> end() = 0;
    virtual ~LinkedListADT() {}
};

template <typename T>
class LinkedList : LinkedListADT<T>{
public:
    LinkedList(): count(0), first(nullptr), last(nullptr){}
    LinkedList(const LinkedList<T>& list): LinkedList(){
        auto current = list.first;
        while(current){
            add(current->info);
            current = current->link;
        }
    }

    LinkedList<T>& operator=(const LinkedList<T>& list){
        destroy();
        auto current = list.first;
        while(current){
            add(current->info);
            current = current->link;
        }
        return *this;
    }

    LinkedListIterator<T> sequentualSearch(T data){
        auto current = first;
        while(current){
            if(current->info == data){
                return LinkedListIterator<T>(current);
            }

            current = current->link;
        }

        return end();
    }
    
    void add(T info){
        Node<T>* newNode = new Node<T>(info);
        if(first == nullptr){ // empty list
            first = newNode;
            last = newNode;
        } else {
            last->link = newNode;
            last = newNode;
        }

        count++;
    }

    void remove(T info){
        if(first == nullptr){
            std::cerr << "Empty list; nothing to remove" << std::endl;
        }else if(first->info == info){
            auto current = first;
            first = current->link;
            delete current;
            count--;
        } else {
            auto current = first->link;
            auto beforeCurrent = first;

            while(current){
                if(current->info == info){
                    beforeCurrent->link = current->link;
                    delete current;
                    count--;
                    return;
                }
                beforeCurrent = current;
                current = current->link;
            }

            std::cerr << "Not found" << std::endl;
        }
    }

    void print(){
        auto current = first;
        while(current){
            std::cout << current->info << " ";
            current = current->link;
        }
        std::cout << std::endl;
    }

    LinkedListIterator<T> begin(){return LinkedListIterator<T>(first);}
    LinkedListIterator<T> end(){return LinkedListIterator<T>(nullptr);}
    ~LinkedList() { destroy();}
protected:
    unsigned count;
    Node<T>* first;
    Node<T>* last;

    void destroy(){
        auto current = first;
        while(current){
            auto temp = current;
            current = current->link;
            delete temp;
            temp = nullptr;
        }

        first = nullptr;
        last = nullptr;
        count = 0;
    }
};

#endif
