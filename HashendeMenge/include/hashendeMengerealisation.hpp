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

            void insert(T x)override;

            bool find(const T& x)override;

            void remove(const T& x)override;

            void belegungsfaktor()override;

            void print() const;

            size_t size() const; 


        private:

            const std::function<size_t(const std::string &)> hashfkt;

            size_t num_buckets;

            std::vector<List> buckets;  

    };

    


