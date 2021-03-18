#include<iostream>

using namespace std;

void init();
void Quick_sort(int l,int r);
void Print();

int size;
int *arr;

int main(){
	
	init();
	
	return 0;
}

void init(){
	cin >> size;
	arr = new int[size];
	for(int i=0;i<size;i++){
		cin>>arr[i];
	}
	Quick_sort(0,size-1);
	Print();
	delete []arr;
}

void Quick_sort(int l,int r){
	int pl = l;
	int pr = r;
	int x = arr[(l+r)/2];
	do {
		while(arr[pl]<x)pl++;
		while(arr[pr]>x)pr--;
		if(pl<=pr){
			int temp = arr[pl];
			arr[pl]=arr[pr];
			arr[pr]=temp;
			pl++;
			pr--;
		}
	}while(pl<=pr);
	if(l<pr)Quick_sort(l,pr);
	if(r>pl)Quick_sort(pl,r);
}

void Print(){
	for(int i=0;i<size;i++){
		cout << arr[i] << endl;
	}
}			   
			   
			