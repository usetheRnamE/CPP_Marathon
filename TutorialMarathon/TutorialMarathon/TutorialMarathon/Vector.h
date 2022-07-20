#pragma once

template<typename Vector>
class VectorIterator
{
public:
	using  ValueType = typename Vector::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;

public:
	VectorIterator(PointerType ptr) : Ptr(ptr) {}

	VectorIterator& operator++()
	{
		Ptr++;
		return *this;
	}


	VectorIterator& operator++(int) // postfix operator
	{
		VectorIterator it = *this;
		++(*this);
		return it;
	}

	VectorIterator& operator--()
	{
		Ptr--;
		return *this;
	}

	VectorIterator& operator--(int) // postfix operator
	{
		VectorIterator it = *this;
		--(*this);
		return it;
	}

	ReferenceType operator[](int index)
	{
		return *(Ptr[index]);
	}

	PointerType operator->()
	{
		return Ptr;
	}

	ReferenceType operator*()
	{
		return *Ptr;
	}

	bool operator==(const VectorIterator& other) const
	{
		return Ptr == other.Ptr;
	}

	bool operator!=(const VectorIterator& other) const
	{
		return !(*this == other);
	}
private:
	PointerType Ptr;
};

template<typename T>
class Vector
{
public:
	using ValueType = T;
	using Iterator = VectorIterator<Vector<T>>;
public:
	Vector()
	{
		ReAlloc(2);
	}

	~Vector()
	{
		::operator delete(Data, Campacity * sizeof(T));
	}

	void PushBack(const T& value)
	{
		if (Size >= Campacity)
			ReAlloc(Campacity + Campacity / 2);

		Data[Size] = value;
		Size++;
	}

	void PushBack(T&& value)
	{
		if (Size >= Campacity)
			ReAlloc(Campacity + Campacity / 2);

		Data[Size] = std::move(value);
		Size++;
	}

	template<typename... Args> //variatic template
	T& EmplaceBack(Args&&... args)
	{
		if (Size >= Campacity)
			ReAlloc(Campacity + Campacity / 2);

		new(&Data[Size]) T(std::forward<Args>(args)...); // doen`t provide MoveDestroy action

		//Data[Size] = T(std::forward<Args>(args)...); provides Move/Destroy action

		return Data[Size++];
	}

	void PopBack()
	{
		if (Size > 0)
		{
			Size--;
			Data[Size].~T();
		}
	}

	void Clear()
	{
		for (size_t i = 0; i < Size; i++)
			Data[i].~T();

		Size = 0;
	}

	const T& operator[](size_t index) const
	{
		return Data[index];
	}

	T& operator[](size_t index)
	{
		return Data[index];
	}

	size_t GetSize() const { return Size; }

	VectorIterator begin()
	{
		return VectorIterator(Data);
	}

	VectorIterator end()
	{
		return VectorIterator(Data + Size);
	}

private:
	void ReAlloc(size_t newCampacity)
	{
		//T* newBlock = new T[newCampacity]; // allocate a new block of memory (calls a constructor)

		T* newBlock = (T*)::operator new(newCampacity * sizeof(T)); //does not call an constructor

		if (newCampacity < Size)
			Size = newCampacity;

		for (size_t i = 0; i < Size; i++)
			Data[i].~T();

		for (size_t i = 0; i < Size; i++) // move old elements into a new block
			newBlock[i] = std::move(Data[i]);

		//delete[] Data; calls an destructor thus we delete already deleted obj

		::operator delete(Data, Campacity * sizeof(T)); //does not call an destructor

		Data = newBlock;
		Campacity = newCampacity;
	}

private:
	T* Data = nullptr;

	size_t Size = 0;
	size_t Campacity = 0;
};