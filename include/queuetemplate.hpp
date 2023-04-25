#pragma once

namespace ProjectAlpha {

    template <class T>

    class queuetemplate{

        public:
            virtual void enqueue(T) =0;  //insert_back
            virtual auto dequeue() =0;   //remove_front
            virtual int size() =0;

    } ;
}

