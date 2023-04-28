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
		Worker** newSpace = new Worker * [newSize]; //û�н���ڴ��������  newSize
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
			
			
				newSpace[this->m_EmpNum + i] = wk;
			
			
			delete[] this->m_EmpArray;
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
//void WorkerManager::save() {
//	ofstream ofs;
//	ofs.open("employee.txt", ios::out);
//	for (int i = 0; i < this->m_EmpNum; i++) {
//		ofs << this->m_EmpArray[i]->id << " "<< this->m_EmpArray[i]->name << " " << this->m_EmpArray[i]->dId << endl;
//	}
//	ofs.close();
//
//}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//�������ʽ���ļ�--д�ļ�

	//----------------�������-------------���ܼ�һ
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->id << " " << this->m_EmpArray[i]->name << " " << this->m_EmpArray[i]->dId << " " << endl;
	}
	//�ر��ļ�
	ofs.close();
}
//����ְ��
void WorkerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;

		int select = 0;
		cin >> select;


		if (select == 1) //��ְ���Ų���
		{
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			int ret = isExist(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2) //����������
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;

			bool flag = false;  //���ҵ��ı�־
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->name == name)
				{
					cout << "���ҳɹ�,ְ�����Ϊ��"
						<< m_EmpArray[i]->id
						<< " �ŵ���Ϣ���£�" << endl;

					flag = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				//���޴���
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}


	system("pause");
	system("cls");
}


















void WorkerManager::showMenu() {
	cout << "��ӭʹ��ְ������ϵͳ" << endl;
	cout << "0���˳��������" << endl;
	cout << "1������ְ����Ϣ" << endl;
	cout << "2����ʾְ����Ϣ" << endl;
	cout << "3��ɾ����ְְ����Ϣ" << endl;
	cout << "4���޸�ְ����Ϣ" << endl;
	cout << "5������ְ����Ϣ" << endl;

	cout << endl;

}
void WorkerManager::exitSystem() {
	cout << "�´��ټ�" << endl;
	system("pause");
	exit(0);

}

int WorkerManager::isExist(int id) {
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->id == id) {
			index = i;
		break;
			
		}
	
	}
		return index;


}
void WorkerManager::delEmp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ�Ϊ��" << endl;

	}
	else {
		cout << "������Ҫɾ���ڼ����˴�������" << endl;
		int b;
		cin >> b;
		int a = b - 1;
		for (int i = a; i < this->m_EmpNum; i++) {
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		cout << "ɾ�����" << endl;
	}
	this->m_EmpNum--;
	this->save();
}
void WorkerManager::mod_Emp() {
	cout << "�������޸�ְ�����" << endl;
	int id;
	cin >> id;
	int ret = this->isExist(id);
	if (ret != -1) {

		delete this->m_EmpArray[ret];
		int newId=0;
		string newName=" ";
		int dSelect = 0;
		cout << "�鵽" << id << "�����µ�" << endl;
		cin >> newId;
		cin >> newName;
		cin >> dSelect;

		Worker* worker = NULL;
		switch (dSelect) {

		case 1:
			worker = new Employee(newId, newName, dSelect);
			break;
		case 2:
			worker = new Manager(newId, newName, dSelect);
			break;
		case 3:
			worker = new Boss(newId, newName, dSelect);
			break;





		}
		this->m_EmpArray[ret] = worker;
		cout << "�޸ĳɹ�" << endl;



		this->save();

	}
	    system("pause");
		system("cls");
}



WorkerManager::~WorkerManager(){

	if (this->m_EmpArray != 0) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}

}