#pragma once
#include <memory>
#include <iostream>
#include "../include/listnode.hpp"



namespace Datenstrukturen {

    template<class T>

    class DoublyLinkedList{

    public:
    DList();

    std::shared_ptr<ListNode<T>> getLast() const;
    std::shared_ptr<ListNode<T>> insertEnd(T x);
    std::shared_ptr<ListNode<T>> removeFront();
    void print() const;

    private:
    std::shared_ptr<<ListNode<T>> head;
    std::shared_ptr<<ListNode<T>> tail;

  };

}


	 
