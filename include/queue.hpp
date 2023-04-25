#include <iostream>
#include <../include/queueinterface.hpp>

namespace ProjektAlpha{

    template<classT>

    class queue : public queueinterface<T>{

        public:
        queue(){}
        void enqueue (T data);
        T dequeue ();
        int size();

        private:
        abstarctlist<T> list;

    };

}
