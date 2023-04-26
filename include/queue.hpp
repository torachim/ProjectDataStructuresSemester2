#include <iostream>
#include <../include/queueinterface.hpp>

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
        dList<T> list;

    };

}
