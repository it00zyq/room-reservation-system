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
// ��ʼ��ԤԼ��Ϣ
void intitVector();
// �޸�ԤԼ״̬
void modifyVector(int index, string status);

class SystemManager {
public:
	Identity *person;
	
	SystemManager();

	~SystemManager();

	// ���˵�
	void showMenuMain();

	// ����¼��Ϣ
	void checkInfo(int identity);

};