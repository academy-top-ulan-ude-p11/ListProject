#include <iostream>
#pragma once
class List
{
	struct Node
	{
		int value;
		Node* next;
		Node* prev;
	};

	Node* begin;
	Node* end;

	int size;

	Node* IndexPtr(int index);

public:
	List() : begin{ nullptr }, end{ nullptr }, size{ 0 } {}
	~List()
	{
		Node* nodeCurr{ begin };
		while (begin)
		{
			nodeCurr = nodeCurr->next;
			delete begin;
			begin = nodeCurr;
		}
	}

	int Size();
	int& At(int index);
	int& operator[](int index);

	friend std::ostream& operator<<(std::ostream& out, const List& list);
	void PushBegin(int value);
	void PushEnd(int value);
	void Insert(int index, int value);

	int PopBegin();
	int PopEnd();
	int Remove(int index);

	int Contain(int key);

	void Sort();

};

