#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>


using namespace std;

int N;
int arr[20][20] = { 0, };
int ans = -1;

void up(int cnt);
void down(int cnt);
void left(int cnt);
void right(int cnt);

void DFS(int cnt) {

    if (cnt == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ans = (ans < arr[i][j] ? arr[i][j] : ans);
            }
        }
        return;
    }

    up(cnt);
    down(cnt);
    left(cnt);
    right(cnt);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    DFS(0);

    cout << ans << "\n";

    return 0;
}

void up(int cnt) {
    int temp[20][20] = { 0, };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = arr[i][j];
        }
    }

    //상
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = i + 1; k < N; k++) {
                if (arr[i][j] == 0) {
                    break;
                }
                if (arr[k][j] == 0) {
                    continue;
                }
                if (arr[i][j] == arr[k][j]) {
                    arr[i][j] += arr[k][j];
                    arr[k][j] = 0;
                }
                break;
            }
        }
    }

    //이동
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = i + 1; k < N; k++) {
                if (arr[i][j] != 0) {
                    break;
                }
                if (arr[k][j] != 0) {
                    arr[i][j] = arr[k][j];
                    arr[k][j] = 0;
                }
            }
        }
    }

    DFS(cnt + 1);

    //복원
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

void down(int cnt) {
    int temp[20][20] = { 0, };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = arr[i][j];
        }
    }

    //하
    for (int i = N - 1; i >= 1; i--) {
        for (int j = 0; j < N; j++) {
            for (int k = i - 1; k >= 0; k--) {
                if (arr[i][j] == 0) {
                    break;
                }
                if (arr[k][j] == 0) {
                    continue;
                }
                if (arr[i][j] == arr[k][j]) {
                    arr[i][j] += arr[k][j];
                    arr[k][j] = 0;
                }
                break;
            }
        }
    }

    //이동
    for (int i = N-1; i >=1; i--) {
        for (int j = 0; j < N; j++) {
            for (int k = i-1; k >=0; k--) {
                if (arr[i][j] != 0) {
                    break;
                }
                if (arr[k][j] != 0) {
                    arr[i][j] = arr[k][j];
                    arr[k][j] = 0;
                }
            }
        }
    }

    DFS(cnt + 1);

    //복원
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

void left(int cnt) {
    int temp[20][20] = { 0, };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = arr[i][j];
        }
    }

    //상
    for (int j = 0; j < N - 1; j++) {
        for (int i = 0; i < N; i++) {
            for (int k = j + 1; k < N; k++) {
                if (arr[i][j] == 0) {
                    break;
                }
                if (arr[i][k] == 0) {
                    continue;
                }
                if (arr[i][j] == arr[i][k]) {
                    arr[i][j] += arr[i][k];
                    arr[i][k] = 0;
                }
                break;
            }
        }
    }

    //이동
    for (int j = 0; j < N - 1; j++) {
        for (int i = 0; i < N; i++) {
            for (int k = j + 1; k < N; k++) {
                if (arr[i][j] != 0) {
                    break;
                }
                if (arr[i][k] != 0) {
                    arr[i][j] = arr[i][k];
                    arr[i][k] = 0;
                }
            }
        }
    }

    //for (int i = 0; i < N; i++) {
    //    for (int j = 0; j < N; j++) {
    //        cout << arr[i][j] << "\t";
    //    }
    //    cout << "\n";
    //}
    //cout << "\n";

    DFS(cnt + 1);

    //복원
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

void right(int cnt) {
    int temp[20][20] = { 0, };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = arr[i][j];
        }
    }

    //좌
    for (int j = N - 1; j >= 1; j--) {
        for (int i = 0; i < N; i++) {
            for (int k = j - 1; k >= 0; k--) {
                if (arr[i][j] == 0) {
                    break;
                }
                if (arr[i][k] == 0) {
                    continue;
                }
                if (arr[i][j] == arr[i][k]) {
                    arr[i][j] += arr[i][k];
                    arr[i][k] = 0;
                }
                break;
            }
        }
    }

    //이동
    for (int j = N - 1; j >= 1; j--) {
        for (int i = 0; i < N; i++) {
            for (int k = j - 1; k >= 0; k--) {
                if (arr[i][j] != 0) {
                    break;
                }
                if (arr[i][k] != 0) {
                    arr[i][j] = arr[i][k];
                    arr[i][k] = 0;
                }
            }
        }
    }

    DFS(cnt + 1);

    //복원
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}