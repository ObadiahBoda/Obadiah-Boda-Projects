// Obadiah Boda LEC a
#include <cstdlib>


template<typename T>
MyBSTree<T>::MyBSTree()
{
    m_root = NULL;
}

template<typename T>
MyBSTree<T>::~MyBSTree()
{
    clear(m_root);
}

template<typename T>
MyBSTree<T>::MyBSTree(const MyBSTree& rhs)
{
    m_root = cpy(rhs.m_root);
}

template <typename T>
Node<T>* MyBSTree<T>::cpy(const Node <T> *t) const
{
    if(t == NULL) return NULL;
    else
    {
        return new Node<T>(cpy(t-> m_left), cpy(t -> m_right), t -> m_data);
    }
}



template<typename T>
int MyBSTree<T>::size() const
{
    return (size(m_root));
}

template<typename T>
int MyBSTree<T>::size(Node<T>* t) const
{
    if (t == NULL) return 0;

    return(1 + size(t-> m_right) + size(t -> m_left));
}

template <typename T>
bool MyBSTree<T>::isEmpty() const
{
    if(m_root == NULL) return true;

    return false;
}

template<typename T>
int MyBSTree<T>::height() const
{
    return height(m_root);
}

template <typename T>
int MyBSTree<T>::height(const Node<T>* t) const
{
    if(t == NULL) return 0;

    int l = height(t ->m_left);
    int r = height(t ->m_right);

    if(l > r) return(l+1);

    else return(r+1);
}


template<typename T>
const T& MyBSTree<T>::getMax()const throw (Oops)
{
    return getMax(m_root);
}

template<typename T>
const T& MyBSTree<T>::getMax(const Node<T>* t) const throw (Oops)
{
    if(m_root == NULL) throw Oops("OOPS! : Tree is Empty!!");

    else
    {
        if(t-> m_right != NULL) return getMax(t-> m_right);

        else return t-> m_data;
    }
}

template<typename T>
const T& MyBSTree<T>::getMin() const throw (Oops)
{
    return getMin(m_root);
}

template<typename T>
const T& MyBSTree<T>::getMin(const Node<T>* t) const throw (Oops)
{
    if(t == NULL) throw Oops("OOPS! : Tree is Empty!!");

    else
    {
        if(t-> m_left != NULL) return getMin(t->m_left);

        else return t-> m_data;
    }
}

template <typename T>
int MyBSTree<T>::find(const T& x) const
{
    return find(x, m_root);
}

template <typename T>
int MyBSTree<T>::findT(const T& x, const Node<T>* t) const
{
    if(t==NULL) return (-1);

    if(t->m_data == x) return 1;

    if(x < t->m_data) return  findT(x, t->m_left);

    else return  findT(x, t->m_right);
}

template <typename T>
int MyBSTree<T>::find(const T& x, const Node<T>* t) const
{
    int k =0;
    if(t==NULL) return (1);

    if(t->m_data == x) return 1;

    if(x < t->m_data) k+= 1 + abs(find(x, t->m_left));

    else k+= 1 + abs(find(x, t->m_right));

    if(findT(x, t) == -1) return -k;

    return k;
}


template <typename T>
void MyBSTree<T>::clear()
{
    clear(m_root);
}

template <typename T>
void MyBSTree<T>::clear(Node<T>*& t)
{
    if(t != NULL)
    {
        clear(t->m_right);
        clear(t->m_left);

        delete t;
    }
    t = NULL;
}

template<typename T>
void MyBSTree<T>::insert(const T& x)
{
    insert(m_root, x);
}

template<typename T>
void MyBSTree<T>::insert(Node<T>*& t, const T& x)
{
    if(t == NULL)
    {
        t = new Node<T>;
        t->m_data = x;
        t->m_right = NULL;
        t->m_left = NULL;
    }

    else
    {
        if(x < t->m_data) insert(t->m_left, x);

        else if(x > t -> m_data) insert(t-> m_right, x);

        else return;
    }
}

template<typename T>
void MyBSTree<T>::remove(const T& x)
{
    remove(x, m_root);
}

template<typename T>
void MyBSTree<T>::remove(const T& x, Node<T>*& t)
{
    if(t == NULL) return;
    if(x <t->m_data) remove(x, t-> m_left);
    else if(x > t -> m_data) remove(x,t-> m_right);
    else
    {
        if(t-> m_left != NULL && t -> m_right != NULL)
        {
            t-> m_data = getMax(t -> m_left);
            remove(t -> m_data, t -> m_left);
        }

        else
        {
            Node<T> *child = t;
            t = t-> m_left;
            if(t == NULL)
            {
                t = child ->m_right;
            }
            delete child;
        }
    }
}


template <typename T>
void MyBSTree<T>::printPreOrder() const
{
  printPreOrder(m_root);
}

template <typename T>
void MyBSTree<T>::printPreOrder(const Node<T>* t) const
{
  cout<<t -> m_data<< " ";

  if(t -> m_left != NULL) printPreOrder(t -> m_left);

  if(t -> m_right != NULL) printPreOrder(t -> m_right);

}

template <typename T>
void MyBSTree<T>::printPostOrder() const
{
  printPostOrder(m_root);
}

template <typename T>
void MyBSTree<T>::printPostOrder(const Node<T>* t) const
{
  if(t -> m_left != NULL) printPostOrder(t -> m_left);


  if(t -> m_right != NULL) printPostOrder(t -> m_right);

  cout<<t -> m_data<< " ";
}


template <typename T>
void MyBSTree<T>::print() const
{
  int pad = 0;
  prettyPrint (m_root, pad);
}

template <typename T>
void MyBSTree<T>::prettyPrint(const Node<T> *t, int pad) const
{
  string s(pad, ' ');

  if(t == NULL)
  {
    cout<<"\n";;
  }

  else
  {
    prettyPrint(t -> m_right, pad + 4);

    cout<<s<<t -> m_data << endl;

    prettyPrint(t -> m_left, pad + 4);
  }
}

template <typename T>
const MyBSTree<T> & MyBSTree<T>::operator = ( const MyBSTree & rhs )
{
  if(this != &rhs)
  {
    clear();

    m_root = cpy(rhs.m_root);
  }

  return *this;
}


