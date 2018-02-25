#ifndef COUNTRY_H
#define COUNTRY_H
#include<iostream>
using namespace std;
const int COUNTRY_CODE_SIZE = 4;
const int COUNTRY_NAME_SIZE = 34;
class Country
{
	char country_code[COUNTRY_CODE_SIZE];
	char country_fullname[COUNTRY_NAME_SIZE];
	public:
	char* get_country_code(void);
	char* get_country_fullname(void);
	void print();
};
#endif