#pragma once
#include <memory>
#include "listnode.hpp"

namespace ProjectAlpha{

    template<class T>
    class List{
    public:

        List();

        ListNodeptr insert_front(T x);
        ListNodeptr insert_after(const ListNodeptr&, T x);
        ListNodeptr remove_front();
        ListNodeptr remove_after(const ListNodeptr&);

        ListNodeptr next(const ListNodeptr&);

        void print() const;

    private:
        ListNodeptr head;
    };
}