//기본 정렬문제라 주석 달게없음

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int num[1000000];
vector<int>n1;
int main(){
    
    cin >> N;
	
	for(int i=0;i<N;i++){
		n1.push_back(0);
	}
	
    int n;
    for(int i=0;i<N;i++){
		cin>>n1[i];
        //cin>>num[i];
    }
    //sort(num,num+N);
	sort(n1.begin(),n1.end());
    for(int i=0;i<N;i++){
        cout << n1[i] << "\n";
    }
    
    return 0;
}