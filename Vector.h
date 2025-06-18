#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <iostream>

//---------------------------------------------------------------------------------

/**

  \class Vector Template
  \brief

  \author Josie Lim
  \version 1.0
  \date 26/02/24

  \version 2.0
  \date 29/02/24
  \brief

   */

//---------------------------------------------------------------------------------


using std::cerr;
using std::endl;

const unsigned INITIAL_SIZE = 5;

template <class T>
class Vector
{
private:
    T *m_array;     // pointer to array on the heap
    unsigned m_size;     // number of elements in the vector
    unsigned m_capacity;     // size of array on the heap


public:
    /**
    \brief Default constructor for Vector class.
    */
    Vector();

    /**
    \brief Copy constructor for Vector class.

    \param other The Vector object to copy.
    */
    Vector(const Vector<T>& other);     // copy constructor

    /**
    \brief Destructor for Vector class.
    */
    ~Vector();

    /**
    \brief Retrieve the size of the vector.

    \return The size of the vector.
    */
    unsigned GetSize() const;

    /**
    \brief Retrieve the capacity of the vector.

    \return The capacity of the vector.
    */
    unsigned GetCapacity() const;

    /**
    \brief Add an item to the vector.

    \param item The item to be added.
    \return True if the addition is successful, false otherwise.
    */
    bool Add(const T& item);

    /**
    \brief Remove the last item from the vector.
    */
    void RemoveLast();

    /**
    \brief Insert an item at a specified index.

    \param index The index where the item should be inserted.
    \param item The item to be inserted.
    */
    void InsertAt(unsigned index, const T& item);

    /**
    \brief Remove an item at a specified index.

    \param index The index of the item to be removed.
    */
    void RemoveAt(unsigned index);

    /**
    \brief Retrieve an item at a specified index.

    \param index The index of the item to be retrieved.
    \return The retrieved item.
    */
    T& RetrieveAt(unsigned index) const;

    /**
    \brief Replace an item at a specified index.

    \param index The index of the item to be replaced.
    \param item The item to replace the existing one.
    */
    void ReplaceAt(unsigned index, const T& item);

    /**
    \brief Check if the vector is empty.

    \return True if the vector is empty, false otherwise.
    */
    bool IsEmpty() const;

    /**
    \brief Copy the content of another vector.

    \param other The vector to copy.
    */
    void Copy(const Vector<T>& other);

    /**
    \brief Clear the vector (remove all elements).
    */
    void Clear();

    /**
    \brief Resize the vector when needed.
    */
    void Resize();

    /**
    \brief Overloaded [] operator for accessing elements by index.

    \param index The index of the element to access.
    \return The reference to the accessed element.
    */
    T& operator[](unsigned index);

    /**
    \brief Overloaded [] operator for accessing elements by index (const version).

    \param index The index of the element to access.
    \return The constant reference to the accessed element.
    */
    const T& operator[](unsigned index) const;

    /**
    \brief Overloaded assignment operator.

    \param other The vector to assign.
    \return The reference to the assigned vector.
    */
    const Vector<T>& operator=(const Vector<T>& other);
};

//.......................................................................................................//

/// class implementation ///
template <class T>
Vector<T>::Vector()
    : m_array(new T[INITIAL_SIZE]), m_size(0)
{
    if (m_array != nullptr)
    {
        m_capacity = INITIAL_SIZE;
    }
}

template <class T>
Vector<T>::Vector(const Vector& other)
{
    Copy(other);
}

template <class T>
Vector<T>::~Vector()
{
    if (m_array != nullptr)
    {
        delete[] m_array;
        m_array = nullptr;
    }
}

template <class T>
unsigned Vector<T>::GetSize() const
{
    return m_size;
}

template <class T>
unsigned Vector<T>::GetCapacity() const
{
    return m_capacity;
}

template <class T>
bool Vector<T>::Add(const T& item)
{
    if (m_size > m_capacity / 2)
    {
        Resize();
    }
    if (m_size != m_capacity)
    {
        m_array[m_size] = item;
        m_size++;
        return true;
    }
    return false;
}

template <class T>
void Vector<T>::RemoveLast()
{
    if (m_size > 0)
    {
        m_size--;
    }
    else
    {
        cerr << "Error: Vector is empty, remove from the back unsuccessful.";
    }
}

template <class T>
void Vector<T>::InsertAt(unsigned index, const T& item)
{
    if (index < 0 && index >= m_size)
    {
        cerr << "Error: Invalid index number." << endl;
    }

    if (m_size == m_capacity)
    {
        Resize();
    }

    for (int i = m_size; i > index; i--)
    {
        m_array[i] = m_array[i - 1];
    }

    m_array[index] = item;
    m_size++;
}

template <class T>
void Vector<T>::RemoveAt(unsigned index)
{
    if (index < 0 && index >= m_size)
    {
        cerr << "Error: Invalid index number." << endl;
    }

    for (int i = index; i < m_size - 1; i++)
    {
        m_array[i] = m_array[i + 1];
    }
    m_size--;
}

template <class T>
T& Vector<T>::RetrieveAt(unsigned index) const
{
    if (index >= 0 || index < m_size-1)
    {
        return m_array[index];
    }
    else
    {
        cerr << "Error: Invalid index number." << endl;
    }

}
template <class T>
void Vector<T>:: ReplaceAt(unsigned index, const T& item)
{
    if (index >=0 && index < m_size)
    {
        m_array[index] = item;
    }
    else
    {
        cerr << "Error: Invalid index number." << endl;
    }
}

template <class T>
bool Vector<T>::IsEmpty() const
{
    return m_size == 0;
}

template <class T>
void Vector<T>::Copy(const Vector &other)
{
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_array = new T[m_capacity];

    if (m_array != nullptr)
    {
        for (unsigned i = 0; i < m_size; i++)
        {
            m_array[i] = other.m_array[i];
        }
    }
}

template <class T>
void Vector<T>::Clear()
{
    m_size = 0;
}

template <class T>
void Vector<T>::Resize()
{
    int newCapacity = m_capacity *2;
    T *newArray = new T[newCapacity];

    for (int i = 0; i < m_size; i++)
    {
        newArray[i] = m_array[i];
    }

    m_capacity = newCapacity;
    delete[] m_array;

    m_array = newArray;
}

template <class T>
T& Vector<T>::operator[](unsigned index)
{
    if (index > 0 || index < m_size-1)
    {
        return m_array[index];
    }
    else
    {
        cerr << "Invalid index number." << '\n';
    }
}

template <class T>
const T& Vector<T>::operator[](unsigned index) const
{
    if (index > 0 || index < m_size-1)
    {
        return m_array[index];
    }
    else
    {
        cerr << "Invalid index number." << '\n';
    }
}

template <class T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if (this != &other)
    {
        delete[] m_array;       // delete existing memory
        Copy(other);
    }
    return *this;
}

#endif // VECTOR_H_INCLUDED
