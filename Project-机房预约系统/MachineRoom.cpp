#include "MachineRoom.h"

MachineRoom::MachineRoom(int id, int capacity) {
	this->id = id;
	this->capacity = capacity;
}
// ��ȡ�������
int MachineRoom::getId() {
	return this->id;
}

// ��ȡ�����������
int MachineRoom::getCapacity() {
	return this->capacity;
}