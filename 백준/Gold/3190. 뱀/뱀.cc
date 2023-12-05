#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int N,K,L;
int board[101][101] = { 0, };
queue<pair<int,char>>op; 
queue<char>tq;

int main() {
    pair<int, int> tail = { 1,1 };
    pair<int, int> head = { 1,1 };

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;
    cin >> K;

    board[1][1] = 1;
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        board[a][b] = 2;
    }
    cin >> L;

    char c = 'R';
    int t = 0;
    for (int i = 0; i < L; i++) {
        int x;
        char d;
        cin >> x >> d;

        //x시간 전까지 이동 명령
        for (; t < x; t++) {
            op.push({ t,c });
        }
        if (d == 'L') {
            if (c == 'R') {
                c = 'U';
            }
            else if (c == 'L') {
                c = 'D';
            }
            else if (c == 'U') {
                c = 'L';
            }
            else if (c == 'D') {
                c = 'R';
            }
        }
        else if (d == 'D') {
            if (c == 'R') {
                c = 'D';
            }
            else if (c == 'L') {
                c = 'U';
            }
            else if (c == 'U') {
                c = 'R';
            }
            else if (c == 'D') {
                c = 'L';
            }
        }
        t = x + 1;
        op.push({ x,c });
    }
    for (; t <= 10000; t++) {
        op.push({ t,c });
    }



    while (!op.empty()) {
        int T = op.front().first;
        int c = op.front().second;

        //꼬리 이동용 큐
        tq.push(c);

        op.pop();

        //해당 방향으로 이동
        if (c == 'R') {
            head.second++;
        }
        else if (c == 'L') {
            head.second--;
        }
        else if (c == 'U') {
            head.first--;
        }
        else if (c == 'D') {
            head.first++;
        }

        //벽이나 뱀 몸통에 부딫혔는지 체크
        if (!(head.first <= N && head.second <= N && head.first > 0 && head.second > 0) || board[head.first][head.second] == 1) {
            cout << T + 1 << "\n";
            break;
        }
        //사과가 없다면
        else if(board[head.first][head.second] == 0) {
            int c = tq.front();
            tq.pop();

            //꼬리 지워주기
            board[tail.first][tail.second] = 0;

            //해당 방향으로 이동
            if (c == 'R') {
                tail.second++;
            }
            else if (c == 'L') {
                tail.second--;
            }
            else if (c == 'U') {
                tail.first--;
            }
            else if (c == 'D') {
                tail.first++;
            }
        }

        //머리 추가
        board[head.first][head.second] = 1;
    }

    return 0;
}