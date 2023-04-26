#pragma once
#include <memory>


namespace ProjectAlpha {

template <class E>
class AbstractListe { // enthält rein virtuelle methoden, die in den Subklassen überschrieben werden müssen
public:
    virtual void add(E element) = 0;
    virtual void addFirst(E element) = 0;
    virtual void addLast(E element) = 0;
    virtual E remove(int index) = 0;
    virtual E removeFirst() = 0;
    virtual E get(int index) const = 0;
    virtual int size() const = 0;
};

template <typename E>
class Node { // definiert die Knoten der Liste
public:
Node(E element, Node<E>* next = nullptr, Node<E>* prev = nullptr);

};

template <typename E>
    class EinfachVerkettet : public AbstractListe<E> {
    
    

public:
    //EinfachVerkettet() : size_(0), head(nullptr) {} //leere Liste



    void add(E element)  { //fügt ein Element am Ende hinzu, indem sie die "addLast" Methode aufruft
        addLast(element);
    }
        
        void addFirst(E element) ; 

        void addLast(E element) ;

        E remove(int index) ;

        E removeFirst() ;

        E get(int index) const ;

        int size() const ;

    
    };



template <typename E>
class DoppeltVerkettet : public EinfachVerkettet<E> {

 private:
    Node<E>* tail; // Tail zeigt auf den letzten knoten

public:
    DoppeltVerkettet() : EinfachVerkettet<E>(), tail(nullptr) {}

    void add(E element) {  //addLast, addFirst, remove, removeFirst, removeLst wird überschrieben
        addLast(element); //überschreibt add von basisklasse EinfachVerkettet, indem sie die Methode addLast aufruft, sodass element am ende der liste hinzufügen
    }

    void addFirst(E element);

    void addLast(E element);

    E remove(int index);

    E removeFirst(); //entfernt den erste knoten aus der liste
    
    E removeLast();

    

};

}


