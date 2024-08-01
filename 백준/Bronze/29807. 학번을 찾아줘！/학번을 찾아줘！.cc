#include<iostream>
#include<vector>

using namespace std;

vector<int>score;
int main(){
    
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        int num = 0;
        cin >> num;
        score.push_back(num);
    }
    for(int t=0;t<5-T;t++){
        score.push_back(0);
    }
    
    int ans = 0;
    if(score[0] > score[2]){
        ans += (score[0] - score[2])*508;
    }
    else{
        ans += (score[2] - score[0])*108;
    }
    
    if(score[1] > score[3]){
        ans += (score[1] - score[3])*212;
    }
    else{
        ans += (score[3] - score[1])*305;
    }
    
    ans += 707 * score[4];
    
    ans *= 4763;
    
    cout << ans << "\n";
    
    return 0;
}