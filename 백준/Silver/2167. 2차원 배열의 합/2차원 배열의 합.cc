#include<iostream>
using namespace std;

int main(){
    
    int N,M;
    int arr[301][301] = {0,};
    int T;
    int i,j,x,y;
    cin >> N >> M;
    for(int a=0;a<N;a++){
        for(int b=0;b<M;b++){
            cin >> arr[a][b];
        }
    }
    
    cin >> T;
    for(int t=0;t<T;t++){
        cin >> i >> j >> x >> y;
        i--;
        j--;
        x--;
        y--;
        int sum = 0;
        for(int a = i;a <= x;a++){
            for(int b = j;b <= y;b++){
                sum += arr[a][b];
            }
        }
        cout << sum << "\n";
    }
    
    return 0;
}