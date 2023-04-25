#include <iostream>
#include <../include/queuetemplate.hpp>

namespace ProjektAlpha{

    template<classT>

    class queue : public queueinterface<T>{

        public:
         void enqueue (T data);
         T dequeue ();
         int size();

        private:
        abstarctlist<T> list;

    };

}
