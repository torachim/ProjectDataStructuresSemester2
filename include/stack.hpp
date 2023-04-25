#pragma once
#include <iostream>
#include "../include/stackinterface.hpp"
#include "../include/list.hpp"
#include "../include/listnode.hpp"
#include "../src/linkedkist.ipp"

namespace ProjektAlpha{


    template<class T>

    class stack:public stacktemplate<T>{

        public:
        stack();
        void push (T data);
        T pop ();
        int size();
        bool isEmpty();
        void printStack();

        private:
        List<T> list;
       



    };
}




