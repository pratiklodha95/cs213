   // This template class design is created by generalizing
   // the linked list design of list0.C 
   // 

    using namespace std;
    #include <iostream>
    #include <fstream>
    #include <string>

    template <class T>
    class list { 
       class node { public :
	     T val;
	     node * next;
             };
      public : node * head;
	    list() { head = 0;} // constructor
            
	    bool isempty ()
            { if ( head == 0 ) return true; else return false; } 

  	    int length ()
            { node * p = head;
              int count = 0;
              while ( p != 0 ) { count ++; p = p->next; };
              return count;
            }

            list insert (T elm )
            { node * p = new node;
              p->val = elm;
              p->next = head; // connects the new node to old list
              head = p;
              return (*this);
            }
           
	    list append (T elm )
            { // find the last node of list
              node * p = new node;
              p->val = elm; p->next = 0;
              if ( head == 0 ) head = p;
              else { node * curr = head; node * prev = head;
	         while ( curr != 0 ) {
		    prev = curr; curr = curr->next; };
                 prev->next = p;
              };
              return (*this);
             }
            
	    void display ( )
             { node * p = head;
               for ( int i = 1 ; i <= this->length(); i++ )
	        { cout << " element no " << i << " is = " 
		       << p->val << endl; p = p->next;
                };
             }
    };

    int main()
      {  int num;
	 list<int> l;
	 while ( cin >> num) l=l.insert(num);
	 cout << " No of list elements in l = " << l.length() << endl;
         l.display();	
         ifstream in ( "strfile", ios::in);
	 string c;
	 list<string> m;
	 while ( in >> c) m=m.append(c);
	 cout << " No of list elements in m = " << m.length() << endl;
         m.display();	
     }
