//#include<iostream>
//using namespace std;
//int main() {
//	int arr[] = { 5 , 4 , 6, 8 ,9, 7 , 1 , 2,3 };
//	cout << "ÅÅĞòÇ°£º" << endl;
//	for (int i = 0; i < 9; i++) {
//		cout << arr[i] << " " << endl;
//		
//
//	}
//	cout << "***************" << endl;
//	cout << "ÅÅĞòºó:" << endl;
//	for (int i = 0; i < 9 - 1; i++) {
//		for (int j = 0; j < 9 - i - 1; j++) {
//			int temp = 0;
//
//			if (arr[j] > arr[j + 1]) {
//				temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			
//			}
//		
//		}
//	
//	
//	}
//	for (int k = 0; k < 9; k++) {
//	
//		cout << arr[k] << " ";
//	
//	}
//
//		cout << sizeof(arr)/sizeof(arr[0]);
//
//
//
//	return 0;
//}