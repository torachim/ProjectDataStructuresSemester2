//mithilfe einfach verketteter Liste
#include "../include/stack.hpp"
#include "../include/list.hpp"
#include "../include/listnode.hpp"
#include <iostream>

namespace ProjectAlpha {

    template<class T>
    stack<T>::stack(): list() {}

    template<class T>
    void stack<T>::push(T data){
        list.insertFront(data);
    }

    template<class T>
    T stack<T>::pop(){
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
    void stack<T>::printStack(){
        return list.print();
    }
    
    

}


