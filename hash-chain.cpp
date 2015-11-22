

/***********************************************
***********************************************
**********AUTHOR:CS14BTECH11030****************
**********NAME:SATISH REDDY.Y******************
*************COMPILATION:G++*******************
*****OPERATING SYSTEM TESTED:UBUNTU(LINUX)*****
************DATE CREATED:6/OCT/2015************
*********DATE LAST MODIFIED:7/OCT/2015*********
***********************************************
***********************************************/


/***********************************PROB STMT:HASH TABLE WITH CHAINING*********************************************/











#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>											//libraries needed
#include<cstring>


#define sizehash 100										//max size of bucket

using namespace std;


typedef struct node
{
	string data;											//record struct and typedefining it
	struct node *nextptr;
}no;

no* array[sizehash];
bool check[sizehash];


int hash(string n){
	int sum = 0;
	

	 for (int i = 0; i < n.size(); i++) {							//hash function to convert string to key
    	sum += n[i];
    	
  		}
	return sum%sizehash;
}


void insert(string n){
	int key = hash(n);									//finding the key of value to be inserted
	
	if(check[key]){
		no* newnode = new no;
		newnode->data = n;
		newnode->nextptr = array[key];					//if first insertion of that key insert with node initiation
		array[key] = newnode;
	}else{
		no* newnode = new no;
		array[key] = newnode;
		newnode->data = n;								//otherwise just add to the node 
		newnode->nextptr = NULL;
		check[key] = true;
	}
}

void print(){
	int i =0;
	while (i!=sizehash){
		if(check[i]){
			no* pointer = array[i];
			while(pointer!=NULL){
				cout<<pointer->data<<" ";
				pointer = pointer->nextptr;									//printing records corresponding to each key
			}
			printf("\n");
		}else{
			;
		}
		i++;
	}
}
void search(string n){
	int key = hash(n);
	int flag = 0;
	if(check[key]){
		no* pointer = array[key];
		while(pointer!=NULL){
			if(pointer->data==n){								//get the key and search for record in linked list
				printf("value found\n");
				return;
			}else{
				pointer = pointer->nextptr;
			}
		}
	}else{
		printf("Value not found\n");
		return;
	}
	if(flag==0){
		printf("Value not found\n");
		return;
	}
}
void Delete(string n)
{
	int flag =0;
	int key = hash(n);
	if(!check[key]){
		printf("value to be deleted not found\n\n");
		return;
	}else{
		no* pointer = array[key];								//search for the keys liked list and delete record
		no* pointer1 = pointer;
		if(pointer->nextptr==NULL){
			if(pointer->data==n){
			check[key] = false;
			printf("Deleted\n");
			return;
		}
		else
			{
				printf("value to be deleted not found\n");
				return;
			}	
		}

		if(pointer->data==n && pointer->nextptr!=NULL){
			array[key] = pointer->nextptr;
			pointer->nextptr=NULL;
		}
		while(pointer!=NULL){

			if(pointer->data==n){
				printf("value to be deleted found\n");
				pointer1->nextptr=pointer->nextptr;
				pointer->nextptr = NULL;
				printf("Deleted\n");
				
				return;
			}else{
				pointer1 = pointer;
				pointer = pointer->nextptr;
				
			}
		}
	}
	if(flag==0){
		printf("value to be deleted not found\n");
		return;
	}
}

int main(int argc, char const *argv[])
{
	/* code */													//give options to insert,search,delete
	int i,choice,m;
	string n;
	for(i=0;i<sizehash;i++){
		check[i] = false;
	}




	while(true){
	printf("Enter 1 to insert into hash table\n2 to search in hash table\n3 to delete from hash table\n4 to print hash table\n5 to exit\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
		{
			printf("Enter String to insert\n");
			cin.clear();
			cin.sync();
			cin>>n;
			insert(n);
			break;
		
		}
		case 2:
		{
			printf("Enter the String to be searched\n");
			cin.clear();
			cin.sync();
			cin>>n;
			search(n);
			break;
		}
		case 3:
		{
			printf("Enter the String to be deleted\n");
			cin.clear();
			cin.sync();
			cin>>n;
			Delete(n);
			break;
		}
		case 4:
		{
			print();
			break;
		}
		case 5:
		return 0;
		default:
		return 0;
	}
}

	return 0;
}