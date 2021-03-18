#include<iostream>
#include<algorithm>

using namespace std;

string str;
int Stick=0;
int Sum=0;

void init();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	//'(' 가 나올때마다 쇠막대기 개수 증가 ')'  나올때마다 쇠막대기 개수 감소 '()' 나오면 그동안 저장한 쇠막대기 개수만큼 총 개수 ++
	cin >> str;
	for(int i=0;i<str.length()-1;i++){
		//쇠막대기 추가
		if(str[i]=='('&&str[i+1]!=')')Stick++;
		//저장한 쇠막대기 개수만큼 총합에 추가
		else if(str[i]=='('&&str[i+1]==')'){
			Sum+=Stick;
			//()를 다 계산햇으므로 건너뜀
			i++;
		}
		//해당 쇠막대기는 더이상 레이저로 안나눠지므로 총합에 더해줌
		else {
			Stick--;
			Sum++;
		}
	}
	//마지막 조각 포함
	cout << Sum+1 << "\n";
}
