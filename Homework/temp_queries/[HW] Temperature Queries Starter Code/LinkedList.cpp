#include <iostream>
#include <string>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "TemperatureData.h"
#include "TemperatureDatabase.h"
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList():head(nullptr), tail(nullptr) {
	// Implement this function
}

LinkedList::~LinkedList() {
	delete head->next;
	delete tail->next;
	delete head;
	delete tail;
	// Implement this function
}

LinkedList::LinkedList(const LinkedList& source) {
	head = source.head;
	tail = source.tail;

}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	head = source.head;
	tail = source.tail;
	return *this;

}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function
}

void LinkedList::clear() {
	// Implement this function
}

Node* LinkedList::getHead() const {
	return head;

}

string LinkedList::print() const {
	string outputString;
	// Implement this function
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
