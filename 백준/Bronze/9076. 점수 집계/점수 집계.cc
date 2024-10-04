#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >>N;
    
    for(int i=0;i<N;i++){
        vector<int>score;
        int num;
        for(int j=0;j<5;j++){
            cin >> num;
            score.push_back(num);
        }
        sort(score.begin(),score.end());
        
        if(score[3] - score[1] >= 4){
            cout << "KIN" << "\n";
        }
        else{
            cout << score[1] + score[2] + score[3] << "\n";
        }
    }
    return 0;
}
