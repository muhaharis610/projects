#include<iostream>
using namespace std;
class Node {
public:
    string date;
    string Name;
    string Deparment ;
    string Deg;
    Node*next;
};
Node* head=new Node();
bool check(string x)
{
    if (head==NULL)
        return false;
    Node*t=new Node;
    t=head;
    while (t!=NULL)
	{
        if (t->Name==x)
            return true;
        t=t->next;
    }
    return false;
}
void Insert_Record(string Name,string date,string Deparment,string Deg)
{
    if (check(Name))
	{
        cout<<"Student with this ";
        cout<<"Record Already Exists:\n";
        return;
    }
    Node*t=new Node();
    t->date=date;
    t->Name=Name;
    t->Deparment =Deparment ;
    t->Deg=Deg;
    t->next=NULL;
    if (head==NULL||(head->date>=t->date))
	{
        t->next=head;
        head=t;
    }
    else {
        Node*c=head;
        while (c->next!=NULL&& c->next->date<t->date)
		{
            c=c->next;
        }
        t->next=c->next;
        c->next=t;
    }
    cout<<"Record Inserted ";
    cout<<"Successfully\n";
}
void Search_Record(string Name)
{
    if (!head) 
	{
        cout<<"No such Record ";
        cout<<"Available\n";
        return;
    }
    else {
        Node*p=head;
        while (p)
		{
            if(p->Name==Name)
			{
                cout<<"Date:";
                cout<<p->date<<endl;
                cout<<"Name:";
                cout<<p->Name<< endl;
                cout<<"Deparment  :";
                cout<<p->Deparment << endl;
                cout<<"Degree :";
                cout<<p->Deg<< endl;
                return;
            }
            p = p->next;
        }
        if(p==NULL)
            cout<<"No such Record ";
            cout<<"Available\n";
    }
}
int Delete_Record(string Name)
{
    Node*t=head;
    Node*p=NULL;
    if (t!= NULL && t->Name==Name) 
	{
        head=t->next;
        delete t;
        cout<<"Record Deleted ";
        cout<<"Successfully\n";
        return 0;
    }
    while (t!=NULL && t->Name!=Name)
 	{
        p=t;
        t=t->next;
    }
    if (t==NULL)
	{
        cout<<"Record does not Exist\n";
        return -1;
        p->next=t->next;
        delete t;
        cout<<"Record Deleted ";
        cout<<"Successfully\n";
        return 0;
    }
}
void Show_Record()
{
    Node*p=head;
    if(p== NULL)
	{
        cout<<"No Record ";
        cout<<"Available\n";
    }
    else {
        cout<<"Date\t\tName\t\tDay\t";
        cout<<"\tDegree\n";
        while(p!=NULL)
		{
            cout<<p->date<<" \t";
            cout<<p->Name<<" \t";
            cout<<p->Deparment <<" \t";
            cout<<p->Deg<< endl;
            p=p->next;
        }
    }
}
int main()
{
    head=NULL;
    string Name,date,Deparment ;
    string Deg;
    while(true) 
	{
    	cout<<"\n\t###### Student Record Book";
        cout<<" ######\n\n\tPress\n\t1:";
        cout<<" To Create a new record\n\t2:";
        cout<<" To Delet Student record\n\t3:";
        cout<<" To Search Record\n\t4:";
        cout<<" To View All Record\n\t5: To Exit\n";
        cout <<"\nEnter your Choice:\n";
        int Choice;
        cin>>Choice;
        if(Choice==1)
	 	{
            cout<<"Enter Name of Student:\n";
            cin>>Name;
            cout<<"Enter Date:\n";
            cin>>date;
            cout<<"Enter Deparment  :\n";
            cin>>Deparment ;
            cout<<"Enter Degree :\n";
            cin>>Deg;
            Insert_Record(Name,date,Deparment ,Deg);
        }
        else if (Choice==2) 
		{
            cout<<"Enter Name whose ";
            cout<<"Record is to be deleted:\n";
            cin>>date;
            Delete_Record(date);
        }
        else if (Choice==3) 
		{
            cout<<"Enter Name you ";
            cout<<"want to Search:\n";
            cin>>Name;
            Search_Record(date);
        }
        else if (Choice==4) 
		{
            Show_Record();
        }
        else if (Choice==5) 
		{
            exit(0);
        }
        else {
            cout <<"Invalid Choice";
            cout <<" Try Again\n";
        }
    }
    return 0;
}
