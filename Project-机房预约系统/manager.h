#pragma once
#include<iostream>
#include<string>
#include<set>
#include "Identity.h"
#include "student.h"
#include "teacher.h"
using namespace std;

class Manager : public Identity {
public:
	set<int> stuSet;
	set<int> teaSet;


	Manager(string name, string password);

	// ����˺�
	void addAccount();

	// �鿴�˺�
	void showAccount();

	// �鿴������Ϣ
	void showMachineRoom();

	// ���ԤԼ��Ϣ
	void clearAppointment();

	// ��ʾ��ݲ˵�
	virtual void operatorMenu();

	// ��ʼ��ѧ���˺�����
	void initStuSet();

	// ��ʼ����ʦ�˺�����
	void initTeaSet();

};

