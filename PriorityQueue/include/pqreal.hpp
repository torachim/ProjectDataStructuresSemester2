#ifndef PQUEUE_REAL
#define PQUEUE_REAL
#include <iostream>
#include "pqabstract.hpp"
#include "PQueuenode.hpp"
#include <vector>



using namespace ProjectAlpha;

    template<class T>
    class PQueue_realisation : public abstract_Pqueue<T>{
    public:

        PQueue_realisation();

        int get_size();

        void insert(T data, int prioritaet);

        T remove();

        void print();

        std::vector<PQnode <T> > Schlange;

        

    private:

        int size;

        int parent(int i);

        int right_child(int i);

        int left_child(int i);

        void shift_down(int i);

        void shift_up(int i);

    };





#endif

    template<class T>
    PQueue_realisation<T>::PQueue_realisation(){
        size = 0;
        //Schlange = std::vector<std::shared_ptr<PQnode <T> > >();
    }

    template<class T>
    PQnode<T>::PQnode(T data, int prioritaet): data_(data), prioritaet_(prioritaet){
    }

    template<class T>
    T PQnode<T>::get_data(){
        return data_;
    }

    template<class T>
    int PQueue_realisation<T>::get_size(){
        return size;
    }

    template<class T>
    void PQueue_realisation<T>::insert(T data, int prioritaet){
        PQnode<T> p = PQnode<T>(data, prioritaet);
        Schlange.push_back(p);
        shift_up(size);
        size = size + 1;
    }

    template<class T>
    int PQueue_realisation<T>::parent(int i){
        int t = (i - 1)/2;
        return t;
    }

    template<class T>
    int PQueue_realisation<T>::right_child(int i){
        int t = ((2 * i)+ 2);
        return t;
    }

    template<class T>
    int PQueue_realisation<T>::left_child(int i){
        int t = ((2 * i)+ 1);
        return t;
    }

    template<class T>
    int PQnode<T>::get_prioritaet(){
        return prioritaet_;
    }

    template<class T>
    void PQueue_realisation<T>::shift_up(int i){
        while(i > 0 and (Schlange[i].get_prioritaet() > Schlange[parent(i)].get_prioritaet())){
            //std::swap(Schlange[parent(i)], Schlange[i]);
            PQnode <T> hilfe = Schlange[parent(i)];
            Schlange[parent(i)] = Schlange[i];
            Schlange[i] = hilfe;
            i = parent(i);
        }
    }

    template<class T>
    void PQueue_realisation<T>::shift_down(int i){
        int max_indx = i;
        int l = left_child(i);
        int r = right_child(i);
        if(l <= size and (Schlange[max_indx].get_prioritaet() < Schlange[l].get_prioritaet())){
            max_indx = l;
        }
        if(r <= size and (Schlange[max_indx].get_prioritaet() < Schlange[r].get_prioritaet())){
            max_indx = r;
        }
        if(i != max_indx){
           // std::swap(Schlange[i], Schlange[max_indx]);
            PQnode <T> hilfe = Schlange[max_indx];
            Schlange[max_indx] = Schlange[i];
            Schlange[i] = hilfe;
            shift_down(max_indx);
        }
    }

    template<class T>
    T PQueue_realisation<T>::remove(){
        T result = Schlange[0].get_data();
        Schlange[0] = Schlange[size - 1];
        size = size - 1;
        Schlange.pop_back();
        shift_down(0);
        return result;
    }

    template<class T>
    void PQueue_realisation<T>::print(){
        for(int k = 0; k < size; k++){
            std::cout << Schlange[k].get_data() << std::endl;;
        }
    }



//Hier folgt die realisation der Priority Queue