#include <iostream>
using namespace std;
template<class T>

class INsort{
	int size;
	public:
	INsort(int &s)
	{
		size=s;
	}
T *array=new T[size];

void printArray()
 {
  for (int i = 0; i < size;i++) 
  {
    cout << "  " << array[i];
  }
  cout << "\n";
}
void insertSort() {
	int count=0;
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;
    if(key=>array[j])
	{
		count++;
	}
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      count++;
      --j;
    }
    array[j + 1] = key;
  }
  cout<<"number of comparisons is:"<<count;
  cout<<endl;
}
void input()
{
cout<<"Enter the array------"<<endl;
  for(int i=0;i<size;i++)
  {
  	cout<<"enter the "<<i+1<<" element:";
  	cin>>array[i];
  	cout<<endl;
  }
}
};
int main() {
	int size;
	cout<<"Enter the size of the array:";
	cin>>size;
	INsort<int> data(size);
  
  data.input();
  data.insertSort(); 
  cout << "Sorted Array in Ascending Order:\n";  
  data.printArray();
}
