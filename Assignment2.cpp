//A Cpp program to enter a matrix and print its transpose of its sparse matrix using simple and fast technique
#include<iostream>
using namespace std;

//function to convert matrix to sparse matrix
void sparse(int matrix[20][20],int smatrix[20][20],int row,int col,int value)
{
    int k=1;
    smatrix[0][0]=row;
    smatrix[0][1]=col;
    smatrix[0][2]=value;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(matrix[i][j]!=0)
            {
                smatrix[k][0]=i;
                smatrix[k][1]=j;
                smatrix[k][2]=matrix[i][j];
                k++;
            }
        }
       cout<<"\n";
    }
    cout<<"Sparse matrix is:\n";                    //Printing the sparse matrix
    for(int i=0;i<k;i++)
    {
        cout<<smatrix[i][0]<<"\t"<<smatrix[i][1]<<"\t"<<smatrix[i][2]<<"\n";
    }
}

//function for simple transpose the given sparse matrix
void simple(int smatrix[20][20],int col,int val)
{
    int k=1,b[20][20];
    b[0][0]=smatrix[0][1];
    b[0][1]=smatrix[0][0];
    b[0][2]=smatrix[0][2];
    for(int i=0;i<col;i++)
    {
        for(int j=1;j<val+1;j++)
        {
            if(smatrix[j][1]==i)
            {
                b[k][0]=smatrix[j][1];
                 b[k][1]=smatrix[j][0];
                  b[k][2]=smatrix[j][2];
                  k++;
            }

        }

    }
    //printing the transposed matrix
    cout<<"After simple transpose,matrix is:\n";
    for(int i=0;i<k;i++)
    {
        cout<<b[i][0]<<"\t"<<b[i][1]<<"\t"<<b[i][2]<<"\n";

    }

}
//function to fast transpose the sparse matrix
void ftranspose(int smatrix[20][20])
{
	int i,temp[20][20],col,loc,total[10],index[10];
		temp[0][1]=smatrix[0][0];
		temp[0][0]=smatrix[0][1];
		temp[0][2]=smatrix[0][2];
		for(i=0;i<smatrix[0][1];i++)
        {
            total[i]=0;
        }
	for(i=1;i<=smatrix[0][2];i++)
	{
		col=smatrix[i][1];
		total[col]++;
	}
		index[0]=1;

	for(i=1;i<smatrix[0][1];i++)
	{
	    index[i]=index[i-1]+total[i-1];
	}

	for(i=1;i<=smatrix[0][2];i++)
    {
		col=smatrix[i][1];
		loc=index[col]++;
		temp[loc][0]=smatrix[i][1];
		temp[loc][1]=smatrix[i][0];
		temp[loc][2]=smatrix[i][2];
	}
	//Printing the transposed matrix
	cout<<"Fast transpose:"<<endl;

	for(i=0;i<=smatrix[0][2];i++)
	{
		cout<<temp[i][0]<<"\t"<<temp[i][1]<<"\t"<<temp[i][2]<<endl;
	}

}

int main()
{
    transpose:                                          //Label 1
    int m,n,val=0,a[20][20],smatrix[20][20],ch;
    char choice,choice2;
    cout<<"Enter the number of rows and columns:";
    cin>>m>>n;
    cout<<"Enter the elements of matrix:\n";          //Taking input for the matrix
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]!=0)
            {
                val++;
            }

        }

    }
    transpose1:                                 //Label 2
    
    sparse(a,smatrix,m,n,val);                  //function call to find the sparse of matrix
    cout<<"Enter your choice from following to transpose the matrix:\n1.Simple Transpose\n2.Fast Transpose :";
    cin>>ch;
    switch(ch)
    {
    case 1:
    	 	simple(smatrix,n,val);              //function call for simple transpose
    	 	break;
    case 2:
    		ftranspose(smatrix);                //function call for fast transpose
    		break;

    }
    cout<<"Do you want to continue(y/n)?"<<endl;
    cin>>choice;
    if(choice=='y'|| choice=='Y')
    {
        cout<<"Do you want to continue with same matrix of enter a new one?(s/n)\n";
        cin>>choice2;

        if(choice2=='s'||choice2=='S')
        {
            goto transpose1;                        //Jump to label transpose1
        }
        else if (choice2=='n'|| choice2=='N')
        {
            goto transpose;                         //jump to label transpose

            }
            else{
                cout<<"Error!Wrong input"<<endl;        //error message for wrong input
            }


    }
    else if (choice=='n'||choice=='N')
        {
            cout<<"Thank you"<<endl;
        }
        else{
            cout<<"Error!Wrong input"<<endl;                //Error message for wrong input
        }
    return 0;
}



