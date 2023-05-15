#include<iostream>
using namespace std;
#include<conio.h>
struct node
{
	int roll_no;
	string name;
	float per,marks;
	node *next;
	
};
class std_rec{
	node *first;
	public:
	std_rec()
	{
		first=NULL;
		}	
	void insert()
	{
		if(first==NULL)
		{
			first=new node;
			cout<<"Enter Roll No: "<<endl;
			cin>>first->roll_no;
			cout<<"Enter Name: "<<endl;
			cin>>first->name;
			cout<<"Enter Marks: "<<endl;
			cin>>first->marks;
			first->per=first->marks/100*100;
			
			first->next=NULL;
			
		}
		else
		{
		    node *temp=first;
		    while(temp->next!=NULL)
		    {
		    	temp=temp->next;
			}
			node *ptr;
			ptr=new node;
			cout<<"Enter Roll No: "<<endl;
			cin>>ptr->roll_no;
			cout<<"Enter Name: "<<endl;
			cin>>ptr->name;
			cout<<"Enter Marks: "<<endl;
			cin>>ptr->marks;
			ptr->per=first->marks/100*100;
			ptr->next=NULL;
			temp->next=ptr;
			
		}
	}
	void search()
	{
		node *temp=first;
		int found=0;
	   int s_roll;
	   cout<<"Type here  roll no which you want to search."<<endl;
	   cin>>s_roll;
	   if(first==NULL)
	   {
	   	 cout<<"linked list is Empty";
		   return;
		   }	
		else
		     while(temp!=NULL)
		     {
		     	if(s_roll==temp->roll_no)
		     	{
		     		cout<<" Your Roll NO: "<<temp->roll_no<<endl;
		     		cout<<" Your Name: "<<temp->name<<endl;
		     		cout<<" Your Marks: "<<temp->marks<<endl;
		     		cout<<" Your Percentage: "<<temp->per<<endl;
		     		found++;
		     		return;
				 }
				 temp=temp->next;
			 }
			 if(found==0)
			 {
			 	cout<<"This was not inserted in Linked list";
			 }
		
	}
	void update(){
		node *temp=first;
		int found=0;
	   int u_roll;
	   cout<<"Type here which you want to update."<<endl;
	   cin>>u_roll;
	   if(first==NULL)
	   {
	   	 cout<<"linked list is Empty";
		   return;
		   }
       	else
		     while(temp!=NULL)
		     {
		     	if(u_roll==temp->roll_no)
		     	{
		     		cout<<" Enter New Roll NO: "<<endl;
		     		cin>>temp->roll_no;
		     		cout<<" Enter New Name: "<<endl;
		     		cin>>temp->name;
		     		cout<<" Enter New Marks: "<<endl;
		     		cin>>temp->marks;
		     		found++;
		     		return;
				 }
				 temp=temp->next;	
		
	}
	
	}
	void del()
	{
		int d_roll,found=0;
		node *ptr=first;
		node *temp=first;
		
		if(first==NULL)
		{
			cout<<"Linked list is Empty..";
			return;
		}
		cout<<"Enter roll no which you want deleted "<<endl;
		cin>>d_roll;
		if(ptr->roll_no==d_roll)
		{
			first=ptr->next;
			delete ptr;
			cout<<"Student record deleted "<<endl;
			found++;
			return;
		}
		
		else
		      while(ptr!=NULL)
		      {
		      	if(ptr->roll_no==d_roll)
		      	{
		      		temp->next=ptr->next;
		      		delete ptr;
		      		cout<<"Student record has been deleted.";
		      		found++;
					  return;
				  }
				  temp=ptr;
				  ptr=ptr->next;
			  }
			  if(found==0)
			  {
			  	cout<<"This roll no is not found..."<<endl;
			  }
	}
	void show()
	{
		node *ptr=first;
		while(ptr!=NULL)
		{
			cout<<"Your Roll NO: "<<ptr->roll_no<<endl;
			cout<<"Your Name: "<<ptr->name<<endl;
			cout<<"Your Marks: "<<ptr->marks<<endl;
			cout<<"Your Percentage: "<<ptr->per;
			ptr=ptr->next;
			cout<<"\n\n"<<endl;
		}
	}
};
int main()
{
	std_rec s1;
	p:
	system("cls");
	int choice;
	cout<<"\n\n\t\t________Student Managemet System________"<<endl;
	cout<<"\n\t_______Welcome to Student Management Record_______"<<endl;
	cout<<"\n  1\t|\t Insert Student Record"<<endl;
	cout<<"\n  2\t|\t Search Student Record"<<endl;
	cout<<"\n  3\t|\t Update Student Record"<<endl;
	cout<<"\n  4\t|\t Delete Student Record"<<endl;
	cout<<"\n  5\t|\t Show Student Record"<<endl;
	cout<<"\n  6\t|\t Exit\n\n"<<endl;
	cout<<"Enter your Choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
			
			    system("cls");
			    s1.insert();
			    break;
			}
		case 2:
			{
				system("cls");
             	s1.search();
				break;
			}
		case 3:
			{
				system("cls");
				s1.update();
				break;
			}
		case 4:
			{
				system("cls");
				s1.del();
				break;
			}
		case 5:
			{
				system("cls");
				s1.show();
				break;
			}
		case 6:
			    exit(0);
		default:
			    cout<<"Invalid Choic.. Try Again";
	}
	getch();
	goto p;
	}
