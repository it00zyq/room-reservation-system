#pragma once
#include<iostream>
#include<string>
using namespace std;

class MachineRoom {
public:
	MachineRoom(int id, int capacity);
	// ��ȡ�������
	int getId();
	// ��ȡ�����������
	int getCapacity();

private:
	int id;
	int capacity;

};