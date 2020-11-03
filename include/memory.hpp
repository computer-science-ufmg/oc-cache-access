#ifndef MEMORY_H
#define MEMORY_H

#include<string>
#include<map>
#include<vector>
class Memory{
    private:
        std::map<int, std::string> data;
    public:
        Memory();
        void write(int address, std::string b);
        void write_block(int address, std::vector<std::string> b);
		std::string get_word(int address);
        std::vector<std::string> get_block(int address);
};

#endif