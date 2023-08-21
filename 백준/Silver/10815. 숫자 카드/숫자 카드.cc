#include<iostream>
#include<algorithm>

using namespace std;

int arr[500001] = { 0, };

int  binary_search(int s, int e, int num) {
    int m;

    while (s < e) {
        m = (s + e) / 2;

        if (arr[m] < num) {
            s = m + 1;
        }
        else if(arr[m] > num) {
            e = m;
        }
        else {
            break;
        }
    }

    return m;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, num;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> num;

        int m = binary_search(0, N, num);
        
        if (arr[m] != num) {
            cout << 0 << " ";
        }
        else{
            cout << 1 << " ";
        }
    }



    return 0;
}