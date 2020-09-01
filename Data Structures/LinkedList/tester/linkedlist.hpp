//Obadiah Boda section a

#ifndef LINKEDLIST_HPP_INCLUDED
#define LINKEDLIST_HPP_INCLUDED

#include <iostream>
using namespace std;

  // Purpose: Default constructor
  // Postconditions: this list represents the empty list
  template <class T>
  LinkedList<T>::LinkedList()
  {
    m_size = 0;
    m_head = NULL;
    m_back = NULL;
  }


  // -------------
  // --------- Big 3 Member Functions ---
  // -------------

  // Purpose: Destructor
  template <class T>
  LinkedList<T>::~LinkedList()
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

  // Purpose: performs a deep copy of the data from rhs into this linkedlist
  // Parameters: rhs is linked list to be copied
  // Returns: *this
  // Postconditions: this list contains same data values (in the same order)
  //     as are in rhs; any memory previously used by this list has been
  //     deallocated.
  template <class T>
  const LinkedList<T>&  LinkedList<T>::operator= (const LinkedList<T>& rhs)
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
  template <class T>
  LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
  {
      *this = rhs;
  }



  // -------------
  // --------- Basic Accessor Operations ---
  // -------------

  // Purpose: accessor function to the size the list
  // Returns: current size of the list
  template <class T>
  int LinkedList<T>::size() const
  {
    return this->m_size;
  }

  // Purpose: determines whether the list is empty
  // Returns: 'true' if list is empty; 'false' otherwise
  template <class T>
  bool LinkedList<T>::isEmpty() const
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
  template <class T>
  LLNode<T>* LinkedList<T>::getFirstPtr()
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
  template <class T>
  const LLNode<T>* LinkedList<T>::getFirstPtr() const
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
  template <class T>
  LLNode<T>* LinkedList<T>::getLastPtr()
  {
   if(m_size == 0)
      {
          return NULL;
      }
return this->m_back;
  }

  // Purpose: accessor function for a node in the list
  // Returns: pointer to the node at the i'th position in the list;
  //          counting starts from '0' .
  //     returns NULL if no such element exists.
  template <class T>
  LLNode<T>* LinkedList<T>::getAtPtr(int i)
  {
      if(i > m_size)
      {
          return NULL;
      }
      LLNode<T>* temp = this->m_head;
for(int k = 0; k < i ; k++)
{
    temp = temp->m_next;
}
    return temp;
  }



  // -------------
  // --------- Basic Mutator Operations ---
  // -------------

  // Purpose: effectively "empties" the list,
  //          Turn the list into an empty list.
  // Postconditions: ALL dynamically allocated memory for elements is
  //.                deallocated
  template <class T>
  void LinkedList<T>::clear()
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

  // Purpose: insert element x in the front of the list
  // Parameters: x is data value to inserted
  // Postconditions: x is the first element of the list
  template <class T>
  void LinkedList<T>::insert_front(const T& x)
  {
    LLNode<T>* p = this->m_head;
    m_head = new LLNode<T>(x,p);
    if(m_size == 0)
    {
        m_back = m_head;
    }
    m_size++;
  }

  // Purpose: insert element x in the back of the list
  // Parameters: x is data value to inserted
  // Postconditions: x is the last element of the list
  template <class T>
  void LinkedList<T>::insert_back(const T& x)
  {
    LLNode<T>* p = this->m_back;
    m_back = new LLNode<T>(x,NULL);
    if(p == NULL)
    {
        m_head = m_back;
    }
    else{
       p->m_next = m_back;
    }
    m_size++;
  }

  // Purpose: puts the data value x at the position pointed by pos
  // Parameters: x is data value to inserted
  //     pos pointer to the position to insert x at.
  // Preconditions: pos is a pointer to a node in this list.
  // Postconditions: x is inserted at the position pointed by pos
  template <class T>
  void LinkedList<T>::insert(const T& x, LLNode<T>* pos)
  {
    LLNode<T>* q = new LLNode<T>;
    q->m_data = pos->m_data;
    q->m_next = pos->m_next;
    pos->m_data = x;
    pos->m_next = q;
    m_size++;
  }


  // Purpose: remove the element in the front of the list
  // Postconditions: the first element of the list is removed
  template <class T>
  void LinkedList<T>::remove_front()
  {
    LLNode<T>* p = this->m_head;
    m_head = m_head->m_next;
    delete p;
    m_size--;
  }

  // Purpose: removes the element at the back of the list
  // Postconditions: the last element of the list is removed
  template <class T>
  void LinkedList<T>::remove_back()
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
  }

  // Purpose: remove the element in the position pointed by pos
  // Parameters: pos pointer to the position to remove.
  // Preconditions: pos is a pointer to a node in this list.
  // Postconditions: element pointed by pos is removed from the list
  template <class T>
  void LinkedList<T>::remove(LLNode<T>* pos)
  {
    if(pos->m_next == NULL)
    {
        remove_back();
    }
    else{
         pos->m_data = pos->m_next->m_data;
    LLNode<T>* q = pos->m_next;
    pos->m_next = q->m_next;
    delete q;
    m_size--;

    }
  }


  // --------
  // ---- Complex Operations ---
  // --------

  // Purpose: determines whether this list is identical to rhs list in
  // terms of data values and their order in the list
  // Parameters: rhs is list to be compared to this list
  // Returns: true if lists are identical; otherwise, false
  template <class T>
  bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
  {
    if(m_size != rhs.m_size )
    {
        return false;
    }
    if(m_size == 0)
    {
        return true;
    }
    LLNode<T>* p = rhs.m_head;
    LLNode<T>* temp = m_head;
    while(p != NULL)
    {
        if(temp->m_data != p->m_data)
        {
            return false;
        }
        p = p->m_next;
        temp = temp->m_next;
    }
    return true;
  }

  // Purpose: determines whether x is in the list
  // Parameters: x is data value to be found
  // Returns: a pointer to the position of x in the list;
  //     otherwise, NULL
  template <class T>
  LLNode<T>* LinkedList<T>::find(const T& x)
  {
    if(m_size == 0)
    {
        return NULL;
    }
    LLNode<T>* p = m_head;
    while(p != NULL)
    {
        if(x == p->m_data)
        {
            return p;
        }
        p = p->m_next;
    }
  return NULL;
  }

  // Purpose: reverses the elements from the list
  // Postconditions: the list is now in reverse order
  template <class T>
  void LinkedList<T>::reverse()
  {
    LLNode<T>* p = m_head;
    LLNode<T>* q = m_head;
    LLNode<T>* temp = new LLNode<T>(p->m_data,NULL);

    while(p->m_next != NULL)
    {
        p = p->m_next;
        temp = new LLNode<T>(p->m_data,temp);

    }
    m_head = temp;
    p = m_head;
    while(p->m_next != NULL)
    {
        p = p->m_next;
    }
    m_back = p;

    //delete
    temp = q;
    while(q != NULL)
    {
        q = q->m_next;
        delete temp;
        temp = q;
    }
  }

  // Purpose: appends two lists
  // Parameters: xlist, a list to append to the end of 'this' list
  // Postconditions: elements of xlist are appended to 'this' list
  template <class T>
  void LinkedList<T>::append(const LinkedList<T>& xlist)
  {
      LLNode<T>* p = xlist.m_head;
      LLNode<T>* temp = m_back;
      while (p != NULL)
      {
         temp->m_next = new LLNode<T>(p->m_data, NULL);
         p = p->m_next;
         temp = temp->m_next;
      }

    m_back = p;
    m_size += xlist.m_size;
  }

  // Purpose: removes a section of a lists
  // Parameters:    start pointer to the begining of the section to remove.
  //                end pointer to the end of the section to remove.
  // Preconditions: start and end are pointers to nodes in this list.
  //                start precedes end in this list.
  // Postconditions: elements between start and end (inclusive) are removed
  //                 from the list.
  template <class T>
  void LinkedList<T>::clip(LLNode<T>* start, LLNode<T>* stop)
  {
    LLNode<T>* p = start->m_next;
    LLNode<T>* temp = p;
    int k = 2;
    while (p != stop)
    {
     p = p->m_next;
     delete temp;
     temp = p;
     k++;
    }
    start->m_data = p->m_next->m_data;
    start->m_next = p->m_next->m_next;
    delete p->m_next;
    delete p;

    m_size-= k;

  }

  // Purpose: Makes this list a slice of another list.
  // Parameters:    xlist, the source of a slice of data.
  //                start pointer to the begining of the slice.
  //                end pointer to the end of the slice.
  // Preconditions: start and end are pointers to nodes in the 'xlist' list.
  //                start precedes end in this list
  // Postconditions: 'this' list is made a copy of the elements between start
  //                  and end in xlist.
  template <class T>
  void LinkedList<T>::slice( const LinkedList<T>& xlist, LLNode<T>* start, LLNode<T>* stop)
  {
    LLNode<T>* temp = new LLNode<T>(start->m_data, NULL);
    LLNode<T>* q = temp;
    LLNode<T>* p = start;
    int k =1;
    while(p != stop)
    {
        p = p->m_next;
        temp->m_next = new LLNode<T>(p->m_data,NULL);
        temp = temp->m_next;
        k++;
    }
    m_back = temp;
    m_head = q;
    m_size = k;
  }




// ---------------  Utility Function for Printing
// Purpose: prints a LinkedList

template <typename T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list)
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

#endif // LINKEDLIST_HPP_INCLUDED




