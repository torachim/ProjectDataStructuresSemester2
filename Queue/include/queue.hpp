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
        std::shared_ptr<Node <T> > tail;  //Poinetr auf dem letzten Element der Queue
        std::shared_ptr<Node <T> > head;  //Pointer auf de m vordesten Element der Qeue
        int size_;                        //Variable speichert Größe der Queue

    };


/////////////Implementierung/////////


    template<class T>
    Node<T>::Node(T element){   //Node Konstruktor 
        element_ = element;     //eingegebenes Elements wird als Node betrachtet
    }

    template<class T>
    queue<T>::queue(){        //Queue Konstruktor
        head = nullptr;       //Queue wird als leer makiert
        tail = nullptr;       //Queue wird als leer makiert
        size_=0;
    }

    template<class T>
    void queue<T>::enqueue(T data){
        
        if (tail == nullptr) {         //überprüft, ob die Liste leer ist
            tail = std::make_shared<Node<T>>(data); //einfügen des Elementes
            head = tail;                            // Element als erstes und letztes Elment makiert,da einziges Element in der Queue
        } 
        else {    //falls Liste schon Elemente enthält
                std::shared_ptr<Node <T>> newTail = std::make_shared<Node<T>>(data); //speichern des einzufügenden Elementes in Variable newTail
                tail->next = newTail;  //neues Element wird als Nachfolger des vorherigen letzten Elementes makiert
                tail = newTail;        //eingefügtes Elemt wird als letztes Elemnt der Queue makiert
        };

        size_ = size_ + 1;    // Erhöhung der Queue Größe um eins
    }

    template<class T>
    T queue<T>::dequeue(){
       
       if (head== nullptr) {      //Ausnahmebehandlung: überprüft ob Queue leer ist
            throw std::out_of_range("Queue is empty");
        }
        else{                         //falls Queue nicht leer
        T removed = head -> element_; // erste Element wird in der Variable removed gespeichert
        head = head->next;            //nachfolgendes Element wird als erstes Element makiert, erste Element somit entfernt
        size_ = size_ - 1;            //Stack Größe um eins reduziert
        
        if (head == nullptr) {        //überprüft ob Liste keine Elemente mehr hat
            tail = nullptr;            //falls ja wird Liste als leer makiert
        } 

        return removed;
        }
    }
    

    template<class T>
    int queue<T>::size(){
        return size_;         // Wiedergabe des Wertes, welches in size gespeichert-> entspricht der Größe der Queue
    }

   

    template<class T>
    void queue<T>::printQueue(){
        std::shared_ptr<Node<T>> current = head;    //current hilft beim durchlaufen der Queue
        while (current){                            //bis alle Elemente durchlaufen sind
            std::cout<< current-> element_ <<" | "; //drucke das gerade betrachtete Element
            current= current -> next;               //wandere zum nächsten Element
        }
        std::cout << std::endl;                     //zur nächsten Zeile
    }
    
    

}










