#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class list { 
	class node { 
	public:
	 string nameplate;
	 int entry_count;
	 int exit_count;
	 node * next;
 	};
 	public:  node * head;
 	list()
 	{
 		entry_count=exit_count=head=0;
 	}

 	//fint the position of the list , with the same nameplate , and update the entry and exit count as required
 	list find (string value)
 	{
 		if(head==0)
 		{
 			return 0;
 		}
 		else
 		{
 			node * pointer=head;
 			while(pointer!=NULL)
 			{
 				if(pointer->nameplate==value)
 				{
 					return pointer;
 				}
 				pointer=pointer->next;

 			}
 		}
 	}

 	//insert a new list , at the start if there is no previous entry found
 	list insert (string value)
    { 
      node * p = new node;
      if ( p == 0 ) 
      {cerr << "no space" << endl; exit (1);}
      p->nameplate = value;
      p->next = head; 
      return (*this);
    }
 };

int main()
{
	string nameplate;
	
	return 0;
}
