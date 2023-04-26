#pragma once
#include <memory>


namespace ProjectAlpha{

    template<class T>
    class listnode{
        public:
            listnode(T data);

        public:
            std::shared_ptr<listnode> next;

            T data_;

    };

    typedef std::shared_ptr<listnode<class T>> ListNodeptr;
}