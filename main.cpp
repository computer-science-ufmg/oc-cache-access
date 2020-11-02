#include"include/cache.hpp"
#include"include/memory.hpp"
#include"include/cpu.hpp"

#include<iostream>

int main(int agrc, char const *argv[]){

    std::cout << Cpu::b_to_int("10001110") << std::endl;
    std::cout << Cpu::int_to_b(255, 1) << std::endl;
    return 0;
}