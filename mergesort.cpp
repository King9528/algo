#include<iostream>
using namespace std;
void merge(int arr[],int left,int mid,int right,int &comp)
{
  int i=left;//variable at the beginninfg of the left part
  int j=mid+1;//variable at the beginninfg of the right part
  int count=0;//variable for the temp array
  int temp[right-left+1];
  while(i<=mid&&j<=right)
  {
    if(arr[i]<=arr[j])
    {
        temp[count]=arr[i];
        i++;count++;comp++;
    }
    else
    {
        temp[count]=arr[j];
        j++;count++;comp++;
    }
  }
  if(i>mid)
  {
    while(j<=right)
    {
        temp[count]=arr[j];
        count++;j++;
    }
  }
  if(j>right)
  {
    while(i<=mid)
    {
        temp[count]=arr[i];
        count++;i++;
    }
  }
  int k=0;
  for(int t=left;t<=right;t++)
  {
    arr[t]=temp[k++];
  }
}
void mergesort(int arr[],int left,int right,int &comp)
{
 if(left<right)//it will work till the left is less than right int other words when only one elements remain after division
 {
    int mid=(right+left)/2;
    mergesort(arr,left,mid, comp);
    mergesort(arr,mid+1,right,comp);
    merge(arr,left,mid,right,comp);
 }
}
int main()
{
    int n;//variable for the size of the array
    cout<<"Enter the number of elememts in the array:";//entering the number of elelmets in array
    cin>>n;
    int arr[n];//declaring an array of size of n
    cout<<endl<<"Enter the array;"<<endl;//entering the array
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int left=0;
    int right=n-1;
    int comp=0;
    mergesort(arr,left,right,comp);//passing the left rigth and the array to the merge sort function
    //printing the array after the meerge sort
    cout<<"your array is:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    cout<<"Your number of comparisons is "<<comp;
    return 0;
}
