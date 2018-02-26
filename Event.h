#ifndef EVENT_H
#define EVENT_H
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
const int SCORE_SIZE = 25;
const int ATHELETE_SIZE = 4;
class Event
{
	int sport;
	int country;
	char score[SCORE_SIZE]; 
	int athelete[ATHELETE_SIZE];
	int numerical_ranking;
	int index_of_next_event;
	
public:
	int get_index_of_next_event(void);
	void print(const vector<Athelete>&, const vector<Country>&);
};
#endif