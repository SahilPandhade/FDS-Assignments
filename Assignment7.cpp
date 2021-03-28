#include<iostream>
using namespace std;
int n;                                      //global variable n for array size
//Swap function to swap two array elements
void swap(int *a,int *b,int arr[])
{
    int temp=*a;
    *a=*b;
    *b=temp;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<" "<<arr[i]<<" ";
    }
}
//Function to sort array by bubble sort algorithm
void bubblesort(int arr[])
{
    for(int i=0;i<n-1;i++)
    {
        int flag=0;                                 //flag indicates whether a swap took place or not
        cout<<"\n Pass:"<<i+1<<" ";
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1],arr);        //call swap function if element greater than next element
                flag=1;
            }
        }
            if(flag==0)
            {
                cout<<"Array Sorted\n";
                break;                              //break out of loop if no swap took place i.e. array is now sorted
            }
        }
}
    
//Function to search for a element according to binary search
    int binarysearch(int arr[],int first,int last,int x)
    {
        if(last>=first)
        {
            int mid=first+(last-first)/2;
            if(arr[mid]==x)
            {
                return mid;
            }
            else if(arr[mid]>x)
            {
                return binarysearch(arr,first,mid-1,x);
            }
            else{
                return binarysearch(arr,mid+1,last,x);
            }
            
        }
        return -1;
    }
    //Display function
    void display(int arr[])
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
            cout<<endl;
        }
    }
    
//main function
int main()
{
    
    char c;
    do{
    cout<<"\nEnter array size\n";
    cin>>n;                                         //Get array size from user
    int arr[n];
    cout<<"Enter the array\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];                                //take array input from user
    }
    cout<<"\nArray before sort:\n";
    display(arr);
    cout<<"\nArray after sort:\n";
    bubblesort(arr);                                //Calling the bubblesort function
    display(arr);                                   //Display sorted array

    do{
        int num;
        cout<<"Enter the element to search for:\n";
        cin>>num;                                   //Get element to search from the user
        
        int pos=binarysearch(arr,0,n-1,num);
        if(pos==-1)
        {
            cout<<"Element not present in array\n";
        }
        else{
            cout<<"Element "<<num<<" present at index: "<<pos;
            
        }
        cout<<"Do you want to continue searching?(Y/N)";
        cin>>c;
        
    }while(c=='Y'||c=='y');
        cout<<"Do you want to repeat?(Y/N)";
        cin>>c;
    }while(c=='Y'||c=='y');
 return 0;
}

