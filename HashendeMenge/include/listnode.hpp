#pragma once
#include <memory>


namespace ProjectAlpha{

    class listnode{
        public:
            listnode(int data);

        public:
            std::shared_ptr<listnode> next;

            int data_;

    };

    typedef std::shared_ptr<listnode> ListNodeptr;
}