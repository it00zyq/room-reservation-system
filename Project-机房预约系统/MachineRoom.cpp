#include "MachineRoom.h"

MachineRoom::MachineRoom(int id, int capacity) {
	this->id = id;
	this->capacity = capacity;
}
// 获取机房编号
int MachineRoom::getId() {
	return this->id;
}

// 获取机房最大容量
int MachineRoom::getCapacity() {
	return this->capacity;
}