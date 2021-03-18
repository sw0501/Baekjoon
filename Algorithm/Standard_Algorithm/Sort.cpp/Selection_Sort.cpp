#include<iostream>
#include<algorithm>

using namespace std;

void init();
void Selection_sort(int arr[],int size);
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
	Selection_sort(arr,size);
	Print(arr,size);
}

void Selection_sort(int arr[],int size){
	for(int i=0;i<size-1;i++){
		int min = i;
		for(int j=i;j<size;j++){
			if(arr[j]<arr[min])min=j;
		}
		int temp = arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
}

void Print(int arr[],int size){
	for(int i=0;i<size;i++){
		cout << arr[i] << endl;
	}
}	
