//#include<string>
//using namespace std;
//#include<iostream>
//#define MAX 1000
//
//
//void showMenu() {
//	cout << "***********" << endl;
//	cout << "**1.���****" << endl;
//	cout << "**2.��ʾ****" << endl;
//	cout << "**3.ɾ��****" << endl;
//	cout << "**4.����****" << endl;
//	cout << "**5.�޸�****" << endl;
//	cout << "**6.���****" << endl;
//	cout << "**0.�˳�****" << endl;
//	cout << "***********" << endl;
//
//}
//struct Person {
//	string name;
//	int age;
//
//
//
//};
//struct addressbooks {
//	struct Person personArray[MAX];
//	int m_size;
//
//
//
//};
//
//
//
//void addPerson(struct addressbooks * abs) {
//	
//	
//	cout << "����" << endl;
//	string name;
//	cin >> name;
//	
//	abs->personArray[abs->m_size].name = name;
//	cout << "����" << endl;
//	int age;
//	cin >> age;
//	abs->personArray[abs->m_size].age = age;
//	abs->m_size++;
//
//
//}
//void show(struct addressbooks * abs) {
//	for (int i = 0; i < abs->m_size; i++)
//	{
//
//		cout << "����" << abs->personArray[i].name << "  ";
//		cout << "����" << abs->personArray[i].age << "  ";
//	}
//	system("pause");
//	
//}
//int isExit(struct addressbooks * abs,string name) {
//	for (int i = 0; i < abs->m_size; i++) {
//		abs->personArray[i].name = name;
//		return i;
//	}
//	return -1;
//}
//void deletePerson(struct addressbooks * abs) {
//	cout << "��Ҫɾ�����˵�����" << endl;
//	string name;
//	cin >> name;
//	int ret = isExit(abs,name);
//	if (ret != -1) {
//		for (int j = ret; j < abs->m_size; j++) {
//			abs->personArray[j] = abs->personArray[j + 1];
//			abs->m_size--;
//			cout << "ɾ���ɹ�" << endl;
//
//		}
//	}
//	else {
//		cout << "wrong" << endl;
//	}
//
//
//
//}
//void findPerson(struct a){}
//
//
//
//
//int main() {
//	addressbooks abs;
//	abs.m_size = 0;
//	bool flag = true;
//	
//	while (flag) {
//		showMenu();
//		cout << "please input number to control" << endl;
//		int select;
//		cin >> select;
//	
//		switch (select) {
//		case 1:
//			
//			addPerson(&abs);
//			break;
//		case 2:
//			show(&abs);
//			break;
//		case 3:
//			
//			deletePerson(&abs);
//			/*{
//			string name;
//			cin >> name;
//			int ret = isExit(&abs, name);
//			if (ret != -1) {
//				cout << "exist";
//			}
//			else {
//				cout << "no";
//			}
//
//		}*/
//			break;
//		case 4:
//
//
//			break;
//		case 5:
//			break;
//		case 6:
//			break;
//		case 0:
//			cout << "�´��ټ�" << endl;
//			
//			flag = false;
//			system("pause");
//			break;
//
//
//			
//		default:
//			cout << "wrong!again" << endl;
//			break;
//		
//		}
//
//
//
//
//}
//
//
//	
//	return 0;
//}