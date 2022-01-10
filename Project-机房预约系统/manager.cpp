#include "manager.h"

Manager::Manager(string name, string password) {
	this->name = name;
	this->password = password;
	this->initStuSet();
	this->initTeaSet();
}

// ����˺�
void Manager::addAccount() {
	cout << "1 - ѧ��" << endl;
	cout << "2 - ��ʦ" << endl;
	cout << "��ѡ��Ҫ��ӵ��˺����ͣ�";
	int choice = 0;

	cin >> choice;
	while (choice != 1 && choice != 2) {
		cout << "����������������룺";
		cin >> choice;
	}

	int id;
	string name;
	string password;
	string fileName;

	if (choice == 1) {
		cout << "������ѧ�ţ�";
		cin >> id;
		// ѧ�ż��
		while (stuSet.find(id) != stuSet.end()) {
			cout << "ѧ���Ѵ��ڣ����������룺";
			cin >> id;
		}
		fileName = STUDENT_FILE;
	}
	else {
		cout << "������ְ���ţ�";
		cin >> id;
		// ְ���ż��
		while (teaSet.find(id) != teaSet.end()) {
			cout << "ְ�����Ѵ��ڣ����������룺";
			cin >> id;
		}
		fileName = TEACHER_FILE;
	}



	cout << "������������";
	cin >> name;

	cout << "���������룺";
	cin >> password;

	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app);
	if (!ofs.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	// д���ļ�
	ofs << id << " " << name << " " << password << endl;
	ofs.close();

	cout << "��ӳɹ���" << endl;


	system("pause");
	system("cls");

	// ��������
	if (fileName == STUDENT_FILE) {
		stuSet.insert(id);
	}
	else {
		teaSet.insert(id);
	}
}

// �鿴�˺�
void Manager::showAccount() {
	cout << "1 - ѧ��" << endl;
	cout << "2 - ��ʦ" << endl;
	cout << "��ѡ��Ҫ�鿴���˺����ͣ�";
	int choice = 0;

	cin >> choice;
	while (choice != 1 && choice != 2) {
		cout << "����������������룺";
		cin >> choice;
	}

	int id;
	string name;
	string password;
	string fileName;
	string title;


	if (choice == 1) {
		fileName = STUDENT_FILE;
		title = "ѧ��\t����\t����";
		
	}
	else {
		fileName = TEACHER_FILE;
		title = "ְ����\t����\t����";
	}

	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout << "���ļ�ʧ�ܣ�" << endl;
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

// �鿴������Ϣ
void Manager::showMachineRoom() {
	ifstream ifs;
	ifs.open(ROOM, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	int id;
	int capacity;
	while (ifs >> id && ifs >> capacity) {
		cout << id << "�Ż���" << " " << "����" << capacity << endl;
	}

	system("pause");
	system("cls");
}

// ���ԤԼ��Ϣ
void Manager::clearAppointment() {
	ofstream ofs;
	// ����ļ�
	ofs.open(APPOINTMENT, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

// ��ʾ��ݲ˵�
void Manager::operatorMenu() {
	bool tag = true;
	while (tag)
	{
		cout << "*****����ԤԼϵͳ(����Ա��)*****" << endl;
		cout << "* 1 - ����˺�               *" << endl;
		cout << "* 2 - �鿴�˺�               *" << endl;
		cout << "* 3 - �鿴������Ϣ           *" << endl;
		cout << "* 4 - ���ԤԼ��Ϣ           *" << endl;
		cout << "* 0 - ������һ��             *" << endl;
		cout << "******************************" << endl;
		cout << "* ��ѡ�� - ";

		int choice = 0;
		cin >> choice;
		while (choice < 0 && choice > 4) {
			cout << "�����������������: ";
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

// ��ʼ������
void Manager::initStuSet() {
	int id;
	string name;
	string password;

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	// �������
	stuSet.clear();
	// ͬ���ļ����ݵ�����
	while (ifs >> id && ifs >> name && ifs >> password) {
		stuSet.insert(id);
	}
	ifs.close();
}

// ��ʼ������
void Manager::initTeaSet() {
	int id;
	string name;
	string password;

	ifstream ifs;
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}

	// �������
	teaSet.clear();
	// ͬ���ļ����ݵ�����
	while (ifs >> id && ifs >> name && ifs >> password) {
		teaSet.insert(id);
	}

	ifs.close();
}