//Obadiah Boda section A
#ifndef QUEUELIST_HPP_INCLUDED
#define QUEUELIST_HPP_INCLUDED

#include "abstactqueue.h"

#include <iostream>
using namespace std;


template <class T>
class LLNode
{
public:
  T m_data;              // Data to be stored
  LLNode<T>* m_next;     // Pointer to the next element in the list
  string name;
  int eaten;

  // Purpose: Default constructor
  // Postconditions: next pointer set to NULL
  // ---INLINE---
  LLNode() : m_next(NULL) {}

  // Purpose: Auxiliaty constructor, construct from parameters
  // Postconditions: data and next pointer set to parameters
  // ---INLINE---
  LLNode(const T& x, LLNode<T>* p)
             : m_data(x), m_next(p) {}


};


template <typename T>
class Qlist : public AbstractQueue<T>
{
public:
  LLNode<T>* m_head;     // Pointer to the first element
  LLNode<T>* m_back;     // Pointer to the last element
  int m_size;
  int global_eaten;

  int small;
  int large;
  string small_name;
  string large_name;

  Qlist()
  {
    m_size = 0;
    m_head = NULL;
    m_back = NULL;
  }


  ~Qlist()
  {
    LLNode<T>* p = this->m_head;
    LLNode<T>* temp = p;
    m_head = NULL;
    m_back = NULL;
    while(p != NULL)
    {
        p = p->m_next;
        delete temp;
        temp = p;
    }
     delete p;
     m_size = 0;
  }

  // Purpose: performs a deep copy of tthrow Oops("error front");he data from rhs into this linkedlist
  // Parameters: rhs is linked list to be copied
  // Returns: *this
  // Postconditions: this list contains same data values (in the same order)
  //     as are in rhs; any memory previously used by this list has been
  //     deallocated.

  const Qlist<T>&  operator= (const Qlist<T>& rhs)
  {

    m_size = rhs.m_size;
    LLNode<T>* p = rhs.m_head;
    if(m_size == 0)
    {
        m_head = NULL;
        m_back = NULL;
        return *this;
    }
    else{
        m_head = new LLNode<T>(p->m_data,NULL);
        LLNode<T>* temp = m_head;
        while(p->m_next != NULL)
        {
            p = p->m_next;
            temp->m_next = new LLNode<T>(p->m_data,NULL);
            temp = temp->m_next;
        }
        m_back = temp;
        return *this;
    }
  }

  // Purpose: copy constructor
  // Parameters: rhs is the LinkedList that is to be copied
  // Postconditions: this list contains same data values (in same order)
  //      as in rhs.

  Qlist(const Qlist<T>& rhs)
  {
      *this = rhs;
  }


  void set_name(string n)
  {
      m_head->name = n;
  }

    string get_name()
    {
        return m_back->name;
    }


  // -------------
  // --------- Basic Accessor Operations ---
  // -------------

  // Purpose: accessor function to the size the list
  // Returns: current size of the list

  int size() const
  {
    return this->m_size;
  }

  // Purpose: determines whether the list is empty
  // Returns: 'true' if list is empty; 'false' otherwise

  virtual bool isEmpty() const
  {
      if(m_head == NULL)
      {
          return true;
      }
    return false;
  }

  // Purpose: Get a pointer to the first element node
  // Returns: pointer to the first node in the list;
  //     returns NULL if the list is empty


  LLNode<T>* getFirstPtr()
  {
      if(m_size == 0)
      {
          return NULL;
      }
return this->m_head;
  }

  // Purpose: Get a pointer to constant to the first element node
  // Returns: pointer to constant to the first node in the list;
  //     returns NULL if the list is empty

  const LLNode<T>* getFirstPtr() const
  {
   if(m_size == 0)
      {
          return NULL;
      }
return this->m_head;
  }

  // Purpose: accessor function for last element node
  // Returns: pointer to the last element's node in the list;
  //     returns NULL if list is empty

  LLNode<T>* getLastPtr() const
  {
   if(m_size == 0)
      {
          return NULL;
      }
return this->m_back;
  }


  void clear()
  {
    LLNode<T>* p = this->m_head;
    LLNode<T>* temp = p;
    m_head = NULL;
    m_back = NULL;
    while(p != NULL)
    {
        p = p->m_next;
        delete temp;
        temp = p;
    }
     delete p;
     m_size = 0;


  }



