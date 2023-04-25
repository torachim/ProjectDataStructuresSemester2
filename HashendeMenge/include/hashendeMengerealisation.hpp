#pragma once
#include <iostream>
#include "hashendemenge.hpp"
#include "list.hpp"
#include <memory>
#include <string>
#include <cstddef>
#include <functional>

using namespace ProjectAlpha;

    class hashendeMengerealisation : public hashendemenge<std::string>
    {
        public:

            hashendeMengerealisation();

            void insert(const std::string x);

            bool find(const std::string& x);

            void remove(const std::string& x);

            void print() const;

            size_t size() const; 


        private:

            const std::function<size_t(const std::string &)> hashfkt;

            size_t num_buckets;

            std::vector<List> buckets;  

    };

    


