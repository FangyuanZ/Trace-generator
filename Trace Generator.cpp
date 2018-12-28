#include<iostream.h>
#include<stdlib.h>
#include<math.h> double floor(double x)
#include<math.h>
#include<vector>
using namespace std;


int RAND(int max, int min, int n)  //generate a random number
{
	for(int i=0; i<n; i++)
	{	
		int u= (double)rand() / (RAND_MAX + 1) * (max-min) + min +1 ;
		return u;
	}
}

int EQU(int a, int b, int c) //find the result of the multiplication of two consecutive number(find r)
{
	int x=(-b+sqrt(b*b-4*a*c))/2*a;
	return x;
}

int CMP(int s) //determine whether the integer can be devided into the multiplication of two consecutive number
{
	for(int i=2;i<s;i++)
	{
		if(s==i*(i-1)) 
		{	return 1;
			break;
		}
	}
	return 0;
}

int CMP2(int t)  //determine whether the integer is even or odd
{	
	if(t%2==0)
		return 0;
	else
		return 1;
}

int MAX(int f)  //solve the inequility
{

	int i=2;
	while(i*(i-1)<f)
	{
		i++;
	}
	return i-1;
}


void main()
{
	int i=0,j=0,k=0; 
	int m,n,u,r;
	double relatedness;
	

	cout<<"please input the number of tasks"<<endl; //input three parameters
	cin>>n;

	cout<<"please input the number of task 1"<<endl;
	cin>>m;

	cout<<"please input the relatedness"<<endl;  
	cin>>relatedness;


	int f=floor(n*(n-1)*relatedness);  //the number of pairs with occurrence patterns


	if(CMP(f))//situation 1
	{
		r=EQU(1,-1,-f);	// the number of tasks with occurrence patterns in 1-projection including task 1


		vector<int> array(r);

		for(k=0;k<r;k++)     //the random number of times for which each task shows in each row :from <1> to <5>
		{
			array[k]=RAND(5,1,1);
			array[0]=1;
		}

		vector< vector<int> > Array(m, vector<int>(0)); //Define a two-dimension array
		for(j=0; j<m; j++) //control the number of rows(m) by j
		{
			for(i=0;i<r;i++)    //generate tasks row by row which have occurence patterns in A-transactionalized trace 
			{
				for(k=0;k<array[i];k++)
				{
					Array[j].push_back(i+1);
				}

			}	
		}

		vector<int> brray(m); //generate randomly for the rest tasks

		int x=n-r;
	
		for(j=0;j<x;j++)
		{
			for(k=0;k<m;k++)
			{
				brray[k]=RAND(5,0,1);

				for(int q=0;q<brray[k];q++)
				{
					Array[k].push_back(r+1);
				}
			
			}
			r++;

		}

		cout<<"The output trace is: "<<endl;
		for(j=0;j<m;j++)//show the result
		{
			for(i=0;i<Array[j].size();i++)
			{
				cout<<Array[j][i]<<" ";
			}
			cout<<endl;
		}

	}


	if(!(CMP2(f))&&!(CMP(f)))//scenario 1
	{
		r=MAX(f);

		int num=r;

		vector<int> array(r);

		for(k=0;k<r;k++)     //the number of patterns
		{
			array[k]=RAND(5,1,1);
			array[0]=1;
		}

		vector< vector<int> > Array(m, vector<int>(0)); //Define a two-dimension array
		for(j=0; j<m; j++) //control the number of rows(m) by j
		{
			for(i=0;i<r;i++)    //generate tasks row by row that have occurence patterns in A-transactionalized trace 
			{
				for(k=0;k<array[i];k++)
				{
					Array[j].push_back(i+1);
				}

			}	
		}

		vector<int> brray(m);//generate the rest of the tasks randomly

		int x=n-r;
	
		for(j=0;j<x;j++)
		{
			for(k=0;k<m;k++)
			{
				brray[k]=RAND(5,0,1);

				for(int q=0;q<brray[k];q++)
				{
					Array[k].push_back(r+1);
				}
			
			}
			r++;

		}

		vector<int>::iterator it;//step 1: remove task "r+1"

		for(k=0;k<m;k++)
		{

			for(it=Array[k].begin();it!=Array[k].end();)
			{
				if(*it ==(num+1))
					it=Array[k].erase(it);
				else
					++it;
			}
		}

		int g=(f-num*(num-1))/2; //the number of pairs with occurrence patterns left to add
		int flag=0;
		int u=Array[0].size();
	

		for(i=0;i<m;i++) //find the max size of the sub-trace in each row
		{
			if(u>Array[i].size())
				u=Array[i].size();
		}
			

		for(it=Array[0].begin();*it<(g+1);it++)
		{
			if(*it !=(g+1))
				flag++;
		}
		
		Array[0].insert(Array[0].begin()+flag,num+1); //let task r+1 is inserted right after task g(k in the expanation)

		Array[m-1].insert(Array[m-1].begin()+Array[m-1].size(),num+1);
		for(k=1;k<m-1;k++) //step 2: insert in a random position after task g in each row
		{
	
		
	
			Array[k].insert(Array[k].begin()+flag,num+1);
		
		}

	
		cout<<"The output trace is: "<<endl;
		for(j=0;j<m;j++)
		{
			for(i=0;i<Array[j].size();i++)
			{
				cout<<Array[j][i]<<" ";
			}
			cout<<endl;
		}
	

	}


	if(CMP2(f))//scenario 2
	{

		r=MAX(f);

		int num=r;

		vector<int> array(r);

		for(k=0;k<r;k++)    
		{
			array[k]=RAND(5,1,1);
			array[0]=1;
		}

		vector< vector<int> > Array(m, vector<int>(0)); //Define a two-dimension array
		for(j=0; j<m; j++) //control the number of rows(m) by j
		{
			for(i=0;i<r;i++) //generate tasks row by row that have occurence patterns in A-transactionalized trace 
			{
				for(k=0;k<array[i];k++)
				{
					Array[j].push_back(i+1);
				}

			}	
		}

		vector<int> brray(m);

		int x=n-r;
	
		for(j=0;j<x;j++)
		{
			for(k=0;k<m;k++)
			{
				brray[k]=RAND(5,0,1);

				for(int q=0;q<brray[k];q++)
				{
					Array[k].push_back(r+1);
				}
			
			}
			r++;

		}

		vector<int>::iterator it;//step 1

		for(k=0;k<m;k++)
		{

			for(it=Array[k].begin();it!=Array[k].end();)
			{
				if(*it ==(num+1))
					it=Array[k].erase(it);
				else
					++it;
			}
		}

		int g=(f+1-num*(num-1))/2;
		int flag=0;
		int u=Array[0].size();
	

		for(i=0;i<m;i++)
		{
			if(u>Array[i].size())
				u=Array[i].size();
		}
			

	
		for(it=Array[0].begin();*it<(g+1);it++)
		{
			if(*it !=(g+1))
				flag++;
		}
		

		Array[0].insert(Array[0].begin()+flag,num+1);//step 2
		Array[m-1].insert(Array[m-1].begin()+Array[m-1].size(),num+1);

		for(k=1;k<m-1;k++)
		{
	
		
		
			Array[k].insert(Array[k].begin()+flag,num+1);
		
		}

		for(k=1;k<m;k++)//step 3
		{
			Array[k].insert(Array[k].begin()+1,num+1);
		}

		cout<<"The output trace is: "<<endl;

		for(j=0;j<m;j++)
		{
			for(i=0;i<Array[j].size();i++)
			{
				cout<<Array[j][i]<<" ";
			}
			cout<<endl;
		}
	
	}
}

