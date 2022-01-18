#include <bits/stdc++.h>

using namespace std;

void init();
int Move(int index,vector<long long>&temp);


int T;
int A,B;
int arrA[1000];
int arrB[1000];
vector<long long>vA;
vector<long long>vB;

int main(){
	
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	init();
	
	
	return 0;
}

void init(){
	
	long long answer = 0;
	int sum = 0;

	cin >> T >> A >> B;
	
	for(int i=0;i<A;i++){
		cin >> arrA[i];
		sum += arrA[i];
	}
	
	for(int i=0;i<A;i++){
		int temp = 0;
		//원형배열처럼 이용하기 위해 i+A-1로 놓고 범위 밖으로 벗어난경우 j%A로 해당하는 배열값 
		for(int j=i;j<i+A-1;j++){
			temp += arrA[j%A];
			vA.push_back(temp);
		}
	}
	
	vA.push_back(sum);
	vA.push_back(0);
	
	
	sum = 0;
	for(int i=0;i<B;i++){
		cin >> arrB[i];
		sum+=arrB[i];
	}
	
	for(int i=0;i<B;i++){
		int temp = 0;
		for(int j=i;j<i+B-1;j++){
			temp += arrB[j%B];
			vB.push_back(temp);
		}
	}
	
	vB.push_back(sum);
	vB.push_back(0);
	
	sort(vA.begin(),vA.end());
	sort(vB.begin(),vB.end());
	reverse(vB.begin(),vB.end());
	
	int startA=0,startB=0;
	
	
	while(startA<vA.size()&&startB<vB.size()){
		long long sum = vA[startA] + vB[startB];
		if(sum==T){
			int ansA = Move(startA,vA);
			int ansB = Move(startB,vB);
			answer += ansA*ansB;
			startA += ansA;
			startB += ansB;
		}
		else if(sum<T){
			int ansA = Move(startA,vA);
			startA += ansA;
		}
		else{
			int ansB = Move(startB,vB);
			startB += ansB;
		}
	}
	
	
	cout << answer << "\n";
	
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



