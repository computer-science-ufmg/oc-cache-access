#ifndef CPU_H
#define CPU_H

#define ADDRESS_SIZE 32

#include"cache.hpp"
#include"memory.hpp"

#include<string>
#include<fstream>
#include<vector>

class Cpu{
    private:
        std::ifstream input;
        std::ofstream output;
        Cache *cache = nullptr;
        int reads = 0;
        int writes = 0;
        int hits = 0;
        int misses = 0;
        std::vector<std::string> logs;

    public:
        Cpu(char const *input_file);
        ~Cpu();
        static std::string int_to_b(int v);
        static int b_to_int(std::string b);
        void run();
        void print_outputs();
};

#endif