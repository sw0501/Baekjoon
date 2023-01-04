
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    
    int Rs[101] = {0,};
    int W[2001] = {0,};
    int parking[101] = {0,};
    
    for(int i=1;i<=N;i++){
        cin >> Rs[i];
    }
    for(int i=1;i<=M;i++){
        cin >> W[i];
    }
    
    int num;
    long long Price = 0;
    
    queue<int>wait;
    
    int order = 1;
    int vaccum = 101;
    int cnt = 0;
    
    for(int i=0;i<2*M;i++){
        cin >> num;
        
        if(num<0){
            cnt--;
            for(int j=1;j<=N;j++){
                if(parking[j] == -num){
                    parking[j] = 0;
                    break;
                }
            }
        }
        
        else{
            wait.push(num);
        }
        
        while(cnt<N&&!wait.empty()){
            cnt++;
            for(int j=1;j<=N;j++){
                if(parking[j] == 0){
                    parking[j] = wait.front();
                    Price += W[wait.front()]*Rs[j];
                    wait.pop();
                    break;
                }
            }
        }
    }
    
    cout << Price << "\n";
    return 0;
}
