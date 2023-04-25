#include"boss.h"
Boss::Boss(int id, string name, int dId) {

	this->id = id;
	this->name = name;
	this->dId = dId;


}
void Boss::showInfo(){

	cout << "老板id:" << this->id << "\t 老板姓名" << this->name << "\t 老板岗位"
		<< this->getDeptName() << "\t职责 " << "老板管理" << endl;

}
string Boss::getDeptName() {
	return "老板";
}
