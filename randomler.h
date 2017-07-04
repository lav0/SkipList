#pragma once

#include <random>
#include <chrono>
#include <iostream>
#include <fstream>

namespace sl
{
    template<typename T>
    class randomler
    {
        std::ofstream file;
    public:

        randomler()
        {
#ifdef  _DEBUG
        
                file.open("random.log");
#endif           
        }
        ~randomler()
        {
#ifdef  _DEBUG
            
                file.close();
#endif
        }
            
        bool yes_or_no()
        {
            std::default_random_engine rand_engine;
            rand_engine.seed(
                static_cast<unsigned long>(
                    std::chrono::high_resolution_clock::now().time_since_epoch().count()
                    )
            );

            std::uniform_int_distribution<T> distributor(0, 1);

            auto val = distributor(rand_engine);
            bool res = val % 2 == 1;

#ifdef  _DEBUG
            {
                file << (res ? '1' : '0');
                file << '\n';
            }
#endif

            return res;
        }
    };
}


