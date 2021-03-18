#include<iostream>

using namespace std;

void init();
void Buble_sort(int arr[],int size);
void Print(int arr[],int size);

int main(){
	
	init();
	
	return 0;
}

void init(){
	int size;
	cin >> size;
	int *arr = new int[size];
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	Buble_sort(arr,size);
	delete []arr;
}

void Buble_sort(int arr[],int size){
	int temp;
	for(int i=0;i<size-1;i++)
	{
		for(int j=i;j<size;j++)
		{
			if(arr[i]<arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	Print(arr,size);
}

void Print(int arr[],int size){
	for(int i=0;i<size;i++){
		cout << arr[i] << endl;
	}
}			   
			   
			