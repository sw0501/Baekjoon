#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void init();
long long Move(int index,vector<long long>&temp);	//합이 같은 쌍의 개수만큼 이동

int N;
vector<long long>A;
vector<long long>B;
vector<long long>C;
vector<long long>D;
vector<long long>L;
vector<long long>R;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	
	cin >> N;
	for(int i=0;i<N;i++){
		long long a,b,c,d;
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
	
	for(int i=0;i<A.size();i++){
		for(int j=0;j<B.size();j++){
			L.push_back(A[i]+B[j]);
		}
	}
	
	for(int i=0;i<C.size();i++){
		for(int j=0;j<D.size();j++){
			R.push_back(C[i]+D[j]);
		}
	}
	
	sort(L.begin(),L.end());
	sort(R.begin(),R.end());
	//중간에서만나기 (MITM) 사용을 위해서 반대로 정렬
	reverse(R.begin(),R.end());
	
	int start1=0;
	int start2=0;
	
	long long answer = 0;
	
	while(start1<L.size()&&start2<R.size()){
		long long sum = L[start1]+R[start2];
		if(sum==0){
			//합이 같은 쌍이 여러개인 경우 곱
			long long s1 = Move(start1,L);
			long long s2 = Move(start2,R);
			answer += s1*s2;
			start1 += s1;
			start2 += s2;
		}
		else if(sum>0){
			start2 += Move(start2,R);
		}
		else {
			start1 += Move(start1,L);
		}
	}
	
	cout << answer << "\n";
}

long long Move(int index,vector<long long>&temp){
	long long ans = 1;
	if(index==temp.size()-1)return ans;
	while(temp[index]==temp[index+1]){
		ans++;
		index++;
		if(index==temp.size()-1)return ans;
	}
	return ans;
}



