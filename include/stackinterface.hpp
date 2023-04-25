#pragma once
#include <iostream>

namespace ProjectAlpha{

    template <class T>

    class stacktemplate{

        public:
            virtual void push(T) =0;  //insert_front
            virtual T pop() =0;    //remove_front
            virtual int size() =0;

    } ;
}

