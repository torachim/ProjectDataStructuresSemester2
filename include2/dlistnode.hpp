#pragma once

#include <memory>


namespace ProjectAlpha {

    template<class T>


    class DListNode{
    public:
    DListNode(T data) : data_(data), next(nullptr) {} 

    public:
    std::shared_ptr<DListNode<T>> next;
    std::weak_ptr<DListNode<T>> prev;
    
  
    int data_;
};


typedef std::shared_ptr<DoublyLinkedListNode> DListNodeptr;   ///????????`
typedef std::weak_ptr<DoublyLinkedListNode> WeakDListNodeptr;

}


	
