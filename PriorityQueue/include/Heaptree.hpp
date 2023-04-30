/*#ifndef HEAPTREE
#define HEAPTREE
#include <iostream>
#include <memory>
#include "Heaptreenode.hpp"

namespace ProjectAlpha{

    template<class T>
    class Heaptree{
    public:

        Heaptree();

        void print();

        void remove_wrz();

        void remove_letzt();

    private:
        std::shared_ptr<Heaptreenode <T> > Wurzel;   
        std::shared_ptr<Heaptreenode <T> > letztes; 
    };
}



#endif*/