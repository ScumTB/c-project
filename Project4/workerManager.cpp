#include"workerManager.h"

//���캯����ʵ��
WorkerManager::WorkerManager() {



	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {


		cout << "�ļ�������" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
	ifs.close();
	return;
	}
	char a;
	ifs >> a;
	if (ifs.eof()){
	cout << "�ļ�Ϊ��" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
		
	}
	int number = this->getEmpNum();
	cout << "ְ������Ϊ" << number << endl;
	this->m_EmpNum = number;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->initEmp();
	for (int i = 0; i < this->m_EmpNum; i++) {
		cout << this->m_EmpArray[i]->id << this->m_EmpArray[i]->name << endl;
	}





}

void WorkerManager::showEmp() {
	if (this->m_FileIsEmpty) {

		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else {


		for (int i = 0; i < this->m_EmpNum; i++) {

			this->m_EmpArray[i]->showInfo();
			
		}

	}
	system("pause");
	system("cls");



}

void WorkerManager::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {
			worker = new Employee(id, name, dId);
		}else if(dId == 2) {
			worker = new Manager(id, name, dId);
		}else{

			worker = new Boss(id, name, 3);
		}
		this->m_EmpArray[index] = worker;
		index++;

	
	}
	ifs.close();


	

}
int WorkerManager::getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	
	while (ifs >> id && ifs >> name && ifs >> dId) {

		num++;
	}
	return num;

}
void WorkerManager::addEmp() {
	int num = 0;
	cout << "���������Ա������" << endl;
	cin >> num;
	if (num > 0) {
		int newSize = this->m_EmpNum + num;
		Worker** newSpace = new Worker* [newSize*4]; //û�н���ڴ��������  newSize
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}		
		}
		for (int i = 0; i < num; i++) {
			int id;
			string name;
			int dSelect;
			cout << "��" << i + 1 << "����ְ�����" << endl;
			cin >> id;
			cout << "��" << i + 1 << "����ְ������" << endl;
			cin >> name;
			cout << "ѡ���λ" << endl;
			cout << "1.Ա����λ" << endl;
			cout << "2.�����λ" << endl;
			cout << "3.�ϰ��λ" << endl;
			cin >> dSelect;
				Worker * wk = NULL;//******
			switch (dSelect) {
			case 1:
				wk = new Employee(id, name, 1);
				break;
			case 2:
				wk = new Manager(id, name, 2);
				break;
			case 3:
				wk = new Boss(id, name, 3);
				break;
			default:
				cout << "weong" << endl;
				break;

			}
			if (sizeof(newSpace) <= sizeof(newSize))
			{
				newSpace[this->m_EmpNum + i] = wk;
			}
			
			//delete[] this->m_EmpArray;
			this->m_EmpArray = newSpace;
			this->m_EmpNum = newSize;
			this->save();
			cout << "�ɹ����" << endl;
			system("pause");
			system("cls");

		}

	
	}
	else {
		cout << "wrong again" << endl;
	}
}
void WorkerManager::save() {
	ofstream ofs;
	ofs.open("employee.txt", ios::out);
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->id << this->m_EmpArray[i]->name << this->m_EmpArray[i]->dId << endl;
	}
	ofs.close();

}

void WorkerManager::showMenu() {
	cout << "��ӭʹ��ְ������ϵͳ" << endl;
	cout << "0���˳��������" << endl;
	cout << "1������ְ����Ϣ" << endl;
	cout << "2����ʾְ����Ϣ" << endl;
	cout << "3��ɾ����ְְ����Ϣ" << endl;
	cout << "4���޸�ְ����Ϣ" << endl;
	cout << "5������ְ����Ϣ" << endl;
	cout << "6�����ձ������" << endl;
	cout << "7����������ĵ�" << endl;
	cout << endl;

}
void WorkerManager::exitSystem() {
	cout << "�´��ټ�" << endl;
	system("pause");
	exit(0);

}


WorkerManager::~WorkerManager(){

	if (this->m_EmpArray != 0) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}

}