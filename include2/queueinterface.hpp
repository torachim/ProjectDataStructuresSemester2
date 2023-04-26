#pragma once
#include <iostream>

namespace ProjectAlpha {

    template <class T>

    class queueinterface{

        public:
            virtual void enqueue(T) =0;  //insert_front
            virtual T dequeue() =0;    //remove_front
            virtual int size() =0;

    } ;
}

