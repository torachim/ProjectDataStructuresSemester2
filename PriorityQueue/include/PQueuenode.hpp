#ifndef HEAPTREENODE
#define HEAPTREENODE
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <utility>
#include <string_view>

namespace ProjectAlpha{

    template<class T>
    class PQnode{
    public:

        PQnode(T data, int prioritaet);

        T get_data();

        int get_prioritaet();

        //void set_left_child(T data, int prioritaet);

        //void set_right_child(T data, int prioritaet);

        //std::shared_ptr<Heaptreenode <T> > get_left_child();
        
        //std::shared_ptr<Heaptreenode <T> > get_right_child();

        //void remove_left_child();

        //void remove_right_child();

    private:

        T data_;

        int prioritaet_;




    };
}






#endif