#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include "Identity.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"
#define STUDENT_FILE "student.txt"
#define TEACHER_FILE "teacher.txt"
#define MANAGER_FILE "manager.txt"
#define ROOM "machineRoom.txt"
#define APPOINTMENT "appointment.txt"
using namespace std;

extern vector<Appointment> apponitmentVector;
// 初始化预约信息
void intitVector();
// 修改预约状态
void modifyVector(int index, string status);

class SystemManager {
public:
	Identity *person;
	
	SystemManager();

	~SystemManager();

	// 主菜单
	void showMenuMain();

	// 检查登录信息
	void checkInfo(int identity);

};