#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
        a=b;
        b=temp;
}

int partition(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<=pivot)
        {
            swap(arr[++i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quicksort(int arr[],int low, int high)
{
    if(low<high)
    {
        int pos=partition(arr,low,high);
        quicksort(arr,low,pos-1);
        quicksort(arr,pos+1,high);
    }
}
int main()
{
    //int comp=0;
    int n;//variable for the size of the array
    cout<<"Enter the number of elememts in the array:";//entering the number of elelmets in array
    cin>>n;
    int arr[n];//declaring an array of size of n
    cout<<endl<<"Enter the array;"<<endl;//entering the array
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int low=0;
    int high=n-1;
    quicksort(arr,low,high);//passing the left rigth and the array to the quick sort function
    //printing the array after the quick sort
    cout<<"your array is:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    return 0;
}
