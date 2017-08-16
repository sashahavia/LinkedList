// *****************************************************/
// Aliaksandra Havia                  
// Assignment 3
// LINKED LISTS
/********************************************************/

#include<iostream>
#include<fstream>
using namespace std;

struct node {
	double quantity;
	double price;
	node *next;
	node *prev;
};

// functions headers 
bool isEmpty(node *head);
void insertAsFirstElement(node *&head, node *&last, double quantity, double price, node *&temp);
void insert(node *&head, node *&last, double quantity, double price, node *&temp);
void remove(node *&head, node *newTemp);

// Functions 
bool isEmpty(node *head){
	if (head == NULL){
		return true;
	} else {
		return false;
	}
}

void insertAsFirstElement(node *&head, node *&last, node *&prev, double quantity, double price, node *&temp){
	temp -> quantity = quantity;
	temp -> price = price;
	temp -> next = NULL;
	temp -> prev = NULL;
	head = temp;
	last = temp;
}

void insert(node *&head, node *&last, double quantity, double price, node *&temp){
	if ( isEmpty(head) ){
		insertAsFirstElement(head, last, quantity, price, temp);
	} else {
		temp -> quantity = quantity;
		temp -> price = price;
		temp -> next = NULL;
		temp -> prev = last;
		last -> next = temp;
		last = temp;
	}
}

void remove(node *&head, node *newTemp){
	if( isEmpty()){
		cout << "The list is already empty.\n";
	} else if (head == last) {
		delete head;
		head == NULL;
		last == NULL;
	} else {

	}
}

int main(){
	ifstream input("data.txt");

	if(input.is_open()){
		// cout << "File is open" << endl;
		char type;
		double tempQuantity, tempPrice, total = 0;
		int discount;
		bool promotion = true;
		node *head = NULL;
		node *last = NULL;
		node *temp;

		while( !input.eof()){
			input >> type;

			if( type == 'S'){
				input >> tempQuantity;
				cout << tempQuantity << " Widgets sold" << endl;

				if ( tempQuantity > total ){
					cout << "remainder of " << tempQuantity - total << " Widgets not available" << endl;
					
				} else {

				}

			} else if ( type == 'R') {
				input >> tempQuantity >> tempPrice;
				total += tempQuantity;
				temp = new node();
				insert(head, last, tempQuantity, tempPrice, temp);
				cout << "This n " << temp -> quantity << " " << temp -> price << endl;
				cout << "Total " << total << endl;
				
			} else if ( type == 'P') {
				input >> discount;
				cout << "Discount " << discount << "%" << endl;
			} else {
				cout << "Invalid Type" << endl;
			}
		}
	} else {
		cout << "File not found";
	}
	return 0;
}

