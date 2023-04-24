//#include <iostream>
//using namespace std;
//#include<string>
//
//struct Student {
//	string sname;
//	
//	int score;
//
//
//};
//struct Teacher {
//	string name;
//	struct Student sArray[5];
//};
//string nameSeed = "ABCDE";
//
//void allocate(Teacher tArray[],int len) {
//	for (int i = 0; i < len; i++) {
//		tArray[i].name = "Teacher_";
//		tArray[i].name += nameSeed[i];
//		cout << tArray[i].name << endl;
//
//		for (int j = 0; j < 5; j++) {
//			tArray[i].sArray[j].sname = "Student_";
//			tArray[i].sArray[j].sname += nameSeed[j];
//
//			int random = rand() % 60;
//				tArray[i].sArray[j].score = random;
//			
//		       cout <<"学生的名字："<< tArray[i].sArray[j].sname<< "分数 "<<  tArray[i].sArray[j].score << endl;
//
//
//
//
//			}
//
//
//	}
//}
//
//int main(){
//	Teacher tArray[3];
//	int len = 0;
//	len = sizeof(tArray) / sizeof(tArray[0]);
//	cout << len << endl;
//	allocate(tArray,len);
//
//
//
//	return 0;
//}