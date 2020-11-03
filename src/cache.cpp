#include"../include/cache.hpp"
#include"../include/cpu.hpp"

#include<vector>
#include<iostream>

Cache::Cache(){

}

Cache::~Cache(){

}


bool Cache::hit(int address){
  int index = Cache::get_index(address);
  // std::cout << std::endl << "Acessando endereco ============ " << address << std::endl;
  // std::cout << "Endereco: " << Cpu::int_to_b(address) << std::endl;
  // std::cout << "Index: " << index << std::endl;
  // std::cout << "Tag: " << Cache::get_tag(address) << std::endl;
  // std::cout << "Offset: " << Cache::get_offset(address) << std::endl;
  // std::cout << "CACHE ========================= " << address << std::endl;
  // std::cout << "Tag: " << this->blocks[index].get_tag() << std::endl;
  return (this->blocks[index].is_valid() && (Cache::get_tag(address) == this->blocks[index].get_tag()));
}

int Cache::get_offset(int address){
  std::string address_str = Cpu::int_to_b(address);
  return Cpu::b_to_int(address_str.substr(address_str.size()-2, 2));
}

int Cache::get_index(int address){
  std::string address_str = Cpu::int_to_b(address);
  return Cpu::b_to_int(address_str.substr(address_str.size()-8, 6));
}

int Cache::get_tag(int address){
  std::string address_str = Cpu::int_to_b(address);
  return Cpu::b_to_int(address_str.substr(0, 24));
}

void Cache::write(int address, std::string data){
  if(this->hit(address)){
    this->modify(address, data);
  }
  else{
    int offset = Cache::get_offset(address);
    std::vector<std::string> data_block = this->mem.get_block(address);
    data_block.at(offset) = data;
    this->replace(address, data_block);
  }
}

void Cache::modify(int address, std::string data){
  int index = Cache::get_index(address);
  int offset = Cache::get_offset(address);
  this->blocks[index].set_dirty(true);
  this->blocks[index].set_data(data, offset);
}

void Cache::replace(int address, std::vector<std::string> data){
  int index = this->get_index(address);
  if(this->blocks[index].is_valid() && this->blocks[index].is_dirty()){
    // Write old data back from cache to memory
    std::vector<std::string> data_block = this->blocks[index].to_vector();
    this->mem.write_block(address, data_block);
  }
  // Replacing data in cache
  this->blocks[index].set_tag(this->get_tag(address));
  this->blocks[index].set_valid(true);
  this->blocks[index].set_dirty(false);
  for(int i = 0; i < 4; i++){
    this->blocks[index].set_data(data[i], i);
  }
}

bool Cache::search(int address){
  if(hit(address)){
    return true;
  } else{
    std::vector<std::string> new_data = this->mem.get_block(address);
    replace(address, new_data);
    return false;
  }
}