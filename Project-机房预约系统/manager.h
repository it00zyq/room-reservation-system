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

	// 添加账号
	void addAccount();

	// 查看账号
	void showAccount();

	// 查看机房信息
	void showMachineRoom();

	// 清空预约信息
	void clearAppointment();

	// 显示身份菜单
	virtual void operatorMenu();

	// 初始化学生账号容器
	void initStuSet();

	// 初始化教师账号容器
	void initTeaSet();

};

