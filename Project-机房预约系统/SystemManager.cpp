#include "SystemManager.h"

vector<Appointment> apponitmentVector;


SystemManager::SystemManager() {
	this->person = NULL;
}

SystemManager::~SystemManager() {
	if (this->person != NULL) {
		delete this->person;
		this->person = NULL;
	}
}

// 主菜单
void SystemManager::showMenuMain() {
	while (true) {
		cout << "*****机房预约系统*****" << endl;
		cout << "* 1 - 学生           *" << endl;
		cout << "* 2 - 教师           *" << endl;
		cout << "* 3 - 管理员         *" << endl;
		cout << "* 0 - 退出系统       *" << endl;
		cout << "**********************" << endl;
		cout << "请选择 - ";
		int choice = 0;
		cin >> choice;
		while (choice < 0 || choice > 3) {
			cout << "请重新输入正确的身份编号：";
			cin >> choice;
		}
		if (choice == 0) {
			cout << "您已成功退出系统!" << endl;
			return;
		}
		checkInfo(choice);
	}
}

void SystemManager::checkInfo(int identity) {
	ifstream ifs;
	int id, fid;
	string name, fname;
	string password, fpwd;

	if (this->person != NULL) {
		delete this->person;
		this->person = NULL;
	}

	switch (identity)
	{
	case 1:
		// 学生信息输入
		cout << "请输入学号：";
		cin >> id;
		cout << "请输入姓名：";
		cin >> name;
		cout << "请输入密码：";
		cin >> password;

		// 学生信息验证
		// 打开文件
		ifs.open(STUDENT_FILE, ios::in);
		if (!ifs.is_open()) {
			cout << "文件不存在或打开失败!" << endl;
			ifs.close();
			return;
		}

		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && name == fname && password == fpwd) {
				this->person = new Student(id, name, password);
				break;
			}
		}
		break;
	case 2:
		// 教师信息输入
		cout << "请输入职工号：";
		cin >> id;
		cout << "请输入姓名：";
		cin >> name;
		cout << "请输入密码：";
		cin >> password;

		// 教师信息验证
		// 打开文件
		ifs.open(TEACHER_FILE, ios::in);
		if (!ifs.is_open()) {
			cout << "文件不存在或打开失败!" << endl;
			ifs.close();
			return;
		}

		while (ifs >> fid && ifs >> fname && ifs >> fpwd) {
			if (id == fid && name == fname && password == fpwd) {
				this->person = new Teacher(id, name, password);
				break;
			}
		}
		break;
	case 3:
		// 管理员信息输入
		cout << "请输入姓名：";
		cin >> name;
		cout << "请输入密码：";
		cin >> password;

		// 管理员信息验证
		// 打开文件
		ifs.open(MANAGER_FILE, ios::in);
		if (!ifs.is_open()) {
			cout << "文件不存在或打开失败!" << endl;
			ifs.close();
			return;
		}

		while (ifs >> fname && ifs >> fpwd) {
			if (name == fname && password == fpwd) {
				this->person = new Manager(name, password);
				break;
			}
		}
		break;
	default:
		break;
	}

	if (this->person != NULL) {
		cout << "身份验证成功！" << endl;
		system("pause");
		system("cls");
		this->person->operatorMenu();
	}
	else {
		cout << "身份验证失败!" << endl;
		system("pause");
		system("cls");
	}
}

// 初始化预约信息
void intitVector() {
	ifstream ifs(APPOINTMENT, ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败！" << endl;
		return;
	}
	Appointment appointment;
	apponitmentVector.clear();
	while (ifs >> appointment.date && ifs >> appointment.time
		&& ifs >> appointment.stuId && ifs >> appointment.stuName
		&& ifs >> appointment.roomId && ifs >> appointment.status) {
		apponitmentVector.push_back(appointment);
	}
	ifs.close();
}

// 修改预约状态
void modifyVector(int index, string status) {
	// 修改信息
	apponitmentVector[index].status = status;

	// 更新文件
	ofstream ofs(APPOINTMENT, ios::out | ios::trunc);
	for (vector<Appointment>::iterator it = apponitmentVector.begin();
		it != apponitmentVector.end(); it++) {
		Appointment appointment = *it;
		ofs << appointment.date << " " << appointment.time << " " <<
			appointment.stuId << " " << appointment.stuName << " " <<
			appointment.roomId << " " << appointment.status << endl;
	}

	ofs.close();
}