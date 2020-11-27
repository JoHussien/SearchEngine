vector<string> vertices;
vector<string> true_vertices;
vector<double> ranks;
vector <double> impressions;
vector<int> clicks;
vector<double> CTRs;
vector<int> children_number;
vector<double> myscores;
unordered_map<string,list<string >> mygraph;
unordered_map<string,list<string >> create_Graph(int V){
    unordered_map<string,list<string>> adjacencyList(V + 1);
    //vector<<vector<int>>& graph_int;
    return adjacencyList;
}
void add_edge(unordered_map<string,list<string >> &adjacencyList, string source, string destination,vector<Edge>& edges){
  
        adjacencyList[source].push_back(destination);
        Edge edge;
        //edge.index= int(source.at(9));
        edge.src=source;
        edge.dest= destination;
        edges.push_back(edge);
        }
    
   
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
    

vector<int> children_count(unordered_map<string,list<string >> graph){
	vector<int> children;
	for (auto& value : graph) {
        string vertex = value.first;
        //~ cout<<vertex<<"\n" <<endl;
        list< string > adjacentVertices = value.second;
        list< string >::iterator itr = adjacentVertices.begin();
         int count=0;
        
        while (itr != adjacentVertices.end()) {
            count++;
            itr++;
        }
        children.push_back(count);
	    //~ cout<<count<<endl;
	} 
	
	        return children;

}
void read_webpages(const char *filename, unordered_map<string,list<string >>& graph, vector<Edge>& edges){
  

ifstream file;
file.open(filename);
string data = "";
int V=0;
while(!file.eof())
{ 
    getline(file, data);
    V++;
 }
 file.close();
unordered_map<string,list<string >> graph_returned =create_Graph(V);
file.open(filename);
while(!file.eof())
{ 
    getline(file, data,',');
    string source = data;
    getline(file, data);
    string destination = data;
    add_edge(graph_returned,source,destination,edges);
    //cout<<"source: "<<source<<"\t"<<"Destination: "<<destination<<endl;
}
file.close();
graph= graph_returned;
for (auto& value : graph) {
        string vertex = value.first;
        vertices.push_back(vertex);}
//~ print_graph(graph);
copy( vertices.begin()+1,  vertices.end(), back_inserter(true_vertices));
mygraph=graph;
}

void print_edges(vector<Edge> edges){
	for(auto& value: edges)
		cout<<value.src<<"->>" <<value.dest<<endl;
	}


vector<double> page_rank(unordered_map<string,list<string >>& graph)
{ vector<int> children_num = children_count(graph);
	copy( children_num.begin()+1,  children_num.end(), back_inserter(children_number));
	int V= children_num.size();
	V=V;
	double initial_rank= 1.0/V;
	 vector<double>  starting_r(V,initial_rank);
	 //~ for(double x: starting_r)
		//~ cout<<x<<endl;
    //~ for(string x: true_vertices)
			//~ cout<<x<<endl;
	//cout<<vertices.size()<<endl;
    vector<double> new_rank(V,0.0);
        for (auto& value : graph) {
        string vertex = value.first;
        //cout<<vertex<<"\n" <<endl;
        list< string > adjacentVertices = value.second;
        list< string >::iterator itr = adjacentVertices.begin();
        vector<string>::iterator it = find(vertices.begin(), vertices.end(), vertex);
        int vertix_index= distance(vertices.begin(), it);
        double current_vertix_rank= starting_r[vertix_index];
        //cout<<vertix_index<<endl<<current_vertix_rank<<endl;
        
        while(itr!= adjacentVertices.end())
        {	//First we get the index of each child of the children
			string child = (*itr);
			vector<string>::iterator it = find(vertices.begin(), vertices.end(), child);
			int index= distance(vertices.begin(), it);
			double children_count_current= children_num[index];
			//cout<<child<<" "<<index<<" "<<children_count_current<<" "<<starting_r[index]<<endl;
			current_vertix_rank+=starting_r[index]/children_count_current;
			itr++;
			}
		new_rank[vertix_index]= current_vertix_rank;
		
	}
	
	copy(new_rank.begin()+1, new_rank.end(),back_inserter(ranks));
	
    return ranks;
   
	}
	
void print_specific(int num,vector<int>& childrennumber){
	cout<<true_vertices[num]<<endl;
	cout<<"This page has "<<childrennumber[num] <<" children" <<" and the its rank is "<<ranks[num]<<"\n";
	}	
//now we have ranks sorted in ranks and we have vertices names in true_vertices and we have the children count in children_number

