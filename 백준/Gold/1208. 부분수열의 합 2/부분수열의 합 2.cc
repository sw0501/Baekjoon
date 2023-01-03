#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void init();
void DFS(int index, int sum, int end, vector<int> &temp);
int Move(int index, vector<int> &temp);

int N,S;
vector<int>arr;
vector<int>L;
vector<int>R;

long long answer = 0;

int main(){
	
	/*
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	
	init();
	
	
	return 0;
}

void init(){
	
	
	
	cin >> N >> S;
	for(int i=0;i<N;i++){
		int num;
		cin >> num;
		arr.push_back(num);
	}
	
	
	
	
	//절반씩 나누어서 부분수열의 합을 벡터에 저장 후 정렬
	DFS(0,0,N/2,L);
	DFS(N/2,0,N,R);
	
	
	
	sort(L.begin(),L.end());
	sort(R.begin(),R.end());
	reverse(R.begin(),R.end());
	
	/*
	for(int i = 0;i<L.size();i++){
		cout << L[i] << " ";
	}
	cout << "\n";
	for(int i = 0;i<R.size();i++){
		cout << R[i] << " ";
	}
	cout << "\n";
	*/
	
	int p1=0;
	int p2=0;
	
	while(p1<L.size()&&p2<R.size()){
		int sum = L[p1]+R[p2];
		
		//부분수열의 합이 같은 경우 탐색하여 곱
		if(sum==S){
			long long s1 = Move(p1,L);
			long long s2 = Move(p2,R);
			answer += s1*s2;
			p1 += s1;
			p2 += s2;
		}
		else if(sum>S){
			long long temp = Move(p2,R);
			p2 += temp;
		}
		else {
			long long temp = Move(p1,L);
			p1 += temp;
		}
		//cout << p1 << " " << p2 << " " << sum << " " << answer << "\n";
	}
	
	//공집합인 경우 제외
	if(S==0)answer--;
	
	
	cout << answer << "\n";
	
}

void DFS(int index, int sum, int end, vector<int> &temp){
	
	if(index==end){
		temp.push_back(sum);
		return;
	}
	
	DFS(index+1,sum,end,temp);
	DFS(index+1,sum+arr[index],end,temp);
}

int Move(int index, vector<int> &temp){
	int ans = 1;
	if(index==temp.size()-1)return ans;
	while(temp[index]==temp[index+1]){
		ans++;
		index++;
		if(index==temp.size()-1)return ans;
	}
	return ans;
}

