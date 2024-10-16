#include <iostream>
#include <vector>

using namespace std;

vector<int>decimal;

int arr[1000001] = { 0, };
int main()
{

    int N;
    cin >> N;

    // 코드를 작성해주세요
    for (int i = 2; i <= N; i++) {
        if (arr[i])continue;
        decimal.push_back(i);
        for (int j = i; j <= N; j += i) {
            arr[j] = 1;
        }
    }

    int M = decimal.size();

    for (int a = 0; a < M; a++) {
        for (int b = 0; b < M; b++) {
            if (decimal[a] + decimal[b] > N)break;
            for (int c = 0; c < M; c++) {
                if (decimal[a] + decimal[b] + decimal[c] > N)break;
                for (int d = 0; d < M; d++) {
                    if (decimal[a] + decimal[b] + decimal[c] + decimal[d]> N)break;
                    if (decimal[a] + decimal[b] + decimal[c] + decimal[d] == N) {
                        cout << decimal[a] << " " << decimal[b] << " " << decimal[c] << " " << decimal[d] << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << -1;

    return 0;
}