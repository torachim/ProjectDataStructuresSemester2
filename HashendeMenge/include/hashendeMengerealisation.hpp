#pragma once
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

            hashendeMengerealisation();

            void insert(const T x);

            bool find(const T& x)const;

            void remove(const T& x);

            void print() const;

            size_t size() const; 



        private:

            const std::function<size_t(const T &)> hashfkt;

            size_t num_buckets;

            std::vector<List <T> > buckets;  

            void belegungsfaktor();

    };

    


