#pragma once
#include <iostream>
#include "queueNode.hpp"
#include "queueinterface.hpp"

namespace ProjectAlpha{

    template<class T>

    class queue : public queueinterface<T>{

        public:
        queue();
        void enqueue (T data);
        T dequeue ();
        int size();
        void printQueue();

        private:
        std::shared_ptr<Node <T> > tail;
        std::shared_ptr<Node <T> > head;
        int size_;

    };


/////////////Implementierung/////////


    template<class T>
    Node<T>::Node(T element){
        element_ = element;
    }

    template<class T>
    queue<T>::queue(){
        head = nullptr;
        tail = nullptr;
    }

    template<class T>
    void queue<T>::enqueue(T data){
        
        if (tail == nullptr) {
            tail = std::make_shared<Node<T>>(data);
            head = tail;
        } 
        else {
                std::shared_ptr<Node <T>> newTail = std::make_shared<Node<T>>(data);
                tail->next = newTail;
                tail = newTail;
        };

        size_ = size_ + 1;
    }

    template<class T>
    T queue<T>::dequeue(){
       
       if (head== nullptr) {
            throw std::out_of_range("Queue is empty");
        }
        
        T removed = head -> element_;
        head = head->next;
        size_ = size_ - 1;
        
        if (head == nullptr) {
            tail = nullptr;
        } 

        return removed;
    }
    

    template<class T>
    int queue<T>::size(){
        return size_;
    }

   

    template<class T>
    void queue<T>::printQueue(){
        std::shared_ptr<Node<T>> current = head;
        while (current){
            std::cout<< current-> element_ <<" | ";
            current= current -> next;
        }
        std::cout << std::endl;
    }
    
    

}










