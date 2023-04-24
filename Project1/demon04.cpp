//#include<iostream>
//#include<string>
//using namespace std;
//
//struct hero {
//	string name;
//	int age;
//};
//// 5
//
//
//void bubblesort(struct hero heroarray[], int len) {
//	for (int i = 0; i < len - 1; i++) {
//		for (int j = 0; j < len -i-1; j++) {
//
//			if (heroarray[j].age > heroarray[j + 1].age) {
//
//				hero temp = heroarray[j];
//				heroarray[j] = heroarray[j + 1];
//				heroarray[j + 1] = temp;
//			}
//
//			
//		}
//	}
//	for (int k = 0; k < len; k++) {
//
//		cout << heroarray[k].name << heroarray[k].age << endl;
//	}
//}
////void printhero(hero heroarray[], int len) {
////
////	for (int k = 0; k < len; k++) {
////	
////		cout << heroarray[k].name << heroarray[k].age << endl;
////	}
////
////
////}
//
//int main(){
//	struct hero heroarray[5] = {
//		{"a",32},
//		{"b",66},
//		{"c",55},
//		{"d",12},
//		{"e",75}
//
//	};
//	int len = 0;
//	len = sizeof(heroarray) / sizeof(heroarray[0]);
//	cout << len << endl;
//	bubblesort(heroarray, len);
//	/*printhero(heroarray, len);*/
//
//	return 0;
//}