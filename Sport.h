#ifndef SPORT_H
#define SPORT_H
#include<iostream>
#include<vector>
using namespace std;
const int SPORT_NAME_SIZE = 60;
class Sport
{
	char sport_name[SPORT_NAME_SIZE]="CRICKET";
	int index_of_an_event;
	
public:
	char* get_sport_name(void);
	int get_index_of_an_event(void);
	void print();
};
#endif