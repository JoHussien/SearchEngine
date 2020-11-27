

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;
#include "structs.h"
#include "Graph.h"
#include "Screens.h"
//#include "WebGraphfile.h"
int main()
{   //First Outputing to the user the first Screen
	
    //Creating the Webgraph
    //Will parse the csv file and connect each webpage to its number as the graph is graph of int
     
    const char * filename = "WebGraph.csv";
    unordered_map<string,list<string >> graph;
	vector<Edge> edges;
    read_webpages(filename,graph,edges);
    cout<<"The WebGRaph Constructed is :\n";
    //print_graph(graph);
    vector<int> childrennumber= children_count(graph);
    vector<double> ranks = page_rank(graph);
    getting_impressions("Impressions.csv");
		//const char *filename
    first_Screen(graph);
    
    
   
     
    
    return 0;
}
