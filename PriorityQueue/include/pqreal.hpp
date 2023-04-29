#ifndef PQUEUE_REAL
#define PQUEUE_REAL
#include <iostream>
#include "pqabstract.hpp"
#include "Heaptree.hpp"

using namespace ProjectAlpha;

    template<class T>
    class PQueue_realisation : public abstract_Pqueue<T> {
    public:

        PQueue_realisation();

        size_t get_size();

        void insert(T x, int priorität);

        T remove();

        void print();

    private:

        size_t size;

    };





#endif

    template<class T>
    PQueue_realisation<T>::PQueue_realisation(){
        size = 0;
    }

    template<class T>
    Heaptree<T>::Heaptree(){
        Wurzel = nullptr;
        letztes = nullptr;
    }

    template<class T>
    Heaptreenode<T>::Heaptreenode(T data, int prioritaet){
        data_ = data;
        prioritaet_ = prioritaet;
        left_child = nullptr;
        right_child = nullptr;
        parent = nullptr;
    }

    template<class T>
    void Heaptree<T>::remove_wrz(){
        if(Wurzel == nullptr){
            throw std::logic_error("Error ein Wurzelknoten sollte entfernt werden existiert aber nicht");
        }
    }
//Hier folgt die realisation der Priority Queue