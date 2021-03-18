#include<iostream>
#include<set>

using namespace std;

set<int> S1[21] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
set<int> S[21]={0,};
int M;

int main(){
	
	ios::sync_with_stdio(0);
    cin.tie(0);
	
    cin >> M;
    for(int i=0;i<M;i++){
        string cal;
        int num;
        cin >> cal;
		//추가
        if(cal.compare("add")==0){
			cin >> num;
			S[num].insert(1);
		}
		//제거
		else if(cal.compare("remove")==0){
			cin >> num;
			S[num].insert(0);
		}
		//확인
		else if(cal.compare("check")==0){
			cin >> num;
			cout << (int)S[num] << "\n";
		}
		//토글
		else if(cal.compare("toggle")==0){
			cin >> num;
			S[num].insert((S[num]>0?0:1));
		}
		//초기화
		else if(cal.compare("all")==0){
			S = S1;
		}
		//비우기
		else if(cal.compare("empty")==0){
			S.clear();
		}
    }
	
}