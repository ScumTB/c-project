#include"employee.h"
Employee::Employee(int id,string name,int dId) {
	this->id = id;
	this->name = name;
	this->dId = dId;
}
void Employee::showInfo(){
	cout << "职工id:" << this->id << "\t 职工姓名" << this->name << "\t 职工岗位" 
		<< this->getDeptName() << "\t职责 " << "做好自己该做的事情" << endl;


}
string Employee::getDeptName(){

	return string("职工");
}