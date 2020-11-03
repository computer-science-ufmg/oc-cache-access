#include"include/cache.hpp"
#include"include/memory.hpp"
#include"include/cpu.hpp"

#include<iostream>

int main(int argc, char const *argv[]){

    if(argc > 1){
        Cpu *cpu = new Cpu(argv[1]);
        cpu->run();
        cpu->print_outputs();
        delete cpu;
    }
    else{
        std::cout << "Provide an input file..." << std::endl;
    }

    return 0;
}