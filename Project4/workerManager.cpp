#include"workerManager.h"

//构造函数空实现
WorkerManager::WorkerManager() {

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