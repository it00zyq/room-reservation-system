#pragma once
#include<iostream>
#include<string>
#include "Identity.h"
#include"SystemManager.h"
using namespace std;

class Teacher : public Identity {
public:
	int id;

	Teacher(int id, string name, string password);

	// �鿴����ԤԼ
	void showAllAppointment();
	// ���ԤԼ
	void auditAppointment();

	// ��ʾ��ݲ˵�
	virtual void operatorMenu();
};
