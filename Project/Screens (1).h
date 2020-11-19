
void first_Screen();
void middle_Screen();
void final_Screen();
void first_Screen(){
    int option;
     cout<<"Welcome!\n"<<"What Would You Like to Do?!\n";
    cout<<"1. New Search\n"<<"2.Exit\n";
    cout<<"Type Your Choice: ";
    do{
        cin>>option;}while(option!=1&&option!=2);
        if(option==2)
            exit;
        else
            middle_Screen();
    //Call New Search Function
}
void middle_Screen(){
    int option;
    cout<<"Search Results: \n";
    //need to put here the list of webpages
    cout<<"Would You Like to: \n";
    cout<<"\t 1.Choose a WebPage to Open\n" "\t 2.New Search\n"<<"\t 3. Exit\n";
    cout<<"Type Your Choice: ";
    do{
        cin>>option;}while(option!=1&&option!=2);
        if(option==3)
            exit;
        else if(option==2)
            first_Screen();
        else
        
            final_Screen();
}
void final_Screen(){
    int option;
    cout<<"You are viewing WebPage:\t \n";
    //Need to output the result of search query
    cout<<"Would You Like to: \n";
    cout<<"\t 1.Back To Search Results\n" "\t 2.New Search\n"<<"\t 3.Exit\n";
    cout<<"Type Your Choice: "<<endl;
    do{
        cin>>option;}while(option!=1&&option!=2);
        if(option==3)
            exit;
        else if(option==2)
            first_Screen();
        else
            middle_Screen();
}
