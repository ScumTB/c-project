#pragma once
#include<iostream>
#include<fstream>
#define FILENAME "employee.txt"
using namespace std;
#include<string>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
class WorkerManager {

public:
	WorkerManager();

	void showMenu();
	void exitSystem();
	int m_EmpNum;
	Worker** m_EmpArray;
	void addEmp();
	void save();
	bool m_FileIsEmpty;
	int getEmpNum();
	void initEmp();
	void showEmp();
	void delEmp();
	int isExist(int id);
	void mod_Emp();
	void find_Emp();










	~WorkerManager();



};