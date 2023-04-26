//mithilfe einfach verketteter Liste
#include "../include/queue.hpp"
#include "../include/dlist.hpp"
#include "../include/dlistnode.hpp"
#include <iostream>

namespace ProjectAlpha {

    template<class T>
    queue<T>::queue(): list() {}

    template<class T>
    void stack<T>::enqueue(T data){
        list.insertBack(data);
    }

    template<class T>
    T stack<T>::dequeue(){
        if(isEmpty()){
            std::cout <<"Stack is empty\n";
            return T();
        }
        else{
            t value = list.removeFront()->data_;
            return value;
        }
    }

    template<class T>
    int stack<T>::size(){
        return list.size();
    }

    template<class T>
    bool stack<T>::isEmpty(){
        return(list.getHead== nullptr);
    }

    template<class T>
    void stack<T>::printQueue(){
        return list.print();
    }
    
    

}







