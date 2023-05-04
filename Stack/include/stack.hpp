#ifndef STACK
#define STACK
#include <iostream>
#include "../include/stackinterface.hpp"
#include "../include/list.hpp"



namespace ProjectAlpha {


    template<class E>

    class stack: public stackinterface<E> {

        public:
        stack();
        void push (E data);
        E pop ();
        int size();
        void printStack();

        private:
        EinfachVerkettet<E> list;

    };

    #endif







    ////////////// Implementierung /////////////



    template<class E>
    stack<E>::stack(): list() {}

    template<class E>
    void stack<E>::push(E data){
        list.addFirst(data);
    }

    template<class E>
    E stack<E>::pop(){
        if (list.head== nullptr) {
            throw std::out_of_range("Stack is empty");
        }
        else{
            E value = list.removeFirst();
            return value;
        }
    }

    template<class E>
    int stack<E>::size(){
        return list.size();
    }


    template<class E>
    void stack<E>::printStack(){
        return list.print();
    }
    
    
    

}










