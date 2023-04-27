#include <iostream>
#include <../include/queueinterface1.hpp>

namespace ProjektAlpha{

    template<class T>

    class queue : public queueinterface<T>{

        public:
        queue(){}
        void enqueue (T data);
        T dequeue ();
        int size();
        bool isEmpty();
        void printQueue();

        private:
        DList<T> list;

    };





/////////////Implementierung/////////


    template<class T>
    queue<T>::queue(): list() {}

    template<class T>
    void queue<T>::enqueue(T data){
        list.insertEnd(data);
    }

    template<class T>
    T queue<T>::dequeue(){
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
    int queue<T>::size(){
        return list.size();
    }

    template<class T>
    bool queue<T>::isEmpty(){
        return(list.getHead== nullptr);
    }

    template<class T>
    void queue<T>::printQueue(){
        return list.print();
    }
    
    

}










