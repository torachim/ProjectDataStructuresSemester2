#ifndef HASHENDE_M
#define HASHENDE_M
#include <iostream>
#include "hashendemenge.hpp"
#include "list.hpp"
#include <memory>
#include <string>
#include <cstddef>
#include <functional>
#include <vector>

using namespace ProjectAlpha;

    template<class T>
    class hashendeMengerealisation : public abstract_hashendemenge<T>
    {
        public:

            hashendeMengerealisation();             //Konstruktor einer Hashtabelle

            void insert(const T x);                 //Siehe Interface abstract_hashendemenge<T>

            bool find(const T& x)const;             //Siehe Interface abstract_hashendemenge<T>

            void remove(const T& x);                //Siehe Interface abstract_hashendemenge<T>

            void print() const;                     //Druckt die Hashtabelle

            size_t size() const;                    //Gibt die Anzahl an Elementen der Hashtabelle zurueck



        private:

            const std::function<size_t(const T &)> hashfkt;     //Hashfunktion welche jeder Information eine Zahl zuordnent durch Zahl % num_buckets lässt dich das Bucket dieser Information zuordnen

            size_t num_buckets;                                 //Anzahl an Buckets dieser Hashtabelle

            std::vector<List <T> > buckets;                     //Ein Vektor welcher die einzelnen Buckets enthällt welche durch Listen realiesiert werden 

            void belegungsfaktor();                             //Eine Funktion welche abhängig vom Fall die Anzahl an Buckets verdoppelt oder halbiert

    };

