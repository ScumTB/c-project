#include<iostream>
using namespace std;
#include "workerManager.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

int main() {

	//Worker* worker = NULL;
	//worker = new Employee(1, "张三", 2);
	//worker->showInfo();
	//


	//Worker* worker = NULL;
	//worker = new Manager(2,"李斯",3);
	//worker->showInfo();
	//delete worker;

	WorkerManager wm;


	while(true){
		wm.showMenu();
		int choice = 0;
		cout << "请输入您的选择" << endl;
		
		cin >> choice;
		switch (choice) {
		case 0:
			wm.exitSystem();
			break;
		case 1:
			wm.addEmp();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			cout << "wrong againg" << endl;
			system("cls");
			break;

		}
		
		
		
		}
	
		

	
	
	system("pause");
	return 0;
}