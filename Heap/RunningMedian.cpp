#include<bits/stdc++.h>

using namespace std;

long long maxhp[100000]={0};
long long minhp[100000]={0};
long long size1;
long long size2;

void maxheap(long long *arr, long long i)
{
    long long max;
    long long left=2*i;
    long long right=(2*i)+1;
    long long len= size1;
    //cout<<"size of tree : "<<len<<endl;
    if(left<=len && arr[left]>arr[i])
    {
        max=left;
    }
    else{
        max = i;
    }
    if(right<=len && arr[right]>arr[max])
    {
        max=right;
    }
    if(max != i)
    {
        long long temp=arr[i];
        arr[i]=arr[max];
        arr[max]=temp;
        maxheap(arr,max);
    }
}
void minheap(long long *arr, long long i)
{
    long long min;
    long long left=2*i;
    long long right=(2*i)+1;
    long long len= size2;
    //cout<<"size of tree : "<<len<<endl;
    if(left<=len && arr[left]<arr[i])
    {
        min=left;
    }
    else{
        min = i;
    }
    if(right<=len && arr[right]<arr[min])
    {
        min=right;
    }
    if(min != i)
    {
        long long temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
        minheap(arr,min);
    }
}

void deleteNode(long long *arr,long long flag)
{
    long long temp;
    if(flag==1)
    {
        //cout<<"Del max first: "<<arr[1];
        //cout<<"Del max last: "<<arr[size1];
        temp=arr[1];
        arr[1]=arr[size1];
        arr[size1]=temp;
        size1--;
        maxheap(arr,1);
    }
    else{

        //cout<<"Del  min first: "<<arr[1];
        //cout<<"Del  min last: "<<arr[size2];
        temp=arr[1];
        arr[1]=arr[size2];
        arr[size2]=temp;
        size2--;
        minheap(arr,1);
    }

}

long long getTop(long long *arr)
{
    return arr[1];
}

void buidMaxHeap(long long *arr,long long x)
{   
    arr[size1+1]=x;
    size1++;
    //cout<<"\nBuildMaxHeap called : "1
    //cout<<"\n Element  : "<<x<<endl;
    //cout<<"\n Size1  : "<<size1<<endl;<<endl;
    long long parent1= floor(size1/2);
    long long cur = size1;
    for(long long parent=parent1;parent>=1;)
    {
        if(arr[cur]>arr[parent])
        {
            long long temp=arr[cur];
            arr[cur]=arr[parent];
            arr[parent]=temp;
        }
        else{
            break;
        }

        cur=parent;
        parent =  floor(parent/2);

    }  
}

void buidMinHeap(long long *arr,long long x)
{
    arr[size2+1]=x;
    size2++;
    //cout<<"\nBuildMinHeap called : "<<endl;
    //cout<<"\n Element  : "<<x<<endl;
    //cout<<"\n Size2  : "<<size2<<endl;
    long long parent1= floor(size2/2);
    long long cur = size2;
    for(long long parent=parent1;parent>=1;)
    {
        if(arr[cur]<arr[parent])
        {
            long long temp=arr[cur];
            arr[cur]=arr[parent];
            arr[parent]=temp;
        }
        else{
            break;
        }

        cur=parent;
        parent =  floor(parent/2);

    }  
}

void rebalanceheap()
{
    if((size1 - size2) >= 2)
    {
        long long temp=maxhp[1];
        deleteNode(maxhp,1);
        buidMinHeap(minhp,temp);

    }
    else if((size2 - size1) >= 2 )
    {
        long long temp=minhp[1];
        deleteNode(minhp,0);
        buidMaxHeap(maxhp,temp);
    }
}

void printMaxHeap()
{
    cout<<"\n***********max **********"<<endl;
    for(long long i=1;i<=size1;i++)
    {
        cout<<maxhp[i]<<" ";
    }
    cout<<"\n*********************"<<endl;
}

void printMinHeap()
{
    cout<<"\n***********min **********"<<endl;
    for(long long i=1;i<=size2;i++)
    {
        cout<<minhp[i]<<" ";
    }
    cout<<"\n*********************"<<endl;
}

double getMedian()
{
    if(size1 > size2)
    {
        return maxhp[1];
    }
    else if(size2 > size1){
        return minhp[1];
    }
    else{
        double temp=(maxhp[1]+minhp[1])/2.0;
        return temp;
    }
}

void addnumbertoheap(long long x)
{
    //cout<<"add number  : "<<x<<endl;
    //cout<<"\nsize1 : "<<size1<<endl;
    if(size1==0 ||  x < maxhp[1])
    {
        buidMaxHeap(maxhp,x);
        //cout<<"\nmaxEle: "<<maxhp[1];
    }
    else
    {
        buidMinHeap(minhp,x);
        //cout<<"\nminEle: "<<minhp[1];
    }
}
int main()
{
    
    size1=0;
    size2=0;

    long long total;
    cin>>total;
    long long stm[total];
    double mdn[total];
    
    for(long int i=0;i<total;i++)
    {
        cin>>stm[i];
    }

    for(long int i=0;i<total;i++)
    {
        //cout<<"stm[i]"<<stm[i]<<endl;
        addnumbertoheap(stm[i]);
        //printMaxHeap();
        //printMinHeap();
        rebalanceheap();
        //printMaxHeap();
        //printMinHeap();
        mdn[i]=getMedian();
        cout<< fixed << setprecision(1)<<mdn[i]<<endl;
    }


    return 0;
}