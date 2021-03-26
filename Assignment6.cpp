//Cpp program to simulate pizza parlor
#include<iostream>
#include<cstdlib>
#define max 5
using namespace std;

class pizza
{
    int front,rear,q[max];
     public:
        pizza()                 //Constructor
        {
  	         front=-1;
  	         rear=-1;
        }

    int isfull()                //Check if queue is full or not
    {
     if((front==0&&rear==max-1)||front==rear+1)
    {
  		return 1;
    }
    else
    {
   		return 0;
    }
    }

     int isempty()              //Check if queue is empty or not
    {
        if(front==-1&&rear==-1)
        {
   	         return 1;
        }
         else
        {
   	         return 0;
         }
    }
        //Function to add a order to queue
        void add()
        {
  	         if(isfull()==0)
  	         {
  	 	       cout<<"\n Enter the order ID: ";
  	 	       if(front==-1&&rear==-1)
  	 	       {
  	  		         front=0;
  	  		          rear=0;
  	  		          cin>>q[rear];
  	 	       }
  	 	       else
  	 	         {
  	   		        rear=(rear+1)%max;
  	   		        cin>>q[rear];
  	 	        }

  	            }
  	     else
  	     {
  	 	        cout<<"\n Orders are full ";
  	     }

        }

        //Function to serve the order
        void serve()
        {
  	         if(isempty()==0)
  	         {
  	 	       if(front==rear)
  	 	       {
  	 	 	     cout<<"\n Order served is : "<<q[front];
  	 	 	      front=-1;
  	 	 	      rear=-1;
  	 	       }
  	 	       else
  	 	       {
  	 	 	     cout<<"\n Order served is : "<<q[front];
  	 	 	     front=(front+1)%max;
  	 	       }
  	         }
  	         else
  	        {
  	 	        cout<<"\n Orders are empty ";
  	        }
                }

        //Display function
        void display()
         {
  	         if(isempty()==0)
  	         {
  	            for(int i=front;i!=rear;i=(i+1)%max)
  	             {
  	  	           cout<<q[i]<<" <- ";
  	             }
  	 	       cout<<q[rear];
  	         }
  	         else
  	        {
 	 	        cout<<"\n Orders are empty";
 	         }
        }

        //Check function
         void check()
            {
                while(1){
                int ch;
                cout<<"\n\nPIZZA PARLOR !\n";
                 cout<<"\n 1. Place a order \n 2. Display the Orders \n 3. Serve a pizza \n 4.Exit \n Enter your choice : ";
                cin>>ch;
                switch(ch)
                {
                                case 1:
                                        add();
                                        break;

                                case 2:
                                        display();
                                        break;

                                case 3:
                                        serve();
                                        break;

                                case 4:
                                        exit(0);

                                default:
                                        cout<<" Invalid choice ";
                                        check();
                        }
                }

};
};

//main function
int main()
 {

        pizza p1;
        p1.check();
        return 0;

 }




