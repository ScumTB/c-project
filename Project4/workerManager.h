#pragma once
#include<iostream>
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









	~WorkerManager();



};