#include "teacher.h"


Teacher::Teacher(int id, string name, string password) {
	this->id = id;
	this->name = name;
	this->password = password;
	intitVector();
}

// 查看所有预约
void Teacher::showAllAppointment() {
	cout << "编号\t" << "日期\t" << "时间段\t" << "学号\t" << "姓名\t" << "机房号\t" << "状态" << endl;
	for (unsigned int i = 0; i < apponitmentVector.size(); i++) {
		cout << i + 1 << "\t"
			<< apponitmentVector[i].date << "\t"
			<< apponitmentVector[i].time << "\t"
			<< apponitmentVector[i].stuId << "\t"
			<< apponitmentVector[i].stuName << "\t"
			<< apponitmentVector[i].roomId << "\t"
			<< apponitmentVector[i].status << endl;
	}

	system("pause");
	system("cls");
}

// 审核预约
void Teacher::auditAppointment() {
	set<int> auditId; //用于记录需要审核的预约编号
	cout << "编号\t" << "日期\t" << "时间段\t" << "学号\t" << "姓名\t" << "机房号\t" << "状态" << endl;
	for (unsigned int i = 0; i < apponitmentVector.size(); i++) {
		if (apponitmentVector[i].status == "待审核") {
			cout << i + 1 << "\t"
				<< apponitmentVector[i].date << "\t"
				<< apponitmentVector[i].time << "\t"
				<< apponitmentVector[i].stuId << "\t"
				<< apponitmentVector[i].stuName << "\t"
				<< apponitmentVector[i].roomId << "\t"
				<< apponitmentVector[i].status << endl;
			// 用于记录需要审核的预约编号
			auditId.insert(i + 1);
		}
	}
	int index = 0;
	cout << "请选择你要审核的预约编号：";
	cin >> index;
	while (auditId.find(index) == auditId.end()) {
		cout << "输入错误，请重新输入：";
		cin >> index;
	}

	if (apponitmentVector[index - 1].status != "待审核") {
		cout << "预约信息状态错误!" << endl;
		system("pause");
		system("cls");
		return;
	}

	int res;
	string result;
	cout << "1 - 通过" << endl;
	cout << "2 - 不通过" << endl;
	cout << "请选择审核结果：";
	cin >> res;
	if (res == 1) {
		result = "已通过";
	}
	else {
		result = "未通过";
	}
	modifyVector(index - 1, result);

	cout << "审核成功！" << endl;
	system("pause");
	system("cls");
}

// 显示身份菜单
void Teacher::operatorMenu() {
	bool tag = true;
	int choice;
	while (tag) {
		cout << "*****机房预约系统(管理员端)*****" << endl;
		cout << "* 1 - 审核预约                 *" << endl;
		cout << "* 2 - 查看所有预约             *" << endl;
		cout << "* 0 - 返回上一层               *" << endl;
		cout << "********************************" << endl;
		cout << "* 请选择 - ";

		cin >> choice;
		while (choice < 0 && choice > 2) {
			cout << "输入错误，请重新输入: ";
			cin >> choice;
		}

		switch (choice) {
		case 1:
			auditAppointment();
			break;
		case 2:
			showAllAppointment();
			break;
		case 0:
			tag = false;
			break;
		default:
			break;
		}
	}
	system("pause");
	system("cls");
}