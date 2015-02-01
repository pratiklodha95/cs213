   // This template list class is obtained by generalizing the
   // list class definition developed in list3.C

    using namespace std;
    #include <iostream>
    #include <string>
    #include <fstream>

   template <class T>
   class list { 
     class node { public:
	     T val;
	     node * next;
             };
     public : node * head;
	    list<T>() { head = 0;} // constructor
            
	    bool isempty ()
            { if ( head == 0 ) return true;
              else return false; }

  	    int length ()
            { node * p = head;
              int count = 0;
              while ( p != 0 ) { count ++; p = p->next; };
              return count;
            }

            list<T> operator+ ( T elm )
            { node * p = new node;
            if ( p == 0 ) 
               cerr << " fatal error : no space on heap "
                    << endl;
               p->val = elm; p->next = 0; 
            // find the last node of list
              if ( head == 0 ) head = p;
              else { 
                 node * curr = head; node * prev = head;
	         while ( curr != 0 ) {
		    prev = curr; curr = curr->next; };
                 prev->next = p;
              };
              return (*this);
             }
             
           list<T> operator+ ( list<T> l)
            { 
            if ( head == 0 ) return l;
              else { 
                 node * curr = head; node * prev = head;
	         while ( curr != 0 ) {
		    prev = curr; curr = curr->next; };
                 prev->next = l.head;
              };
              return (*this);
             }
 
	  void operator= ( node* p)
	    { head = p; return ;}
	    
	  friend ostream & operator<< (ostream &x, list<T> l)
            { node * p = l.head;
              for ( int i = 1 ; i <= l.length(); i++ )
	      { x << " element no " << i << " is = " 
	       << p->val << endl; p = p->next;
              };
          return x;
          }
	  
    };


    int main()
    {   int num;
	list<int> l;
	while ( cin >> num) l = l + num;
	cout << " No of list elements in l = " << l.length() << endl;
        cout << " display of list l \n" << l << endl;
        ifstream in1 ( "strfile1", ios::in);
	string c;
	list<string> l2;
	while ( in1 >> c) l2 = l2 + c;
	cout << " No of list elements in l2 = " << l2.length() << endl;
        cout << " display of list l2 \n" << l2 << endl;
	// now create another string list to test list merge
        ifstream in2 ( "strfile2", ios::in);
        list<string> l3;
	while ( in2 >> c) l3 = l3 + c;
	cout << " No of list elements in l3 = " << l3.length() << endl;
        cout << " display of list l3 \n" << l3 << endl;
        list<string> l4;
        l4 = l2 + l3;
	cout << " No of list elements in l4 = " << l4.length() << endl;
        cout << " display of list l4 \n" << l4 << endl;
     }
