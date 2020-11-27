int Partition(vector<output> &a, int start, int end)
{

	float pivot = a[end].score;

	float pIndex = start;


	for (float i = start; i < end; i++)
	{
       
         
		if (a[i].score <= pivot)
		{
			swap(a[i], a[pIndex]);
			pIndex++;
		}
	}
	// swap pIndex with Pivot
	swap (a[pIndex], a[end]);

	// return pIndex (index of pivot element)
	return pIndex;
}


void  quicksort_comparisions(vector<output> &a,int start, int end)
{

	if (start >= end)
		return ;


	int pivot = Partition(a, start, end);


	quicksort_comparisions(a, start, pivot - 1);


	quicksort_comparisions(a, pivot + 1, end);

  
}
void quicksort(vector<output> &a ,int n)
{

	quicksort_comparisions(a,0,  n-1);

}


//------------------------------Page Rank-----------------------------//
void PageRank(Graph &g,int childerC[]){
    int size=g.nodes.size();
  vector<double>  Prank={0.25,0.25,0.25,0.25};
     
     double PrankUtil[4]={0,0,0,0};
    
    
    
    //i represents all the edges
    for (int i=0; i<size; i++)//represent all the sources
        for (int j=0; j<g.edges.size(); j++)
        {
            // cout<<i<<" "<<g.edges[j].dest<<endl;
        int index=0;
            if(g.nodes[i]==g.edges[j].dest)
                {
                
                PrankUtil[i]=PrankUtil[i]+(Prank[g.edges[j].srcId]/childerC[g.edges[j].srcId]);
                // Prank[i]=PrankUtil[i];
                // cout<<g.edges[j].dest<<" "<<PrankUtil[i]<<" "<<childerC[g.edges[j].srcId]<<endl;
                    
                }
        
        }
        for (int i=0; i<size; i++){
            Prank[i]=PrankUtil[i];
             g.urls[i].pr=PrankUtil[i];
            PrankUtil[i]=0;
            // cout<<Prank[i]<<endl;
        }

    
    
}
//------------------------------Page Rank-----------------------------//

//-----------------------------Ctr-------------------------------------//
void Ctr(Graph &g,string input){

    ofstream Ctr_file;
    Ctr_file.open("Ctr.txt");
    for(int i=0;i<g.urls.size();i++){
        if(g.urls[i].name==input)
        {
            int clks= g.urls[i].clks+1;
            g.urls[i].ctr=(clks/g.urls[i].impression)*100;
            g.urls[i].clks=clks;
            // cout<<g.urls[i].ctr;

        }
    Ctr_file << g.urls[i].name << ","<<g.urls[i].clks<<","<<g.urls[i].ctr<<endl;
    }


    Ctr_file.close();
}
//-----------------------------Ctr-------------------------------------//


//------------------------------Score-----------------------------//
void score(Graph &g){
    for(int i=0;i<g.nodes.size();i++){
 double temp=(0.1*g.urls[i].impression)/(1+0.1*g.urls[i].impression);
 double temp1=(1-temp)*g.urls[i].pr;
 double temp2=temp*g.urls[i].ctr;
        g.urls[i].score= (0.4*g.urls[i].pr+(temp1+temp2)*0.6);
        // cout<< g.urls[i].score<<endl;
    }

}


//------------------------------Score-----------------------------//

//-------------------------------reading URls to the graph --------------------//
void readURLs( Graph &g){
    ifstream f;
    f.open("WebGraph.csv");
   if(f.is_open())
   {
        string line;
        int i=0;
        while(getline(f, line))
        {

            stringstream ss(line);
            string src, dest;
            getline(ss,src,','); 
            // cout<<src<<"-> ";
            getline(ss,dest,'\n'); 
            // cout<<dest<<endl;
            g.addEdge(src,dest);
           
            if(g.nodes.size()==0)
             g.nodes.push_back(src);
             else{
            int flags=0;
            int flagd=0;
            for(int j=0;j<g.nodes.size();j++)
                 {
                     if(g.nodes[j]==src)
                    flags=1;
                    if(g.nodes[j]==dest)
                    flagd=1;
                 }


            if(flags==0)
                g.nodes.push_back(src);
             if(flagd==0)
                g.nodes.push_back(dest); 
               
                
     
             }

        }




   }
        f.close();
}

