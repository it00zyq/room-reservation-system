#include "teacher.h"


Teacher::Teacher(int id, string name, string password) {
	this->id = id;
	this->name = name;
	this->password = password;
	intitVector();
}

// �鿴����ԤԼ
void Teacher::showAllAppointment() {
	cout << "���\t" << "����\t" << "ʱ���\t" << "ѧ��\t" << "����\t" << "������\t" << "״̬" << endl;
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

// ���ԤԼ
void Teacher::auditAppointment() {
	set<int> auditId; //���ڼ�¼��Ҫ��˵�ԤԼ���
	cout << "���\t" << "����\t" << "ʱ���\t" << "ѧ��\t" << "����\t" << "������\t" << "״̬" << endl;
	for (unsigned int i = 0; i < apponitmentVector.size(); i++) {
		if (apponitmentVector[i].status == "�����") {
			cout << i + 1 << "\t"
				<< apponitmentVector[i].date << "\t"
				<< apponitmentVector[i].time << "\t"
				<< apponitmentVector[i].stuId << "\t"
				<< apponitmentVector[i].stuName << "\t"
				<< apponitmentVector[i].roomId << "\t"
				<< apponitmentVector[i].status << endl;
			// ���ڼ�¼��Ҫ��˵�ԤԼ���
			auditId.insert(i + 1);
		}
	}
	int index = 0;
	cout << "��ѡ����Ҫ��˵�ԤԼ��ţ�";
	cin >> index;
	while (auditId.find(index) == auditId.end()) {
		cout << "����������������룺";
		cin >> index;
	}

	if (apponitmentVector[index - 1].status != "�����") {
		cout << "ԤԼ��Ϣ״̬����!" << endl;
		system("pause");
		system("cls");
		return;
	}

	int res;
	string result;
	cout << "1 - ͨ��" << endl;
	cout << "2 - ��ͨ��" << endl;
	cout << "��ѡ����˽����";
	cin >> res;
	if (res == 1) {
		result = "��ͨ��";
	}
	else {
		result = "δͨ��";
	}
	modifyVector(index - 1, result);

	cout << "��˳ɹ���" << endl;
	system("pause");
	system("cls");
}

// ��ʾ��ݲ˵�
void Teacher::operatorMenu() {
	bool tag = true;
	int choice;
	while (tag) {
		cout << "*****����ԤԼϵͳ(����Ա��)*****" << endl;
		cout << "* 1 - ���ԤԼ                 *" << endl;
		cout << "* 2 - �鿴����ԤԼ             *" << endl;
		cout << "* 0 - ������һ��               *" << endl;
		cout << "********************************" << endl;
		cout << "* ��ѡ�� - ";

		cin >> choice;
		while (choice < 0 && choice > 2) {
			cout << "�����������������: ";
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