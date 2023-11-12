//Linked list implementation

#include "iostream"
#include "string"

using namespace std;

//The class "node" refers to a node in linklist 
class node {
	public:
		int data; //to store data
		node* next; //to store address of next node
		
		node(int value){
			data=value;//initialization
			next=NULL;//initialization
		}
};
class linkedlist{
	private:
		node* head;//to store address of first node
		
	public:
		linkedlist(): head(NULL){}
		//Function to insert values in Linked List
		void insert(int value){
		//A new node with given value is created
		node* newnode= new node(value);
			if(!head){
			//If there is no head i.e NULL, the newly created node is the head
			head = newnode;
			}else{
			//Otherwise, the list is traversed and the new node is appended at the end of the list
			node* temp=head;
			while(temp->next){
				temp=temp->next;
			}
			temp->next=newnode;
		}
	}
	//Function to display the elements of the list
		void display(){
			node* temp=head;
			cout<<endl;
			while(temp){
				cout<<temp->data<<" "<<endl;
				temp=temp->next;
		}
		cout<<endl;
	}
		void delstart(){
		//create a new node and assign it value of head
		node* newnode=head;
		//Change the value of head to next node
		head=head->next;
		//Delete the first node
		delete newnode;
		cout<<"Element deleted."<<endl;
	}
	void delend() {
	//New node created and assigned the value of head
    	node* temp = head;
    //Check whether the second last is null and stop the loop
    	while (temp->next->next != NULL) {
        temp = temp->next;
    }
    //now temp points to the second-to-last node
    	delete temp->next;
    	temp->next = NULL; // Set the next of the second-to-last node to NULL
    	cout<<"Element deleted."<<endl;
}	
		void delnth(int n){
		//Again, create a new node and assign it value of head
			node* temp = head;
		//To check whether the given number of element exists in list
			if (temp == NULL || temp->next == NULL) {
        	cout << "Invalid position" << endl;
        	return;
    	}
    	//FOR Loop to reach the required number of element
			for(int i=1; i<n-1 && temp != NULL; i++){
			temp=temp->next;
		}
		//Create a new node and refer it the value of node to be deleted
			node* todelete=temp->next;
		//replace the deleted node by the node next to it
			temp->next = todelete->next;
			delete todelete;
			cout<<"Element deleted."<<endl;
		}
		void insertnth(int n, int e){
		//Creating a new node with value "e"
			node* newnode = new node(e);
		//Again, create a new node and assign it value of head
			node* temp = head;
		//To check whether the given number of element exists in list
			if (temp == NULL || temp->next == NULL) {
        	cout << "Invalid position" << endl;
        	return;
    	}
    	//FOR Loop to reach the required number of element
			for(int i=1; i<n-1 && temp != NULL; i++){
			temp=temp->next;
		}
		 // Check if position is invalid
    		if (temp == NULL) {
        	cout << "Invalid position" << endl;
        	delete newnode; // Delete the new node to avoid memory leak
        	return;
    	}

    	// Insert the new node in between
    		newnode->next = temp->next;
    		temp->next = newnode;
    		cout<<"Element Inserted."<<endl;
		}
		void updatenth(int n, int e){
		//Again, create a new node and assign it value of head
			node* temp = head;
		//To check whether the given number of element exists in list
			if (temp == NULL || temp->next == NULL) {
        	cout << "Invalid position" << endl;
        	return;
    	}
    	//FOR Loop to reach the required number of element
			for(int i=1; i<n-1 && temp != NULL; i++){
			temp=temp->next;
		}
		//Assign the value given by user to the element
			temp->next->data=e;
			cout<<"Element updated."<<endl;
	}
		void search(int n){
		//Temporaray pointer given value of head
		node* temp=head;
		//Bool to break the code if value is found
    	bool found = false;
    	//Integer to keep track of index
		int x=0;
		//Loop for traversal through the list
    	while (temp != NULL) {
        if (temp->data == n) {
            cout << "Element exists at NO."<<x+1<<" in the list."<< endl;
            found = true;
            break;
        }
        	temp = temp->next;
        	x++;
    }	//If element is not found
    		if (!found) {
        	cout << "Element does not exist." << endl;
    }
	}
		void searchandupdate(int a){
		//Calling the existing function to search	
			linkedlist::search(a);
		//Taking new value of element
			cout<<"Enter the new value of the element: "<<endl;
			int val;
			cin>>val;
		//Temporary pointer
			node* temp=head;
    		bool found = false;
    	//Traversal through list
    		while (temp != NULL) {
        	if (temp->data == a) {
        //Assignment of new value
            temp->data=val;
            cout<<"Value of element is updated."<<endl;
            found = true;
            break;
        }
    	    temp = temp->next;
    }
	}
};

int main()
{
	//object creation
	linkedlist mylist;
	
	//insertion of elements 
	mylist.insert(1);
	mylist.insert(2);
	mylist.insert(3);
	mylist.insert(4);
	mylist.insert(5);
	mylist.insert(6);
	mylist.insert(7);
	mylist.insert(8);
	
	//displaying the elements 
	mylist.display();
	
	//Menu to perform operations
	int choice;
	do{
	cout<<"Enter operation to perform:\n1)Delete from beginning \n2)Delete from end \n3)Delete from nth position \n4)Insert at nth position \n5)Search \n6)Update at nth position \n7)Search and update \n8)Display \n0)Exit"<<endl;
	cin>>choice;
	switch(choice){
		case 1:
			mylist.delstart();
			break;
		case 2:
			mylist.delend();
			break;
		case 3:
			cout<<"Enter which element do you want to delete:"<<endl;
			int n;
			cin>>n;
			mylist.delnth(n);
			break;
		case 4:
			int a,b;
			cout<<"Enter the position where you want to insert a new element:"<<endl;
			cin>>a;
			cout<<"Enter the value of element:"<<endl;
			cin>>b;
			mylist.insertnth(a,b);
			break;
		case 5:
			int search;
			cout<<"Enter element you want to search:"<<endl;
			cin>>search;
			mylist.search(search);
			break;
		case 6:
			int m,e;
			cout<<"Enter which element do you want to update:"<<endl;
			cin>>n;
			cout<<"Enter the value of element:"<<endl;
			cin>>e;
			mylist.updatenth(m,e);
			break;
		case 7:
			int search2;
			cout<<"Enter element you want to search:"<<endl;
			cin>>search2;
			mylist.searchandupdate(search2);
			break;
		case 8: 
			mylist.display();
			break;
		case 0:
			return 0;
			break;
		default:
			cout<<"Invalid selection. Please enter 0-7 as input.";
	}
}while(choice!=0);
	return 0;
}

