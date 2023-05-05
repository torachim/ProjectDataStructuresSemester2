#pragma once
#include <iostream>

namespace ProjectAlpha {

    template <class T>

    class stackinterface{

        public:
            virtual void push(T) =0;  //insert_front / Element des Typen T wird vorne im Stack eingefügt
            virtual T pop() =0;    //remove_front  /forderste Element des Stacks wird entfernt
            virtual int size() =0;  // gibt Größte des Stacks zurück

    } ;
}
