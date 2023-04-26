#include <iostream>
#include "hashendemenge.hpp"
#include "list.hpp"
#include <memory>
#include <string>
#include <cstddef>
#include <functional>
#include <vector>

using namespace ProjectAlpha;

    class hashendeMengerealisation : public abstract_hashendemenge<class T>
    {
        public:

            hashendeMengerealisation();

            void insert(const T x);

            bool find(const T x);

            void remove(const T x);

            void print() const;

            size_t size() const; 


        private:

            const std::function<size_t(const std::string &)> hashfkt;

            size_t num_buckets;

            std::vector<List> buckets;  

    };

    


