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

// ���˵�
void SystemManager::showMenuMain() {
	while (true) {
		cout << "*****����ԤԼϵͳ*****" << endl;
		cout << "* 1 - ѧ��           *" << endl;
		cout << "* 2 - ��ʦ           *" << endl;
		cout << "* 3 - ����Ա         *" << endl;
		cout << "* 0 - �˳�ϵͳ       *" << endl;
		cout << "**********************" << endl;
		cout << "��ѡ�� - ";
		int choice = 0;
		cin >> choice;
		while (choice < 0 || choice > 3) {
			cout << "������������ȷ����ݱ�ţ�";
			cin >> choice;
		}
		if (choice == 0) {
			cout << "���ѳɹ��˳�ϵͳ!" << endl;
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
		// ѧ����Ϣ����
		cout << "������ѧ�ţ�";
		cin >> id;
		cout << "������������";
		cin >> name;
		cout << "���������룺";
		cin >> password;

		// ѧ����Ϣ��֤
		// ���ļ�
		ifs.open(STUDENT_FILE, ios::in);
		if (!ifs.is_open()) {
			cout << "�ļ������ڻ��ʧ��!" << endl;
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
		// ��ʦ��Ϣ����
		cout << "������ְ���ţ�";
		cin >> id;
		cout << "������������";
		cin >> name;
		cout << "���������룺";
		cin >> password;

		// ��ʦ��Ϣ��֤
		// ���ļ�
		ifs.open(TEACHER_FILE, ios::in);
		if (!ifs.is_open()) {
			cout << "�ļ������ڻ��ʧ��!" << endl;
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
		// ����Ա��Ϣ����
		cout << "������������";
		cin >> name;
		cout << "���������룺";
		cin >> password;

		// ����Ա��Ϣ��֤
		// ���ļ�
		ifs.open(MANAGER_FILE, ios::in);
		if (!ifs.is_open()) {
			cout << "�ļ������ڻ��ʧ��!" << endl;
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
		cout << "�����֤�ɹ���" << endl;
		system("pause");
		system("cls");
		this->person->operatorMenu();
	}
	else {
		cout << "�����֤ʧ��!" << endl;
		system("pause");
		system("cls");
	}
}

// ��ʼ��ԤԼ��Ϣ
void intitVector() {
	ifstream ifs(APPOINTMENT, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
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

// �޸�ԤԼ״̬
void modifyVector(int index, string status) {
	// �޸���Ϣ
	apponitmentVector[index].status = status;

	// �����ļ�
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