   // In this design of a linked list class  
   // data elements are of type int  
  using namespace std;
  #include <iostream>
  #include <stdlib.h>
  class list {// definition of node is not to be visible outside
    class node { public:
	     int val;
	     node * next;
    };
    public :
    node * head;     // data member
    // member functions 

    list() { head = 0;} // constructor
            
    bool isempty ()
    { if ( head == 0 ) return true;  else return false; }

    int length ()
    { node * p = head;
      int count = 0;
      while ( p != 0 ) { count ++; p = p->next;};
      return count;
    }

    list insert ( int elm )
    { node * p = new node;
      if ( p == 0 ) 
      {cerr << "fatal error : no space on heap" << endl; exit (1);}
      p->val = elm;
      p->next = head; // connects new node to old list
      head = p;
      return (*this);
    }
         
    list append (int elm )
    { // find the last node of list
      node * p = new node;
      if ( p == 0 ) 
      {cerr << "fatal error : no space on heap" << endl; exit (1);}
      p->val = elm; p->next = 0;
      if ( head == 0 ) head = p;
      else 
      { node * curr = head; node * prev = head;
	while ( curr != 0 ) 
        { prev = curr; curr = curr->next; };
          prev->next = p;
      };
      return (*this);
    }

    void display ()
    { node * p = head;
      for ( int i = 1 ; i <= this->length(); i++ )
      { cout << " element no " << i << " is = " 
	     << p->val << endl; p = p->next;
      };
     }
   };

   int main()
   {  int num;
      list l,m ;
      while ( cin >> num) 
      { l = l.append(num);
        m = m.insert(num);
      }
      cout << " length of list l = " << l.length() << endl;
      l.display();
      cout << " length of list m = " << m.length() << endl;
      m.display();
   }
