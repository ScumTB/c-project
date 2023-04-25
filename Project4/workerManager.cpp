#include"workerManager.h"

//构造函数空实现
WorkerManager::WorkerManager() {

	this->m_EmpArray = NULL;
	this->m_EmpNum = 0;



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
			cout << "成功添加" << endl;
			system("pause");
			system("cls");

			

			

		}



	
	
	}
	else {


		cout << "wrong again" << endl;
	}

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

}