#include"employee.h"
Employee::Employee(int id,string name,int dId) {
	this->id = id;
	this->name = name;
	this->dId = dId;
}
void Employee::showInfo(){
	cout << "ְ��id:" << this->id << "\t ְ������" << this->name << "\t ְ����λ" 
		<< this->getDeptName() << "\tְ�� " << "�����Լ�����������" << endl;


}
string Employee::getDeptName(){

	return string("ְ��");
}