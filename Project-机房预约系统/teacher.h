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

	// 查看所有预约
	void showAllAppointment();
	// 审核预约
	void auditAppointment();

	// 显示身份菜单
	virtual void operatorMenu();
};
