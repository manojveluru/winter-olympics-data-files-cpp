#include"Athelete.h"
#include"Country.h"
#include"Sport.h"
#include"Event.h"
#include<cstdlib>
#include<vector>
#include<fstream>
#include<cstring>
using namespace std;
void print_athletes_by_country(vector<Athelete>& , vector<Country>&);
void print_athletes_by_name(vector<Athelete>& , vector<Country>& );
void print_ranking_by_sport(int , const vector<Sport>& , const vector<Event>& , const vector<Athelete>& , const vector<Country>& );
void print_countries(vector<Country>& countries){
	for(unsigned int i=0;i<countries.size();i++){
		countries[i].print();
	}
	cout<<endl;
}
void print_sports(vector<Sport> sports)
{
	for(unsigned int i=0;i<sports.size();i++){
		sports[i].print();
	}
	cout<<endl;
}
int main()
{
	int c,d,e,f;
	string filename;
	ifstream inp;
	cout<<"Please Enter the file name to be opened: ";
	cin>>filename;
	inp.open(filename,ios::binary);
	if(inp.fail())
	{
		cerr<<"file not found";
		exit(1);
	}
	vector<Sport> sports;
	vector<Country> countries;
	vector<Athelete> atheletes;
	vector<Event> events;
	Country country;
	Sport sport;
	Athelete athelete;
	Event event;
	string choice;
	char menu;
	
	inp.read((char*) &c ,sizeof(c));
	//cout<<c;
	for(int i=0;i<c;i++)
	{
		inp.read((char *)&country,sizeof(country));
		countries.push_back(country);
	}
	
	
	/*for(unsigned int i=0;i<countries.size();i++){
		countries[i].print();
	}*/
	inp.read((char*) &d, sizeof(d));
	for(int i=0;i<d;i++)
	{
		inp.read((char *)&sport,sizeof(sport));
		sports.push_back(sport);
	}
	/*for(unsigned int i=0;i<sports.size();i++){
		sports[i].print();
	}*/
	inp.read((char*) &e, sizeof(e));
	for(int i=0;i<e;i++)
	{
		inp.read((char *)&athelete,sizeof(athelete));
		atheletes.push_back(athelete);
	}
	/*for(unsigned int i=0;i<atheletes.size();i++){
		atheletes[i].print();
		//cout<<atheletes[i].get_next_by_country()<<endl;
	//get_next_by_name(void);
	//get_next_by_country(void);
	}*/
	inp.read((char*) &f, sizeof(f));
	for(int i=0;i<f;i++)
	{
		inp.read((char *)&event,sizeof(event));
		events.push_back(event);
	}
	/*for(unsigned int i=0;i<events.size();i++){
		cout<<events[i].get_index_of_next_event()<<endl;
	}*/
	//print_athletes_by_country(atheletes, countries);
	//print_athletes_by_name(atheletes, countries);
	//int choice = select_sport(sports, sports.size());
	//print_ranking_by_sport(choice, sports, events, atheletes, countries);
	while(menu != 'Q' && menu != 'q')
	{
		cout<<"Menu:"<<endl;
		cout<<"1) Print countries"<<endl<<"2) Print sports"<<endl<<"3) Print athletes by name"<<endl<<"4) Print athletes by country"<<endl<<"5) Print ranking by sport"<<endl<<"Q)uit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		if (choice.length() != 1){
			cout<<endl<<"Invalid Choice"<<endl;
			continue;
		}
		menu = choice[0];
		switch(menu)
		{
		case '1':
			{
				print_countries(countries);
				break;
			}
		case '2':
			{
				print_sports(sports);
				break;
			}
		case '3':
			{
				print_athletes_by_name(atheletes, countries);
				break;
			}
		case '4':
			{
				print_athletes_by_country(atheletes, countries);
				break;
			}
		case '5':
			{
				int choice = select_sport(sports, sports.size());
				print_ranking_by_sport(choice, sports, events, atheletes, countries);
				break;
			}
		case 'q':
		case 'Q':
			{
				cout<<endl;
				break;
			}
		default:
			{
				cout<<endl<<"Invalid Choice"<<endl;
				break;
			}

		}
		cout<<endl;
	}
	return 0;
}

void print_athletes_by_country(vector<Athelete>& atheletes, vector<Country>& countries)
{
	cout<<endl;
	int count=1;
	int x =  atheletes[0].get_next_by_country();
	int i=0;
	int athSize =atheletes.size();
	while(i<athSize)
	{
		
		if(x>athSize || x<0){break;}
		int n = atheletes[x].get_country();
		x = atheletes[x].get_next_by_country();
		char* ccode = countries[n].get_country_code();
		char* ath_lname=atheletes[x].get_lastname();
		char* ath_fname = atheletes[x].get_firstname();
		if (strlen(ccode)>0 && strlen(ath_lname)>0 && strlen(ath_fname)>0){
			cout<<ccode<<" "<<ath_lname<<", "<<ath_fname<<endl;
		}
		i++;
		
	}
	cout<<endl;
}

void print_athletes_by_name(vector<Athelete>& atheletes, vector<Country>& countries)
{
	cout<<endl;
	int count=1;
	int x =  atheletes[0].get_next_by_name();
	int i=0;
	int athSize = atheletes.size();
	while(i<athSize)
	{
		
		if(x>athSize || x<0){break;}
		int n = atheletes[x].get_country();
		x = atheletes[x].get_next_by_name();
		char* ccode = countries[n].get_country_code();
		char* ath_lname=atheletes[x].get_lastname();
		char* ath_fname = atheletes[x].get_firstname();
		if (strlen(ccode)>0 && strlen(ath_lname)>0 && strlen(ath_fname)>0){
			cout<<ath_lname<<", "<<ath_fname<<" "<<ccode<<endl;
		}
		i++;
		
	}
	cout<<endl;
}

void print_ranking_by_sport(int choice, const vector<Sport>& sports, const vector<Event>& events, const vector<Athelete>& atheletes, const vector<Country>& countries)
{
	Sport chosen_sport = sports[choice-1];
	cout<<endl<<chosen_sport.get_sport_name()<<endl;
	int event_index = chosen_sport.get_index_of_an_event();
	while(event_index != -1){
		Event current_event = events[event_index];
		current_event.print(atheletes,countries);
		event_index = current_event.get_index_of_next_event();
	}
}