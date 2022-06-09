#include <iostream>

using namespace std;

class LIST
{
private:
	class NODE
	{
	public:
		int data;
		NODE* pNext;
		NODE(int data, NODE* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int SIZE;
	NODE* head;
public:

	LIST()
	{
		head = nullptr;
		SIZE = 0;
	};

	~LIST()
	{
		int size = SIZE;
		for (int i = 0; i < size; i++)
		{
			pop_front();
		}
	}

	void push_back(int data);
	void pop_front();
	void print();
	void clear();
	void MAKENULL();
	void INSERT(int data, int index);
	void DELETE(int index);
	int LOCATE(int data);
	int RETRIEVE(int index);
	NODE* NEXT(int index);
	NODE* END();
	NODE* FIRST();
};

void LIST::push_back(int data)
{
	if (head == nullptr)
	{
		head = new NODE(data);
		SIZE++;
	}
	else
	{
		NODE* current = head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new NODE(data);
		SIZE++;
	}
}

void LIST::pop_front()
{
	if (head != nullptr)
	{
		NODE* temp = head;
		head = head->pNext;
		SIZE--;
		delete temp;
	}
}

void LIST::print()
{
	if (head != nullptr)
	{
		NODE* current = head;
		while (current != nullptr)
		{
			cout << current->data << " ";
			current = current->pNext;
		}
		cout << endl;
	}
}

void LIST::clear()
{
	for (int i = 0; i < SIZE; i++)
	{
		pop_front();
	}
}

void LIST::MAKENULL()
{
	head = nullptr;
	SIZE = 0;
}

void LIST::INSERT(int data, int index)
{
	if (index < SIZE && index >= 0)
	{
		int counter = 0;
		NODE* current = head;
		if (index != 0)
		{
			while (index - 1 != counter)
			{
				current = current->pNext;
				counter++;
			}
			NODE* buffer = current->pNext;
			current->pNext = new NODE(data);
			current = current->pNext;
			current->pNext = buffer;
		}
		else
		{
			head = new NODE(data);
			head->pNext = current;
		}
		SIZE++;
	}
	else if (index == SIZE)
	{
		push_back(data);
	}
}

void LIST::DELETE(int index)
{
	if (index < SIZE && index >= 0)
	{
		if (index != 0)
		{
			int counter = 0;
			NODE* current = head;
			while (index - 1 != counter)
			{
				current = current->pNext;
				counter++;
			}
			NODE* temp = current->pNext;
			current->pNext = temp->pNext;
			delete temp;
			SIZE--;
		}
		else
		{
			NODE* temp = head;
			head = head->pNext;
			delete temp;
			SIZE--;
		}
	}
}

int LIST::LOCATE(int data)
{
	NODE* current = head;
	int i = 0;
	while (current != nullptr)
	{
		if (current->data == data)
		{
			return i;
		}
		i++;
		current = current->pNext;
	}
	return -1;
}

int LIST::RETRIEVE(int index)
{

	if (index >= 0 && index < SIZE)
	{
		int counter = 0;
		NODE* current = head;
		while (index != counter)
		{
			current = current->pNext;
			counter++;
		}
		return current->data;
	}
	return -1;
}

LIST::NODE* LIST::NEXT(int index)
{
	if (index >= 0 && index < SIZE)
	{
		int counter = 0;
		NODE* current = head;
		while (index != counter && index < SIZE)
		{
			current = current->pNext;
			counter++;
		}
		return current->pNext;
	}
}
LIST::NODE* LIST::END()
{
	NODE* current = head;

	while (current->pNext != nullptr)
	{
		current = current->pNext;
	}
	return current;
}

LIST::NODE* LIST::FIRST()
{
	return head;
}

