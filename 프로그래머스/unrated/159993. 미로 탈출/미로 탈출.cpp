#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

//상하좌우 이동 배열
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//큐 저장용 구조체
typedef struct _maze{
    int x;
    int y;
    int t;
}maze;

int solution(vector<string> maps) {
    queue<maze>q;
    maze m = {0,0,0};
    int CK[100][100] = {0,};	//레버 방문 저장용
	int CK2[100][100] = {0,};	//출구 방문 저장용
    int w = maps[0].size();		//길이
    int h = maps.size();		//높이
    
    
    //출발 지점 기록
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[i].size();j++){
            if(maps[i][j]=='S'){
                m.x = i;
                m.y = j;	//구조체 저장
            }
            else if(maps[i][j]=='X'){
                CK[i][j] = 1;
                CK2[i][j] = 1;
            }
        }
    }
    
    //출구 저장용 변수
    int time = -1;
    
    //시작 지점 큐에 저장
    q.push(m);
    
    
    int flag = 1;	//레버 발견 유무
    
    while(!q.empty()){
        //큐에 저장된 위치
        int x = q.front().x;
        int y = q.front().y;
        int t = q.front().t;
        q.pop();
        
        //레버 발견 전이라면 CK으로 탐색 여부 확인
        if(flag){
            if(CK[x][y]==1)continue;
            CK[x][y] = 1;
        }
        //발견 후라면 CK2 사용
        else {
            if(CK2[x][y]==1)continue;
            CK2[x][y] = 1;
        }
                
        for(int i=0;i<4;i++){
            int tx = x + dx[i];
            int ty = y + dy[i];
            //올바른 위치인 경우 출구 혹은 레버인지 비교 후 큐에 저장
            if(tx<h&&tx>=0&&ty<w&&ty>=0){
                //레버를 찾아야 하는 경우
                if(flag){
                    //이미 방문한 지형인 경우 또는 벽인 경우
                    if(CK[tx][ty] || maps[tx][ty] == 'X')continue;
                    
                    //레버인 경우
                    if(maps[tx][ty]=='L'){
                        flag = 0;	//CK2로 위치 변경
                        //레버를 발견했으므로 탐색 경로 전부 제거 후
                        //레버 위치부터 다시 출발
                        while(!q.empty()){
                            q.pop();
                        }
                    }
	
                    //큐에 현재 위치 저장
                    maze temp = {tx,ty,t+1};
                    q.push(temp);
                    
                    //레버를 발견했다면 다른 탐색 필요 없음
                    if(!flag)break;
                }
                //출구를 찾아야 하는 경우
                else{
                    //이미 방문한 지형인 경우 또는 벽인 경우
                    if(CK2[tx][ty] || maps[tx][ty] == 'X')continue;
                    
                    //출구인 경우 탈출
                    if(maps[tx][ty]=='E'){
                        //cout << tx << " " << ty << " " << t+1 << "\n";
                        return t+1;
                    }
	
                    //큐에 현재 위치 저장
                    maze temp = {tx,ty,t+1};
                    q.push(temp);
                }

            }
        }
    }
    
    //못 찾은 경우 -1 반환
    return -1;
    
}