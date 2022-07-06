#include<iostream>
#include<vector>
using namespace std;

class Graph{
	
	int vertex; // number of vertices
	vector<vector<int>> adj; // adjacency list
	
	public:
		
		// constructor to initialize graph
		// set number of vertices to v
		// initialize adjacency list for v nodes
		Graph(int v){
			vertex = v;
			adj = vector<vector<int>>(v+1);
		}
		
		// add edge (u, v) to graph
		void addEdge(int u, int v){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		// remove edge (u, v) from the graph
		void removeEdge(int v,int u){
			
			// find vertex u in adjacency list of v
			// swap u with last vertex of adj[v]
			// delete the last vertex
			for(int i=0;i<adj[v].size();++i){
				if(adj[v][i]==u){
					swap(adj[v][i], adj[v][adj[v].size()-1]);
					adj[v].pop_back();
					break;
				}
			}
			
			// find vertex v in adjacency list of u
			// swap v with last vertex of adj[u]
			// delete the last vertex
			for(int i=0;i<adj[u].size();++i){
				if(adj[u][i]==v){
					swap(adj[u][i], adj[u][adj[u].size()-1]);
					adj[u].pop_back();
					break;
				}
			}
			
		}
		
		// function to print euler path or euler circuit
		// the function first checks if the euler contains euler circuit or euler path
		// by counting the number of odd vertices
		void printEulerPathCircuit(){
			
			int odd = 0; // number of vertices with odd degree
			int oddVertex = 0; // it stores vertex with odd degree if it exists
			
			for(int i=1;i<=vertex;++i){
				if(adj[i].size()%2==1){
					++odd;
					oddVertex = i;
				}
			}
			
			if(odd==0){
				// if the number of odd degree vertices is 0
				// the graph contains a Euler Circuit
				// we can use any vertex as the starting vertex
				cout<<"Euler Circuit: ";
				// print euler circuit with '1' as the starting vertex
				printEuler(1);
			}
			else if(odd==2){
				// if the number of odd degree vertices is 0
				// the graph contains a Euler Path
				// starting vertex should be of odd degree
				cout<<"Euler Path: ";
				printEuler(oddVertex);
			}
			else{
				cout<<"Euler Path/Circuit Doesn't Exist"<<endl;
			}
			
		}
		
		// the function to print euler path or circuit
		void printEuler(int v){
			
			// print current edge
			cout<<" "<<v<<" ";
			
			// if there are no adjacent vertices left
			// terminate the program
			if(adj[v].size()==0){
				return;
			}
			
			// if there is only 1 edge connected to v
			// choose that edge
			if(adj[v].size()==1){
				int u = adj[v][0];
				removeEdge(v, u);
				printEuler(u);
				return;
			}	
						
			// traverse all neighbours of v 
			// to find a non-bridge edge
			for(auto u: adj[v]){

				if(isValidEdge(v, u)){
					// if edge (v, u) is not a bridge, that it is valid edge
					// then remove edge (v, u) and set u as the current edge
					removeEdge(v, u);
					printEuler(u);
					return;
				}
				
			}
			
		}
		
		// this function checks if (v, u) is a bridge or not
		bool isValidEdge(int v, int u){
			
			int c1, c2;
			c1 = c2 = 0;
			vector<bool> visited;
			
			// first we remove edge (v, u) from the graph
			// then count the number of vertices we can reach from v
			removeEdge(v, u);
			visited = vector<bool>(vertex+1,false);
			c1 = countConnectedVertices(u, visited);
			
			// we add the vertex (v, u) back to the graph
			// then count the number of vertices we can reach from v
			addEdge(v, u);
			visited = vector<bool>(vertex+1,false);
			c2 = countConnectedVertices(u, visited);
			
			// if c1 == c2, that means vertex (v, u) is not a bridge
			// removing (v, u) doesn't disconnect the graph
			// if c1 != c2, that means vertex (v, u) is a bridge
			// removing (v, u) disconnects the graph
			if(c2 == c1) return true;
			else		 return false;
			
		}
		
		// depth first search to count the number of vertices
		// we can reach from u
		int countConnectedVertices(int u, vector<bool> &visited){
			
			visited[u] = true;
			int count = 1;
			for(auto v: adj[u]){
				if(!visited[v]){
					count += countConnectedVertices(v, visited);
				}
			}
			return count;
			
		}
	
};

int main()
{
	// graph G, containing 7 vertices from 1 to 7.
	Graph G(7);
	
	// adding edges to the graph
	// this graph is same as the graph we used in the above example
	// a-1 b-2 c-3 d-4 e-5 f-6 g-7
	// we are assuming graph is connected and undirected
	
    G.addEdge(1,2);
	G.addEdge(1,3);
	G.addEdge(1,4);
	G.addEdge(1,6);
	G.addEdge(2,3);
	G.addEdge(2,5);
	G.addEdge(2,7);
	G.addEdge(5,6);
	G.addEdge(6,7);
	
	// function to print Euler Path or Euler Ciruit
	G.printEulerPathCircuit();
}