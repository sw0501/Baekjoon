#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//사용하지 않는 객실 = 0 / 사용 or 준비 중인 객실  = 1
vector<int>arr[1001];

bool compare(vector<string>&a,vector<string>&b){
    if(a[0]==b[0]){
        return a[1]<b[1];
    }
    return a[0]<b[0];
}

int solution(vector<vector<string>> book_time) {
    
    sort(book_time.begin(),book_time.end(),compare);
    
    int answer = 0;
    
    //방 개수
    int cnt = 1;
   	for(int i=0;i<book_time.size();i++){
        
        int start = 0;
        int end = 0;
       	
        //문자열 정수로 변환
        for(int j=0;j<5;j++){
            //:는 건너뜀
            if(j==2)continue;
            
            start *= 10;
            end *= 10;
            
            start += (int)(book_time[i][0][j]-'0');
            end += (int)(book_time[i][1][j]-'0');
        }
        
        //정리 시간 추가
        end +=10;
        
        //다음 날로 넘어가는 경우 2359로 고정
        if(end>2359)end = 2359;
        //60 넘어가는 경우 시간 증가
        else if(end%100 >= 60){
            end -= 60;
            end += 100;
        }
        
        //ut << start << " " << end << "\n";
        
        //비어있는 경우 arr에 저장하고 continue
       	if(arr[0].size()==0){
            arr[0].push_back(start);
            arr[0].push_back(end);
            continue;
        }
        
        
        int reserve = 1;
        //빈 방 조회
        for(int j=0;j<cnt;j++){
            //정리 시간 조회
            int flag = 0;
            for(int k=1;k<arr[j].size();k+=2){
                //정리 시간 이후에 대실 시작이라면
                if(arr[j][k] <= start){
                    //뒤에 남은 예약이 있고 겹치지 않거나 마지막 예약 인 경우
                    if((arr[j].size()>=k+3&&arr[j][k+1]>=end)||arr[j].size()==k+1){
                        //현재 방에 예약 추가 후 정렬
                        arr[j].push_back(start);
                        arr[j].push_back(end);
                        sort(arr[j].begin(),arr[j].end());
                        
                        //예약 추가 확인
                        flag = 1;
                        
                        //반복문 탈출
                        break;
                    }
                }
            }
            //예약을 했다면 탈출
            if(flag){
                reserve = 0;
                break;
            }
        }
        
        //예약을 하지 못했다면
        if(reserve){
            //새로운 방에 예약 추가 및 방 개수 증가
            arr[cnt].push_back(start);
            arr[cnt].push_back(end);
            cnt++;
        }
        
    }
    
    return cnt;
}