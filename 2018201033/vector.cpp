//**********************************************************************
// RollNo: 2018201033 Name : Darshan Kansagara
//**********************************************************************

#include<iostream>
#include<stdlib.h>
using namespace std;

class vector
{
    private:
        int vsize;  // define size of vector
        int vcapacity;  //define vector capacity
        int *varr;  //Vector to store numbers


        //**********************************************************************
        // Allocating Memory when need to increases Vector capacity
        //**********************************************************************
       	void allocatememory()
       	{
       		//cout<<"\nBefore push :"<<" vsize : "<<vsize<<" vcapacity : "<<vcapacity<<endl;
    		varr = (int *)realloc(varr, sizeof(int)*(vcapacity*2));
    		vcapacity=vcapacity*2;
    		//cout<<"\nAfter push : "<<" vsize : "<<vsize<<" vcapacity : "<<vcapacity<<endl;
       	}


        //**********************************************************************
        // Deallocating Memory When vector size reduces
        //**********************************************************************
       	void deallocatememory()
       	{
       		//cout<<"\nBefore pop :"<<" vsize : "<<vsize<<" vcapacity : "<<vcapacity<<endl;
			varr = (int *)realloc(varr, sizeof(int)*(vcapacity/2));
			vcapacity=vcapacity/2;
			//cout<<"\nAfter pop :"<<" vsize : "<<vsize<<" vcapacity : "<<vcapacity<<endl;
       	}

    public:  

    	vector()
    	{
    		vsize=0;
    		vcapacity=2;
    		varr = (int *)malloc(vcapacity * sizeof(int));
    	}

    	vector(int n,int x)
    	{
    		vsize=n;
    		vcapacity=n+2;
    		varr = (int *)malloc(vcapacity * sizeof(int));
    		for(int i=0;i<vsize;i++)
    		{
    			varr[i]=x;
    		}
    	}

        //**********************************************************************
        // Pushing Element into Vector 
        //**********************************************************************
    	void push_back(int x)
    	{
    		if(vsize+1>=vcapacity)
    		{
    			allocatememory();
    		}
    		varr[vsize++]=x;		
    	}

        //**********************************************************************
        // Popout an Element from vector  from end
        //**********************************************************************
    	int pop_back()
    	{
    		int popnumber;
    		if(vsize<=0)
    		{
    			cout<<"\nVector is Empty.!!!"<<endl;
                return -1;
    		}
    		else{

    			popnumber = varr[vsize-1];
    			vsize--;

    			if(((vsize*2)+1)<=vcapacity)
    			{
    				deallocatememory();
    			}

    			return popnumber;
    		}
    	}

        //**********************************************************************
        // Printing whole vector 
        //**********************************************************************
    	void vprint()
    	{
    		if(vsize<1)
    		{
    			cout<<"\nNo Element in an vector !!!"<<endl;
    			return;
    		}
    		cout<<endl;
    		for(int i=0;i<vsize;i++)
    		{
    			cout<<varr[i]<<" ";
    		}
    	}

        //**********************************************************************
        // Inserting an  Element at specific Index in vector
        //**********************************************************************
    	void insert(int ind,int x)
    	{
    		if(vsize<= ind || ind<0)
    		{
    			cout<<"\nGiven Index out of bound !!!"<<endl;
    			return;
    		}
    		if(vsize+1>=vcapacity)
    		{
    			allocatememory();
    		}
    		for(int i=vsize-1;i>=ind;i--)
    		{
    			varr[i+1]=varr[i];
    		}
    		varr[ind]=x;
    		vsize++;
    	}

        //**********************************************************************
        // Deleting element from perticular index
        //**********************************************************************
    	void erase(int ind)
    	{
    		if(vsize<= ind)
    		{
    			cout<<"\nNo Element present at index "<<ind<<endl;
    			return;
    		}
    		for(int i=ind;i<vsize-1;i++)
    		{
    			varr[i]=varr[i+1];
    		}
    		vsize--;

    		if(((vsize*2)+1)<=vcapacity)
			{
				deallocatememory();
			}
    	}

        //**********************************************************************
        // Return Front element 
        //**********************************************************************
    	int front()
    	{
    		if(vsize>=1)
    			return varr[0];
    		else
            {
                cout<<"\nVector is Empty !!!"<<endl;
    			return -1;
            }
    	}

        //**********************************************************************
        // Return Back Element
        //**********************************************************************
    	int back()
    	{
    		if(vsize>=1)
    			return varr[vsize-1];
    		else
            {
                cout<<"\nVector is Empty !!!"<<endl;
    			return -1;
            }
    	}

        //**********************************************************************
        // Return element from perticular index
        //**********************************************************************
    	int v(int ind)
    	{
    		if(ind>=vsize || ind<0)
    		{
                cout<<"\nVector Index out of bound !!!"<<endl;
    			return -1;
    		}
    		else
    			return varr[ind];
    	}

        //**********************************************************************
        // return size of vector
        //**********************************************************************
        int size()
        {   
        	return vsize;  
        } 
 
};

int main()
{
    vector v1;

    cout<<"size : "<<v1.size()<<endl;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    cout<<"size : "<<v1.size()<<endl;
    v1.insert(100,90);
    v1.erase(2);
    for(int i=0;i<v1.size();i++)
    {
       cout<<v1.v(i)<<" ";
    }
    cout<<endl;
    cout<<"Front : "<<v1.front()<<endl;
    cout<<"back : "<<v1.back()<<endl;
    v1.pop_back();
    cout<<"\n Value Pop : \n";
    for(int i=0;i<v1.size();i++)
    {
       cout<<v1.v(i)<<" ";
    }
    cout<<endl;
    v1.insert(4,20);
    cout<<"\nValue inserted : \n";
    for(int i=0;i<v1.size();i++)
    {
       cout<<v1.v(i)<<" ";
    }
    v1.erase(3);
    cout<<"\nvalue erase : \n";
    for(int i=0;i<v1.size();i++)
    {
       cout<<v1.v(i)<<" ";
    }
    cout<<"\nsize is :"<<v1.size()<<endl;
    vector b;
    cout<<b.size()<<endl;
    for(int i=0;i<9;i++)
    {
        b.push_back(3);
    }
    cout<<b.size()<<endl;
    for(int i=0;i<8;i++)
    {
        b.pop_back();
    }
    cout<<b.size()<<endl;
    return 0;
}
