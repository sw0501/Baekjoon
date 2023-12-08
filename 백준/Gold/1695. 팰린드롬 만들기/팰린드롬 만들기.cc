#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int N;
int arr[5002] = { 0, };
int DP[5002][5002] = {0,};

//
int DFS(int a,int b) {
    //이미 최소 개수가 정해져있다면 값 리턴
    if (DP[a][b] != -1) {
        return DP[a][b];
    }
    else {
        if (a>=b) {
            DP[a][b] = 0;
            return DP[a][b];
        }
        else {
            if (arr[a] == arr[b]) {
                DP[a][b] = DFS(a+1,b-1);
                return DP[a][b];
            }
            else {
                DP[a][b] = min(DFS(a, b - 1), DFS(a + 1, b)) + 1;
                return DP[a][b];
            }
        }
    }
}

int main() {
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
   
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            DP[i][j] = -1;
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    //DP[a][b] : a부터 b까지 팰린드롬 만들때 필요한 최소 개수
    //a==b 일 때 DP[a+1][b-1] = DP[a][b]
    //a!=b 인 경우 min(DP[a+1][b],DP[a][b-1])+1
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            DFS(i, j);
        }
    }

    cout << DP[0][N - 1];

    return 0;
}