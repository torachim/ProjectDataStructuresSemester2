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
          else{                                                 //Ist s/a kleiner als 0.25
               belegungsfaktor();                               //Rufe Belegungsfaktor auf und halbiere die Anzahl an Buckets
               remove(x);                                       //Entferne das Element
          }
     }

     template<class T>
     void hashendeMengerealisation<T>::belegungsfaktor(){       //Belegungsfaktorfunktion
          double s = size();                                    //s wird auf die anzahl an Elementen gestzt
          double a = num_buckets;                               // a auf die Anzahl an Buckets
          std::vector <T> zwischenspeicher;
          for(int i = 0; i < num_buckets; i++){
               std::shared_ptr<listnode <T> > current = buckets[i].get_head();
               while(current != nullptr){
                    zwischenspeicher.push_back(current -> data_);
                    current = current -> next;
               }
          }
          if((s/a) >= 0.75){
               num_buckets = num_buckets * 2;
          }
          else{
               num_buckets = num_buckets * 0.5;
          }
          buckets = std::vector<List <T> >(num_buckets);

          for(const T &wort : zwischenspeicher){
               insert(wort);
          }

     }

     template<class T>
     void hashendeMengerealisation<T>::print() const{
          for(int i = 0; i < num_buckets; i++){
               buckets[i].print();
          }
          std::cout << "Hashtabelle gedruckt" << std::endl;
     }

     template<class T>
     size_t hashendeMengerealisation<T>::size() const{
          int j = 0;
          for(int i = 0; i < num_buckets; i++){
               std::shared_ptr<listnode <T> > current = buckets[i].get_head();
               while(current != nullptr){
                    j = j + 1;
                    current = current -> next;
               }
          }
          return j;
     }

     template<class T>
     bool hashendeMengerealisation<T>::find(const T& x)const{
          int Element = hashfkt(x) % num_buckets;
          std::shared_ptr<listnode <T> > current = buckets[Element].get_head();
          while(current != nullptr){
               if(current -> data_ == x){
                    return true;
               }
               else{
                    current = current -> next;
               }
          }
          return false;
     }



     template<class T>
     List<T>::List(){
          head = nullptr;
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::get_head() const{
          return head;
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::insert_front(T x){
          std::shared_ptr<listnode <T> > n = std::make_shared<listnode <T> >(x);
          if(head){
               n -> next = head;
               head = n;
          }
          head = n;
          return n;
     }

     template<class T>
     void List<T>::print() const{
          std::shared_ptr<listnode <T> > current = head;
          while(current){
               std::cout << current -> data_ << "->";
               current = current -> next;
          }
          std::cout << "null" << std::endl;
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::remove_front(){
          if(not head){
               return nullptr;
          }
          std::shared_ptr<listnode <T> > neuerHead = head -> next;
          head = neuerHead;
          return neuerHead;
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::next(const std::shared_ptr<listnode <T> >& vorhaerigerknoten){
          return vorhaerigerknoten -> next;
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::insert_after(const std::shared_ptr<listnode <T> >& vorhaerigerknoten, T x){
          std::shared_ptr<listnode <T> > neuerNaechsterKnoten = std::make_shared<listnode <T> >(x);
          neuerNaechsterKnoten -> next = vorhaerigerknoten -> next;
          vorhaerigerknoten -> next = neuerNaechsterKnoten;
          return neuerNaechsterKnoten;
     }

     template<class T>
     std::shared_ptr<listnode <T> > List<T>::remove_after(const std::shared_ptr<listnode <T> >& vorhaerigerknoten){
         std::shared_ptr<listnode <T> > loeschenKnoten = vorhaerigerknoten -> next;
         vorhaerigerknoten -> next = loeschenKnoten -> next;
         return vorhaerigerknoten -> next;
     }

    


