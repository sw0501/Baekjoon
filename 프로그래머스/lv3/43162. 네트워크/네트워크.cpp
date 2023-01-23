#include <string>
#include <vector>

using namespace std;

vector<vector<int>> *p;

int connect[201] ={0,};
int computer_num;

void DFS(vector<vector<int>>&p, int number){
    if(connect[number])return;
    connect[number] = 1;
    for(int i=0;i<computer_num;i++){
        if(i==number)continue;
        if(p[number][i]==1){
            DFS(p,i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    int answer = 0;
    computer_num = n;
    
    for(int i=0;i<n;i++){
        if(!connect[i]){
            answer++;
            DFS(computers,i);
        }
    }
    
    
    return answer;
}