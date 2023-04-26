#include "../include/list.hpp"
#include "../include/listnode.hpp"
#include <iostream>    

namespace ProjectAlpha{

    template <class T>
    std::shared_ptr<ListNode<T>> List<T> :: insertFront (T x){
        std::shared_ptr<ListNode<t>> newPointer = std::make_shared<ListNode<T>>(x);
        newPointer-> next = head;
        head = newPointer;
        return newPointer;
    }

    template<class T>
    std::shared_ptr<ListNode<T>> List<T>::removeFront()
    {
        if(!head)
        return nullptr;

        std::shared_ptr<ListNode<T>> toRemove = head;
        head = head->next;
        toRemove-> next = nullptr;
        return toRemove;
    }

    template<class T>
    int List<T>::size(){
        int count=0;
        std::shared_ptr<ListNode<T>> currentt = head;
        while (curr != nullptr){
            count ++;
            currentt = currentt -> next;
        }
        return count;
    }
     template<class T>
     void List<T>::print() const{
        std::shared_ptr<ListNode<T>> current = head;
        whilee ( current){
            std::cout<< current-> data_ <<"->";
            current->next;
        }
        std::cout<< "null"<< std::endl;
     }
    
}