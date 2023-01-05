#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main()
{
    queue<string>q[100];
    
    int N;
    cin >> N;
    getchar();
    string str;
    
    for(int i=0;i<N;i++){
        getline(cin,str);
        int current = str.find(' ');
        int previous = 0;
        while(current != string::npos){
            string substring = str.substr(previous,current-previous);
            q[i].push(substring);
            previous = current + 1;
            current = str.find(' ',previous);
        }
        q[i].push(str.substr(previous,current-previous));
    }
    
    /*
    for(int i=0;i<N;i++){
        while(!q[i].empty()){
            cout << q[i].front() << " ";
            q[i].pop();
        }
        cout << "\n";
    }
    */
    
    getline(cin,str);
    
    int previous = 0;
    int current = str.find(' ');
    while(current != string::npos){
        string substring = str.substr(previous,current-previous);
        //cout << substring << " ";
        int flag = 1;
        for(int i=0;i<N;i++){
            if(!q[i].empty() && substring == q[i].front()){
                q[i].pop();
                flag = 0;
                break;
            }
        }
        //큐에 없는 단어를 사용한 경우
        if(flag){
            cout << "Impossible" << "\n";
            return 0;
        }
        previous = current+1;
        current = str.find(' ',previous);
    }
    
    int flag = 1;
    for(int i=0;i<N;i++){
        //cout << "last" << str.substr(previous,current-previous) << " ";
        if(!q[i].empty()){
            if(str.substr(previous,current-previous)==q[i].front()){
                q[i].pop();
                flag = 0;
                break;
            }
            //마지막 단어 가 틀린 경우
            else {
                cout << "Impossible" << "\n";
                return 0;
            }
            
        }
        
    }
    
    if(flag){
        cout << "Impossible" << "\n";
        return 0;
    }
    
    //L은 모두 처리했으나 아직 사용안한 단어가 남아있는 경우
    for(int i=0;i<N;i++){
        if(!q[i].empty()){
            cout << "Impossible" << "\n";
            return 0;
        }
    }
    
    //모든 단어 처리했고 큐에 빈 단어가 없는 경우
    cout << "Possible" << "\n";
    
    
    return 0;
}
