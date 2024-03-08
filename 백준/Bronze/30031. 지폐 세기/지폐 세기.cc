#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    int answer = 0;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        if(a==136)answer+=1000;
        else if(a==142)answer+=5000;
        else if(a==148)answer+=10000;
        else if(a==154)answer+=50000;
    }
    cout << answer << "\n";
    
    return 0;
}