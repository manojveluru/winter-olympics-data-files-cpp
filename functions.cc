#include"Athelete.h"
#include"Country.h"
#include"Sport.h"
#include"Event.h"
#include"header.h"
char* Athelete :: get_lastname(void)
{
	return lastname;
}
char* Athelete :: get_firstname(void)
{
	return firstname;
}
int Athelete :: get_country(void)
{
	return country;
}
int Athelete :: get_next_by_name(void)
{
	return next_by_name;
}
int Athelete :: get_next_by_country(void)
{
	return next_by_country;
}
void Athelete :: print()
{
	cout<<lastname<<", "<<firstname<<" "<<endl;
}

char* Country :: get_country_code(void)
{
	return country_code;;
}
char* Country :: get_country_fullname(void)
{
	return country_fullname;
}
void Country :: print()
{
	cout<<get_country_code()<<" "<<get_country_fullname()<<endl;
}

char* Sport :: get_sport_name(void)
{
	return sport_name;
}
int Sport :: get_index_of_an_event(void)
{
	return index_of_an_event;
}
void Sport :: print()
{
	cout<<sport_name<<endl;
}

int Event :: get_index_of_next_event(void)
{
	return index_of_next_event;
}

void Event :: print(const vector<Athelete>& athelets, const vector<Country>& countries)
{
	Country countryObj = countries[country];
	cout<<setw(3)<<countryObj.get_country_code()<<" ";
	cout<<setfill(' ') << setw(3) << numerical_ranking<<" "<<setw(3)<<score<<" ";
	for(int i=0;i<ATHELETE_SIZE;i++){
		if(athelete[i] != -1){
			Athelete curr_athelete = athelets[athelete[i]];
			cout<<curr_athelete.get_lastname()<<", "<<curr_athelete.get_firstname()<<"; ";
		}
	}
	cout<<endl;
	
}

void print_countries(vector<Country>& countries)
{
	cout<<endl;
	for(unsigned int i=0;i<countries.size();i++){
		countries[i].print();
	}
	cout<<endl;
}

void print_sports(vector<Sport>& sports)
{
	cout<<endl;
	for(unsigned int i=0;i<sports.size();i++){
		sports[i].print();
	}
	cout<<endl;
}

void print_athletes_by_country(vector<Athelete>& atheletes, vector<Country>& countries)
{
	cout<<endl;
	int x =  atheletes[0].get_next_by_country();
	int i=0;
	int athSize =atheletes.size();
	while(i<athSize)
	{
		
		if(x>athSize || x<0){break;}
		int n = atheletes[x].get_country();
		char* ccode = countries[n].get_country_code();
		char* ath_lname=atheletes[x].get_lastname();
		char* ath_fname = atheletes[x].get_firstname();
		if (strlen(ccode)>0 && strlen(ath_lname)>0 && strlen(ath_fname)>0){
		cout<<ccode<<" "<<ath_lname<<", "<<ath_fname<<endl;
			
		}
		x = atheletes[x].get_next_by_country();
		i++;
		
	}
	cout<<endl;
}

void print_athletes_by_name(vector<Athelete>& atheletes, vector<Country>& countries)
{
	cout<<endl;
	int x =  atheletes[0].get_next_by_name();
	int i=0;
	int athSize = atheletes.size();
	while(i<athSize)
	{
		
		if(x>athSize || x<0){break;}
		int n = atheletes[x].get_country();
		char* ccode = countries[n].get_country_code();
		char* ath_lname=atheletes[x].get_lastname();
		char* ath_fname = atheletes[x].get_firstname();
		if (strlen(ccode)>0 && strlen(ath_lname)>0 && strlen(ath_fname)>0){
			cout<<ath_lname<<", "<<ath_fname<<" "<<ccode<<endl;
		}
		x = atheletes[x].get_next_by_name();
		i++;
		
	}
	cout<<endl;
}


int select_sport(vector<Sport>& sports, int value)
{
	int j=1,choice;
	for(int i=0;i<value;i++)
	{
		cout<<j<<")"<<" "<<sports[i].get_sport_name()<<endl;
		j++;
	}
	while(1){
		cout<<"Select Sport: ";
		cin>>choice;
		if(choice < j && choice >0)
		{	
			return choice;
		}
		cout<<"Invalid choice"<<endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	
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














