#pragma once
#include <iostream>
#include "stackinterface.hpp"
#include "stackNode.hpp"



namespace ProjectAlpha {


    template<class T>

    class stack: public stackinterface<T> {

        public:
        stack();
        void push (T data);
        T pop ();
        int size();
        void printStack();

        private:
        std::shared_ptr<Node <T> > head;
        int size_; 

    };


    ////////////// Implementierung /////////////

    template<class T>
    Node<T>::Node(T element){
        element_ = element;
    }

    template<class T>
    stack<T>::stack(){
        head = nullptr;
    }

    template<class T>
    void stack<T>::push(T data){
        std::shared_ptr<Node <T>> newHead= std::make_shared<Node<T>>(data);
        newHead -> next = head;
        head = newHead;
         size_ = size_ + 1;
    }

    template<class T>
    T stack<T>::pop(){
        if (head== nullptr) {
            throw std::out_of_range("Stack is empty");
        }
        else{
            T removed = head->element_;
            head = head->next;
            return removed;
            
        }
    }

    template<class T>
    int stack<T>::size(){
        return size_;
    }


    template<class T>
    void stack<T>::printStack(){
        std::shared_ptr<Node<T>> current = head;
        while (current){
            std::cout<< current-> element_ <<" | ";
            current= current -> next;
        }
        std::cout << std::endl;
    }
    
    

}










