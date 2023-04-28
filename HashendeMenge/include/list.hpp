#ifndef LIST 
#define LIST
#include <memory>
#include <iostream>
#include "listnode.hpp"

namespace ProjectAlpha{

    template<class T>
    class List{
    public:

        List();

        std::shared_ptr<listnode <T> > insert_front(T x);
        std::shared_ptr<listnode <T> > insert_after(const std::shared_ptr<listnode <T> >&, T x);
        std::shared_ptr<listnode <T> > remove_front();
        std::shared_ptr<listnode <T> > remove_after(const std::shared_ptr<listnode<T> >&);
        std::shared_ptr<listnode <T> > get_head()const;

        std::shared_ptr<listnode <T> > next(const std::shared_ptr<listnode <T> >&);

        void print() const;

    private:
        std::shared_ptr<listnode <T> > head;
    };
}

#endif