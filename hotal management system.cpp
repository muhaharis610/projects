/*     Hotal management system project
 In this project we perform these function
 menu()
 insert()
 del()
 update()
 search()
 sort()
       */
#include<stdio.h>
#include<iostream>
using namespace std;
int cont=0;
struct node {
	string id;
	string name;
	string roomtype;
	char gender;
	string cnic;
	node *next;
};
class hotel {
		node *first;
	public:
		hotel() {   //constructor
			first=NULL;
		}
		void menu() {
p://p is a label
			int choice;
			cout<<"\n\t\t _______HOTEL MANAGEMENT SYSTEM______"<<endl;
			cout<<"\n\t_____WELCOME TO HOTEL MANAGEMENT SYSTEM______"<<endl;
			cout<<"\n\n\tS.No	|  Function		|	Description"<<endl;
			cout<<"==============================================================="<<endl;
			cout<<"\n\t1\t|  Allocate Room\t|\t"<<"Insert New Room"<<endl;
			cout<<"\n\t2\t|  Search Room\t\t|\t"<<"Search Room With Id"<<endl;
			cout<<"\n\t3\t|  Update Room\t\t|\t"<<"Update Room "<<endl;
			cout<<"\n\t4\t|  Delete Room\t\t|\t"<<"Delete Room With Id"<<endl;
			cout<<"\n\t5\t|  Record Show\t\t|\t"<<"Show Record"<<endl;
			cout<<"\n\t7\t|  Exist      \t\t|\t"<<"Move"<<endl;
			cout<<"\n\t6\t|  Linkedlist counted\t|\t"<<"Show Record"<<endl;
			cout<<"===============================================================\n"<<endl;
			cout<<"\nEnter Your Choice: ";
			cin>>choice;
			switch(choice) {
				case 1:
					system("CLS");  //clear screen
					insert();
					break;
				case 2:
					system("CLS");
					search();
					break;
				case 3:
					system("CLS");
					update();
					break;
				case 4:
					system("CLS");
					del();
					break;
				case 5:
					system("CLS");
					show();
					break;
				case 6:
					system("cls");
					count();
					break;
				case 7:
					exit(0);
				default:
					cout<<"Invalid choice";

			}
			goto p;
		}
		bool check_id(string n) { //this function is used for check id
//			node *ptr;
//				ptr=first;
//			while(ptr!=NULL) {
//					if(ptr->id==temp->id||ptr->cnic==temp->cnic) {
//						cout<<"This record is already inserted plz enter anothor data!";
//						return;
//					}
//					pt=pt->next;
//				}
			if (first==NULL)
				return false;
			node *ptr;
			ptr=first;
			while (ptr!=NULL) {
				if (ptr->id==n)
					return true;
				ptr=ptr->next;
			}
			return false;
		}
		bool is_alphabetical(string input) {
			for (char c; c<input.length(); c++) {
				if (!isalpha(input[c])) {
					if(input[c]==' ') {
						continue;
					}
					return false;
				}
			}
			return true;
		}
		bool is_Numerically(string input) {
			for (int n; n<input.length(); n++) {
				if (!isdigit(input[n])|| input.length()!=15) {
					if(input[n]=='_') {
						continue;
					}
					return false;
				}
			}
			return true;
		}
		bool check_dub(string cn){
			if (first==NULL)
				return false;
			node *ptr;
			ptr=first;
			while (ptr!=NULL) {
				if (ptr->cnic==cn)
					return true;
				ptr=ptr->next;
			}
			return false;
		}
		bool check_type(string input) {
			for (int n; n<input.length(); n++)
			{
				if (!isdigit(input[n]))
				return false;
			
		    }
		    return true;
	    }
//	    bool is_check( string g)
//	    {
////	    	if(!isalpha(g[0]))
////	    	{
////	    		return false;
////			}
////			else{
//				if(isalpha(g[0])!='F' || isalpha(g[0])!='M')
//				return false;
//				else
//				return true;
//		//	}
//	    	
//		}
	void insert() {
			cout<<"\n____Only 50 rooms are available_____\n";
			cout<<"\n  ###ALLOCATE ROOM### \n"<<endl;

			if(cont<=3) {
				if(first==NULL) {
					first = new node;
					while(true) {

						cout<<" Enter Room ID:"<<endl;
						cin>>first->id;
						if(check_type(first->id)) 
							break;
							else {
								cout<<"Error: input must be Numerically  \n";
							}
						}
					while(true) {

						cout<<" Enter Your Name:"<<endl;
						cin>>first->name;
						if(is_alphabetical(first->name) ) {
							break;
						} else {
							cout<<"Error: input must be alphabetical \n";
						}
					}
					cin.ignore();
					do {

						cout<<" Enter Your CNIC:"<<endl;
						cin>>first->cnic;
						if(is_Numerically(first->cnic)) {
							break;
						} else {
							cout<<"Error: input must be Numerically and digit =13 \n";
						}
					} while(true);
					do{
					cout<<" Enter Your gender: (F ya M)"<<endl;
					cin>>first->gender;
//					if(first->gender.length()>1)
//					{
//						cout<<"Error! You can enter only F or M"<<endl;
//					}
//					else{
//						if(is_check(first->gender)){
//							    break;
//						    	
//						}
//						else{
//							cout<<"Error!"<<endl;
//						}
//						
						
					//}
					if(first->gender==70 || first->gender==102 || first->gender==109|| first->gender ==77)
					    break; 
					else
					    cout<<"You can enter only F for female or M for male"<<endl;
					
                }while(true);
					cout<<" Enter Room Type (single or double)"<<endl;
					cin>>first->roomtype;
					cont++;
					cout<<"Record inserted successfully! \n"<<endl;
					first->next=NULL;
					return;
				} else {

					node *ptr=first;
					while(ptr->next!=NULL) {
						ptr=ptr->next;
					}
					node *temp;
					temp = new node;
					do {
						cout<<" Enter Room ID:"<<endl;
						cin>>temp->id;
					//	while(true) {
//						cout<<" Enter Room ID:"<<endl;
//						cin>>first->id;
						if(check_type(temp->id)){
						    if(check_id(temp->id))
						    cout<<"Error: You cannot enter duplicate id Try again!\n";
							else {
									break;
							}}
						 else{
						 	cout<<"Error: input must be Numerically  \n";
						 }
					} while(true);
					do {

						cout<<" Enter Your Name:"<<endl;
						cin>>temp->name;
						if(is_alphabetical(temp->name) ) {
							break;
						} else {
							cout<<"Error: input must be alphabetical \n";
						}
					}

					while(true);

					do {

						cout<<" Enter Your CNIC:"<<endl;
						cin>>temp->cnic;
						if(is_Numerically(temp->cnic)) {
							if(check_dub(temp->cnic)){
								cout<<"Error! You cannot enter duplicate cnic."<<endl;
							}
							else
							break;
						} else {
							cout<<"Error: input must be Numerically and digit =13 \n";
						}
					} while(true);
					do{
					
					cout<<"Enter your gender (f ya m)"<<endl;
					cin>>temp->gender;
					if(temp->gender==70 || temp->gender==102 || temp->gender==109|| temp->gender ==77)
					    break; 
					else
					    cout<<"You can enter only F for female or M for male"<<endl;
					
                }while(true);
					cout<<" Enter Room Type (Single or Double)"<<endl;
					cin>>temp->roomtype;
					temp->next=NULL;
					cont++;
					cout<<"Record inserted successfully!\n "<<endl;
					ptr->next= temp;
				}
			} else {
				cout<<"you can only insert room id less than or equal to 50";
			}

		}
		void search() {
			cout<<"\n  ###SEARCH ROOM### \n"<<endl;
			node *ptr= first;
			string s_id;
		    int	found=0;
//			if(first==NULL	) {
//				cout<<"Record is not available. plz.. enter data";
//				return;
//			} else

				cout<<"Enter Id which you want to search:  "<<endl;
			cin>>s_id;
			while(ptr!=NULL) {
				if(s_id==ptr->id) {
					cout<<"Room ID  "<<ptr->id<<endl;
					cout<<"Customer Name: "<<ptr->name<<endl;
					cout<<"Customer CNIC: "<<ptr->cnic<<endl;
					cout<<"Gender: "<<ptr->gender<<endl;
					cout<<"Room Type  "<<ptr->roomtype<<endl;
					found++;
					return;
				}
				ptr=ptr->next;
			}
			if(found==0) {
				cout<<"This such Id is not found!"<<endl;
			}
		}
		void update() {
			cout<<"\n ###UPDATE ROOM### \n"<<endl;
			int found=0;
			node *ptr= first;
			string u_id;
//			if(first==NULL) {
//				cout<<"Record is not found plz.. enter record and try again"<<endl;
//				return;
//			}
			cout<<"Enter Id which you want to update:  ";
			cin>>u_id;
			while(ptr!=NULL) {
				if(u_id==ptr->id) {
					cout<<"Enter New Id: "<<endl;
					cin>>ptr->id;
					cout<<"Customer Name: "<<endl;
					cin>>ptr->name;
					cout<<"Customer CNIC: "<<endl;
					cin>>ptr->cnic;
					cout<<"Gender: "<<endl;
					cin>>ptr->gender;
					cout<<"Room Type: "<<endl;
					cin>>ptr->roomtype;
					cout<<"Record updated successfully! \n"<<endl;
					found++;
				}
				ptr=ptr->next;
			}
			if(found==0) {
				cout<<"This id is not found! "<<endl;
				return;
			}
		}
		void del() {
			cout<<"\n  ###DELETE ROOM### \n"<<endl;
			node *ptr=first;
			string d_id;
			 int found=0;
			if(first==NULL) {
				cout<<"Record is not available!";
				return;
			} else {
				cout<<"Enter Room Id which you want delete"<<endl;
				cin>>d_id;
				if(d_id==ptr->id) {
					first=ptr->next;
					delete ptr;
					cout<<"Customer Id has been deleted "<<endl;
					found++;
					return;
				} else {
					node *temp=first;
					while(ptr!=NULL) {
						if(ptr->id==d_id) {
							temp->next=ptr->next;
							delete ptr;
							cout<<"Customer Id has been deleted "<<endl;
							found++;
							return;
						}
						temp=ptr;
						ptr=ptr->next;
					}
				}
			}
			if(found==0)
				cout<<"This such id is not found!";
		}
		void count() {
			cout<<"\n ###COUNT ROOM### \n"<<endl;
			int c=0;
			if(first==NULL) {
				cout<<"All rooms are free";
				return;
			} else {
				node *ptr=first;
				while(ptr!=NULL) {
					c++;
					ptr=ptr->next;
				}
				cout<<"Total Room Inserted:  "<<c<<endl;
			}
		}
		void show() {
			bubblesort();
			cout<<"\n  ###SHOW RECORD### \n"<<endl;
			if(first==NULL) {
				cout<<"Record is not available!";
				return;
			}
			node *ptr=first;
			while(ptr!=NULL) {
				cout<<"Room Id: "<<ptr->id<<endl;
				cout<<"Customer Name: "<<ptr->name<<endl;
				cout<<"CNIC: "<<ptr->cnic<<endl;
				cout<<"Gender: "<<ptr->gender<<endl;
				cout<<"Room type:"<<ptr->roomtype<<endl;
				cout<<"____________________"<<endl;
				ptr=ptr->next;
			}
		}
		void bubblesort() {
			int swapped, i;
			node *ptr1;
			node *lptr = NULL;
			if (first == NULL)
				return;
			do {
				swapped = 0;
				ptr1 = first;
				while (ptr1->next != lptr) {
					if (ptr1->id > ptr1->next->id) {
						string	i=ptr1->id;
						string n=ptr1->name;
						string cn=ptr1->cnic;
						char g=ptr1->gender;
						string r=ptr1->roomtype;
						ptr1->id=ptr1->next->id;
						ptr1->name=ptr1->next->name;
						ptr1->cnic=ptr1->next->cnic;
						ptr1->gender=ptr1->next->gender;
						ptr1->roomtype=ptr1->next->roomtype;
						ptr1->next->id=i;
						ptr1->next->name=n;
						ptr1->next->cnic=cn;
						ptr1->next->gender=g;
						ptr1->next->roomtype=r;
						swapped = 1;
					}
					ptr1 = ptr1->next;
				}
				lptr = ptr1;
			} while (swapped);
		}
};
int  main() {
	hotel h1;
	h1.menu();
	//h1.show();
}
