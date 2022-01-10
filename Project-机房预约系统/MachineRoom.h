#pragma once
#include<iostream>
#include<string>
using namespace std;

class MachineRoom {
public:
	MachineRoom(int id, int capacity);
	// 获取机房编号
	int getId();
	// 获取机房最大容量
	int getCapacity();

private:
	int id;
	int capacity;

};