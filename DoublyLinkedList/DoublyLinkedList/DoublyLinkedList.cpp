/*
* Title: Doubly Linked List
* Author: Edgar Podvezko
* Date: 2020
* Software: Visual Studio 2019
*/

/*
	Title: Doubly Linked List
	Author: Podvezko Edgar
	Date: 202
	Software: Visual Studio 2017
*/


#include <iostream>



class Node
{
public:
	int value;
	Node* next;
	Node* prev;
	Node(int val) {
		this->value = val;
		std::cout << "Node constructor! -> " << this->value << std::endl;
		this->next = (Node*)0;
		this->prev = (Node*)0;
	}
	~Node() {
		std::cout << "Node destructor" << std::endl;
		std::cout << "I had the value " << this->value << std::endl;
	}
};
class List
{

public:
	Node* head;
	Node* tail;

	List() {
		std::cout << "List Constructor!" << std::endl;
		this->head = 0;
		this->tail = 0;
	}
	~List() {
		std::cout << "List Destructor!" << std::endl;
	}
	void insert(Node* n, Node* x) {
		if (n != 0) {
			x->next = n->next;
			n->next = x;
			x->prev = n;
			if (x->next != 0)
				x->next->prev = x;
		}
		if (this->head == 0) {
			this->head = x;
			this->tail = x;
			x->prev = 0;
			x->next = 0;
		}
		else if (this->tail == n) {
			this->tail = x;
		}
	}


	/* Delete Node */
	void andDelete(Node* x) {

		if (x->prev != 0)
			x->prev->next = x->next;
		else
			this->head = x->next;
		if (x->next != 0)
			x->next->prev = x->prev;
		else
			this->tail = x->prev;

	}
	/* Find Node (by value) */
	void toFind(Node* head, int x) {
		std::cout << "Finding the node..." << std::endl;
		Node* current = head;
		std::cout << "Current is: " << current->value << std::endl;
		while (current != NULL) {
			if (current->value == x) {
				std::cout << "Found!" << std::endl;
				andDelete(current);
				return;
			}
			current = current->next;
			std::cout << "Current now is: " << current->value << std::endl;
		}
		std::cout << "Not Found :(" << std::endl;
	}

	/* Find Node (by position) */
	void findByAddress(Node* head, int x) {
		Node* current = head;
		for (int i = 0; i < x; i++) {
			current = current->next;
		}
		andDelete(current);
	}


	/* Find middle Node */
	void getMiddle(struct Node* head)
	{
		struct Node* to_mid = head; // it's purpose is to go to the middle
		struct Node* to_end = head; // while this one goes to the end


		/* Until it reaches the end, to_mid will move to the next node while to_end will move +2 */
		if (head != NULL)
		{
			while (to_end != NULL && to_end->next != NULL)
			{
				to_end = to_end->next->next;
				to_mid = to_mid->next;
			}
			printf("The middle element is [%d]\n\n", to_mid->value);
		}
	}

	/* Display DLL */
	void display() {
		Node* i = this->head;
		std::cout << std::endl << "List: ";
		while (i != 0) {
			std::cout << i->value << " ";
			i = i->next;
		}

		std::cout << std::endl << std::endl;

		/*std::cout << std::endl;
		i = this->head;
		while (i != 0) {
			std::cout << &i->value << ",";
			i = i->next;
		}
		std::cout << std::endl; */
	}
};

int main(int argc, char* argv[])
{
	List* l = new List();
	l->insert(0, new Node(4));
	l->insert(l->head, new Node(6));
	l->insert(l->head, new Node(8));
	l->insert(l->head, new Node(9));
	l->insert(l->head, new Node(5));
	l->insert(l->head, new Node(3));
	l->insert(l->head, new Node(13));
	l->display();

	std::cout << "Deleting 3rd member; " << std::endl;

	/* It currently searches by the position, which is 2. Finding the specific one is commented and functions properly */
	l->findByAddress(l->head, 2);		// search by position
	//l->toFind(l->head, 13);			// delete specific value
	std::cout << "After deletion: ";
	l->display();

	l->getMiddle(l->head);				// Find the middle node

	delete l;
	return 0;
}