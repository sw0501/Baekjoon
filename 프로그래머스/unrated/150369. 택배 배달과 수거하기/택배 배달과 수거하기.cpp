#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
        
    int deliver = n-1;	//전달 목적지
    int collect = n-1;	//수거 목적지
    int dest = n-1;		//최종 목적지
    
    //맨 끝 집에 배달할 택배와 수거할 택배가 없는 경우 최종 목적지 변경
    while(deliveries[dest]==0&&pickups[dest]==0){
        dest--;
        deliver--;
        collect--;
    }
    
    //모든 집에 배달할 때까지 반복
    while(dest>-1){
        answer += (dest+1)*2;	//목적지 까지 왕복 거리 추가
        
        int package = cap;	//전달 택배 수
        int empty = cap;	//수거 택배 수
        
        //택배 배달
        while(deliver>=0){
            //택배 초과인 경우
            if(deliveries[deliver]>package){
                deliveries[deliver] -= package;
                break;
            }
            //그 외
            else{
                package -= deliveries[deliver];
                deliver--;
            }
        }
        
        //전달할 택배가 없는 집은 건너뜀
        while(deliveries[deliver]==0){
            deliver--;
        }
        
        //택배 수거
        while(collect>=0){
            //빈 택배 초과인 경우
            if(pickups[collect]>empty){
                pickups[collect] -= empty;
                break;
            }
            //그 외
            else{
                empty -= pickups[collect];
                collect--;
            }   
        }
        
        //수거할 택배가 없는 집은 건너뜀
        while(pickups[collect]==0){
            collect--;
        }
        
        //다음 택배 배달 시 최종 목적지 수정
        dest = (collect>deliver?collect:deliver);
    }
    
    
    return answer;
}