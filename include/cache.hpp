#ifndef CACHE_H
#define CACHE_H

#define CACHE_SIZE 64

#include"cache_block.hpp"
#include"memory.hpp"

class Cache{
    private:
        CacheBlock blocks[CACHE_SIZE];
        Memory mem;

    public:
        Cache();
        ~Cache();
        bool hit(int address);
        static int get_index(int address);
        static int get_offset(int address);
        static int get_tag(int address);
        void write(int address, std::string data);
        void modify(int address, std::string data);
        void replace(int address, std::vector<std::string> data);
        bool search(int address);
};

#endif