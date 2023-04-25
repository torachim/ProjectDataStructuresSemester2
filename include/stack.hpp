#include <iostream>
#include <../include/stacktemplate.hpp>
#include sarah

namespace ProjektAlpha{


    template<class T>

    class stack:public stacktemplate<T>{

        public:
        stack(){}
         void push (T data);
         T pop ();
         int size();

        private:
        abstractlist<T> list;
       



    };
}




