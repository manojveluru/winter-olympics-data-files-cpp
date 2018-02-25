#ifndef ATHELETE_H
#define ATHELETE_H
#include<iostream>
using namespace std;
const int NAME_SIZE = 30;
class Athelete
{
	char lastname[NAME_SIZE];
	char firstname[NAME_SIZE];
	int country;
	int next_by_name;
	int next_by_country;
public:
	//char* lastname = new char[value];
	char* get_lastname(void);
	char* get_firstname(void);
	int get_country(void);
	int get_next_by_name(void);
	int get_next_by_country(void);
	//void set_lastname(char* r);
	void print();
};
#endif