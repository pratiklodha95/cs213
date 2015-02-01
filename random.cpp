#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ofstream out ("exit", ios::out);

	time_t t;
	srand(time(&t));
	int number;
	cout <<"enter the number of input";
	cin >>number;
	for(int i=0;i<number;i++)
	{
		int num= (rand()%9000)+1000;
		
		char letter[]={(char)(65+rand()%26),(char)(65+rand()%26)};
		out<<letter[0]<<letter[1]<<num<<endl;
	}
		
	return 0;
}
