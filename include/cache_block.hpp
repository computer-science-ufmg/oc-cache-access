#ifndef CACHE_BLOCK_H
#define CACHE_BLOCK_H

#define BLOCK_SIZE 4

#include<string>
#include<vector>

class CacheBlock{
  private:
    bool dirty = false;
    bool valid = false;
    int tag;
    std::string data[BLOCK_SIZE];

  public:
    bool is_dirty();
    void set_dirty(bool dirty);
    bool is_valid();
    void set_valid(bool valid);
    int get_tag();
    void set_tag(int tag);
    std::string get_data(int offset);
    void set_data(std::string data, int offser);
    std::vector<std::string> to_vector();

};

#endif