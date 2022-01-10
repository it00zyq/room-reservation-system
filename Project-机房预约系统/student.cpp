#include "student.h"

Student::Student(int id, string name, string password) {
	this->id = id;
	this->name = name;
	this->password = password;
	this->initRoomSet();
	// 初始化预约信息容器
	intitVector();
}

void Student::initRoomSet() {
	ifstream ifs(ROOM, ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败！" << endl;
		return;
	}
	int id;
	int capacity;
	while (ifs >> id && ifs >> capacity) {
		roomSet.insert(id);
	}

	ifs.close();
}

// 申请预约
void Student::applyAppointment() {
	Appointment appointment;
	int choice = 0;
	cout << "1 - 周一" << endl;
	cout << "2 - 周二" << endl;
	cout << "3 - 周三" << endl;
	cout << "4 - 周四" << endl;
	cout << "5 - 周五" << endl;
	cout << "请选择日期：";
	cin >> choice;

	switch (choice)
	{
	case 1:
		appointment.date = "周一";
		break;
	case 2:
		appointment.date = "周二";
		break;
	case 3:
		appointment.date = "周三";
		break;
	case 4:
		appointment.date = "周四";
		break;
	case 5:
		appointment.date = "周五";
		break;
	default:
		break;
	}

	cout << "1 - 上午" << endl;
	cout << "2 - 下午" << endl;
	cout << "请选择时间段：";
	cin >> choice;
	if (choice == 1) {
		appointment.time = "上午";
	} else {
		appointment.time = "下午";
	}

	cout << "请输入机房编号：";
	cin >> appointment.roomId;
	while (roomSet.find(appointment.roomId) == roomSet.end()){
		cout << "输入错误，请重新输入：";
		cin >> appointment.roomId;
	}

	appointment.stuId = this->id;
	appointment.stuName = this->name;
	appointment.status = "待审核";

	ofstream ofs(APPOINTMENT, ios::out | ios::app);
	ofs << appointment.date << " " << appointment.time << " " <<
		appointment.stuId << " " << appointment.stuName << " " <<
		appointment.roomId << " " << appointment.status << endl;
	ofs.close();

	// 更新预约信息容器
	apponitmentVector.push_back(appointment);

	cout << "申请成功！" << endl;
	system("pause");
	system("cls");
}
// 查看我的预约
void Student::showMyAppointment() {
	cout << "编号\t" << "日期\t" << "时间段\t" << "机房号\t" << "状态" << endl;
	for (unsigned int i = 0; i < apponitmentVector.size(); i++) {
		if (apponitmentVector[i].stuId == this->id) {
			cout << i + 1 << "\t"
				<< apponitmentVector[i].date << "\t"
				<< apponitmentVector[i].time << "\t"
				<< apponitmentVector[i].roomId << "\t"
				<< apponitmentVector[i].status << endl;
		}
	}
	system("pause");
	system("cls");
}
// 查看所有预约
void Student::showAllAppointment() {
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

// 取消预约
void Student::cancelAppointment() {
	set<int> myId;
	cout << "编号\t" << "日期\t" << "时间段\t" << "学号\t" << "姓名\t" << "机房号\t" << "状态" << endl;
	for (unsigned int i = 0; i < apponitmentVector.size(); i++) {
		if (apponitmentVector[i].status == "待审核" && apponitmentVector[i].stuId == this->id) {
			cout << i + 1 << "\t"
				<< apponitmentVector[i].date << "\t"
				<< apponitmentVector[i].time << "\t"
				<< apponitmentVector[i].stuId << "\t"
				<< apponitmentVector[i].stuName << "\t"
				<< apponitmentVector[i].roomId << "\t"
				<< apponitmentVector[i].status << endl;
			// 用于记录当前学生包含的预约编号
			myId.insert(i + 1);
		}
	}
	int index = 0;
	cout << "请选择你要取消的预约编号：";
	cin >> index;
	while (myId.find(index) == myId.end()) {
		cout << "输入错误，请重新输入：";
		cin >> index;
	}
	if (apponitmentVector[index - 1].status == "已取消") {
		cout << "预约信息状态错误!" << endl;
		system("pause");
		system("cls");
		return;
	}
	modifyVector(index - 1, "已取消");

	cout << "取消成功！" << endl;
	system("pause");
	system("cls");
}

// 显示身份菜单
void Student::operatorMenu() {
	bool tag = true;
	int choice;
	while (tag){
		cout << "*****机房预约系统(学生端)*****" << endl;
		cout << "* 1 - 申请预约               *" << endl;
		cout << "* 2 - 取消预约               *" << endl;
		cout << "* 3 - 查看我的预约           *" << endl;
		cout << "* 4 - 查看所有预约           *" << endl;
		cout << "* 0 - 返回上一层             *" << endl;
		cout << "******************************" << endl;
		cout << "* 请选择 - ";

		cin >> choice;
		while (choice < 0 && choice > 4) {
			cout << "输入错误，请重新输入: ";
			cin >> choice;
		}

		switch (choice) {
		case 1:
			applyAppointment();
			break;
		case 2:
			cancelAppointment();
			break;
		case 3:
			showMyAppointment();
			break;
		case 4:
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