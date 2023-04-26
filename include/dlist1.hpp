#pragma once
#include <memory>
#include <iostream>



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

    class DList{

    public:
    DList(): head(nullptr), tail(nullptr){}

    std::shared_ptr<DListNode<T>> insertEnd(T x);
    std::shared_ptr<DListNode<T>> removeFront();
    int size();
    void print() const;

    private:
    std::shared_ptr<<ListNode<T>> head;
    std::shared_ptr<<ListNode<T>> tail;

  };







////////////////Implementierung/////////////


template<class T>
    std::shared_ptr<DListNode<T>> DList<T>:: insertEnd(T x){
        std::shared_ptr<ListNode<T>> newNode = std::make_shared<DListNode<T>>(x)
        if(!head){
            head = newNode,
        }
        else{
            tail->next = newNode;
        }
        tail= newNode
    }


    template <class T>
    std::shared_ptr<DListNode<T>> DList<T>::removeFront(){
        if(!head){
            return nullptr;
        }
        else{
            std::shared_ptr<ListNode<T>> toRemove=head ;  
            head=head->next;   
            return head; 
        }
    }
    

    template<class T>
    int DList<T>::size(){
        int count=0;
        std::shared_ptr<DListNode<T>> currentt = head;
        while (curr != nullptr){
            count ++;
            currentt = currentt -> next;
        }
        return count;


    template <class T>
    void DList<T>::print()const{

            std::shared_ptr<DListNode<T>> current = head;

            while(current)
            {
                std::cout<<current->data_<<"->";
                current=current->next;
            } 
            std::cout<<"null"<<std::endl;   
        }


}


}


	 
