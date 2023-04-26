#include"workerManager.h"

//构造函数空实现
WorkerManager::WorkerManager() {



	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {


		cout << "文件不存在" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
	ifs.close();
	return;
	}
	char a;
	ifs >> a;
	if (ifs.eof()){
	cout << "文件为空" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
		
	}
	int number = this->getEmpNum();
	cout << "职工个数为" << number << endl;
	this->m_EmpNum = number;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->initEmp();
	for (int i = 0; i < this->m_EmpNum; i++) {
		cout << this->m_EmpArray[i]->id << this->m_EmpArray[i]->name << endl;
	}





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
	cout << "请输入添加员工数量" << endl;
	cin >> num;
	if (num > 0) {
		int newSize = this->m_EmpNum + num;
		Worker** newSpace = new Worker* [newSize];
		if (this->m_EmpArray != 0) {
			for (int i = 0; i < m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];

			}
		
		}
		for (int i = 0; i < num; i++) {
			int id;
			string name;
			int dSelect;
			cout << "第" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			cout << "第" << i + 1 << "个新职工名字" << endl;
			cin >> name;
			cout << "选择岗位" << endl;
			cout << "1.员工岗位" << endl;
			cout << "2.经理岗位" << endl;
			cout << "3.老板岗位" << endl;
			cin >> dSelect;
				Worker * worker = NULL;//******
			switch (dSelect) {
			case 1:
				worker = new Employee(id, name, 3);
				break;
			case 2:
				worker = new Manager(id, name, 3);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "weong" << endl;
				break;

			}
			newSpace[this->m_EmpNum + i] = worker;
			delete[] this->m_EmpArray;
			this->m_EmpArray = newSpace;
			this->m_EmpNum = newSize;
			this->save();
			cout << "成功添加" << endl;
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
	cout << " * ****************" << endl;
	cout << " * ***0. exit*********" << endl;
	cout << " * ***1. add em********" << endl;
	cout << " * ***2. display********" << endl;
	cout << " * ***3. del*****" << endl;
	cout << " * ***4. modify*********" << endl;
	cout << " * ***5. find********" << endl;
	cout << " * ***6. sort********" << endl;
	cout << " * ***7. clear*********" << endl;
	cout << " * ****************" << endl;

}
void WorkerManager::exitSystem() {
	cout << "下次再见" << endl;
	system("pause");
	exit(0);

}


WorkerManager::~WorkerManager(){

	if (this->m_EmpArray != 0) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}

}