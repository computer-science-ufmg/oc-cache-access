#ifndef CPU_H
#define CPU_H

#include<string>

class Cpu{
    private:
    public:
        static std::string int_to_b(int v, int size);
        static int b_to_int(std::string b);
};

#endif