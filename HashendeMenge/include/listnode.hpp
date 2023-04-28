#ifndef LISTNODE
#define LISTNODE
#include <memory>
#include <iostream>


namespace ProjectAlpha{

template<class T>
class listnode{
public:
    explicit listnode(T data);
    
    std::shared_ptr<listnode<T> > next;

    T data_;

};

    
}

#endif