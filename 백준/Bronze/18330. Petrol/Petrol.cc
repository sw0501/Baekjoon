#include<iostream>

using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    K += 60;

    if (N <= K) {
        cout << N * 1500;
    }
    else {
        cout << (K) * 1500 + (N - K) * 3000;
    }


    return 0;
}