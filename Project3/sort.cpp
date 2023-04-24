//#include<iostream>
//#include<string>
//using namespace std;
//
//template <class T>
//void swapT(T& a, T& b) {
//
//	T temp = a;
//	a = b;
//	b = temp;
//}
//
//template <class T>
//void mySort(T array[], int len) {
//	for (int i = 0; i < len, i++) {
//		int max = i;//************
//		int j =0;
//		for (int j = i + 1; j < len; j++) {
//			if (array[max] < array[j]) {
//				max = j;
//			}
//		}
//			if (max != j) {
//				swapT(array[max], array[i]);
//			}
//	}
//}
//template <class T>
//void printArray(T array[], int len) {
//	for (int i = 0; i < len; i++) {
//		cout << array[i] << " ";
//		cout << endl;
//
//	}
//
//}
//void test01() {
//	char charArr[] = "badcfe";
//	int num = sizeof(charArr) / sizeof(char);
//	mySort(charArr, num);
//	printArray(charArr, num);
//	cout << num << endl;
//}
//
//int main() {
//	test01();
//	return 0;
//}