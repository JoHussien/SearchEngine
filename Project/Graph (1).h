#include <map>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;
map <string,int> read_webpages(string file_name){
    ifstream open_file(file_name);
    vector<vector<string>> pages;
    while(!eof){
        string source;
        open_file>>source;
        string path;
        open_file>>path;
        
    }
}
void create_Graph(int V, map<string, string> webPages){
    map<string, string>::iterator it;
    unordered_map<string,list<string >> adjacencyList(V + 1);
    ifstream open_file(file_name);
    vector<vector<string>> pages;
    while(!eof){
        string source;
        open_file>>source;
        string path;
        open_file>>path;
        adjacencyList[source].push_back(path);}
    
    
    // for (it=webPages.begin(); it!=webPages.end(); it++) {
    //     // Adding Edge to the Directed Graph
    //     adjacencyList[it->first].push_back(it->second);

        
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
    
}
    int main(){
        map<string,string> webPages;
        webPages["test1"]="test2";
        webPages["test1"]="test3";
        webPages["test2"]="test3";
        webPages["test3"]="test5";
        create_Graph(4,webPages );
        return 0;
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