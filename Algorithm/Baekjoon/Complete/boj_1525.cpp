#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<set>

using namespace std;

int CK[9] = {0,};
set<string> s;
queue<pair<string,int>> q;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init();
int BFS();

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	init();
	
	
	return 0;
}

void init(){
	string puzzle = "";
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			char temp;
			cin >> temp;
			puzzle += temp;
		}
	}
	
	s.insert(puzzle);
	q.push(make_pair(puzzle,0));
	
	cout << BFS() << "\n";
}

int BFS(){
	while(!q.empty()){
		//큐의 첫번째 원소 pair<string,int> 중 string 저장
		string str = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(str == "123456780"){
			return cnt;
		}
		
		int temp,x,y;
		temp = str.find('0');
		x = temp%3;
		y = temp/3;
		
		
		for(int i=0;i<4;i++){
			string ts = str;
			int tx = x+dx[i];
			int ty = y+dy[i];
			if(tx<0||tx>2||ty<0||ty>2){
				continue;
			}
			int tchar = ts[x+3*y];
			ts[x+3*y] = ts[tx+3*ty];
			ts[tx+3*ty] = tchar;
			if(s.find(ts)==s.end()){
				s.insert(ts);
				q.push(make_pair(ts,cnt+1));
			}
		}
		
	}
	return -1;
}
