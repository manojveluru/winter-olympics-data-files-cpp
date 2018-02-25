#include"Athelete.h"
#include"Country.h"
#include"Sport.h"
#include"Event.h"
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
	cout<<lastname<<", "<<firstname<<endl;
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

void Event :: print(vector<Athelete>&, vector<Country>&)
{
	
}

