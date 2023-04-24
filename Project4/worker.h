#pragma once
#include<iostream>
#include<string>
using namespace std;
class Worker {
public:
	int id;
	string name;
	int dId;
	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;



};