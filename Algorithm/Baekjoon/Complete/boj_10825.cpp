#include<iostream>
#include<algorithm>

using namespace std;

struct Grade{
	string name;
	int K;
	int E;
	int M;
};

bool compare(Grade x,Grade y);

int main(){
	
	Grade SORT[100001];
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		string name;
		int K,E,M;
		cin >> name >> K >> E >> M;
		SORT[i] = {name,K,E,M};
	}
	sort(SORT,SORT+N,compare);
	for(int i=0;i<N;i++){
		cout << SORT[i].name << "\n";
	}
	return 0;
}

bool compare(Grade x,Grade y){
	if(x.K==y.K){
		if(x.E==y.E){
			if(x.M==y.M){
				return x.name<y.name;
			}
			//수학점수는 내림차순
			return x.M>y.M;
		}
		//영어는 오름차순
		return x.E<y.E;
	}
	//국어점수는 내림차순
	return x.K>y.K;
}

