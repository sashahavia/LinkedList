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
	int record;
	node *next;
};


int main(){
	ifstream input("data.txt");

	if(input.is_open()){
		// cout << "File is open" << endl;
		char tempType;
		double tempQuantity, tempPrice, total = 0;
		int tempDiscount;
		int recordCount = 0;
		double newTotal;
		bool promotion = true;
		node *n, n2; // pointer to node
		node *t, t2; // pointer temporary node
		node *h = NULL, *h2 = NULL; // pointer to head

		while( !input.eof()){
			input >> tempType;

			if( tempType == 'S'){
				input >> tempQuantity;
				cout << tempQuantity << " Widgets sold" << endl;

				if ( tempQuantity > total ){
					cout << "remainder of " << tempQuantity - total << " Widgets not available" << endl;
					
				} else {
					
				}

			} else if ( tempType == 'R') {
				input >> tempQuantity >> tempPrice;
				total += tempQuantity;
				cout << "Total " << total << endl;
				recordCount++;
				if ( h == NULL){
					n = new node;
					n -> quantity = tempQuantity;
					n -> price = tempPrice;
					n -> record = recordCount;
					t = n; // temporary equals to n
					h = n; // head equals to n
				} else if (n != NULL){
					n = new node;
					n -> quantity = tempQuantity;
					n -> price = tempPrice;
					n -> record = recordCount;
					t -> next = n; // point to the next node's pointer next
				} else {
					n -> next = NULL;
				}
				cout << "This n " << n -> quantity << " " << n -> price << endl;

				
			} else if ( tempType == 'P') {
				input >> tempDiscount;
				cout << "Discount " << tempDiscount << "%" << endl;
			} else {
				cout << "Invalid Type" << endl;
			}
		}
	} else {
		cout << "File not found";
	}
	return 0;
}

