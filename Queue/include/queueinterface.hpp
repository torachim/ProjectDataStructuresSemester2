#pragma once
#include <iostream>

namespace ProjectAlpha {

    template <class T>

    class queueinterface{

        public:
            virtual void enqueue(T) =0;  //insert_end    / fügt Element des Typen T am Ende der Liste ein
            virtual T dequeue() =0;    //remove_front    / entfernt das erste Element der Queue
            virtual int size() =0;     //gibt Größe der Queue wieder

    } ;
}