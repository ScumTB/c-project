#include"manager.h"


Manager::Manager(int id,string name,int dId){
	this->id = id;
	this->name = name;
	this->dId = dId;

}
 void Manager::showInfo(){
	 cout << "����id:" << this->id << "\t ��������" << this->name << "\t �����λ"
		 << this->getDeptName() << "\tְ�� " <<"����ϰ������·������Ա��" << endl;
 
 }
string Manager::getDeptName(){
	return "����";
}