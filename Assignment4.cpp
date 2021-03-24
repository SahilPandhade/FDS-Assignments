//A cpp code to create employee database using singly linked list
#include<iostream>
#include<string>
using namespace std;

//Structure to store information of employee
struct Employee{
	string name;
	int emp_id;
	int salary;
	string dept;
	struct Employee* next;
};

Employee* head;

//Function to insert employee data in data base
void insert(){
	Employee* temp = new Employee();
	
	cout<<"Enter Employee ID,Name,department and salary\n";
	cin>>temp->emp_id >> temp->name >> temp->dept >> temp->salary;
	temp->next = head;
	head = temp;
}

//Functon to remove the required employee data from the records
void Remove()
{
	string name;
	cout<< "Enter name of employee" << endl;
	cin>> name;
	Employee* prev = head;
	while((prev->next)->name != name)
	{
		prev = prev->next;
	}
	Employee* temp = prev->next;
	prev->next = temp->next;
	delete temp;
}

//Function to display the data records
void display(){
	Employee* temp;
	temp = head;
	cout<<"Details are:\nID\tName\tDept\tSalary\n";
	while(temp != NULL){
		cout<< "\n" << temp->emp_id << "\t" << temp->name << "\t" << temp->dept << "\t" << temp->salary << "\n";
		temp = temp->next;
	}
}

//function to search and print the required employee data
void search(){
	string name;
	cout<< "Enter name of employee\n";
	cin>> name;
	Employee* temp = head;  
	while (temp != NULL){  
		if (temp->name == name){
			cout<< "\n" << temp->emp_id << "\n" << temp->name << "\n" << temp->dept << "\n" << temp->salary << "\n";
			return;
		}
		temp = temp->next;  
	}
	cout<< "Employee not found\n";
}

//Function to modify the data of a record
void Modify()
{
    int emp;
    Employee* temp=head;
    cout<<"Enter employee id to modify details\n";
    cin>>emp;
    while(temp!=NULL)
    {
        if(temp->emp_id==emp)
        {
            	cout<<"Enter Employee ID,Name,department and salary\n";
            	cin>>temp->emp_id >> temp->name >> temp->dept >> temp->salary;
            	break;
        }
        temp=temp->next;
    }
}

//Main function
int main()
{
	head = NULL;
	int choice,no_of_p;
	char numb;
	do{
	    
	cout<<"1.Create\n2.Display\n3.Insert\n4.Delete\n5.Search\n6.Modify\n";
	cin>>choice;
	
	//Switch statement to display according to user input
	switch(choice)
	{
		case 1:
		    cout<<"Enter no of people\n";
		    cin>>no_of_p;
		    for(int i=0;i<no_of_p;i++)
		    {
			insert();
			}
			break;
		case 2:
			display();
			break;
		case 3:
			insert();
			break;
		case 4:
			Remove();
			break;
		case 5:
			search();
			break;
		case 6:
		    Modify();
		    break;
		default:
		    cout<<"Error Wrong input\n";
		    break;
		
	}
	cout<<"\nDo you want to continue(Y/N)?\n";
	cin>>numb;
	}
	while(numb=='Y'||numb=='y');
}
	
		







