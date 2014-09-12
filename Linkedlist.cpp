
#include <iostream>
#include <cstdlib>
using namespace std;
#ifndef Null
	#define Null 0
#endif


class Node
{
	public:
		int data;
		Node *link;
};

class LList
{
	public:
		LList (){};
		~LList();
		void create();
		void display();
		Node* getNode();
		void append(Node* NewNode);
		void insert(Node *NewNode, int pos);
		void rtraverse();
		void deleteNode(int deletePos);
	private:
		Node *Head, *Tail;
		void recursiveTraverse (Node *tmp)
		{
			if (tmp == Null)
			{
				return;
			}
			cout << tmp->data << "\t";
			recursiveTraverse (tmp->link);
		}
};

LList :: ~LList ()
{
	Node *Temp;
	while (Head != Null)
	{
		Temp = Head;
		Head = Head->link;
		delete Temp;
	}
}

void LList :: create ()
{
	char ans;
	Node *NewNode;
	while (1)
	{
		cout << "Any more nodes to be added (Y/N):";
		cin >> ans;
		if (ans == 'n' || ans == 'N')
		{
			break;
		}
		NewNode = getNode ();
		append(NewNode);
	}
}

void LList :: append(Node* NewNode)
{
	if (Head == Null)
	{
		Head = NewNode;
		Tail = NewNode;
	}
	else
	{
		Tail->link = NewNode;
		Tail = NewNode;
	}
}

Node* LList :: getNode()
{
	Node *Newnode;
	Newnode =  new Node;
	cin >> Newnode->data;
	Newnode->link = Null;
	return (Newnode);
}

void LList :: display()
{
	Node *temp = Head;
	if (temp == Null)
	{
		cout << "Empty List";
	}
	else
	{
		while(temp != Null)
		{
			cout << temp->data << "\t";
			temp = temp->link;
		}
	}
	cout << endl;
}

int main()
{
	LList L1;
	L1.create();
	L1.display();

	return 0;
}
