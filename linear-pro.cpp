




/***********************************************
***********************************************
**********AUTHOR:CS14BTECH11030****************
**********NAME:SATISH REDDY.Y******************
*************COMPILATION:G++*******************
*****OPERATING SYSTEM TESTED:UBUNTU(LINUX)*****
************DATE CREATED:11/OCT/2015************
*********DATE LAST MODIFIED:12/OCT/2015*********
***********************************************
***********************************************/


/***********************************PROB STMT:LINEAR PROBING*********************************************/











#include<stdlib.h>
#include<iostream>
#include<string>											//libraries needed
#include<cstring>
#include<stdio.h>


using namespace std;

#define sizehash 100



string hash_table[sizehash];
bool check[sizehash];
bool deleted[sizehash];

int hash(string n){
	int sum = 0;
	

	 for (int i = 0; i < n.size(); i++) {							//hash function to convert string to key
    	sum += n[i];
    	
  		}
	return sum%sizehash;
}



void insert(string s){
	int key = hash(s);
	int key1 = key;
	if(check[key])
		key = (key+1)%sizehash;
	else											//go to key position if not empty space insert else advance one step
		{
			hash_table[key] = s;
			check[key] = true;
			return;
		}
	while(check[key]&& key1!=key)
		key = (key+1)%sizehash;
	if(key1==key){
		cout<<"No Space Left"<<endl;				//if there is no empty space till you return to same space again insertion cant be done
		return;
	}
	cout<<"going to insert"<<endl;
	hash_table[key] = s;
	check[key] = true;
}




void search(string s){
	int key = hash(s);
	int key1 = key;
	if(!check[key])
		{
			cout<<"Not Found"<<endl;
			return;
		}
	else if(check[key]&&hash_table[key]==s&&!deleted[key])
		{
			cout<<"Found"<<endl;
			return;
		}else{
			key = (key+1)%sizehash;								//search for element in hash table if found and is not deleted print found else go next step until you find it or return to same point
		}

	while(check[key]&&key1!=key){
		if(hash_table[key]==s&&!deleted[key]){
			cout<<"found"<<endl;
			return;
		}
		else
			key = (key+1)%sizehash; 

	}
	cout<<"Not found"<<endl;
	
}






void Delete(string s){
	int key = hash(s);
	int key1 = key;
	if(!check[key])
		{
			cout<<"Not Found so not deleted"<<endl;
			return;
		}
	else if(check[key]&&hash_table[key]==s&&!deleted[key])
		{
			cout<<"Found and deleted"<<endl;
			deleted[key] = true;										//search for element in hash table if found change flag of deleted to be true
			return;
		}else{
			key = (key+1)%sizehash;								//step advancement should follow a polynomial steps each time
		}

	while(check[key]&&key1!=key){
		if(hash_table[key]==s&&!deleted[key]){
			cout<<"found and deleted"<<endl;
			deleted[key] = true;
			return;
		}
		else
			key = (key+1)%sizehash; 

	}
	cout<<"Not found so not deleted"<<endl;

}






































int main(int argc, char const *argv[])
{
	/* code */													//give options to insert,search,delete
	int i,choice,m;
	string n;

	for(i=0;i<sizehash;i++){
		check[i] = false;
		deleted[i] = false;
		hash_table[i] = "";

	}




	while(true){
	printf("Enter 1 to insert into hash table\n2 to search in hash table\n3 to delete from hash table\n4 to exit\n");
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
		return 0;
		default:
		return 0;
	}
}

	return 0;
}