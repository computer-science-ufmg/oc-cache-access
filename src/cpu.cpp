#include"../include/cpu.hpp"
#include<cmath>
#include<sstream>
#include<iostream>

#define OUTPUT_PATH "result.txt"

Cpu::Cpu(char const *input_file){
  this->input.open(input_file);
  this->output.open(OUTPUT_PATH);
  this->cache = new Cache();
}

Cpu::~Cpu(){
  this->input.close();
  this->output.close();
  delete this->cache;
}

int Cpu::b_to_int(std::string b){
  int num = 0;
  int baseDigit = 1;
  int i;
  for(i = b.size() - 1; i >= 0; i--){
    num += int(b[i] - 48) * baseDigit;
    baseDigit *= 2;
  }
  return num;
}

std::string Cpu::int_to_b(int v){
  std::stringstream ss;
  std::string binary;
  int size = ADDRESS_SIZE;

  while(v > 0){
    char bit = char(v % 2)+'0';
    ss << bit;
    v = std::floor(v/2);
    size--;
  }
  while(size > 0 ){
    ss << '0';
    size--;
  }

  binary = ss.str();
  std::reverse(binary.begin(), binary.end());
  return binary;
}

void Cpu::run(){
  while(!input.eof()){
    std::stringstream ss("");
    int address;
    bool write;
    input >> address >> write;

    if(write){
      this->writes++;

      std::string data;
      input >> data;

      this->cache->write(address, data);
      ss << address << ' ' << 1 << ' ' << data << " W" << std::endl;
    }
    else{
      this->reads++;

      bool hit = this->cache->search(address);
      ss << address << ' ' << 0 << ' ' << (hit ? " H" : " M") << std::endl;

      if(hit){
        this->hits++;
      }
      else{
        this->misses++;
      }
    }
    this->logs.push_back(ss.str());
  }
}

void Cpu::print_outputs(){
  float hit_rate = ((float)hits)/((float)(hits+misses));
  float miss_rate = ((float)misses)/((float)(hits+misses));

  output << "READS: " << reads << std::endl;
  output << "WRITES: " << writes << std::endl;
  output << "HITS: " << hits << std::endl;
  output << "MISSES: " << misses << std::endl;
  output << "HIT RATE: " << hit_rate << std::endl;
  output << "MISS RATE: " << miss_rate << std::endl;

  for(std::vector<std::string>::iterator it = logs.begin(); it != logs.end(); ++it){
    output << *it;
  }
}