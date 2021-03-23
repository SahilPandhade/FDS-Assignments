//A Cpp program to simulate a bank system to add,modify,search and delete the bank details of people 
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>

using namespace std;
//Structure of bank details like name,account number and debt
struct Bank{
	string name;
	string account;
	int debt;
}s[10];
//Main function
int main()
{
	int choice,no_of_people,i=0,debt=0;
	char cont;
	string namet,acc;
	cout<<"Enter number of people\n";                               //Enter number of people
	cin>>no_of_people;
	for(i=0;i<no_of_people;i++)
			{
				cout<<"Enter name,Account number and debt\n";       //Get user input for details
				cin>>s[i].name >> s[i].account >> s[i].debt;
			}
	do{
	cout<<"Enter your choice:\n1.Add\n2.Search\n3.Delete\n4.Display\n";     //Display available options
	cin>>choice;
	
	switch(choice)
	{
		case 1:                                                             //Case to modify existing data base
			cout<<"Enter name,account number and debt to add\n";
			cin>>namet >> acc >> debt;
			s[no_of_people].name=namet;
			s[no_of_people].account=acc;
			s[no_of_people].debt=debt;
			no_of_people++;
			break;
		case 2:
			cout<<"Enter the five digit account number to search\n";        //case to search given account number details
			cin>>acc;
			for(i=0;i<no_of_people;i++)
			{
				if(s[i].account==acc)
				{
				cout<<"Details are:\n";
				cout<<"Name\tAcc No.\tDebt\n";
				cout<<s[i].name <<"\t" << s[i].account <<"\t" << s[i].debt <<"\n";  //Print out details of matched account number
				break;
				}
				
			}
			break;
			
		case 3:
			cout<<"Enter name of account you want to delete\n";                 //case to delete a entry
			cin>>namet;
			for(i=0;i<no_of_people;i++)
			{
				if(s[i].name==namet)
				{
					for(int j=i;j<no_of_people-1;j++)
					{
						s[j].name=s[j+1].name;
						s[j].account=s[j+1].account;
						s[j].debt=s[j+1].debt;
					}
					no_of_people--;
				}
			}
			break;
		case 4:                                                                 //Case to display the entered details
			cout<<"Name\tAcc No.\tDebt\n";
			for(i=0;i<no_of_people;i++)
			{
				cout<<s[i].name<<"\t"<<s[i].account<<"\t"<<s[i].debt<<endl;
			}
			break;
		default:
			cout<<"Error\n";                                                    //Default error message in case of wrong input
			break;
	}
	cout<<"Do you want to continue (y/n)\n";                                    //ask user if he wants to continue the process
	cin>>cont;
	}
while(cont=='Y'|| cont=='y');
return 0;
	
}