void getting_impressions(const char *filename){
  

 //~ cout<<"Ranks "<<ranks.size();
    //~ cout<<endl<<true_vertices.size();
ifstream file;
string data = "";

int V=children_number.size();
//~ cout<<V<<endl;

file.open(filename);
vector<double> imp(V,1.0);
while(getline(file, data,','))
{    
    //getline(file, data,',');
    string source = data;
    getline(file, data,'\n');
    //cout<<data<<endl;
    double impression = stod(data);
    //double impression =1.0;
    vector<string>::iterator it = find(true_vertices.begin(), true_vertices.end(), source);
    int source_index= distance(true_vertices.begin(), it);
    //~ cout<<source<<endl;
    //~ cout <<source_index<<"  "<<impression<<endl;
    imp[source_index]= impression;
}
file.close();
impressions = imp;

//~ for(double x: impressions)
	//~ cout<<x<<endl;
vector<int> initial_clicks(V,0);

clicks = initial_clicks;
vector<double> initial_CTRS(V,0.0);
CTRs = initial_CTRS;
}


void ctr_click_update(int webpage_selected){
	//~ ifstream file;
	//~ file.open(filename);
	//~ string data = "";
	//~ file.open(filename);
	//~ string selected_vertex = true_vertices[webpage_selected];
	//~ while(!file.eof())
//~ {
	//~ getline(file, data,',');
    //~ string source = data;
    //~ getline(file, data);
    //~ if(source==selected_vertex)
		//~ {int old_clicks = int(data);}
//~ }
	//~ file.close();
	//~ ofstream file;
	//~ file.open(filename);
	//~ string data = "";
	ofstream file;
    file.open("CTRs.txt");
    //need to construct the impressions once
    //cout<<true_vertices.size()<<endl;
    for(int i=0;i<4;i++){
        if(i==webpage_selected)
        {
            int clks= clicks[webpage_selected]+1;
			CTRs[webpage_selected] = (clks/impressions[webpage_selected])*100;
			clicks[webpage_selected] = clks;

        }
    file << true_vertices[i]<< ","<<clicks[i]<<","<<CTRs[i]<<endl;
    }


    file.close();
}
	//now the CTRs file has been created and update when the user selects a page each time 
	// we need now to compute the score of each webpage
	
	
void compute_score(){
	cout<<"Yes";
	int V=children_number.size();
	cout<<V<<endl;
	vector<double> scores(V,0.0);
	for(int i=0; i<V; i++){
		cout<<"NNN";
		scores[i] = ((0.4 * ranks[i]) + ((1.0 - ((0.1*impressions[i])/(1+ 0.1*impressions[i])))*ranks[i] + ((0.1*impressions[i])/(1+0.1*impressions[i]))*CTRs[i])*0.6);
		cout<<"Score web page: " <<true_vertices[i]<<" is " <<scores[i]<<endl;
		}
	myscores=scores;
		}
void update_Score(int webpage_Selected){
	int i= webpage_Selected;
	myscores[i] = ((0.4 * ranks[i]) + ((1.0 - ((0.1*impressions[i])/(1+ 0.1*impressions[i])))*ranks[i] + ((0.1*impressions[i])/(1+0.1*impressions[i]))*CTRs[i])*0.6);
		cout<<"Score web page: " <<true_vertices[i]<<" is " <<myscores[i]<<endl;
	}


void swap(webpage* a, webpage* b)
{
    webpage t = *a;
    *a = *b;
    *b = t;
}
int partition (vector<webpage> &arr, int low, int high)
{
    
    double pivot = arr[high].score;
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].score > pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
  
void quickSort(vector<webpage> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int V= 4;
//now I have a vector os scores and a vector of vertices each index in the later vector is corresponinfd to the first vector
// now we need to sort the vector of vertices using the vector of scores
vector<webpage> mypages(V);
void fill_webpages(){
	cout<<"aloha "<<V<<endl;
	vector<webpage> pages(V);
	for(int i=0; i<V; i++){
		pages[i].index = i;
		pages[i].name=true_vertices[i];
		
		pages[i].score= myscores[i];
		}
	quickSort(pages, 0, V-1);
	mypages=pages;
	}

void print_webpages(unordered_map<string,list<string >>& graph)
{	cout<<"hey "<<mypages.size()<<endl;
	//cout<<"Available webpages to search in are, select one using its full name\n";
	int i=0; 
	//fill_webpages();
	//quickSort(mypages, 0, 3);
	for(auto& value: mypages)
	{
        cout<<value.index<<".  "<<value.name<<"\n" <<endl;
        i++;
      }
}