#endif


     template<class T>
     hashendeMengerealisation<T>::hashendeMengerealisation():   //Konstruktor der Hashtabelle
          hashfkt(std::hash<T>()),                              //Hashfunktion
          num_buckets(32)                                       //Anzahl an Buckets wird auf 32 festgelegt
     {
          buckets = std::vector<List <T> >(num_buckets);        //Der Vektor mit der passenden Anzahl an Buckets wird erstellt
     }

     template<class T>
     listnode<T>::listnode(T data){                             //Konstruktor eines Listenknoten
          data_ = data;                                         //data_ wird auf die übergegebene Daten gesetzt
          next = nullptr;                                       //Der Pfeil der auf das naechste Element zeigt zeigt ins nichts
     }

     template<class T>
     void hashendeMengerealisation<T>::insert(const T x){       //Funktion die ein Element in die Hashtabelle einfuegt
          if(find(x)){                                          //Wenn das Element bereits in der Hashtabelle existiert, dann ...
            throw std::logic_error("Ein Element welches der Liste hinzugefuegt werden soll existiert bereits");     //Fehlermeldung wird ausgegeben 
          }
          double s = size();                                    //s wird auf die Anzahl der Elemente in der Hashtabelle gesetzt
          double a = num_buckets;                               // a wird auf die Anzahl der Buckets gesetzt

          if((s/a)<0.75){                                       //Wenn s geteilt a kleiner als 0.75 ist, dann ...
               buckets[hashfkt(x) % num_buckets].insert_front(x);       //Element wird in sein entsprechendes Bucket eingefuegt
          }
          else {                                                //Wenn s geteilt a groeßer als 0.75 ist, dann ...
               belegungsfaktor();                               //Aufruf der Funktion belegungsfaktor um die Hashtabelle zu erweitern
               insert(x);                                       //Element wird eingefuegt
          }
          
     }

     template<class T>
     void hashendeMengerealisation<T>::remove(const T& x){      //Funktion welche ein Element aus der Hashtabelle entfernt
          if(not find(x)){                                      //Wenn das Element nicht gefunden wird, dannn...
               throw std::invalid_argument("Ein Element welches Entfernt werden sollte existiert nicht");       //Fehlermeldung wird ausgegeben
          }
          double s = size();                                    //s wird auf die Anzahl an Elementen gesetzt
          double a = num_buckets;                               //a wird auf die Anzahl an Buckets gesetzt
          if((s/a) > 0.25){                                     //Wenn s geteilt a groeßer als 0.25
               int element = hashfkt(x) % num_buckets;          //Das Bucket des zu entfernenden Elementes wird berechnen und auf element gesetzt
               std::shared_ptr<listnode <T> > aktuell = buckets[element].get_head();        //Ein Pointer zeigt auf den Kopf des Entsprechenden Buckets
               if(aktuell -> data_ == x){                       //Wenn das Head Element auf das der Pointer zeigt dem zu entfernenden Element entspricht, dann ...
                    buckets[element].remove_front();            //Dann entferne den Kopf des Buckets
               }
               else{
                    std::shared_ptr<listnode <T> > hilfe = aktuell;  //Hilfspointer
                    while(aktuell != nullptr){                       //Solange der Pointer aktuell noch auf ein Listenelement zeigt
                         if(aktuell -> data_ == x){                  //Überpruefe ob das Element auf welches der Pointer zeigt dem zu entfernenden Element entspricht
                              buckets[element].remove_after(hilfe);  //Enferne das Element hinter dem Hilfspointer
                              break;                                 //Breche die Funktion ab
                         }
                         hilfe = aktuell;                            //Wurde das Element noch nicht entfernt setze Hilfe auf aktuell
                         aktuell = aktuell -> next;                  //Setze Aktuell auf sein NAchfolgeknoten
                    }
               }
          }
          else{                                                 //Ist s/a kleiner als 0.25
               belegungsfaktor();                               //Rufe Belegungsfaktor auf und halbiere die Anzahl an Buckets
               remove(x);                                       //Entferne das Element
          }
     }

     template<class T>
     void hashendeMengerealisation<T>::belegungsfaktor(){       //Belegungsfaktorfunktion
          double s = size();                                    //s wird auf die anzahl an Elementen gestzt
          double a = num_buckets;                               // a auf die Anzahl an Buckets gestzt
          std::vector <T> zwischenspeicher;                     //Vektor Zwischenspeicher wird erstellt
          for(int i = 0; i < num_buckets; i++){                 //for Schleife welche durch die Tabelle durch itteriert 
               std::shared_ptr<listnode <T> > current = buckets[i].get_head();       //shared Pointer welcher auf das erste Element des entsprechenden Buckets zeigt
               while(current != nullptr){                       //Solange der Pointer nicht ins nichts zeigt
                    zwischenspeicher.push_back(current -> data_);          //Das Element auf welches der Pointer zeigt wird in den Zwischenspeicher eingefuegt und aus dem Bucket entfernt
                    current = current -> next;                  //Der Pointer wecheselt auf das naechste Element 
               }
          }
          if((s/a) >= 0.75){                                    //Wenn s geteilt a groeßer gleich 0.75 ist, dann
               num_buckets = num_buckets * 2;                   //Bucket Anzahl wird verdoppelt
          }
          else{                                                 //Wenn s geteilt a kleiner als 0.25 ist, dann
               num_buckets = num_buckets * 0.5;                 //Buckets Anzahl wird verdoppelt
          }
          buckets = std::vector<List <T> >(num_buckets);        //Hashtabelle wird neu gebaut

          for(const T &wort : zwischenspeicher){                //range-based for loop um die Woerter wieder in die Hashtabelle einzufuegen
               insert(wort);                                  //Woerter werden eingefuegt
          }

     }

     template<class T>
     void hashendeMengerealisation<T>::print() const{           //Print Funktion welche die Hashtabelle druckt
          for(int i = 0; i < num_buckets; i++){                 //for Schleife welche durch die buckets itteriert
               buckets[i].print();                              //Drucke Funktion der einzelnen Listen wird aufgerufen
          }
          std::cout << "Hashtabelle gedruckt" << std::endl;
     }

     template<class T>
     size_t hashendeMengerealisation<T>::size() const{          //Funktion welche die Anzahl an Elementen der Hashtabelle zurueckgibt
          int j = 0;                                            //Zählvariable j
          for(int i = 0; i < num_buckets; i++){                 //for Schleife um durch die BUckets durch zu itterieren
               std::shared_ptr<listnode <T> > current = buckets[i].get_head();       //shared Pointer welcher auf den head des Buckets zeigt
               while(current != nullptr){                       //Solange der Pointer nicht ins nichts zeigt, dann...
                    j = j + 1;                                  //Zählvariable + 1 da Element gefunden
                    current = current -> next;                  //Zeiger zeigt auf Naechtses Element des Buckets 
               }
          }
          return j;                                             //Zaehlvariable wird zurueckgegeben
     }

     template<class T>
     bool hashendeMengerealisation<T>::find(const T& x)const{         //Funktion welche ueberprueft ob ein Element in der Hashtabelle enthalten ist
          int Element = hashfkt(x) % num_buckets;                     //Das Bucket des potentiellen Elements wird berechnet
          std::shared_ptr<listnode <T> > current = buckets[Element].get_head();           //Shared Pointer welcher auf den Kopf des entsprechenden Buckets zeigt
          while(current != nullptr){                                  //Solange der Pointer nicht ins nichts zeigt...
               if(current -> data_ == x){                             //Wenn die data an der Stelle des zu suchendem Objekts entspricht, dann...
                    return true;                                      //Gebe true zurueck, da Objekt gefunden
               }
               else{                                                  //Wenn die data nicht dem zu suchenden Objekt entspricht, dann
                    current = current -> next;                        //Wechsle auf das naechste Objekt
               }
          }
          return false;                                               //Wenn das zu suchende Objekt nicht gefunden wird wird false zurueckgegeben
     }



     template<class T>
     List<T>::List(){                                                 //Konstruktor einer Liste
          head = nullptr;                                             //Head zeigt ins nichts
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::get_head() const{        //Funktion welche den head einer Liste zurueckgibt
          return head;                                                //Kopf wird zurueckgegebn
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::insert_front(T x){       //Funktion welche ein Element vorne in der Liste einfuegt
          std::shared_ptr<listnode <T> > n = std::make_shared<listnode <T> >(x);          //Es wird ein Pointer erzeugt welhcer auf das Objekt zeigt welches eingefuegt werden soll
          if(head){                                                   //Wenn ein head schon existiert, dann..
               n -> next = head;                                      //Wird der momentane head als nachfolger vom euen Element festgelegt
               head = n;                                              //Der head wird auf n verschoben
          }
          head = n;                                                   //Wenn kein head existiert wird einfach der head auf n gestezt
          return n;
     }

     template<class T>
     void List<T>::print() const{                                     //Funktion welche eine Liste ausdruckt
          std::shared_ptr<listnode <T> > current = head;              //Shared Pointer zeigt auf den aktuellen head
          while(current){                                             //Solange Current noch auf Elemente zeigt
               std::cout << current -> data_ << "->";                 //Drucke die aktuelle Data
               current = current -> next;                             //Wechsel auf nachfolger Element
          }
          std::cout << "null" << std::endl;                           //Null wird gedruckt sobald der pointer ins nichts zeigt
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::remove_front(){          //Element welches das erste Element einer Liste entfernt
          if(not head){                                               //Wenn kein Head existiert...
               return nullptr;                                        //Gebe den Nullpointer zurueck
          }
          std::shared_ptr<listnode <T> > neuerHead = head -> next;    //Shared pointer neuer Head zeigt auf das nachfolge Element vom head 
          head = neuerHead;                                           //head wird auf den neuen Head gesetzt
          return neuerHead;
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::next(const std::shared_ptr<listnode <T> >& vorhaerigerknoten){        //Funktion welche einen pointer auf das nachfolge Element eines Knoten zeigt
          return vorhaerigerknoten -> next;
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::insert_after(const std::shared_ptr<listnode <T> >& vorhaerigerknoten, T x){  //Funktion welche ein Element hinter ein anderes einfuegt
          std::shared_ptr<listnode <T> > neuerNaechsterKnoten = std::make_shared<listnode <T> >(x);                  //Ein shared Pointer auf das neue Element wird erzeugt
          neuerNaechsterKnoten -> next = vorhaerigerknoten -> next;                                                       //Das naechste Element des neuen Knoten wird festgelegt auf das nachfolge Element vom gegebenen Knoten
          vorhaerigerknoten -> next = neuerNaechsterKnoten;                                                               //Der gegebene Knoten bekommt den neuen Knoten als nachfolger
          return neuerNaechsterKnoten;
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::remove_after(const std::shared_ptr<listnode <T> >& vorhaerigerknoten){        //Funktion welche ein Element hinter einem anderen entfernt
         std::shared_ptr<listnode <T> > loeschenKnoten = vorhaerigerknoten -> next;                                        //Ein Pointer auf das zu loeschende Objekt wird erstellt
         vorhaerigerknoten -> next = loeschenKnoten -> next;                                                               //Der nachfolger vom zu loeschenden Knoten wird der nachfolger von seinem vorgaenger. Somit wird der zu loeschende Knoten nicht mehr verwaltet und geloescht
         return vorhaerigerknoten -> next;
     }

    


