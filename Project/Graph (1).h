#include <map>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;
unordered_map<string,list<string >> create_Graph(int V){
    unordered_map<string,list<string>> adjacencyList(V + 1);
    return adjacencyList;
}
void add_edge(unordered_map<string,list<string >> &adjacencyList, string source, string destination){
  
        adjacencyList[source].push_back(destination);}
    
    
    // for (it=webPages.begin(); it!=webPages.end(); it++) {
    //     // Adding Edge to the Directed Graph
    //     adjacencyList[it->first].push_back(it->second);
void print_graph(unordered_map<string,list<string >> adjacencyList){
        
    for (auto& value : adjacencyList) {
        string vertex = value.first;
        list< string > adjacentVertices = value.second;
        list< string >::iterator itr = adjacentVertices.begin();
         
        cout  << vertex ;
          
        while (itr != adjacentVertices.end()) {
            cout << " -> " << (*itr) ;
            ++itr;
        }
         
        cout << endl;
    }    
        
    }
    

   

void read_webpages(const char * filename){
  

ifstream file(filename);
string data = "";
int V=0;
while(!file.eof())
{
    getline(file, data);
    
    V++;
    
}
unordered_map<string,list<string >> graph =create_Graph(V);
while(!file.eof())
{
    getline(file, data,',');
    string source = data;
    getline(file, data);
    string destination = data;
    add_edge(graph,source,destination);
    //cout<<"source: "<<source<<"\t"<<"Destination: "<<destination<<endl;
}
print_graph(graph);
}












// void addEdge(vector<int> adj[], int u, int v) 
// { 
//     adj[u].push_back(v); 
//     // adj[v].push_back(u); 
// } 
  
// // A utility function to print the adjacency list 
// // representation of graph 
// void printGraph(vector<int> adj[], int V) 
// { 
//     for (int v = 0; v < V; ++v) 
//     { 
//         cout << "\n Adjacency list of vertex "
//              << v << "\n head "; 
//         for (auto x : adj[v]) 
//           cout << "-> " << x; 
//         printf("\n"); 
//     } 
// } 
  
// // Driver code 
// int main() 
// { 
//     int V = 5; 
//     vector<int> adj[V]; 
//     addEdge(adj, 0, 1); 
//     addEdge(adj, 0, 4); 
//     addEdge(adj, 1, 2); 
//     addEdge(adj, 1, 3); 
//     addEdge(adj, 1, 4); 
//     addEdge(adj, 2, 3); 
//     addEdge(adj, 3, 4); 
//     printGraph(adj, V); 
//     return 0; 
// } 