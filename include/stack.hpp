#pragma once
#include <iostream>
#include "../include/stackinterface.hpp"
#include "../include/list.hpp"
#include "../include/listnode.hpp"
#include "../src/linkedlist.ipp"

namespace ProjektAlpha {


    template<class T>

    class stack: public stackinterface<T>{

        public:
        stack();
        void push (T data);
        T pop ();
        int size();

        private:
        List<T> list;
       



    };
}

