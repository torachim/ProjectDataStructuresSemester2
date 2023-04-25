#include <iostream>
#include "hashendemenge.hpp"
#include <memory>
#include <string>
#include <functional>
#include <cstddef>


using namespace ProjectAlpha;

    class hashendemengerela : public hashendemenge<std::string>{
        public:
            hashendemengerela();

            void insert(const std::string x);

            bool find(const std::string& x) const;

            void remove(const std::string& x);

            void print() const;

            size_t size() const; 


        private:

            const std::function<size_t(const std::string&)> hashfkt;

            size_t num_buckets;

            std::vector<List> buckets;  

    };

    


