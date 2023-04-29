#ifndef HEAPTREENODE
#define HEAPTREENODE
#include <iostream>
#include <memory>

namespace ProjectAlpha{

    template<class T>
    class Heaptreenode : public std::enable_shared_from_this<Heaptreenode <T> >{
    public:

        Heaptreenode(T data, int prioritaet);

        T get_data();

        void set_left_child(T data, int prioritaet);

        void set_right_child(T data, int prioritaet);

        std::shared_ptr<Heaptreenode <T> > get_left_child();
        
        std::shared_ptr<Heaptreenode <T> > get_right_child();

        void remove_left_child();

        void remove_right_child();

    private:

        T data_;

        int prioritaet_;


    };
}






#endif