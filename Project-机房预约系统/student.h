#pragma once
#include<iostream>
#include<string>
#include<set>
#include "Identity.h"
#include "appointment.h"
#include "SystemManager.h"
using namespace std;

class Student : public Identity {
public:
	int id;
	set<int> roomSet;

	Student(int id, string name, string password);
	// ����ԤԼ
	void applyAppointment();
	// �鿴�ҵ�ԤԼ
	void showMyAppointment();
	// �鿴����ԤԼ
	void showAllAppointment();
	// ȡ��ԤԼ
	void cancelAppointment();

	// ��ʼ��
	void initRoomSet();

	// ��ʾ��ݲ˵�
	virtual void operatorMenu();

};
