#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N,W,L;
    int B[1001];
    queue<pair<int,int>>Bridge;
    
    cin >> N >> W >> L;
    
    for(int i=0;i<N;i++){
        cin >> B[i];
    }
    
    int i = 0;
    int T = 0;
    
    
    Bridge.push(make_pair(T,B[i]));
    
    int weight = 0, max_cnt = 0;
    weight += B[i];
    max_cnt++;
    
    //시간 및 다음 대기 버스 번호 증가
    T++;
    i++;
    
    while(!Bridge.empty()){
        //맨 앞이 빠져나갈 수 있는 경우
        if(Bridge.front().first + W == T){
            weight -= Bridge.front().second;
            Bridge.pop();
            max_cnt--;
        }
        
        //다리에 버스가 올라갈 수 있는 경우
        if(max_cnt < W && weight + B[i] <= L && i < N){
            Bridge.push(make_pair(T,B[i]));
            weight += B[i];
            max_cnt++;
            i++;
        }
        
        T++;
    }

    cout << T << "\n";

    return 0;
}
