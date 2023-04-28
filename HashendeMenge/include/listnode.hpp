#ifndef LISTNODE
#define LISTNODE
#include <memory>
#include <iostream>


namespace ProjectAlpha{

template<class T>
class listnode{
public:
    explicit listnode(T data);                  //Konstruktor eines Knoten
    
    std::shared_ptr<listnode<T> > next;         //Nachbarknoten des erstellten Knoten

    T data_;                                    //Daten welche in dem Knoten gespeichert werden

};

    
}

#endif