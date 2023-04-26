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
     void hashendeMengerealisation<T>::belegungsfaktor


//Hier Implementierung der Funktionen fortsetzen.
}