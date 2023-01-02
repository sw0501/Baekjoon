
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    queue<pair<int,int>>q;
    
    //1 Fav, 2 Not Fav, 3 Wait
    int arr[500001] = {0,};
    
    int N;
    
    cin >> N;
    
    int conf;
    int num;
    int fav;
    
    for(int i=0;i<N;i++){
        cin >> conf;
        if(conf==1){
            cin >> num >> fav;
            q.push(make_pair(num,fav));
        }
        else {
            cin >> num;
            if(q.front().second == num){
                arr[q.front().first] = 1;
            }
            else{
                arr[q.front().first] = 2;
            }
            q.pop();
        }
    }
    
    while(!q.empty()){
        arr[q.front().first] = 3;
        q.pop();
    }
    
    int flag = 1;
    for(int i=0;i<=N;i++){
        if(arr[i] == 1){
            cout << i << " ";
            flag = 0;
        }
    }
    if(flag)cout << "None";
    cout << "\n";
    
    flag = 1;
    for(int i=0;i<=N;i++){
        if(arr[i] == 2){
            cout << i << " ";
            flag = 0;
        }
    }
    if(flag)cout << "None";
    cout << "\n";
    
    flag = 1;
    for(int i=0;i<=N;i++){
        if(arr[i] == 3){
            cout << i << " ";
            flag = 0;
        }
    }
    if(flag)cout << "None";
    cout << "\n";

    return 0;
}
