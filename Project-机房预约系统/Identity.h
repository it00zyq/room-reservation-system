#pragma once
#include<iostream>
#include<string>

using namespace std;


class Identity {
public:
	string name;
	string password;

	// 显示身份菜单
	virtual void operatorMenu() = 0;
};