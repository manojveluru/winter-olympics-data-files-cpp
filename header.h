#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<vector>
#include<cstring>
#include<fstream>
#include<cstdlib>
void print_athletes_by_country(vector<Athelete>& , vector<Country>&);
void print_athletes_by_name(vector<Athelete>& , vector<Country>& );
void print_ranking_by_sport(int , const vector<Sport>& , const vector<Event>& , const vector<Athelete>& , const vector<Country>& );
void print_countries(vector<Country>& countries);
void print_sports(vector<Sport>& sports);
#endif
