#include"Athelete.h"
#include"Country.h"
#include"Sport.h"
#include"Event.h"
#include<iomanip>
char* Athelete :: get_lastname(void)
{
	return lastname;
}
/*void Athelete :: set_lastname(char* r)
{
	lastname = r;
}*/
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
	cout<<countryObj.get_country_code()<<" ";
	cout<<setfill(' ') << setw(3) << numerical_ranking<<" "<<score<<" ";
	for(int i=0;i<ATHELETE_SIZE;i++){
		if(athelete[i] != -1){
			Athelete curr_athelete = athelets[athelete[i]];
			cout<<curr_athelete.get_lastname()<<", "<<curr_athelete.get_firstname()<<"; ";
		}
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
		if(choice <= j && choice >0)
		{	
			return choice;
		}
		cout<<"Invalid choice"<<endl;
		cin.clear();
		cin.ignore(10000, '\n');
	}
	
}
















