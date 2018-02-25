#include"Athelete.h"
#include"Country.h"
#include"Sport.h"
#include"Event.h"
#include<cstdlib>
#include<vector>
#include<fstream>

void print_athletes_by_country(vector<Athelete>& , vector<Country>&);
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
		//atheletes[i].print();
		cout<<atheletes[i].get_next_by_country()<<endl;
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
	print_athletes_by_country(atheletes, countries);
	return 0;
}

void print_athletes_by_country(vector<Athelete>& atheletes, vector<Country>& countries)
{
	cout<<endl;
	int count=1;
	/*for(int i=0;i<atheletes.size();i++)
	{
		cout<<atheletes[i].get_next_by_country()<<" "<<atheletes[i].get_lastname()<<" "<<atheletes[i].get_country()<<endl;
	}*/
	for(int i=0;i<atheletes.size();i++)
	{
		
		
		int n = atheletes[i].get_country();
		count=1;
		for(int j=atheletes.size()-1;j>i;j--)
		{
			int k = atheletes[j].get_country();
			if( n == k){count++;}
		}
		
		//cout<<countries[i].get_country_code()<<" "<<atheletes[i].get_country()<<endl;
		/*int limit = atheletes.size() - 1;
        while(i < limit  && atheletes[i].get_country() == atheletes[i+1].get_country())
		{
			count++;
			i++;
		}*/
		
		
		
		     
			//cout<<n<<" "<<"count: "<<count<<endl;
			cout<<atheletes[i].get_next_by_country()<<" "<<atheletes[i].get_country()<<" "<<atheletes[i].get_lastname()<<endl;
		
		
	}
	cout<<endl;
}

