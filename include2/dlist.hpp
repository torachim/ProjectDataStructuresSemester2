#pragma once
#include <memory>
#include <iostream>
#include "../include/dlistnode1.hpp"



namespace ProjectAlpha{



  template<class T>

    class DListNode{
    public:
    DListNode(T data) : data_(data), next(nullptr) {} 

    public:
    std::shared_ptr<DListNode<T>> next;
    std::weak_ptr<DListNode<T>> prev;
    
  
    int data_;
};


    template<class T>

    class DoublyLinkedList{

    public:
    DList(). head(nullptr), tail(nullptr){}

    std::shared_ptr<DListNode<T>> insertEnd(T x);
    std::shared_ptr<DListNode<T>> removeFront();
    int size();
    void print() const;

    private:
    std::shared_ptr<<ListNode<T>> head;
    std::shared_ptr<<ListNode<T>> tail;

  };

}


	 
