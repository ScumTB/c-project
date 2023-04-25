#include"manager.h"


Manager::Manager(int id,string name,int dId){
	this->id = id;
	this->name = name;
	this->dId = dId;

}
 void Manager::showInfo(){
	 cout << "管理id:" << this->id << "\t 管理姓名" << this->name << "\t 管理岗位"
		 << this->getDeptName() << "\t职责 " <<"完成老板任务，下发任务给员工" << endl;
 
 }
string Manager::getDeptName(){
	return "管理";
}