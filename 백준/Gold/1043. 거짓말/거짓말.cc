/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

vector<int>truth;
int party[50][50]={0,};
int set[50] = {0,};

int getParent(int x){
    if(set[x]==x)return x;
    else return set[x] = getParent(set[x]);
}

int find(int a,int b){
    a = getParent(a);
    b = getParent(b);
    if(a==b){
        return 1;
    }
    else return 0;
}

void unionParent(int a,int b){
    a = getParent(a);
    b = getParent(b);
    if(a>b){
        set[a] = b;
    }
    else {
        set[b] = a;
    }
}

int main()
{
    int N,M;
    
    cin >> N >> M;
 
    for(int i=1;i<=N;i++){
        set[i] = i;
    }
    
    int  num;
    
    cin >> num;
    
    for(int i=0;i<num;i++){
        int a;
        cin >> a;
        truth.push_back(a);
    }
    
    for(int i=0;i<M;i++){
        cin >> party[i][0];
        for(int j=1;j<=party[i][0];j++){
            cin >> party[i][j];
            if(j!=1){
                unionParent(party[i][j],party[i][j-1]);
            }
        }
    }
    
    
    int ans = 0;
    
    for(int i=0;i<M;i++){
        int flag = 1;
        for(int j=1;j<=party[i][0];j++){
            for(int k=0;k<num;k++){
                if(find(truth[k],party[i][j])){
                    flag = 0;
                    break;
                }
            }
        }
        if(flag)ans++;
    }
    
    cout << ans << "\n";
    
    return 0;
}
