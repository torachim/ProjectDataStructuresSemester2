#include <iostream>
#include <../include/queueinterface1.hpp>
#include <../include/sarahdlist.hpp>

namespace ProjectAlpha{

    template<class E>

    class queue : public queueinterface<E>{

        public:
        queue(){}
        void enqueue (E data);
        E dequeue ();
        int size();
        void printQueue();

        private:
        DoppeltVerkettet<E> list;

    };





/////////////Implementierung/////////


    template<class E>
    queue<E>::queue(): list() {}

    template<class E>
    void queue<E>::enqueue(E data){
        list.add(data);
    }

    template<class T>
    T queue<T>::dequeue(){
       
       if (list.head== nullptr) {
            throw std::out_of_range("Queue is empty");
        }
        
        else{
            t value = list.removeFirst()->data_;
            return value;
        }
    }

    template<class T>
    int queue<T>::size(){
        return list.size();
    }

   

    template<class T>
    void queue<T>::printQueue(){
        return list.print();
    }
    
    

}










