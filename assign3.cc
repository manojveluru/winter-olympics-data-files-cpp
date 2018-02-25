#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
const int value1 = 4;
const int value2 = 34;
class Country
{
	char country_code[value1];
	char country_fullname[value2];
public:
	char* get_country_code(void);
	char* get_country_fullname(void);
	void print();
};
char* Country :: get_country_code(void)
{
	return country_code;
}
char* Country :: get_country_fullname(void)
{
	return country_fullname;
}
void Country :: print()
{
	cout<<get_country_code()<<" "<<get_country_fullname()<<endl;
}
int main()
{
	int c,d;
	ifstream inp;
	inp.open("olympic.dat",ios::binary);
	vector<Country> countries;
	Country country;
	inp.read((char*) &c ,sizeof(c));
	cout<<c;
	for(int i=0;i<c;i++)
	{
		inp.read((char *)&country,sizeof(country));
		countries.push_back(country);
	}
	cout<<endl<<countries.size();
	for(unsigned int i=0;i<countries.size();i++){
		countries[i].print();
	}
	inp.read((char*) &d, sizeof(d));
	return 0;
}


