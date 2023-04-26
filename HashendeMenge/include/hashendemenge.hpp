#include <iostream>
#include <functional>

namespace ProjectAlpha
{
    template <class T>
    class hashendemenge
    {
    public:
        virtual void insert(T) = 0;                 //Einfuegen eines Wertes
        virtual bool find(T) = 0;                   //Kontrolle ob ein Wert bereits in der Hashtabelle enthalten ist
        virtual void remove(T) = 0;                 //Entfernt einen Wert aus der Hashtabelle
        virtual void belegungsfaktor() = 0;        //Belegungsfaktor ueberprueft ob die Hashtabelle vergroessert bzw. verkleinert werden soll
    };

}