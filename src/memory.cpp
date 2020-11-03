#include"../include/memory.hpp"
#include"../include/cpu.hpp"
#include<iostream>
#include<vector>
#include<map>

Memory::Memory(){
	int size = 1024;
	for(int i = 0; i < size; i++){
		this->data[i] = Cpu::int_to_b(0);
	}
}

void Memory::write(int address, std::string b){
	this->data[address] = b;
}

void Memory::write_block(int address, std::vector<std::string> b){
	int start = address - (address % 4);
	std::vector<std::string> block;
	for(int i = 0; i < 4; i++){
		this->write(start + i, b[i]);
	}
}

std::string Memory::get_word(int address){
	return this->data.find(address)->second;
}

std::vector<std::string> Memory::get_block(int address){
	int start = address - (address % 4);
	std::vector<std::string> block;
	for(int i = 0; i < 4; i++){
		block.push_back(this->get_word(start + i));
	}
	std::cout << "BLOCK SIZE ON GETBLOCK: " << block.size() << std::endl;
	return block;
}

