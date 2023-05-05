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
        std::shared_ptr<Node <T> > head;  //Pointer auf dem vordesten Element des Stacks 
        int size_;   // Variable speichert die Größe des Stacks

    };


    ////////////// Implementierung /////////////

    template<class T>
    Node<T>::Node(T element){     //Node Konstrukter
        element_ = element;       //eingegebenes Elements wird als Node betrachtet
    }

    template<class T>
    stack<T>::stack(){            //Stack Konstrukter
        head = nullptr;           //Liste als leer makiert
    }

    template<class T>
    void stack<T>::push(T data){
        std::shared_ptr<Node <T>> newHead= std::make_shared<Node<T>>(data);   //Speichern des eingegebenen Elementes in der Variable newHead
        newHead -> next = head;  //vorherigers erstes Element wird als Nachfolger des neuen Elementes makiert
        head = newHead;          //eingefügtes Element wird als erstes Element makiert
         size_ = size_ + 1;      //Stack Größe um eins erhöht
    }

    template<class T>
    T stack<T>::pop(){
        if (head== nullptr) {   //Ausnahmebehandlung: überprüft ob Stack leer ist
            throw std::out_of_range("Stack is empty");
        }
        else{                            //Falls Stack nicht leer
            T removed = head->element_;  // erste Element wird in der Variable removed gespeichert
            head = head->next;           //nachfolgendes Element wird als erstes Element makiert, erste Element somit entfernt
            size_ = size_ - 1;           //Stack Größe um eins reduziert
            return removed;
            
        }
    }

    template<class T>
    int stack<T>::size(){
        return size_;         // Wiedergabe des Wertes, welches in size gespeichert-> entspricht der Größe des Stacks
    }


    template<class T>
    void stack<T>::printStack(){
        std::shared_ptr<Node<T>> current = head;   //current hilft beim durchlaufen des Stacks
        while (current){                           //bis alle Elemente durchlaufen sind
            std::cout<< current-> element_ <<" | "; //drucke das gerade betrachtete Element
            current= current -> next;               //wandere zum nächsten Element
        }
        std::cout << std::endl;                     //zur nächsten Zeile
    }
    
    

}










