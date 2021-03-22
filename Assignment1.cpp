//A C++ program to demonstrate string operations with and without pointers
#include<iostream>
using namespace std;

  int len(char s[20])                        //function to calculate length
   {
     int i=0;
     while(s[i]!='\0')
      {
          i++;
      }
      return i;
   }
   void length(char *p)                      //function to calculate length with pointers
   {
     int i=0;
     while(*p!='\0')
      {
          p++;
          i++;
      }
      cout<<"\n Length(using pointers):"<<i;
   }

   void copy(char s[20])                    //function to copy string
   {
       int i=0;
       char t[40]="";
       while(s[i]!='\0')
       {
           t[i]=s[i];
           i++;
       }
       t[i]='\0';
       cout<<"\n Copied string:"<<t;
   }

   void scopy(char *p)                      //function to copy string using pointers
   {
       int i=0;
       char c[40];
       while(*p!='\0')
       {
           c[i]=*p;
           i++;
           p++;
       }
       c[i]='\0';
       cout<<"\n Copied string(With pointers):"<<c;
   }
   int concatenate(char s[20],char t[20])    //function for concatenation of strings
   {
      int i=0,j=0;
      while(s[i]!='\0')
      {
          i++;
      }
      while(t[j]!='\0')
      {
          s[i+j]=t[j];
          j++;
      }
        s[i+j]='\0';
   }

   int concat(char *p,char *k)                  //function to concatenate strings using pointers
   {

      while(*p!='\0')
      {

          p++;
      }

      while(*k!='\0')
      {
          *p = *k;

          p++;
          k++;
      }
      *p = '\0';

   }


   void compare(char s[20],char t[20])      //function for comparision of strings
   {
        int i=0,flag=0;
        for(i=0;s[i]!='\0' || t[i]!='\0';i++)
        {
            if(s[i]>t[i])
            {
                cout<<s<<" is greater than "<<t<<endl;
                flag++;
                break;
            }
            else if(s[i]<t[i])
            {
                cout<<s<<" Is Smaller than "<<t<<endl;
                flag++;
                break;
            }
        }
        if(flag==0)
        {
            cout<<s<<" Is Equal to "<<t<<endl;
        }
    }

    void scompare(char *p,char *k)                      //function for comparing strings using pointers
   {
        int i,count=0;
        for(i=0;*p!='\0'&& *k!='\0';i++)
        {
            if(*p>*k)
            {
                cout<<"(With Pointer)string1 is Greater than string2"<<endl;
                count++;
                break;
            }
            else if(*p<*k)
            {
                cout<<"(With Pointer)string1 is Smaller than string2"<<endl;
                count++;
                break;
            }
             p++;
             k++;
        }
        if(count==0)
        {
            cout<<"(With Pointer)string1 is Equal to string2"<<endl;
        }
    }


    void reverse(char s[20],char t[20])                     //function to reverse strings
   {
      int i=0,j=0;

      while(s[i]!='\0')
      {
          i++;
      }
      for(j=0;j<i;j++)
      {
        t[j]=s[i-j-1];
      }
      t[j]='\0';
       cout<<"\n Reverse:"<<t;
   }

   void sreverse(char *p)                                   //function to reverse string using pointers
   {
      int i,j=0;
      char b[40];
      for(i=0;*p!='\0';i++)
      {
      	  b[i]=*p;
          j++;
          p++;
      }
      cout<<"\n Reversed string(With Pointer) :";
      for(i=j-1;i>=0;i--)
      {
        cout<<b[i];
      }
   }

//Main function
int main()
{
    int numb,m=0;
    char s[40],t[40],ch,*p,*k;

    do
    {
      cout<<"Welcome to string operations.Enter the number in front of your choice given below\n 1.Length\n 2.Copy\n 3.Concatenate \n 4.Compare\n 5.Reverse\n";
      cin>>numb;
      switch(numb)
      {
        case 1:                                                             //case 1 to find the length of string
            cout<<"\nEnter String:";
            cin>>s;
            cout<<"\nString Length:(Without pointer) "<<len(s)<<endl;
            length(s);
            break;

        case 2:                                                             //case 2 to copy the string
            cout<<"\n Enter string:";
            cin>>s;
            copy(s);
            scopy(s);

            break;
        case 3:                                                             //case 3 to concatenate the string
             cout<<"\n Enter first string:";
             cin>>s;
             cout<<"\n Enter second string:";
             cin>>t;
             cout<<"for using pointer press 1 or press 2 for without pointer"<<endl;
             cin>>m;
             if(m==2)
             {
             concatenate(s,t);
             cout<<"Concatenated string(Without pointer) : "<<s<<endl;
             }
             else if(m==1)
             {

             concat(s,t);
             cout<<"Concatenated string(With Pointer) : "<<s<<endl;
             }
             else
             {
                 cout<<"Error!"<<endl;
                 break;
             }
             break;
        case 4:                                                             //case 4 to compare the two strings
             cout<<"\n Enter string:";
             cin>>s;
             cout<<"\n Enter another string:";
             cin>>t;
             compare(s,t);
             scompare(s,t);
            break;
        case 5:                                                             //case 5 to reverse the string.

            cout<<"\n Enter string:";
            cin>>s;
            reverse(s,t);
            sreverse(s);

            break;
      }
      cout<<"\n Press c to continue or press e to exit"<<endl;              //Ask user if they want to continue the operations
      cin>>ch;
    }while(ch=='c'|| ch=='C');
    if(ch=='e'||ch=='E')
    {
        cout<<"Thank You!"<<endl;                                           //Exit
    }
    else
    {
        cout<<"Error"<<endl;                                                //Error message for wrong input
    }
    return 0;
}





