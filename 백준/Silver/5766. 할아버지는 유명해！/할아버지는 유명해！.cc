#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int main(){
    
    while(1){
    
        int score[10001] = {0,};
        
        int N,M;
    
        cin >> N >> M;    
        
        if(N== 0 && M == 0){
            break;
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                int num;
                cin >> num;
                
                score[num]++;
            }
        }
        
        int first = 0;
        int second = 0;
        
        queue<int> flist;
        queue<int> slist;
        
        for(int i=1;i<=10000;i++){
            if(score[i] > first){

                while(!slist.empty()){
                    slist.pop();
                }
                
                while(!flist.empty()){
                    slist.push(flist.front());
                    flist.pop();
                }
                
                second = first;
                first = score[i];
                
                flist.push(i);
            }
            else if(score[i]==first){
                flist.push(i);
            }
            else if(score[i] > second){
                while(!slist.empty()){
                    slist.pop();
                }
                slist.push(i);
                second = score[i];
            }
            else if(score[i]==second){
                slist.push(i);
            }
        }
        
        while(!slist.empty()){
            cout << slist.front() << " ";
            slist.pop();
        }
        cout << "\n";
    }

    
    
    return 0;
}