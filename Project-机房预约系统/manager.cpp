#include "manager.h"

Manager::Manager(string name, string password) {
	this->name = name;
	this->password = password;
	this->initStuSet();
	this->initTeaSet();
}

// 添加账号
void Manager::addAccount() {
	cout << "1 - 学生" << endl;
	cout << "2 - 教师" << endl;
	cout << "请选择要添加的账号类型：";
	int choice = 0;

	cin >> choice;
	while (choice != 1 && choice != 2) {
		cout << "输入错误，请重新输入：";
		cin >> choice;
	}

	int id;
	string name;
	string password;
	string fileName;

	if (choice == 1) {
		cout << "请输入学号：";
		cin >> id;
		// 学号检查
		while (stuSet.find(id) != stuSet.end()) {
			cout << "学号已存在，请重新输入：";
			cin >> id;
		}
		fileName = STUDENT_FILE;
	}
	else {
		cout << "请输入职工号：";
		cin >> id;
		// 职工号检查
		while (teaSet.find(id) != teaSet.end()) {
			cout << "职工号已存在，请重新输入：";
			cin >> id;
		}
		fileName = TEACHER_FILE;
	}



	cout << "请输入姓名：";
	cin >> name;

	cout << "请输入密码：";
	cin >> password;

	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app);
	if (!ofs.is_open()) {
		cout << "文件打开失败！" << endl;
		return;
	}

	// 写入文件
	ofs << id << " " << name << " " << password << endl;
	ofs.close();

	cout << "添加成功！" << endl;


	system("pause");
	system("cls");

	// 更新容器
	if (fileName == STUDENT_FILE) {
		stuSet.insert(id);
	}
	else {
		teaSet.insert(id);
	}
}

// 查看账号
void Manager::showAccount() {
	cout << "1 - 学生" << endl;
	cout << "2 - 教师" << endl;
	cout << "请选择要查看的账号类型：";
	int choice = 0;

	cin >> choice;
	while (choice != 1 && choice != 2) {
		cout << "输入错误，请重新输入：";
		cin >> choice;
	}

	int id;
	string name;
	string password;
	string fileName;
	string title;


	if (choice == 1) {
		fileName = STUDENT_FILE;
		title = "学号\t姓名\t密码";
		
	}
	else {
		fileName = TEACHER_FILE;
		title = "职工号\t姓名\t密码";
	}

	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "打开文件失败！" << endl;
		return;
	}

	cout << title << endl;
	while (ifs >> id && ifs >> name && ifs >> password) {
		cout << id << "\t" << name << "\t" << password << endl;
	}

	ifs.close();

	system("pause");
	system("cls");
}

// 查看机房信息
void Manager::showMachineRoom() {
	ifstream ifs;
	ifs.open(ROOM, ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败！" << endl;
		return;
	}

	int id;
	int capacity;
	while (ifs >> id && ifs >> capacity) {
		cout << id << "号机房" << " " << "容量" << capacity << endl;
	}

	system("pause");
	system("cls");
}

// 清空预约信息
void Manager::clearAppointment() {
	ofstream ofs;
	// 清空文件
	ofs.open(APPOINTMENT, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

// 显示身份菜单
void Manager::operatorMenu() {
	bool tag = true;
	while (tag)
	{
		cout << "*****机房预约系统(管理员端)*****" << endl;
		cout << "* 1 - 添加账号               *" << endl;
		cout << "* 2 - 查看账号               *" << endl;
		cout << "* 3 - 查看机房信息           *" << endl;
		cout << "* 4 - 清空预约信息           *" << endl;
		cout << "* 0 - 返回上一层             *" << endl;
		cout << "******************************" << endl;
		cout << "* 请选择 - ";

		int choice = 0;
		cin >> choice;
		while (choice < 0 && choice > 4) {
			cout << "输入错误，请重新输入: ";
			cin >> choice;
		}

		switch (choice)
		{
		case 1:
			addAccount();
			break;
		case 2:
			showAccount();
			break;
		case 3:
			showMachineRoom();
			break;
		case 4:
			clearAppointment();
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

// 初始化容器
void Manager::initStuSet() {
	int id;
	string name;
	string password;

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败！" << endl;
		return;
	}

	// 清除容器
	stuSet.clear();
	// 同步文件数据到容器
	while (ifs >> id && ifs >> name && ifs >> password) {
		stuSet.insert(id);
	}
	ifs.close();
}

// 初始化容器
void Manager::initTeaSet() {
	int id;
	string name;
	string password;

	ifstream ifs;
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败！" << endl;
		return;
	}

	// 清除容器
	teaSet.clear();
	// 同步文件数据到容器
	while (ifs >> id && ifs >> name && ifs >> password) {
		teaSet.insert(id);
	}

	ifs.close();
}