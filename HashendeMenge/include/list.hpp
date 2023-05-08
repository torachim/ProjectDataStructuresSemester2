#ifndef LIST 
#define LIST
#include <memory>
#include <iostream>
#include "listnode.hpp"

namespace ProjectAlpha{

    template<class T>
    class List{
    public:

        List();    //Konstruktor einer Liste

        std::shared_ptr<listnode <T> > insert_front(T x);                                           //Funktion die einen Knoten vorne in der Liste einfuegt
        std::shared_ptr<listnode <T> > insert_after(const std::shared_ptr<listnode <T> >&, T x);    //Funktion welche einen Knoten hinter einen anderen einfuegt
        std::shared_ptr<listnode <T> > remove_front();                                              //Funktion welche das vordere Element einer Liste entfernt
        std::shared_ptr<listnode <T> > remove_after(const std::shared_ptr<listnode<T> >&);          //Funktion welche einen Knoten hinter einem gegebenen entfernt
        std::shared_ptr<listnode <T> > get_head()const;                                             //Funktion welche den Head sprich das vorderste Element einer Liste zurueckgibt

        std::shared_ptr<listnode <T> > next(const std::shared_ptr<listnode <T> >&);                 //Funktion welche den nächsten Knoten eines gegeben Knoten zurueck gibt

        void print() const;                                                                         //Funktion welche die Liste druckt

    private:
        std::shared_ptr<listnode <T> > head;                                                        //Der Kopf sprich das vorderste Element der Liste
    };
}

#endif