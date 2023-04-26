#pragma once 
#include <memory>
#include <stdexcept>
#include <iostream>
#include <string>
#include "../include/verkettet.hpp"


namespace ProjectAlpha {

template <typename E>
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
    E element; //enthält ein Element, zwei zeiger die auf nächsten und vorherigen knoten der liste zeigen
    Node<E>* next;
    Node<E>* prev;

    Node(E element, Node<E>* next = nullptr, Node<E>* prev = nullptr) { //Konstruktor
        this->element = element;
        this->next = next;
        this->prev = prev;
    }
};

template <typename E>
class EinfachVerkettet : public AbstractListe<E> { //erbt von AbsractListe

protected:
    int size_;
    Node<E>* head; //Zeiger auf dem Kopf der liste sowie die Größenvariabel

public:
    EinfachVerkettet() : size_(0), head(nullptr) {} //leere Liste

    void add(E element) override { //fügt ein Element am Ende hinzu, indem sie die "addLast" Methode aufruft
        addLast(element);
    }

    void addFirst(E element) override { //fügt E am anfang
        head = new Node<E>(element, head); //neuen knoten mit E als wert erstellt und ihn als neuen kopf der liste setzt
        size_++;
    }

    void addLast(E element) override { //fügt element am ende hinzu
        if (head == nullptr) { //wenn liste leer dann,..
            head = new Node<E>(element); // neuen knoten am ende der liste herstellt
        } else { //oder..
            Node<E>* current = head; 
            while (current->next != nullptr) { //Die liste ist nicht leer:
                current = current->next; // der nächste zeiger des letzten knotens
            }
            current->next = new Node<E>(element); //wird auf den neuen knoten gesetzt
        }
        size_++; //Größe der Liste wird entspechend erhöht
    }

    E remove(int index) override { //entfernt Element  an der angegebenen Position in der Liste
        if (index < 0 || index >= size_) { //es wierd überprrüft, ob der angegebene index im gültigen bereich der liste liegt
            throw std::out_of_range("Index out of range"); //out of range ausnahme, fehler meldung
        }
        if (index == 0) { //wenn index gleich 0 null
            return removeFirst(); // methode aufgerufen, entfernt das erste element, siehe z.84
        }
        Node<E>* prev = nullptr;  //neuer zeiger prev, zeigt auf nullptr 
        Node<E>* current = head; //neuer zeiger current, wird auf das kopfelement gesetzt
        for (int i = 0; i < index; i++) { //Schleife, liste wird durchlaufen um elemnt zu finden
            prev = current; //prev wird jedesmal auf current gesetzt  um es um ein element zu verschieben
            current = current->next;
        }
        E removed = current->element; //gesuchte element wird in removed gespeichert um es zurückzugeben
        prev->next = current->next; //next zeiger vor dem Element wird auf das nachfolger element gesetzt sodass das zu löschende element herausgeschnitten wird
        delete current; // das zu löschende element wird gelöscht
        size_--; //größe der liste wird reduziert
        return removed; //entfernte element wird zurückgegeben 
    }

    E removeFirst() override {
        if (head == nullptr) { //wenn die Liste leer ist= head zeigt auf nullptr
            throw std::out_of_range("List is empty"); //ausnahme 
        }
        E removed = head->element; //wenn nichtt leer, wert des elements wird gespeichert
        Node<E>* temp = head;  //aktuelle kopfzeiger
        head = head->next; //wird auf den nachfolgerknoten des ersten knotens  umgestellt
        delete temp; // der knoten der auf head mal verwiesen hat, wird gelöscht
        size_--; //Größe der Liste wird reduziert
        return removed; //wird returned, also das entfernte element
    }

    E get(int index) const override { // gibt das Element zurück
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range"); //ausnahme wie zuvor
        }
        Node<E>* current = head; // 
        for (int i = 0; i < index; i++) { // wie ab z. 72
            current = current->next; //findet knoten und gibt dessen wert zurück
        }
        return current->element;
    }

    int size() const override { //gibt wert zurück
        return size_;
    }
};
}

