// Obadiah Boda section a

#ifndef ARRAYLIST_HPP_INCLUDED
#define ARRAYLIST_HPP_INCLUDED

#include <iostream>


using namespace std;

template <typename T>
 void ArrayList<T>::grow()
 {
     if(m_max == 0)
     {
         m_max = 1;
     }
 m_max = 2*m_max;
 T* temp = new T[m_max];

 for(int k = 0; k < m_size; k++)
 {
     temp[k] = m_data[k];
 }
 delete [] m_data;
 m_data = temp;
 }

 template <typename T>
 void ArrayList<T>::shrink()
 {
     if(m_max > 0)
     {
m_max = m_max/2;
T* temp = new T[m_max];

for(int k = 0; k < m_size; k++)
{
    temp[k] = m_data[k];
}
 delete [] m_data;
m_data = temp;
     }
 }

 template <typename T>
 ArrayList<T>::ArrayList(int s, const T& x)     //s coppies of x
 {
    m_max = s*2;
    m_size = s;
    m_data = new T[m_max];

    for(int k = 0; k < s; k++)
    {
        m_data[k] = x;
    }

 }

 template <typename T>
 ArrayList<T>::~ArrayList()
 {
     m_size = 0;
     m_max = 0;
    delete[] m_data;
    m_data = NULL;
 }

 template <typename T>
 ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)     //full copy
 {
    //this = rhs
    m_max = rhs.m_max;
    m_size = rhs.m_size;

    m_data = new T[rhs.m_max];

    for(int k = 0; k < m_size; k++)
    {
        m_data[k] = rhs.m_data[k];
    }

return *this;
 }

 template <typename T>
 ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
 {
*this = cpy;
 }

 template <typename T>
 int ArrayList<T>::size() const
 {
return m_size;
 }

 template <typename T>
const T& ArrayList<T>::first() const
{
if(m_data == NULL )
{
    cout << "!-- ERROR : PANIC in ARRAYLIST.first()!!  (List is empty)" << endl;
    return m_errobj;
}
return m_data[0];
}

template <typename T>
T& ArrayList<T>::operator[](int i)
{
    if(i > m_size)
    {
        cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]  (index out of bounds)" << endl;
        return m_errobj;
    }
return m_data[i];
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const
{
return m_data[i];
}

template <typename T>
int ArrayList<T>::find(const T& x) const
{
    T k;
    int l = 0;
while ((x != k) && (l < m_size))
{
    k = m_data[l];


    l++;
}
if (k == x)
{
    return l - 1;
}
return -1;
}

template <typename T>
void ArrayList<T>::clear()
{
m_size = 0;
m_max = 0;
delete [] m_data;
m_data = NULL;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
if(m_size >= m_max)
{
    grow();
}
    m_data[m_size] = x;
    m_size++;
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
    if(m_size+1 < i)
    {
        cout << "!-- ERROR : PANIC in ARRAYLIST!!.insert()  (index out of bounds)" << endl;
    return;         //throw out of bounds message "!-- ERROR : PANIC in ARRAYLIST!!.insert()  (index out of bounds)"
    }


if(m_size >= m_max)
{
    grow();
}
    for(int k = m_size ; k > i; k--)
    {
        m_data[k]=m_data[k-1];
    }
    m_data[i] = x;
    m_size++;
}

template <typename T>
void ArrayList<T>::remove(int i)
{
if (i > m_size)
{
    cout << "!-- ERROR : PANIC in ARRAYLIST!!.remove()  (index out of bounds)" <<endl;
    return; //throw error message "!-- ERROR : PANIC in ARRAYLIST!!.remove()  (index out of bounds)"
}

if (m_size <= m_max/4)
{
    shrink();
}

if(m_size > 0)
{
    for(int k = i; k < m_size -1 ;k++)
    {
        m_data[k] = m_data[k+1];
    }
    m_size--;
}

}

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
    if((i > m_size) || (k > m_size) )
    {
        cout << "!-- ERROR : PANIC in ARRAYLIST!!.swap()  (index out of bounds)" << endl;
        return; // throw error message "!-- ERROR : PANIC in ARRAYLIST!!.swap()  (index out of bounds)"
    }

T temp;
temp = m_data[i];
m_data[i] = m_data[k];
m_data[k] = temp;
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
int temp = m_size;
m_size += alist.m_size;
if(m_size > m_max)
{
    grow();
}

int l= 0;
for(int k = temp; k < m_size; k++)
{
    m_data[k] = alist.m_data[l];
    l++;
}
}

template <typename T>
void ArrayList<T>::reverse()
{
  for(int k = 0; k < m_size/2; k++)
  {
      swap(k,m_size -1 - k);

  }
}



#endif // ARRAYLIST_HPP_INCLUDED
