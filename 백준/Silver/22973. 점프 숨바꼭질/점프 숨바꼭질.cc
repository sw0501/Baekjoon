#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
   
    long long int K;
    cin >> K;

    K = (K > 0 ? K : -K);

    long long int t = 1;
    int cnt = 0;
    while (1) {
        if (t - 1 > K) {
            cout << -1 << "\n";
            break;
        }
        else if(t-1 == K){
            cout << cnt << "\n";
            break;
        }
        t *= 2;
        cnt++;
    }

    //1
    //3
    //7
    //15
    return 0;
}