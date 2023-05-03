#include <iostream>
#include <../include/queueinterface.hpp>
#include <../include/dlist.hpp>

namespace ProjectAlpha{

    template<class E>

    class queue : public queueinterface<E>{

        public:
        queue();
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
        list.addLast(data);
    }

    template<class E>
    E queue<E>::dequeue(){
       
       if (list.head== nullptr) {
            throw std::out_of_range("Queue is empty");
        }
        
        else{
            E value = list.removeFirst();
            return value;
        }
    }

    template<class E>
    int queue<E>::size(){
        return list.size();
    }

   

    template<class E>
    void queue<E>::printQueue(){
        return list.print();
    }
    
    

}










