#include <iostream>

template <typename T>

class MyVector {
	T* data = nullptr;
	size_t capacity;
	size_t size;

	void copyFrom(const MyVector<T>& other);
	void free();
	void moveFrom(MyVector<T>&& other);

	void resize(size_t newCapacity);

public:

	MyVector();
	MyVector(size_t n);
	MyVector(size_t n, const T& elem);
	MyVector(const MyVector<T>& other);
	MyVector(MyVector<T>&& other) noexcept;
	MyVector<T>& operator=(const MyVector<T>& other);
	MyVector<T>& operator=(MyVector<T>&& other) noexcept;
	~MyVector();


	void push_back(const T& elem);
	void push_back(T&& elem);
	
	void pop_back();

	void insert(size_t idx, const T& elem);
	void insert(size_t idx, T&& elem);

	void erase(size_t idx);
	
	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;

	void shrink_to_fit();

	void clear();

	const T& front() const;
	T& front();

	const T& back() const;
	T& back();

	bool empty() const;

	size_t getSize() const;
	size_t getCapacity() const;

	template <typename T>
	friend std::ostream& operator<<(std::ostream& os, const MyVector<T>& myvector);

};

template<typename T>
inline void MyVector<T>::copyFrom(const MyVector<T>& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new T[capacity];

	for (int i = 0; i < size; i++) {
		data = other.data;
	}
}

template<typename T>
inline void MyVector<T>::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
	capacity = 0;
}

template<typename T>
inline void MyVector<T>::moveFrom(MyVector<T>&& other)
{	
	size = other.size;
	capacity = other.capacity;

	data = other.data;

	other.data = nullptr;
	other.size = other.capacity = 0;
}

template<typename T>
inline void MyVector<T>::resize(size_t newCapacity)
{

	T* newData = new T[newCapacity];

	for (int i = 0; i < size; i++) {
		newData = data;
	}

	delete[] data;

	capacity = newCapacity;
	data = newData;

}

template<typename T>
inline MyVector<T>::MyVector()
{
	size = 0;
	capacity = 8;
	data = new T[capacity];
}

template<typename T>
inline MyVector<T>::MyVector(size_t n)
{
	size = n;
	capacity = n;
	data = new T[capacity];
}

template<typename T>
inline MyVector<T>::MyVector(size_t n, const T& elem)
{
	MyVector<T>::MyVector(n);
	for (int i = 0; i < size; i++) {
		data[i] = elem;
	}
}

template<typename T>
inline MyVector<T>::MyVector(const MyVector<T>& other)
{
	copyFrom(other);
}

template<typename T>
inline MyVector<T>::MyVector(MyVector<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
inline MyVector<T>& MyVector<T>::operator=(MyVector<T>&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
inline MyVector<T>::~MyVector()
{
	free();
}

template<typename T>
inline void MyVector<T>::push_back(const T& elem)
{
	if (size >= capacity)
		resize(capacity * 2);

	data[size++] = elem;
}

template<typename T>
inline void MyVector<T>::push_back(T&& elem)
{
	if (size >= capacity)
		resize(capacity * 2);

	data[size++] = std::move(elem);
}

template<typename T>
inline void MyVector<T>::pop_back()
{
	size--;
}

template<typename T>
inline void MyVector<T>::insert(size_t idx, const T& elem)
{
	if (size >= capacity)
		resize(capacity * 2);

	for (int i = size; i > idx; i--) {
		data[i] = data[i - 1];
	}
	data[idx] = elem;
}

template<typename T>
inline void MyVector<T>::insert(size_t idx, T&& elem)
{
	if (size >= capacity)
		resize(capacity * 2);

	for (int i = size; i > idx; i--) {
		data[i] = std::move(data[i - 1]);
	}
	data[idx] = std::move(elem);
}

template<typename T>
inline void MyVector<T>::erase(size_t idx)
{
	if (idx > size)
		throw std::invalid_argument("Index must be below size...");

	for (int i = idx; i < size - 2; i++) {
		data[i] = data[i + 1];
	}
	size--;
}

template<typename T>
inline T& MyVector<T>::operator[](size_t idx)
{
	if (idx > size)
		throw std::invalid_argument("Index must be below size...");

	return data[idx];
}

template<typename T>
inline const T& MyVector<T>::operator[](size_t idx) const
{
	if (idx > size)
		throw std::invalid_argument("Index must be below size...");

	return data[idx];
}

template<typename T>
inline void MyVector<T>::shrink_to_fit()
{
	T* newData = new T[size];

	for (int i = 0; i < size; i++) {
		newData[i] = data[i];
	}

	capacity = size;
	data = newData;
}

template<typename T>
inline void MyVector<T>::clear()
{
	size_t curr = capacity;
	free();

	capacity = curr;
	size = 0;
	data = new T[capacity];
}

template<typename T>
inline const T& MyVector<T>::front() const
{
	return data[0];
}

template<typename T>
inline T& MyVector<T>::front()
{
	return data[0];
}

template<typename T>
inline const T& MyVector<T>::back() const
{
	return data[size - 1];
}

template<typename T>
inline T& MyVector<T>::back()
{
	return data[size - 1];
}

template<typename T>
inline bool MyVector<T>::empty() const
{
	return size == 0;
}

template<typename T>
inline size_t MyVector<T>::getSize() const
{
	return size;
}

template<typename T>
inline size_t MyVector<T>::getCapacity() const
{
	return capacity;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const MyVector<T>& myvector){
	
	for (int i = 0; i < myvector.size; i++) {
		os << myvector.data[i] << " ";
	}
	
	return os;
}
