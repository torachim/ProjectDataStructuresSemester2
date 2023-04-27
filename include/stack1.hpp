#pragma once
#include <iostream>
#include "../include/stackinterface1.hpp"
#include "../include/list1.hpp"
//#include "../include/listnode.hpp"
//#include "../src/linkedlist.ipp"


namespace ProjectAlpha {


    template<class T>

    class stack: public stackinterface<T> {

        public:
        stack();
        void push (T data);
        T pop ();
        int size();
        bool isEmpty();
        void printStack();

        private:
        List<T> list;

    };







    ////////////// Implementierung /////////////



     template<class T>
    stack<T>::stack(): list() {}

    template<class T>
    void stack<T>::push(T data){
        list.insertAfter(data);
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









