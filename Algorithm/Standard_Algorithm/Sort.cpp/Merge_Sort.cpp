#include<iostream>

using namespace std;

void init();
void Merge_sort(int s,int e);
void Merge(int s,int m,int e);
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
	Merge_sort(0,size-1);
	Print();
	delete []arr;
}

void Merge_sort(int s,int e){
	if(s<e){
		int m = (s+e)/2;
		Merge_sort(s,m);
		Merge_sort(m+1,e);
		Merge(s,m,e);
	}
}

void Merge(int s,int m,int e){
	int *buff = new int[e-s+1];
	int i=s;
	int j=m+1;
	int copy=0;
	while(i<=m&&j<=e){
		if(arr[i]<arr[j])buff[copy++]=arr[i++];
		else buff[copy++]=arr[j++];
	}
	while(i<=m)buff[copy++]=arr[i++];
	while(j<=e)buff[copy++]=arr[j++];
	for(int k=s;k<=e;k++){
		arr[k]=buff[k-s];
	}
	delete []buff;
}

void Print(){
	for(int i=0;i<size;i++){
		cout << arr[i] << endl;
	}
}			   
			   
			