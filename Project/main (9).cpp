

#include <iostream>
#include <map>
using namespace std;

#include "Screens.h"
#include "Graph.h"
#include <fstream>
#include "WebGraphfile.h"
int main()
{   //First Outputing to the user the first Screen
    //Creating the Webgraph
    //Will parse the csv file and connect each webpage to its number as the graph is graph of int
    int V = 4; 
    read_webpages("WebGraph.CSV");
    
    
    
    // printGraph(adj, V);
    first_Screen();
    
    
        
    return 0;
}
