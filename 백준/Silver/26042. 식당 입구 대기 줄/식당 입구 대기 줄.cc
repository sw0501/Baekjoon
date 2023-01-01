#include<iostream>
#include<queue>

using namespace std;

int main(){
    
    queue<int> q;
    
    int N;
    cin >> N;
    
    int a,b;
    int M = 0,s_num = 0;
    for(int i=1;i<=N;i++){
       cin >> a;
       if(a == 1){
           cin >> b;
           q.push(b);
           if(q.size()>M){
               M = q.size();
               s_num = b;
           }
           else if(q.size()==M && b<s_num){
               s_num = b;
           }
       }
       else q.pop();
    }
    
    cout << M << " " << s_num;
    
    return 0;
}