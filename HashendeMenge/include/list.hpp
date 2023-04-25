#pragma once
#include <memory>
#include "listnode.hpp"

namespace ProjectAlpha{

    class List{
    public:

        List();

        ListNodeptr insert_front(int x);
        ListNodeptr ibsert_after(const ListNodeptr&, int x);
        ListNodeptr remove_front();
        ListNodeptr remove_after(const ListNodeptr&);

        ListNodeptr next(const ListNodeptr&);

        void print() const;

    private:
        ListNodeptr head;
    };
}