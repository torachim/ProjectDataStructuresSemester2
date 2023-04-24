#include <iostream>

namespace ProjectAlpha
{
    template <class T>
    class hashendemenge
    {
    public:
        hashendemenge() = 0;
        virtual void insert(T) = 0;
        virtual bool find(T) = 0;
        virtual void remove(T) = 0;
        virtual void belegungsfaktor(T) = 0;
    };

}