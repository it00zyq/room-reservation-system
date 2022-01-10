#include "student.h"

Student::Student(int id, string name, string password) {
	this->id = id;
	this->name = name;
	this->password = password;
	this->initRoomSet();
	// ��ʼ��ԤԼ��Ϣ����
	intitVector();
}

void Student::initRoomSet() {
	ifstream ifs(ROOM, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	int id;
	int capacity;
	while (ifs >> id && ifs >> capacity) {
		roomSet.insert(id);
	}

	ifs.close();
}

// ����ԤԼ
void Student::applyAppointment() {
	Appointment appointment;
	int choice = 0;
	cout << "1 - ��һ" << endl;
	cout << "2 - �ܶ�" << endl;
	cout << "3 - ����" << endl;
	cout << "4 - ����" << endl;
	cout << "5 - ����" << endl;
	cout << "��ѡ�����ڣ�";
	cin >> choice;

	switch (choice)
	{
	case 1:
		appointment.date = "��һ";
		break;
	case 2:
		appointment.date = "�ܶ�";
		break;
	case 3:
		appointment.date = "����";
		break;
	case 4:
		appointment.date = "����";
		break;
	case 5:
		appointment.date = "����";
		break;
	default:
		break;
	}

	cout << "1 - ����" << endl;
	cout << "2 - ����" << endl;
	cout << "��ѡ��ʱ��Σ�";
	cin >> choice;
	if (choice == 1) {
		appointment.time = "����";
	} else {
		appointment.time = "����";
	}

	cout << "�����������ţ�";
	cin >> appointment.roomId;
	while (roomSet.find(appointment.roomId) == roomSet.end()){
		cout << "����������������룺";
		cin >> appointment.roomId;
	}

	appointment.stuId = this->id;
	appointment.stuName = this->name;
	appointment.status = "�����";

	ofstream ofs(APPOINTMENT, ios::out | ios::app);
	ofs << appointment.date << " " << appointment.time << " " <<
		appointment.stuId << " " << appointment.stuName << " " <<
		appointment.roomId << " " << appointment.status << endl;
	ofs.close();

	// ����ԤԼ��Ϣ����
	apponitmentVector.push_back(appointment);

	cout << "����ɹ���" << endl;
	system("pause");
	system("cls");
}
// �鿴�ҵ�ԤԼ
void Student::showMyAppointment() {
	cout << "���\t" << "����\t" << "ʱ���\t" << "������\t" << "״̬" << endl;
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
// �鿴����ԤԼ
void Student::showAllAppointment() {
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

// ȡ��ԤԼ
void Student::cancelAppointment() {
	set<int> myId;
	cout << "���\t" << "����\t" << "ʱ���\t" << "ѧ��\t" << "����\t" << "������\t" << "״̬" << endl;
	for (unsigned int i = 0; i < apponitmentVector.size(); i++) {
		if (apponitmentVector[i].status == "�����" && apponitmentVector[i].stuId == this->id) {
			cout << i + 1 << "\t"
				<< apponitmentVector[i].date << "\t"
				<< apponitmentVector[i].time << "\t"
				<< apponitmentVector[i].stuId << "\t"
				<< apponitmentVector[i].stuName << "\t"
				<< apponitmentVector[i].roomId << "\t"
				<< apponitmentVector[i].status << endl;
			// ���ڼ�¼��ǰѧ��������ԤԼ���
			myId.insert(i + 1);
		}
	}
	int index = 0;
	cout << "��ѡ����Ҫȡ����ԤԼ��ţ�";
	cin >> index;
	while (myId.find(index) == myId.end()) {
		cout << "����������������룺";
		cin >> index;
	}
	if (apponitmentVector[index - 1].status == "��ȡ��") {
		cout << "ԤԼ��Ϣ״̬����!" << endl;
		system("pause");
		system("cls");
		return;
	}
	modifyVector(index - 1, "��ȡ��");

	cout << "ȡ���ɹ���" << endl;
	system("pause");
	system("cls");
}

// ��ʾ��ݲ˵�
void Student::operatorMenu() {
	bool tag = true;
	int choice;
	while (tag){
		cout << "*****����ԤԼϵͳ(ѧ����)*****" << endl;
		cout << "* 1 - ����ԤԼ               *" << endl;
		cout << "* 2 - ȡ��ԤԼ               *" << endl;
		cout << "* 3 - �鿴�ҵ�ԤԼ           *" << endl;
		cout << "* 4 - �鿴����ԤԼ           *" << endl;
		cout << "* 0 - ������һ��             *" << endl;
		cout << "******************************" << endl;
		cout << "* ��ѡ�� - ";

		cin >> choice;
		while (choice < 0 && choice > 4) {
			cout << "�����������������: ";
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