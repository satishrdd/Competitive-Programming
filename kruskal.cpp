


/***********************************************
***********************************************
**********AUTHOR:CS14BTECH11030****************
*************COMPILATION:G++*******************
********OPERATING SYSTEM:UBUNTU(LINUX)*********
************DATE CREATED:29/AUG/2015************
***********************************************
***********************************************/



#include<iostream>																//including required libraries



using namespace std;

int id[100],nnodes,nedges,size1[100],array[100],set1[100][3];

void quicksort(int set1[][3],int start,int end);
int find(int a);
void union_of_subsets(int x,int y);															//required functions
int form_minimumtree_with_kruskal(int set1[][3]);





int main(int argc, char const *argv[])
{
	/* code */
	int i,x,y, weight,size=1;
	cout<<"enter the number of nodes and edges in the graph\n";									//scannning number of node and edges in graph
	cin>>nnodes>>nedges;
	for(i=0;i<nnodes;i++){
		id[i] = i;
		size1[i] =0;																//initiating id and size of all nodes to be i and 0
	}
	

	cout<<"enter the endpoints of each edge and the corresponding weight\n";
	for(i=0;i<nedges;i++){
		cin>>x>>y>>weight;
		set1[i][0] = weight;												//scanning the edgelist
		set1[i][1] = x;
		set1[i][2] = y;
		
		
		size++;
	}



	

	

	



	cout<<"the minimum spanning tree with kruskal algorithm is\n";
	int min_cost = form_minimumtree_with_kruskal(set1);

	cout<<"minimum cost is :"<<min_cost<<endl;


	return 0;
}



int find(int a){
	if(id[a]!=a){
		id[a] = id[id[a]];
		a = id[a];																//going recursively to top most parent and finding they are in same set or not
	}
	return a;
}



void union_of_subsets(int x,int y){
	int p = find(x);
	int q= find(y);
	if(size1[p]<size1[q]){
		id[p] = q;
		size1[q] = size1[q] + size1[p];										//finding sizes of both sets and forming parent accordingly
	}else if(size1[p]>size1[q]){
		id[q] = p;
		size1[p] = size1[p] + size1[q];
	}else if(size1[p]==size1[q]){
		id[q] = p;
		size1[p] = size1[p] + size1[q];
	}
}


/*
int form_minimumtree_with_kruskal(pair <int,pair<int,int> >set[]){
	*/
	int form_minimumtree_with_kruskal(int set1[][3]){
	int a,b,j,cost=0,min_cost=0;
	
	
	


	quicksort(set1,0,nedges-1);

	
		// code 
		for (j = 0; j < nedges; j++)
			{
				a = set1[j][1];
				b =  set1[j][2];
				cost = set1[j][0];		
				if(find(a)!=find(b)){									//seeing the sorted edge list belong to same set or not and doing union accordingly
				min_cost = min_cost + cost;
				union_of_subsets(a,b);
				cout<<a<<"--"<<b<<'\t'<<cost<<endl;
			}
				}
	
		return min_cost;
}






void quicksort(int set1[][3],int start,int end){
    int holder,j,t1,t2,t3,i;

     if(start<end){
         holder=start;
         i=start;
         j=end;																			//selecting holder as start and soring by quicksort

         while(i<j){
             while(set1[i][0]<=set1[holder][0]&&i<end)
                 i++;
             while(set1[j][0]>set1[holder][0])
                 j--;
             if(i<j){
                 t1=set1[i][0];
                 t2 = set1[i][1];
                 t3 = set1[i][2];
                  set1[i][0]=set1[j][0];
                  set1[i][1]=set1[j][1];
                  set1[i][2]=set1[j][2];
                  set1[j][0]=t1;
                  set1[j][1]=t2;
                  set1[j][2]=t3;

             }
         }

         t1=set1[holder][0];
         t2=set1[holder][1];
         t3=set1[holder][2];
         
         set1[holder][0]=set1[j][0];
         set1[holder][1]=set1[j][1];														//swapping elements
         set1[holder][2]=set1[j][2];

         set1[j][0]=t1;
         set1[j][1]=t2;
         set1[j][2]=t3;
         quicksort(set1,start,j-1);
         quicksort(set1,j+1,end);												//dividing array and calling quicksort recursively

    }
}