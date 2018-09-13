#include<iostream>
using namespace std;

class myvector
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

    	myvector()
    	{
    		vsize=0;
    		vcapacity=2;
    		varr = (int *)malloc(vcapacity * sizeof(int));
    	}

    	myvector(int n,int x)
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
    	void vpush_back(int x)
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
    	int vpop()
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
    	void intsertatindex(int ind,int x)
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
    	void eraseatindex(int ind)
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
    	int getfront()
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
    	int getback()
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
    	int getelementatindex(int ind)
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
        int getsize()
        {   
        	return vsize;  
        } 
 
};



int main()
{
	myvector v1;
	//myvector v1(5,1);
	int choice;
	do
	{
		cout<<"\n\n1.push_back(x) : ";
		cout<<"\n2.pop() : ";
		cout<<"\n3.size : ";
		cout<<"\n4.arr[i] : ";
		cout<<"\n5.insert(i,x) : ";
		cout<<"\n6.erase(i) : ";
		cout<<"\n7.front : ";
		cout<<"\n8.back : ";
		cout<<"\n9.Print : ";
		cout<<"\n10.Quit";
		cout<<"\nEnter You choice : ";
		cin>>choice;
		switch(choice)
		{
			int num,ind;
			case 1:
				cout<<"\nEnter element to be inserted  : ";
				cin>>num;
				v1.vpush_back(num);
				break;
			case 2:
				cout<<"\nPop element : "<<v1.vpop();
				break;
			case 3:
				cout<<"\nSize : "<<v1.getsize();
				break;
			case 4:
				cout<<"\nEnter index to find element : ";
				cin>>ind;
				cout<<"\nElement at index "<<ind<<" : "<<v1.getelementatindex(ind);
				break;
			case 5:
				cout<<"\nEnter the index and element : ";
				cin>>ind>>num;
				v1.intsertatindex(ind,num);
				break;
			case 6:
				cout<<"\nEnter the index for erasing element  : ";
				cin>>ind;
				v1.eraseatindex(ind);
				break;
			case 7:
				cout<<"\nfront element : "<<v1.getfront();
				break;
			case 8:
				cout<<"\nback element : "<<v1.getback();
				break;
			case 9:
				cout<<"\nAll element of Vector : ";
				v1.vprint();
				break;
		}

	}while(choice!=10);
	

}