//---------------------------------------reading URls to the graph-----------------------------------------------------//



//-----intialize the struct of URL data---------------------------//

void Url_data(Graph &g)
{

    // string name;
    // float impression;
    URL u;
    for(int i=0;i<g.nodes.size();i++)
    {
        // u.name=g.nodes[i];

    g.urls.resize(g.nodes.size());
    g.urls[i].name=g.nodes[i];
    // cout<<g.urls[i].name;
    }


        ifstream f;
        f.open("Impressions.csv");

    if(f.is_open())
    {
            string line;
            int i=0;
            while(getline(f, line))
            {

                stringstream ss(line);
                string link, impression;
                getline(ss,link,','); 
                // cout<<src<<"-> ";
                getline(ss,impression,'\n'); 
                // cout<<dest<<endl;
                for(int i=0;i<g.nodes.size();i++)
                        {
                            if(link==g.urls[i].name)
                                {
                                
                                    g.urls[i].impression=stof(impression);
                                }

                        }

            }
    }

    ifstream File;
        File.open("Ctr.txt");
        if(File.is_open())
    {
            string line;
            int i=0;
            while(getline(File, line))
            {

                stringstream ss(line);
                string link2, ctr,clks;
                getline(ss,link2,','); 
       
                getline(ss,clks,',');
                getline(ss,ctr,'\n'); 
         
        
                for(int i=0;i<g.nodes.size();i++)
                        {
                            if(link2==g.urls[i].name)
                                {
                                    g.urls[i].ctr=stof(ctr);
                                     g.urls[i].clks=stof(clks);
                                
                                    
                                }

                        }

            }
    }
    
}
//-----intialize the struct of URL data---------------------------//
//parsing input
vector<string> split(string str)
{

    vector<string> name;
    istringstream ss(str);
    string word;
    if(str[0]=='"'&&str[str.size()-1]=='"')
       { 

        //   str.erase(remove(str.begin(), str.end(), '"'), str.end());

           name.push_back(str);
       
       }
    else {
        while (ss >> word)
            {
                name.push_back(word);
            }
    }
        cout<<endl;
    return name;
}
//----------
string make_lowercase( string in )
{
  std::string out;

  std::transform( in.begin(), in.end(), std::back_inserter( out ), ::tolower );
  return out;
}
//-------------------------------------Searching about the key word------------------------//

void KeywordSearch(Graph &g, vector<string> input,   vector<output> &outputs ){
    vector<string> array;
     ifstream f;
      f.open("KeyWord.csv");
   if(f.is_open())
   {
        string line;
        int i=0;
         int flagOr=0;
         int url1=0,url2=0;
        while(getline(f, line))
        {

            stringstream ss(line);
            string url,keyword;
           
            getline(ss,url,','); 
          while( getline(ss,keyword,','))
            {
                if(input[0][0]=='"'&&input[0][input[0].size()-1]=='"')
                    {
                        input[0].erase(remove(input[0].begin(), input[0].end(), '"'), input[0].end());
                        if(input[0]== keyword)
                             array.push_back(url);
                    }
                    // transform(option.begin(), option.end(), option.begin(), ::tolower);
                else if ( make_lowercase( input[1] )=="or")
                {
                    if((input[0]== keyword | input[2]== keyword) &&flagOr==0)
                    {
                             array.push_back(url);
                             flagOr=1;
                    }
                }
                else if ( make_lowercase( input[1] )=="and"){
                    
                    if(input[0]== keyword )
                        url1=1;
                    if(input[2]== keyword)
                        url2=1;
                        if(url1==1&&url2==1 &&flagOr==0)
                             {
                                 array.push_back(url);
                                 flagOr=1;
                             }
                }
                else {
                    if((input[0]== keyword | input[1]== keyword) &&flagOr==0)
                    {
                             array.push_back(url);
                             flagOr=1;
                    }
                }
           
            }
        
        flagOr=0;
        url1=0;
        url2=0;
            
        }
   }
        outputs.resize(array.size());
        for(int i=0;i<array.size();i++){
            for(int j=0;j<g.urls.size();j++)
            {
                if(array[i]==g.urls[j].name)
                {
                    outputs[i].name=g.urls[j].name;
                    outputs[i].score=g.urls[j].score;
        
                }
            }

}
   

}
//-------------------------------------Searching about the key word------------------------//

