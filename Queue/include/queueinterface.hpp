#pragma once
#include <iostream>

namespace ProjectAlpha {

    template <class E>

    class queueinterface{

        public:
            virtual void enqueue(E) =0;  //insert_front
            virtual E dequeue() =0;    //remove_front
            virtual int size() =0;

    } ;
}