#include <functional>
#include <iostream>
#include <string>
#include "../include/hashendeMengerealisation.hpp"

namespace ProjectAlpha{

     template<class T>
     hashendeMengerealisation<T>::hashendeMengerealisation():  
          hashfkt(std::hash<T>()),
          num_buckets(32)
     {
          buckets = std::vector<List>(num_buckets);
     }

     template<class T>
     void hashendeMengerealisation<T>::insert(const T x){
          if(find(x)){
               std::cout << "Das Element existiert bereits!" << std::endl;
               return;
          }
          double s = size();
          double a = num_buckets;

          if((s/a)<0.75){
               buckets[hashfkt(x) % num_buckets].insert_front(x);
          }
          else {
               belegungsfaktor(x);
               insert(x);
          }
          
     }

     template<class T>
     void hashendeMengerealisation<T>::remove(const T& x){
          if(not find(x)){
               std::cout << "Das Element konnte nicht gefunden werden!" << std::endl;
               return;
          }
          double s = size();
          double a = num_buckets;
          if((s/a) > 0.25){
               int element = hashfkt(x) % num_buckets;
               ListNodeptr aktuell = buckets[element].get_head();
               if(aktuell -> data_ == x){
                    buckets[element].remove_front();
               }
               ListNodeptr hilfe = aktuell;
               while(aktuell != nullptr){
                    if(aktuell -> data_ = x){
                         buckets[element].remove_after(hilfe);
                         break;
                    }
                    hilfe = aktuell;
                    aktuell = aktuell -> next;
               }
          }
          else{
               belegungsfaktor(x);
               remove(x);
          }
     }

     template<class T>
     void hashendeMengerealisation<T>::belegungsfaktor(){
          double = size();
          double a = num_buckets;
          std::vector<T> zwischenspeicher;
          for(int i = 0; i < num_buckets; i++){
               ListNodeptr current = buckets[i].get_head();
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
          buckets = std::vector<List>(num_buckets);

          for(const T &wort : zwischenspeicher){
               insert(wort);
          }

     }

     template<class T>
     void hashendeMengerealisation<T>::print() const{
          for(int i = 0; i < num_buckets, i++){
               buckets[i].print();
          }
          std::cout << "Hashtabelle gedruckt" << std::endl;
     }

     template<class T>
     size_t hashendeMengerealisation<T>::size() const{
          int j = 0;
          for(int i = 0; i < num_buckets; i++){
               ListNodeptr current = buckets[i].get_head();
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
          ListNodeptr current = buckets[Element].get_head();
          while(current != nullptr){
               if(current -> data_ == x){
                    return true;
               }
               else{
                    current = current -> next;
               }
          }
          return falsee;
     }


//Hier Implementierung der Funktionen fortsetzen.
}