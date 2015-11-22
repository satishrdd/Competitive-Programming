#include<iostream>
#include<climits>
#include<queue>
#define v 35

int argraph[v][v],n;
bool visited[v];
using namespace std;


bool bfs(int res_graph[][v],int source,int destination,int parent[]);

void max_flow(int source,int destination);

int main(int argc, char const *argv[])
{
	/* code */
	int i,j,source,destination,nedges;
	int x,y,weight;
	char choice;
	cout<<"Enter the number of vertices of the graph"<<endl;
	cin>>n;
	if(n>34){
		cout<<"Entered size more than max limit"<<endl;
		return 0;
	}
	cout<<"Enter m to give graph input as a adjacency matrix or l to give as adjacency list"<<endl;
	cin>>choice;
	if(choice=='m'){
		cout<<"Enter the Maximum flow in the edges enter 0 if there is no edge"<<endl;

		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				cin>>argraph[i][j];
			}
			visited[i] = false;
		}

	}else if(choice=='l'){
		cout<<"Enter number of edges"<<endl;
		cin>>nedges;
		cout<<"Enter Edge in format Source space Destination space max_flow"<<endl;
		while(nedges--){
			cin>>x>>y>>weight;
			argraph[x][y]= weight;
		}

	}
	else{
		cout<<"Invalid Input"<<endl;
		return 0;
	}
	cout<<"Enter the Source and Destination of the flow"<<endl;
	cin>>source>>destination;
	if(source>n||destination>n){
		cout<<"Invalid Source or Destination"<<endl;
		return 0;
	}

	max_flow(source,destination);


	return 0;
}



void max_flow(int source,int destination){
	int res_graph[v][v];
	int parent[v];
	int i, j;
	int flow = INT_MAX;
	int max_flow = 0;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			res_graph[i][j] = argraph[i][j];
		}
	}

	while(bfs(res_graph,source,destination,parent)){
		for (j=destination; j!=source; j=parent[j])
        {
            i = parent[j];
            flow = min(flow, res_graph[i][j]);
        }
 
        // update residual capacities of the edges and reverse edges
        // along the path
        for (j=destination; j != source; j=parent[j])
        {
            i = parent[j];
            res_graph[i][j] -= flow;
            res_graph[j][i] += flow;
        }

        max_flow = max_flow+ flow;
	}

	cout<<"Max Flow that can be achieved in this graph from "<<source<<" to "<<destination<<" is "<<max_flow<<endl;

}


bool bfs(int res_graph[][v],int source,int destination,int parent[]){
	int i;
	for(i=0;i<=n;i++){
		visited[i] = false;
	}
	visited[source] = true;										//change visited [start] to 1

	int x = source;
	queue<int> myqueue;
	parent[source] = -1;
	myqueue.push(source);                               //push start to queue
	
	while(!(myqueue.empty())){
		i = myqueue.front();
		x =i;
		myqueue.pop();

													//pop start and push adjacency list of start and similarly with replacing start with front element 
		i=1;
		for(i=1;i<=n;i++){
			if(res_graph[x][i]>0 && visited[i]==false){
				
					visited[i]=true;
					myqueue.push(i);
					parent[i] = x;						//change visited to 1 for each when pushed and is printed before popping
					//x = i;
				
			}
			
		}
	}
	return(visited[destination]==true);
}



