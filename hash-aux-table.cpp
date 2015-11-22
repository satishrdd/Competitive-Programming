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


/********************************************PROBLEM STMT:HASH TABLE WITH AUXILARY TABLE*********************************************/



#include<iostream>
#include<stdio.h>						//adding useful libraries
#include<cstring>


#define sizehash 100


using namespace std;





string auxilary[sizehash];
int next_index[sizehash];								//bool check ,record data and nextindex arrays for auxilary table
bool check_aux[sizehash];


bool check_main[sizehash];
int main_index[sizehash];						//bool check and main index array for main table






int hash(string n){
	int sum = 0;
	

	 for (int i = 0; i < n.size(); i++) {
    	sum += n[i];
    																//hash function to convert string to key
  		}
	return sum%sizehash;
}



void insert(string n){
 	int key = hash(n);
 	if(check_main[key]){
 		int pos1=0;
 		int pos = main_index[key];
 																//if not first entry go to last entered record with this key ,insert data where you get free space and give the index to last entered key
 		while(next_index[pos]!=-1){

 			pos = next_index[pos];
 			pos1 = pos;
 			 
		}
		if(pos==sizehash){
			cout<<"Overflow in auxilary table ,cant insert"<<endl;
		}else{
			while(check_aux[pos]){
				pos++;
			}
			if(pos==sizehash){
			cout<<"Overflow in auxilary table ,cant insert"<<endl;
			}
			else
			{
				next_index[pos] = -1;
				auxilary[pos] = n;
				check_aux[pos] = true;
				next_index[pos1] = pos;
			}
		}
 	}else{
 		int pos = 0;
 		while(check_aux[pos]){
 			pos++;
 		}
 		if(pos==sizehash){															//if first insertion find empty slot in aux table and insert there and give index in main table
			cout<<"Overflow in auxilary table ,cant insert"<<endl;
		}
		else
		{
			next_index[pos] = -1;
			auxilary[pos] = n;
			check_aux[pos] = true;
			main_index[key] = pos;
			check_main[key] = true;
		}

 	}
}









void search(string n){
	int key  = hash(n);
	if(!check_main[key]){
		cout<<"not found"<<endl;
		return;
	}
	int pos = main_index[key];
	if(auxilary[pos]==n){									//go to the key position in auxilary table and search till you get nextindex -1 else print not found
		cout<<"found"<<endl;
		return;
	}
	while(next_index[pos]!=-1){

		pos = next_index[pos];
		if(auxilary[pos]==n){
			cout<<"found"<<endl;
			return;
		}
	}
	cout<<"Not Found"<<endl;
	return;
	
}


	



void Delete(string n){
	int key = hash(n);
	if(!check_main[key]){
		cout<<"value to be deleted not found"<<endl;
		return;
	}
	int pos = main_index[key];
	int pos1= pos;
	if(!check_aux[pos]){
		cout<<"value to be deleted not found"<<endl;
		return;
	}
	if(auxilary[pos]==n){
		cout<<"Deleted"<<endl;
		check_aux[pos] = false;
		if(!check_aux[pos1]){
			check_main[key] = false;					//search for record to be deleted and make checkof that false
		}
		return;
	}
	while(next_index[pos]!=-1){

		pos = next_index[pos];
		if(auxilary[pos]==n){
			cout<<"Deleted"<<endl;
			check_aux[pos] = false;
			if(!check_aux[pos1]){
			check_main[key] = false;
		}
			return;
		}
	}
	cout<<" value to be deleted not Found"<<endl;
	return;

}

void print(){
	for(int i=0;i<sizehash;i++){
		if(check_main[i]){
			int pos = main_index[i];
			if(check_aux[pos])
				cout<<auxilary[pos]<<" ";								//for each key got to the auxilary table and print all which are not deleted and linked to thie key

		while(next_index[pos]!=-1&&check_aux[pos]){
			pos = next_index[pos];
			if(check_aux[pos])
				cout<<auxilary[pos]<<" ";
			
		}
		cout<<endl;

	}

	}


}




int main(int argc, char const *argv[])
{
	/* code */
	int i,choice,m;
	string n;
	for(i=0;i<sizehash;i++){
		check_aux[i] = false;
		check_main[i] = false;
		next_index[i]= -1;												//give options for insert search delete,print
		main_index[i] = -1;
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