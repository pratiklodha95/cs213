// This design continues the evolution of a linked list class.
// The improvements over listclass1.C include :
// 1. use of operator- to delete the first occurence of a given element

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

    class list { 
        class node { public:
	     int val;
	     node * next;
             };
    public : node * head;
	    list() { head = 0;} // constructor
            
	    bool isempty ()
            { if ( head == 0 ) return true;
              else return false; }

  	    int length ()
            { node * p = head;
              int count = 0;
              while ( p != 0 ) { count ++; p = p->next; };
              return count;
            }

            list operator+ ( int elm )
            { node * p = new node;
            if ( p == 0 ) 
               cerr << " fatal error : no space on heap "
                    << endl;
               p->val = elm;
               p->next = head; // connects new node to list
               head = p;
               return *this;
            }

            list  operator+ ( list l)
            { list res;
              int val;
              node * curr = head; node * tail = res.head;
              if ( curr == 0 ) return res = l;
              else { 
	         while ( curr != 0 ) { 
                    res = res & curr->val;
		    if ( tail != 0 ) tail = tail->next; 
                    else tail = res.head;
                    curr = curr->next; };
                 tail->next = l.head;
              };
              return res;
             }
 
	    list operator&(int elm )
            { // find the last node of list
              node * p = new node;
              p->val = elm; p->next = 0;
              if ( head == 0 ) head = p;
              else { node * curr = head; node * prev = head;
	             while ( curr != 0 ) 
                     { prev = curr; curr = curr->next; };
                     prev->next = p;
              };
              return *this;
             }
           
	    list operator- (int elm )
            { // remove the first node containing elm as data value from the list  
              node * curr, *prev;
              curr = prev = head;
              if (head == 0) 
              { cout << " Empty list - delete not possible \n"; return *this;}
              while ( curr != 0 ) 
              { if (curr->val != elm) {prev = curr; curr = curr->next;}
                else break;
              };
              if (curr == 0) { cout << elm << " not found - can't delete \n"; return *this;}
              // checking for curr with 0 is crucial because otherwise it gives seg fault
              // when doing any part of the following if-then-else
              if (curr == prev) head = curr->next;
              else
                 prev->next = curr->next;
              return *this;
            }

 
	  void operator= ( node* p)
	    { head = p; return ;}
	    
	  friend ostream & operator<< (ostream &x, list l)
            { node * p = l.head;
              if (l.length() == 0) x << " Empty list " << endl;
              else
              for ( int i = 1 ; i <= l.length(); i++ )
	      { x << " element no " << i << " is = " 
	       << p->val << endl; p = p->next;
              };
          return x;
          }
	  
    };

    int main()
    {   int num;
	list l,m ;
        ifstream in("delinp", ios::in);
	while ( cin >> num) 
        { l = l & num;
          m = m + num;
        }
	cout << " length of list l = " << l.length() << endl;
	cout << " display of list l follows \n" << l << endl;
        cout << " length of list m = " << m.length() << endl;
	cout << " display of list m follows \n" << m << endl;
        while (in >> num) 
        { cout << " Trying to delete : " << num << endl;
          m = m-num; 
	  cout << " m after deletion of " << num << " follows : \n" << m << endl;
        }
        in.close();
 	list merge1;
        merge1 = l + l;
        cout << merge1.length() << endl;
        cout << " display merged list l + m \n" << merge1 << endl;
        in.open("delinp");
        while (in >> num) 
        { cout << " Trying to delete : " << num << endl;
          merge1 = merge1-num; 
	  cout << " m after deletion of " << num << " follows : \n" << merge1 << endl;
        }
        in.close();
    }
