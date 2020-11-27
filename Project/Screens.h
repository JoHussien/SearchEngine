
void first_Screen(unordered_map<string,list<string >>& graph);
void middle_Screen(unordered_map<string,list<string >>& graph);
void final_Screen(unordered_map<string,list<string >>& graph, int&, vector<int>&);
void first_Screen(unordered_map<string,list<string >>& graph){
    int option;
     cout<<"Welcome!\n"<<"What Would You Like to Do?!\n";
    cout<<"1. New Search\n"<<"2.Exit\n";
    cout<<"Type Your Choice: ";
    do{
        cin>>option;}while(option!=1&&option!=2);
        if(option==2)
            exit;
        else{compute_score();
			fill_webpages();
            middle_Screen(graph);}
    //Call New Search Function
}
void middle_Screen(unordered_map<string,list<string >>& graph){
    int option;
    cout<<"Search Results: \n";
    print_webpages(graph);
    //need to put here the list of webpages
    cout<<"Would You Like to: \n";
    cout<<"\t 1.Choose a WebPage to Open\n" "\t 2.New Search\n"<<"\t 3. Exit\n";
    cout<<"Type Your Choice: ";
    do{
        cin>>option;}while(option!=1&&option!=2);
        if(option==3)
            exit;
        else if(option==2)
            first_Screen(graph);
        else
			{int webpage_selected;
				vector<int> childrennumber = children_count(graph);;
            final_Screen(graph,webpage_selected,childrennumber);}
}
void final_Screen(unordered_map<string,list<string >>& graph,int& webpage_selected,vector<int>& childrennumber){
    int option;
    cin>>webpage_selected;
    
    cout<<"You are viewing WebPage:\t \n";
    print_specific(webpage_selected,childrennumber);
    ctr_click_update(webpage_selected);
    update_Score(webpage_selected);
    fill_webpages();
    
    //Need to output the result of search query
    cout<<"Would You Like to: \n";
    cout<<"\t 1.Back To Search Results\n" "\t 2.New Search\n"<<"\t 3.Exit\n";
    cout<<"Type Your Choice: "<<endl;
    do{
        cin>>option;}while(option!=1&&option!=2);
        if(option==3)
            exit;
        else if(option==2)
            first_Screen(graph);
        else
            middle_Screen(graph);
}
