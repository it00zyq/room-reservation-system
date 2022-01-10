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
	// 申请预约
	void applyAppointment();
	// 查看我的预约
	void showMyAppointment();
	// 查看所有预约
	void showAllAppointment();
	// 取消预约
	void cancelAppointment();

	// 初始化
	void initRoomSet();

	// 显示身份菜单
	virtual void operatorMenu();

};
