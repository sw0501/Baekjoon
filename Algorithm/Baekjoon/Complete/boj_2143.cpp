#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void init();
int Move(int index,vector<long long>&temp);

long long T;
int N,M;
int arr[1000];
vector<long long>A;
vector<long long>B;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	cin >> T;
	cin >> N;
	
	long long temp = 0;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		temp+=num;
		A.push_back(temp);
	}
	
	//DFS(0,N,0,&A,0);
	
	cin >> M;
	temp = 0;
	for(int i=0;i<M;i++){
		int num;
		cin >> num;
		temp+=num;
		B.push_back(temp);
	}
	
	for(int i=0;i<N;i++){
		for(int j=N-1;j>=i;j--){
			//i==j인 경우는 이미 벡터에 들어있어서 제외
			if(i!=j)A.push_back(A[j]-A[i]);
		}
	}
	
	for(int i=0;i<M;i++){
		for(int j=M-1;j>=i;j--){
			//i==j인 경우는 이미 벡터에 들어있어서 제외
			if(i!=j)B.push_back(B[j]-B[i]);
		}
	}
	
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	reverse(B.begin(),B.end());
	
	int startA=0,startB=0;
	long long answer = 0;
	
	while(startA<A.size()&&startB<B.size()){
		long long sum = A[startA] + B[startB];
		if(sum==T){
			long long sA = Move(startA,A);
			long long sB = Move(startB,B);
			answer += sA*sB;
			startA += sA;
			startB += sB;
		}
		else if(sum<T){
			startA += Move(startA,A);
		}
		else{
			startB += Move(startB,B);
		}
	}
	
	cout << answer << "\n";
	
	// 7 5 4 1 6 4 3 
	// 1 1 2 3 3 4 4 5 6 7
	// 1 2 3 4 5 6
}

int Move(int index,vector<long long>&temp){
	long long ans = 1;
	if(index==temp.size()-1)return ans;
	while(temp[index]==temp[index+1]){
		ans++;
		index++;
		if(index==temp.size()-1)return ans;
	}
	return ans;
}


