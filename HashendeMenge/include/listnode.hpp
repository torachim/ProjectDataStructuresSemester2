#pragma once
#include <memory>
#include <iostream>


namespace ProjectAlpha{

template<class T>
class listnode{
public:
    listnode(T data);
    
    std::shared_ptr<listnode<T>> next;

    T data_;

};

    typedef std::shared_ptr<listnode<class T>> ListNodeptr;
}