  void insert_front(const T& x)
  {
    LLNode<T>* p = this->m_head;
    m_head = new LLNode<T>(x,p);
    if(m_size == 0)
    {
        m_back = m_head;
    }
    m_size++;
  }



  void remove_back()
  {
    delete m_back;
    LLNode<T>* p = this->m_head;
    for(int k = 2; k < m_size; k++)
    {
        p = p->m_next;
    }
    m_back = p;
    p->m_next = NULL;
    m_size--;
    if (m_size == 0 )
    {
        m_head = NULL;
    }
  }



  // Purpose: looks at the front of the queue
  // Returns: a reference to the element currently in front of the queue
  // Exception: if the queue is empty, THROW a 'Oops' object with an error
  //   message!!!
	virtual const T& front() const throw (Oops)
	{
    try
    {
        if (isEmpty() == true) throw Oops("error msg");


        return getLastPtr()->m_data;
    }

       catch(Oops)
        {

            cout << "No elements in queue. (front)" <<endl;
        }
	}


  // Purpose: looks at the back of the queue
  // Returns: a reference to the element currently in the back of the queue
  // Exception: if the queue is empty, THROW a 'Oops' object with an error
  //   message!!!
	virtual const T& back() const throw (Oops)
	{
        try
    {
        if (isEmpty() == true) throw Oops("msg");


        return getFirstPtr()->m_data;
    }

       catch(Oops)
        {
            cout << "No elements in queue. (back)"<<endl;
        }

	}


  // Purpose: enqueue an element into the queue
  // Parameters: x is the item to add to the queue
  // Postconditions: x is now the element at the end of the queue,
	virtual void enqueue(const T& x)
	{
        insert_front(x);
        m_head->eaten = 0;
	}


  // Purpose: dequeues
  // Postconditions: the element formerly at the front of the queue has
  //     been removed.
  // Note: Dequeueing an empty queue results in an empty queue.
	virtual void dequeue()
	{
	    if(isEmpty() == 1)
        {
            return;
        }
        remove_back();
	}

    void requeue()
    {
    LLNode<T>* p = this->m_head;

        for(int k = 2; k < m_size; k++)
            {
                p = p->m_next;
            }

    m_back->m_next = m_head;
    m_head = m_back;

    m_back = p;
    p->m_next = NULL;

    }

    void run()
    {
        if( m_size > 0 )
        {
           small = m_back-> m_data + 5;
           large = m_back-> m_data - 5;
        }

        global_eaten = 0;
        randomEngine re;
        while (m_size > 0)
            {
         m_back->eaten +=  ((m_back->m_data-1 )/5)*5 +5;
         global_eaten +=  ((m_back->m_data-1 )/5)*5 +5;

         if(m_back->eaten > large)
         {
             large = m_back->eaten;
             large_name = m_back->name;
         }

         if(m_back->eaten < small)
         {
             small = m_back->eaten;
             small_name = m_back->name;
         }

        int a;

         a = re.rollD(6);


         cout << get_name() << " eats " << ((m_back->m_data-1 )/5)*5 +5 << " popplers. ";

         if(a == 6 )
        {
            cout << get_name() << " wants one more poppler!" <<endl;
            m_back->m_data = 1;
            requeue();
        }
        else
        {
            cout << get_name() << " is satisfied after eating " << ((m_back->m_data-1 )/5)*5 +5 << " popplers."<<endl;
            dequeue();
        }

        }

        cout <<endl << "A total of "<< global_eaten << " popplers were eaten." <<endl;
        cout << large_name << " ate the most popplers: " << large <<endl;
        cout << small_name << " ate the fewest popplers: " << small <<endl;

    }

};


template <typename T>
std::ostream& operator<< (std::ostream& out, const Qlist<T>& list)
{
    const  LLNode<T>* p = list.getFirstPtr();

    if(p == NULL)
     {
         out << "[ ]";
         return out;
     }


    out << "[";

    while (p->m_next != NULL)
    {
        out << p->m_data << ", ";
        p = p->m_next;
    }
    out <<p->m_data << ", ]";
    return out;
}



#endif // QUEUELIST_HPP_INCLUDED
