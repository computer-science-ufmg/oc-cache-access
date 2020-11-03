#include"../include/cache_block.hpp"

#include<vector>
#include<string>

bool CacheBlock::is_dirty(){
  return this->dirty;
}

void CacheBlock::set_dirty(bool dirty){
  this->dirty = dirty;
}

bool CacheBlock::is_valid(){
  return this->valid;
}

void CacheBlock::set_valid(bool valid){
  this->valid = valid;
}

int CacheBlock::get_tag(){
  return this->tag;
}

void CacheBlock::set_tag(int tag){
  this->tag = tag;
}

std::string CacheBlock::get_data(int offset){
  return this->data[offset];
}

void CacheBlock::set_data(std::string data, int offset){
  this->data[offset] = data;
}

std::vector<std::string> CacheBlock::to_vector(){
  std::vector<std::string> data_block(BLOCK_SIZE);
  for(int i = 0; i < BLOCK_SIZE; i++){
    data_block[i] = this->data[i];
  }
  return data_block;
}