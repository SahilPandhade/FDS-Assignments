//Implementation of stack using array and linked list to push,pop and display elements in Cpp
#include<iostream>
using namespace std;

int stack[100],top=-1,n=100;                //Global data for array implementation

struct Node{
    int data;
    struct Node *next;
};
struct Node *up=NULL;

//Function to push element on stack(using linked list)
void pushl(int x)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=up;
    up=newnode;
}

//Function to pop element on Stack(using Linked List)
void popl()
{
    if(up==NULL)
    {
        cout<<"Stack Underflow!\n";
    }
    else{
        cout<<"Popped element: "<<up->data<<endl;
        up=up->next;
    }
}

//Function to Display stack elements(using Linked list)
void displayl()
{
    struct Node* ptr;
    if(up==NULL)
    {
        cout<<"Stack empty\n";
    }
    else{
        ptr=up;
        cout<<"Stack elements: ";
        while(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr=ptr->next;
        }
    }
    cout<<endl;
}

//------------Array Implementation------------
//Function to Push element on stack using Array
void push(int x)
{
    if(top>=n-1)
    {
        cout<<"Stack Overflow!\n";
    }
    else{
        stack[++top]=x;
    }
}

//Function to pop a stack element(using array)
void pop()
{
    if(top<=-1)
    {
        cout<<"Stack underflow!\n";
    }
    else{
        cout<<"Popped element: "<<stack[top]<<endl;
        top--;
    }
}

//Function to display Stack elements(using Array)
void display()
{
    if (top>=0)
    {
        cout<<"Elements of stack are:  ";
        for(int i=top;i>=0;i--)
        {
            cout<<stack[i]<<" ";
        }
            cout<<endl;
    }
        else{
            cout<<"empty Stack\n";
        }
    
}


//Main function 
int main()
{
    int choice,x,y;
    cout<<"Implement using:\n1.Array\n2.Linked List\n";
    cin>>y;
    switch(y)
    {
        //For Array implementation
        case 1:{
    
    cout<<"Press:\n1.push a element on stack\n2.Pop an element.\n3.display Stack\n4.Exit\n";
    do{
        cout<<"enter choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter element to push\n";
                cin>>x;
                push(x);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                cout<<"Exit\n";
                break;
            default:
                cout<<"Wrong input\n";
        }
        
        }while(choice!=4);
        break;
        }
        
        
        //For Linked list implementation
        case 2:{
            cout<<"Press:\n1.push a element on stack\n2.Pop an element.\n3.display Stack\n4.Exit\n";
    do{
        cout<<"enter choice\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter element to push\n";
                cin>>x;
                pushl(x);
                break;
            case 2:
                popl();
                break;
            case 3:
                displayl();
                break;
            case 4:
                cout<<"Exit\n";
                break;
            default:
                cout<<"Wrong input\n";
        }
        
        }while(choice!=4);
            
            break;
        }
    }        
return 0;
}



