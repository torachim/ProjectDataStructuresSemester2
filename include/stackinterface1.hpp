#pragma once
#include <iostream>

namespace ProjectAlpha {

    template <class E>

    class stackinterface{

        public:
            virtual void push(E) =0;  //insert_front
            virtual E pop() =0;    //remove_front
            virtual int size() =0;

    } ;
}
