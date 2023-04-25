//mithilfe einfach verketteter Liste
#include "../include/stack.hpp"
#include "../include/list.hpp"
#include "../include/listnode.hpp"
#include<iostream>

namspace ProjectAlpha{

    template<class T>
    stack<T>::stack(): list() {}

    template<class T>
    void stack<T>::push(T data){
        list.insertFront(data);
    }

    template<class T>
    T stack<T>::pop(){
        if(isEmpty()){
            std::cout <<"Stack is empty\n";
            return T();
        }
        else{
            t value = list.removeFront()->data_;
            return value;
        }
    }

    template<class T>
    int stack<T>::size(){
        return list.size();
    }

    template<class T>
    bool stack<T>::isEmpty(){
        return(list.getHead== nullptr);
    }

    template<class T>
    void stack<T>::printStack(){
        return list.print();
    }
    
    

}


/*

    class stack{

        struct Node{
            int data;
            Node* next;
            Node(int d, Node* n = nullptr): data(d), next(n){}
        };

        Node* top; 

        stack(): top(nullptr){}


        void push(T data){


            Node* newNode = newNode (data,top); //Zeiger auf neuen Knoten 
            top= newNode;                       // Neuen Knoten als obersten makieren
        }

        T pull(){
            if(top==nullptr){                    //leer? oberster Knoten auf nullptr
                std::cout<< "Stack is empty." << std::endl;
                return -1;
            }
            else{
            T data = top ->data;           // data vorauf top zeigt, da oberste     //???????? T oder int ???????
            Node* temp = top;                // zeiger auf knoten der weg muss
            top = top->next;                // top zu einen danach wechseln
            return data;
            }
        }

        int size(){
            int size =0;           //zähler auf null
            Node* current = top;   // current auf ersten stellen, fängt am Anfang an
            while( current != nullptr){
                size++;
                current= current->next     // wandert eine Stelle weiter
            }
            return size;
        }   
}


