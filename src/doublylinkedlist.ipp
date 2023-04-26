#include "../include/dlist.hpp"
#include "../include/dlistnode.hpp"
#include <iostream>    

namespace ProjectAlpha{

    template <class T>
    ListNodeptr List::remove_front()
        { 
            ListNodeptr neuerHead=head->next;  //2.Objekt
            head=neuerHead;   //2.Objekt neuer Head
            return head; 
        }
    void DoublyLinkedList::print()const
        {
            DListNode current = head;

            while(current)
            {
                std::cout<<current->data_<<"->";
                current=current->next;
            } 
            std::cout<<"null"<<std::endl;   
        }


}