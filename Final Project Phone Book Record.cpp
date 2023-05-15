#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct Contact
{
	string name;
	string num1;
	string num2;
	string email;
	string adress;
};

 
void check(string tname)
{

	ifstream ifs("phonebook.txt");
	if(!ifs.is_open())
	{
		cout<<"File is not open "<<endl;
	}
	else
	{
	
	while(!ifs.eof())
	{
	string name;
		string c1="";
		string c2="";
		string e="";
		string a="";	
		ifs>>name;
		ifs>>c1;
		ifs>>c2;
		ifs>>e;
		ifs>>a;	
		if(name==tname)
		{
			cout<<"Name is already taken."<<endl;
			break;
		}
	
	}
		ifs.close();
	}
}
void add_contact()
{
	system("cls");
	Contact c;
	ofstream file("phonebook.txt",ios::app);
	cout<<"Enter Name: ";
	cin>>c.name;
	check(c.name);
	file<<c.name<<"\t\t";
	cout<<"Enter Number: ";
	cin>>c.num1;
	file<<c.num1<<"\t\t";
	cout<<"Enter Second Number: ";
	cin>>c.num2;
	file<<c.num2<<"\t\t";
	cout<<"Enter email adress: ";
	cin>>c.email;
	file<<c.email<<"\t\t";
	cin.ignore();
	cout<<"Enter Adress: ";
	cin>>c.adress;
	file<<c.adress<<"\n";

file.close();
}
void Display_Record()
{
    string mytext; 
    system("CLS");
	cout<<"Current Record(s)"<<endl;
	cout<<"================================="<<endl;
	cout<< "Name  |    Number1     |     Number2      |      Email       |      Adress         "<<endl<<"------------------------------------\n";
	ifstream in("phonebook.txt");
	if(in.is_open())
	{
		while(getline(in,mytext))
		{ 
		  cout<<mytext<<endl;
		}
		in.close();
	}
	else
	cout<<"file is not open";
}
void search(string Name)
{
	string name,c1,c2,e,a;
	ifstream ifs("phonebook.txt");
	if(!ifs.is_open())
	{
		cout<<"File is not open!"<<endl;
	}
	else
	{	
		ifs>>name;
		ifs>>c1;
		ifs>>c2;
		ifs>>e;
		ifs>>a;
		while(!ifs.eof())
		{
		    if(Name==name)
		    {
		        cout<<"NAME: "<<name<<endl;
		        cout<<"First NO: "<<c1<<endl;
		        cout<<"Second NO: "<<c2<<endl;
		        cout<<"E-mail: "<<e<<endl;
		        cout<<"Address: "<<a<<endl;
		    }
	   ifs>>name;
		ifs>>c1;
	    ifs>>c2;
	    ifs>>e;
		ifs>>a; 
		}
	}
	ifs.close();
}
int main()
{
	char option=0;
		string name;
		string re;
	system("CLS");
		do{
		  	 cout<<"\n\n\n\n\n\n\n\n\n";
   
	cout<<"\t\t\t\t ----------------------------------------\n";
	cout<<"\t\t\t\t-----------------------------------------\n";
	cout<<"\t\t\t\t|          phone book application       |\n";
	cout<<"\t\t\t\t-----------------------------------------\n";
	cout<<"\t\t\t\t----------------------------------------\n";
	cout<<"\t\t\t\t|         [1] Add New Record               |\n";
	cout<<"\t\t\t\t|         [2] Search By Name           |\n";
    cout<<"\t\t\t\t|         [3] Display All Contacts      |\n";
    cout<<"\t\t\t\t-----------------------------------------\n";
	cout<<"\t\t\t\t|             [5] EXIT                  |\n";
	cout<<"\t\t\t\t===========================================\n";
	cout<<"\t\t\t\t  Select Option From Menu>> ";
	
	cin >> option;
	switch(option)
	{
		case '1':
			
			add_contact();
	        system("CLS");
			break;
		case '2':
		    cin.ignore();
			cout<<"Enter name you want to search: ";
			cin>>name;
			system("CLS");
			search(name);
			break;
		case '3':
			system("CLS");
			 Display_Record();
			break;
        default:
        	
        	cout<<"Error.....Invalid Input,  You can Enter only 1 to 3 cases:";
        		system("CLS");
	}
}while(option !='4');
return 0;
}
