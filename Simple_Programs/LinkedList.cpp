#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class LinkedList {
    private:
        Node* head;

    public:
        LinkedList();
        void push(int);
        void deleteNode(int);
        void printList();
        void sort();
        void swap(Node*, Node*);
        void reverseList();
        int getSize();
};

LinkedList::LinkedList() {
    head = NULL;
}

void LinkedList::push(int newData) {
    Node* newNode = new Node;
    Node* current = head;

    newNode->data = newData;

    if(head == NULL) {
        head = newNode;
        return;
    }

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void LinkedList::deleteNode(int val) {
    Node* ptr = head;

    if(head == NULL) return;

    if(head->data == val) {
        head = head->next;
        return;
    }

    while (ptr->next != NULL) {
        if(ptr->next->data == val) {
            ptr->next = ptr->next->next;
            return;
        }
        ptr = ptr->next;
    }
}

void LinkedList::printList() {
    Node* ptr = head;

    while (ptr != NULL) {
        cout<< ptr->data <<" ";
        ptr = ptr->next;
    }

}

void LinkedList::sort() {
    int swapped;
	Node *lPtr; // left pointer will always point to the start of the list
	Node *rPrt = NULL; // right pointer will always point to the end of the list
	
    do {	
		swapped = 0;
		lPtr = head;
		while(lPtr->next != rPrt) {
			if (lPtr->data > lPtr->next->data) 
			{
				swap(lPtr, lPtr->next); 
                swapped = 1; 
			}
			lPtr = lPtr->next;
		}
		//as the largest element is at the end of the list, assign that to rPtr as there is no need to
		//check already sorted list
		rPrt = lPtr;
	} while(swapped);
}

void LinkedList::swap (Node* a, Node* b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void LinkedList::reverseList() {
    Node* ptr = head;
    int tempArray[getSize()];
    int i = 0;

    while (ptr != NULL) {
        tempArray[i] = ptr->data;
        i++;
        ptr = ptr->next;
    }

    i = getSize() - 1;
    ptr = head;
    while (ptr != NULL) {
        ptr->data = tempArray[i];
        i--;
        ptr = ptr->next;
    }

}

int LinkedList::getSize() {
    Node* ptr = head;
    int size = 0;

    while (ptr != NULL) {
        size++;
        ptr = ptr->next;
    }

    return size;
}

int main() {
    LinkedList ls;
    
    ls.push(2);
    ls.push(1);
    ls.push(3);
    ls.push(6);
    ls.push(5);
    ls.push(4);
    ls.deleteNode(3);
    cout << "Initial: "; ls.printList(); cout << endl;
    ls.sort();
    cout << "Sorted: "; ls.printList(); cout << endl;
    ls.reverseList();
    cout << "Reversed: "; ls.printList(); cout << endl;
    cout << "Size: " << ls.getSize() << endl;
}