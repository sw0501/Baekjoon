#include <iostream>
#include<vector>
#include <algorithm>


using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int N,K;
    cin >> N >> K;
    
    vector<int>sensor;
    vector<int>space;
    
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        sensor.push_back(num);
    }
    
    sort(sensor.begin(), sensor.end());
    
    for(int i=0;i<sensor.size()-1;i++){
        space.push_back(sensor[i+1] - sensor[i]);
    }
    
    sort(space.begin(), space.end());
    reverse(space.begin(), space.end());
    
    int ans = 0;
    for(int i=K-1;i<space.size();i++){
        ans += space[i];
    }
    
    cout << ans << "\n";
        
    return 0;
}
