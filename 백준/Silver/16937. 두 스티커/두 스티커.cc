#include <iostream>
#include <algorithm>

using namespace std;

int arr[100][2] = {0,};

int main() 
{
    // 코드를 작성해주세요
    // 양쪽 모서리 끝에 붙이는 게 최적해
    int H, W;
    cin >> H >> W;
    
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        cin >> arr[t][0] >> arr[t][1];
    }
    
    int answer = 0;
    
    for(int i=0;i<T;i++){
        for(int j=i+1;j<T;j++){
            int w1,w2,h1,h2;
            
            h1 = arr[i][0];
            w1 = arr[i][1];
            h2 = arr[j][0];
            w2 = arr[j][1];
            
            if(!(h1 > H || h2 > H || w1 > W || w2 >W)){
                int area = h1 * w1 + h2* w2;
                
                //높이가 겹치는 경우
                if(h1 + h2 > H){
                    //길이 비교
                    if(w1 + w2 <= W){
                        answer = max(answer,area);
                    }
                }
                //높이가 겹치지 않는 경우
                else{
                    answer = max(answer,area);
                }
            }
            
            h1 = arr[i][1];
            w1 = arr[i][0];
            h2 = arr[j][0];
            w2 = arr[j][1];
            
            if(!(h1 > H || h2 > H || w1 > W || w2 >W)){
                int area = h1 * w1 + h2* w2;
                
                //높이가 겹치는 경우
                if(h1 + h2 > H){
                    //길이 비교
                    if(w1 + w2 <= W){
                        answer = max(answer,area);
                    }
                }
                //높이가 겹치지 않는 경우
                else{
                    answer = max(answer,area);
                }
            }
            
            h1 = arr[i][0];
            w1 = arr[i][1];
            h2 = arr[j][1];
            w2 = arr[j][0];
            
            if(!(h1 > H || h2 > H || w1 > W || w2 >W)){
                int area = h1 * w1 + h2* w2;
                
                //높이가 겹치는 경우
                if(h1 + h2 > H){
                    //길이 비교
                    if(w1 + w2 <= W){
                        answer = max(answer,area);
                    }
                }
                //높이가 겹치지 않는 경우
                else{
                    answer = max(answer,area);
                }
            }
            
            h1 = arr[i][1];
            w1 = arr[i][0];
            h2 = arr[j][1];
            w2 = arr[j][0];
            
            if(!(h1 > H || h2 > H || w1 > W || w2 >W)){
                int area = h1 * w1 + h2* w2;
                
                //높이가 겹치는 경우
                if(h1 + h2 > H){
                    //길이 비교
                    if(w1 + w2 <= W){
                        answer = max(answer,area);
                    }
                }
                //높이가 겹치지 않는 경우
                else{
                    answer = max(answer,area);
                }
            }
        }
    }
    
    cout << answer << "\n";
    return 0;
}
