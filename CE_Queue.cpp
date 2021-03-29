//Perform implementation of Queue using array and Linked List a.Enqueue b. Dequeue in Cpp

#include <iostream>
using namespace std;

//--------------------Implementation of queue using array--------------------------------
#define N 50
int queue_arr[N];
int front = -1;
int rear= -1;

//Enqueue Function
void enqueue()
{
   int i;
   if(rear == N-1){
       cout << "Overflow" << endl;
   }
   else if(front == -1 && rear== -1)
   {
       front=0;
       rear=0;
       cout<< "Add the element in queue : "<< endl;
       cin >> i;
       queue_arr[rear] = i;
   }
   else
   {
       rear++;
       cout<< "Insert the element in queue : "<< endl;
       cin >> i;
       queue_arr[rear] = i;
   }
}

//Dequeue function
void dequeue()
{
    if (front == -1 || front>rear)
    {
        cout << "Underflow \n"<< endl;
        return ;
    }
    else
    {
        cout << "Deleted element: "<< queue_arr[front] << endl;
        front = front + 1;
        cout << endl;
    }
}

//Display function
void display()
{
    int j;
    if((front==rear) || (front==rear==-1)){
        cout << "Queue is empty." << endl;
    }
    
    else{
        for(j=front; j<=rear; j++){
            cout << queue_arr[j] << " ";
        }
        cout << "\n";
    }
}
void using_array()
{
   int choice;
    while (1)
    {
        cout << "\n";
        cout << "\n1.Add an element to queue \n2.Delete an element from queue \n3.Display all elements of queue\n4.Exit";
        cout << "\nEnter your choice from the menu: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                cout << "\nWrong choice!!!";
        } 
    }
      
}

//-----------Implementation of queue using Linked list------------------------

struct node {
   int data;
   struct node *next;
};
struct node* frontt = NULL;
struct node* rearr = NULL;
struct node* temp;
//Enqueue function
void enqueuel() 
{
   int val;
   cout<<"Insert the element in queue : "<<endl;
   cin>>val;
   if (rearr == NULL) {
      rearr = (struct node *)malloc(sizeof(struct node));
      rearr->next = NULL;
      rearr->data = val;
      frontt = rearr;
   } else {
      temp=(struct node *)malloc(sizeof(struct node));
      rearr->next = temp;
      temp->data = val;
      temp->next = NULL;
      rearr = temp;
   }
}
//Dequeue function
void dequeuel()
{
   temp = frontt;
   if (frontt == NULL) {
      cout<<"Underflow"<<endl;
      return;
   }
   else
   if (temp->next != NULL) {
      temp = temp->next;
      cout<<"Element deleted from queue is : "<<frontt->data<<endl;
      free(frontt);
      frontt = temp;
   } else {
      cout<<"Element deleted from queue is : "<<frontt->data<<endl;
      free(frontt);
      frontt = NULL;
      rearr = NULL;
   }
}

//Display function
void displayl() {
   temp = frontt;
   if ((frontt == NULL) && (rearr == NULL)) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements : ";
   while (temp != NULL) {
      cout<<temp->data<<" ";
      temp = temp->next;
   }
   cout<<endl;
}

void using_linked_list()
{
     int ch;
   do {
        cout<<"1. Insert element to queue(Enqueue)\n";
        cout<<"2. Delete element from queue(Dequeue)\n";
        cout<<"3. Display elements of queue\n";
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice from the menu: "<<endl;
      
      cin>>ch;
      switch (ch) {
         case 1:
            enqueuel();
         break;
         case 2:
            dequeuel();
         break;
         case 3: 
            displayl();
         break;
         case 4: 
            exit(0);
         break;
         default: 
            cout<<"Wrong choice!!!"<<endl;
      }
   } while(ch!=4);
}
//Main function
int main()
{
    cout<<"Queue implementation using two types :\n";
    cout<<"1.Using Array\n2.Using Linked list\n";
    int choice;
    cin>>choice;
    switch (choice)                                         //Switch cases for different implementations
    {
        case 1 :
            using_array();
            break;
            
        case 2:
            using_linked_list();
            break;
        case 3:
            exit(0);
        default:
            cout<<"Wrong Choice!!!";
    }
    return 0;
}

