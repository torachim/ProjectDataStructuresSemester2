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
    std::shared_ptr<ListNode<T>> insertAfter(T x);
    std::shared_ptr<ListNode<T>> removeFront()


  DListNodeptr remove(const DListNodeptr& n);

  // Get the next Node of the current List
  DListNodeptr next(const DListNodeptr& n) const;
  
  // Get the previous Node of the current List
  DListNodeptr prev(const DListNodeptr& n) const;

  // Print the current List
  void print() const;

private:
  DListNodeptr head;
  DListNodeptr tail;
};

}


	
