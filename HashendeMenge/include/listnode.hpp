#pragma once
#include <memory>


namespace ProjectAlpha{

    template<class T>
    class listnode{
        public:
            explicit listnode(T data);

        public:
            std::shared_ptr<listnode <T> > next;

            T data_;

    };

    typedef std::shared_ptr<listnode<class T> > ListNodeptr;
}