#include"../include/cpu.hpp"
#include<cmath>
#include<sstream>
#include<iostream>

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

std::string Cpu::int_to_b(int v, int size){
    std::stringstream ss;
    std::string binary;
    
    while(v > 0){
        char bit = char(v % 2)+'0';
        ss << bit;
        v = std::floor(v/2);
    }
    binary = ss.str();
    std::reverse(binary.begin(), binary.end());
    return binary;
}