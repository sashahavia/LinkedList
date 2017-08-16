// *****************************************************/
// Aliaksandra Havia                  
// Assignment 3
// LINKED LISTS
/********************************************************/

#include<iostream>
#include<fstream>
using namespace std;

class DataList {
private:
	// Declare a structure for the list
	struct ListNode {
		double quantity; // quantity value in the node
		double price; // price value in the node
		struct ListNode *next;
		struct ListNode *prev;
	};

	ListNode *head; // list head pointer

public:
	// Constructor
	DataList(){
		head = nullptr;
	}
	

	// Linked list operations
	void appendNode(double,double);
	void deleteNode(double,double);
	double searchNode(double,double &);
	void displayList();
};

void DataList::appendNode(double quantity, double price){
	ListNode *newNode; // To point to a new node
	ListNode *nodePtr; // To move through the list

	// Allocate a new node and store values there
	newNode = new ListNode;
	newNode->quantity = quantity;
	newNode->price = price;
	newNode->next = nullptr;
	// cout << "New Values" << endl;
	// cout << newNode->quantity << " " << newNode->price << endl;
	// If there are no nodes in the list 
	// make newNode first node
	if(!head){
		head = newNode;
	}else{ // Otherwise, insert newNode at end
		// Initialize nodeptr to head of list
		nodePtr = head;

		// Find the last node in the list
		while(nodePtr->next){
			nodePtr = nodePtr->next;
		}
		// Insert newNode as the last node
		nodePtr->next = newNode;
	}
}

void DataList::deleteNode(double quantity, double price){
	ListNode *nodePtr; // To traverse the list
	ListNode *previousNode; // To point to the previous node
	ListNode *temp;
	// If the list is empty, do nothing
	// Case 1
	if (!head){
		cout << "Node cannot be deleted from an empty list" << endl;
	} else {
		nodePtr = head;
		previousNode = nullptr;
		while(nodePtr != nullptr){
			if ( nodePtr->quantity == quantity && nodePtr->price == price){
				break;
			} else{
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
				cout << "previousNode " << previousNode->quantity << " " << previousNode->price <<endl;
				cout << "nodePtr " << nodePtr->quantity<< " " << nodePtr->price << endl;
			}
		}
		// Case 2 - Node with "quantity" and "price" not found
		if(nodePtr == nullptr){
			cout << "Quantity and price are not found" << endl;

		} else {
			// case 3 delete from head
			if (nodePtr == head){
				head = head->next;
				
			} else {
				// case 4 delete beyond head
				previousNode->next = nodePtr->next;
				
			}
			delete nodePtr;
		}	
	}	
}

double DataList::searchNode(double quantity, double &total){
	ListNode *nodePtr;
	ListNode *previousNode;
	nodePtr = head;
	double rem;
	double price;
	double totalSales = 0;
	double sales = 0;
	if ( nodePtr->quantity >= quantity ){
		sales = (quantity * (nodePtr->price) * 100.00)/30.00;
		rem = nodePtr->quantity - quantity;
		cout << quantity << " at ";
		cout.precision(2);
		cout << fixed << nodePtr->price << "\tSales: $" << sales << endl;
		totalSales+= sales;
		total -= quantity;
		cout << "\tTotal sales " << totalSales << endl;	
		nodePtr->quantity = rem;
		cout << "After fulfilled " << nodePtr->quantity << endl;
		if(rem == 0){
			cout << "before delete" << endl;
			deleteNode(nodePtr->quantity, nodePtr->price);
		}	 	
	} else {
		nodePtr = head;
		previousNode = nullptr;
		
		while(nodePtr != nullptr){
			rem = quantity - nodePtr->quantity;
			do{
				
				if(rem > nodePtr->quantity){
				sales = (rem * (nodePtr->price) * 100.00)/30.00;
				cout.precision(0);
				cout << fixed << nodePtr->quantity << " at ";
				cout.precision(2);
				cout << fixed << nodePtr->price << "\tSales: $" << sales << endl;
				cout << "Rem " << rem << endl;
				totalSales+= sales;	
				nodePtr->quantity -= rem;
				if(nodePtr->quantity == 0){
					cout << "before delete" << endl;
					deleteNode(nodePtr->quantity, nodePtr->price);
				}
				break;
				
				} else {
				sales = ((nodePtr->quantity) * (nodePtr->price) * 100.00)/30.00;
				cout.precision(0);
				cout << fixed << nodePtr->quantity << " at ";
				cout.precision(2);
				cout << fixed << nodePtr->price << "\tSales: $" << sales << endl;
				cout << "Rem " << rem << endl;
				nodePtr->quantity -= rem;
				if(nodePtr->quantity == 0){
					cout << "before delete" << endl;
					deleteNode(nodePtr->quantity, nodePtr->price);
				}
				
				}
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
				totalSales+= sales;
				rem = quantity - nodePtr->quantity;

			}while(rem > 0);

		}

		if(nodePtr == nullptr){
			cout.precision(0);
			cout << "remainder of " << fixed << rem << " not available" << endl;
			total -= quantity;
		}

		
		// 	while( nodePtr != nullptr && rem != 0) {
		// 		if(rem > 0){
		// 		sales = ((nodePtr->quantity) * (nodePtr->price) * 100.00)/30.00;
		// 		cout.precision(0);
		// 		cout << fixed << nodePtr->quantity << " at ";
		// 		cout.precision(2);
		// 		cout << fixed << nodePtr->price << "\tSales: $" << sales << endl;
		// 		cout << "Rem " << rem << endl;
		// 		nodePtr->quantity = 0;
		// 		if(nodePtr->quantity == 0){
		// 			cout << "before delete" << endl;
		// 			deleteNode(nodePtr->quantity, nodePtr->price);
		// 		}
		// 		previousNode = nodePtr;
		// 		nodePtr = nodePtr->next;
		// 		rem = quantity - nodePtr->quantity;
			
		// 	} else {
		// 		
		// 	}	
		// 	totalSales+= sales;	
		// }
		cout << "\tTotal sales " << totalSales << endl;	
	} 
	totalSales = 0;
	sales = 0;
	rem = 0;
	return total;	
}

void DataList::displayList(){
	ListNode *nodePtr; // To move through the list
	// Position nodePtr at the head of the list
	nodePtr = head;
	// While nodePtr points to a node, traverse
	// the list
	while(nodePtr){
		// Display the values in theis node
		cout.precision(0);
		cout << fixed << nodePtr->quantity << " ";
		cout.precision(2);
		cout << fixed << nodePtr->price << endl;
		// Move to the next node
		nodePtr = nodePtr->next;
	}
}

int main(){
	ifstream input("data.txt");
	DataList list;
	char type;
	double tempQuantity, tempPrice, total = 0;
	int discount;
	bool promotion = true;
	if(input.is_open()){
		// cout << "File is open" << endl;
		while( !input.eof()){
			input >> type;

			if( type == 'S'){
				input >> tempQuantity;
				cout.precision(0);
				cout << fixed << tempQuantity << " Widgets sold" << endl;
				list.searchNode(tempQuantity, total);
				cout.precision(0);
				cout << fixed << "Total after fulfilled " << total << endl;
			} else if ( type == 'R') {
				if(input >> tempQuantity >> tempPrice){
					total += tempQuantity;
					list.appendNode(tempQuantity,tempPrice);
					cout << "Total " << total << endl;
				}
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
	// cout << "Displaying list" << endl;
	list.displayList();
	return 0;
}

