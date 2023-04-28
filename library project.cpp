#include<iostream>
using namespace std;
struct node
{
	int id;
	string book,author,publisher;
	node *next;
};
class library
{
  private:
  node *first;
  public:
  library()
  {
  	first=NULL;
	  }	
  void insert()
  {
  	if(first==NULL)
  	{
  		first= new node;
  		cout<<"Enter ID: ";
  		cin>>first->id;
  		cout<<"BOOK Name: ";
  		cin>>first->book;
  		cout<<"Publisher Name: ";
  		cin>>first->publisher;
  		cout<<"Author Name: ";
  		cin>>first->author;
  		first->next= NULL;
  		return;
	  }
	  else
	  {
	  	node *ptr=first;
	  	while(ptr->next!=NULL){
	  		ptr=ptr->next;
		  }
		  node *temp;
		  temp=new node;
		  cout<<"Enter ID: ";
  		  cin>>temp->id;
  		  cout<<"BOOK Name: ";
  	   	  cin>>temp->book;
  		  cout<<"Publisher Name: ";
  		  cin>>temp->publisher;
  		  cout<<"Author Name: ";
  		  cin>>temp->author;
  		  temp->next= NULL;
  		  ptr->next=temp;
  		  return;
	  }
  }
  void search()
  {
  	int s_id;
  	node *ptr=first;
  	cout<<"Enter search Id: ";
  	cin>>s_id;
  	if(first==NULL)
  	{
  		cout<<"Linked list is empty...."<<endl;
  		return;
	  }
	else
	{
		while( ptr!=NULL)
		{
			if(s_id==ptr->id)
			{
				cout<<"Your Id: "<<ptr->id<<endl;
				cout<<"Book Name: "<<ptr->book<<endl;
				cout<<"Publisher Name: "<<ptr->publisher<<endl;
				cout<<"Auther Name: "<<ptr->author<<endl;
				return;
				
			}
			ptr=ptr->next;
		}
	}
  }
  void update()
  {
  	     int u_id;
  	     node *ptr=first;
     	 cout<<"Enter search Id: ";
  	     cin>>u_id;
  	     if(first==NULL)
  	    {
  		cout<<"Linked list is empty...."<<endl;
  	   	return;
	  }
	else
	{
		while( ptr!=NULL)
		{
			if(u_id==ptr->id)
			{	
			   cout<<"Enter New ID: ";
  		       cin>>ptr->id;
  		       cout<<"BOOK Name: ";
  	   	       cin>>ptr->book;
  		       cout<<"Publisher Name: ";
  		       cin>>ptr->publisher;
  		       cout<<"Author Name: ";
  		       cin>>ptr->author;
			}
  		      ptr=ptr->next;
  } 
    } 
	    
		 
  void delete()
  {
  	  int d_id;
  	  node *temp=first;
  	 node *ptr=first;
     	 cout<<"Enter Id which you want delete :  ";
  	     cin>>d_id;
  	     if(first==NULL)
  	{
  		cout<<"Linked list is empty...."<<endl;
  	   	return;
	  }
	  if(first->id==d_id){
	  	first=ptr->next;
	  	delete ptr;
	  	 cout<<"This id has been delete.."<<endl;
	  	return;
	  }
	  else
	  {
	  	while(ptr!=NULL)
	  	{
	  		if(ptr->id==d_id)
	  		{
	  		   temp->next=ptr->next;
				 delete ptr;
				 cout<<"This id has been delete.."<<endl;
				 return;	
			  }
			  temp=ptr;
			  ptr=ptr->next;
		  }
	  }
	  
  void show()
  {
  	    node *ptr=first;
  	     if(first==NULL)
  	{
  		cout<<"Linked list is empty...."<<endl;
  	   	return;
	  }
	  while(ptr!=NULL)
	  {
	        	cout<<"Your Id: "<<ptr->id<<endl;
				cout<<"Book Name: "<<ptr->book<<endl;
				cout<<"Publisher Name: "<<ptr->publisher<<endl;
				cout<<"Auther Name: "<<ptr->auther<<endl;
				cout<<"\n\n"<<endl;
				ptr=ptr->next;
				return;	
	  }
  }}
};
int main(){
	library obj;
	obj.insert();
}
