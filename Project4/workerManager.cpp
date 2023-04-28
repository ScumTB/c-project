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

void WorkerManager::showEmp() {
	if (this->m_FileIsEmpty) {

		cout << "文件不存在或为空" << endl;
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
	cout << "请输入添加员工数量" << endl;
	cin >> num;
	if (num > 0) {
		int newSize = this->m_EmpNum + num;
		Worker** newSpace = new Worker * [newSize]; //没有解决内存溢出问题  newSize
		if (this->m_EmpArray != NULL) {
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
			cout << "成功添加" << endl;
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
	ofs.open(FILENAME, ios::out);//用输出方式打开文件--写文件

	//----------------这里好像-------------不能加一
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->id << " " << this->m_EmpArray[i]->name << " " << this->m_EmpArray[i]->dId << " " << endl;
	}
	//关闭文件
	ofs.close();
}
//查找职工
void WorkerManager::find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;

		int select = 0;
		cin >> select;


		if (select == 1) //按职工号查找
		{
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;

			int ret = isExist(id);
			if (ret != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2) //按姓名查找
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;

			bool flag = false;  //查找到的标志
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->name == name)
				{
					cout << "查找成功,职工编号为："
						<< m_EmpArray[i]->id
						<< " 号的信息如下：" << endl;

					flag = true;

					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				//查无此人
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}


	system("pause");
	system("cls");
}


















void WorkerManager::showMenu() {
	cout << "欢迎使用职工管理系统" << endl;
	cout << "0、退出管理程序" << endl;
	cout << "1、增加职工信息" << endl;
	cout << "2、显示职工信息" << endl;
	cout << "3、删除离职职工信息" << endl;
	cout << "4、修改职工信息" << endl;
	cout << "5、查找职工信息" << endl;

	cout << endl;

}
void WorkerManager::exitSystem() {
	cout << "下次再见" << endl;
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
		cout << "文件为空" << endl;

	}
	else {
		cout << "输入你要删除第几个人从上往下" << endl;
		int b;
		cin >> b;
		int a = b - 1;
		for (int i = a; i < this->m_EmpNum; i++) {
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		cout << "删除玩成" << endl;
	}
	this->m_EmpNum--;
	this->save();
}
void WorkerManager::mod_Emp() {
	cout << "请输入修改职工编号" << endl;
	int id;
	cin >> id;
	int ret = this->isExist(id);
	if (ret != -1) {

		delete this->m_EmpArray[ret];
		int newId=0;
		string newName=" ";
		int dSelect = 0;
		cout << "查到" << id << "输入新的" << endl;
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
		cout << "修改成功" << endl;



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