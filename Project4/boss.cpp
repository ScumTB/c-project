#include"boss.h"
Boss::Boss(int id, string name, int dId) {

	this->id = id;
	this->name = name;
	this->dId = dId;


}
void Boss::showInfo(){

	cout << "�ϰ�id:" << this->id << "\t �ϰ�����" << this->name << "\t �ϰ��λ"
		<< this->getDeptName() << "\tְ�� " << "�ϰ����" << endl;

}
string Boss::getDeptName() {
	return "�ϰ�";
}
