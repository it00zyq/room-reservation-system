#pragma once
#include<iostream>
#include<string>

using namespace std;


class Identity {
public:
	string name;
	string password;

	// ��ʾ��ݲ˵�
	virtual void operatorMenu() = 0;
};