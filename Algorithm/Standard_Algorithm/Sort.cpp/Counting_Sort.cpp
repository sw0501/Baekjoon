#include<iostream>

using namespace std;

int *counting;
int *count_sum;
int arr;
int M=0;
int N;

void init();
void Counting_sort();
void Print();

int main(){
	
	init();	
	
	return 0;
}

void init(){
	
	cin>>N;
	counting = new int[10001];
	count_sum = new int[10001];
	for(int i=0;i<10001;i++){
		counting[i]=0;
	}
	for(int i=1;i<=N;i++){
		cin>>arr;
		if(arr>M)M=arr;
		counting[arr]++;
	}
	count_sum[0]=counting[0];
	for(int i=1;i<=M;i++){
		count_sum[i]=count_sum[i-1]+counting[i];
	}
	Print();
	delete[]counting;
	delete []count_sum;
		

}

void Print(){
	int i = 1;
	while(i<=M){
		if(counting[i]==0){
			i++;
			continue;
		}
		cout<<i<<"\n";
		counting[i]--;
	}
}