#ifndef HEAPTREENODE
#define HEAPTREENODE
#include <iostream>
#include <vector>


namespace ProjectAlpha{

    template<class T>
    class PQnode{
    public:

        PQnode(T data, int prioritaet);

        T get_data();

        int get_prioritaet();


    private:

        int prioritaet_;

        T data_;

    };
}






#endif