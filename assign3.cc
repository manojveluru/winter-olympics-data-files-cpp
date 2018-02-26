#include"Athelete.h"
#include"Country.h"
#include"Sport.h"
#include"Event.h"
#include"header.h"

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
	for(int i=0;i<c;i++)
	{
		inp.read((char *)&country,sizeof(country));
		countries.push_back(country);
	}
	
	inp.read((char*) &d, sizeof(d));
	for(int i=0;i<d;i++)
	{
		inp.read((char *)&sport,sizeof(sport));
		sports.push_back(sport);
	}
	
	inp.read((char*) &e, sizeof(e));
	for(int i=0;i<e;i++)
	{
		inp.read((char *)&athelete,sizeof(athelete));
		atheletes.push_back(athelete);
	}
	
	inp.read((char*) &f, sizeof(f));
	for(int i=0;i<f;i++)
	{
		inp.read((char *)&event,sizeof(event));
		events.push_back(event);
	}
	
	while(menu != 'Q' && menu != 'q')
	{
		cout<<"Menu:"<<endl;
		cout<<"1) Print countries"<<endl<<"2) Print sports"<<endl<<"3) Print athletes by name"<<endl<<"4) Print athletes by country"<<endl<<"5) Print ranking by sport"<<endl<<"Q)uit"<<endl;
		cout<<"Choice? ";
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

