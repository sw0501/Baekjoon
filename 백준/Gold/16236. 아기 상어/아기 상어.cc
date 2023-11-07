#include<iostream>
#include<queue>
#include<utility>
#include<vector>

using namespace std;

struct fish {
    int x;
    int y;
    int dist;
};

struct shark {
    int x;
    int y;
    int size;
};

shark s = { 0,0,2 };

int arr[21][21] = { 0, };
int dx[4] = { 0,-1,1,0 };
int dy[4] = { -1,0,0,1 };

int N;

fish BFS(int x,int y) {
    int ck[21][21] = { 0, };

    queue<fish>q;
    q.push({ x,y,0 });

    ck[x][y] = 1;

    fish food = { x,y,5000 };
    //cout << "BFS\n";
    while (!q.empty()) {
        fish f = q.front();
        //cout << food.x << " " << food.y << " " << food.dist << "\n";
        q.pop();

        if (f.dist > food.dist) {
            //cout << "NONE\n";
            return food;
        }

        if (arr[f.x][f.y] < s.size && arr[f.x][f.y] > 0) {
            //시작 위치인 경우
            if (f.x == x && f.y == y) {

            }
            //아직 들어간 물고기가 없다면
            else if (!(f.x==x && f.y==y) && (food.x == x && food.y == y)) {
                //cout << "first\n";
                food.x = f.x;
                food.y = f.y;
                food.dist = f.dist;
            }
            else if (food.dist >= f.dist) {
                if (food.dist == f.dist) {
                    if (food.x >= f.x) {
                        if (food.x > f.x) {
                            food.x = f.x;
                            food.y = f.y;
                            food.dist = f.dist;
                        }
                        else {
                            if (food.y >= f.y) {
                                if (food.y > f.y) {
                                    food.x = f.x;
                                    food.y = f.y;
                                    food.dist = f.dist;
                                }
                            }
                        }
                    }
                }
                else {
                    food.x = f.x;
                    food.y = f.y;
                    food.dist = f.dist;
                }
            }
        }


        for (int k = 0; k < 4; k++) {
            int tx = f.x + dx[k];
            int ty = f.y + dy[k];

            if (tx >= 0 && tx < N && ty >= 0 && ty < N) {
                //먹을 수 있는 물고기가 있는 경우
                if (ck[tx][ty] == 0 && arr[tx][ty] <= s.size) {
                    q.push({ tx,ty,f.dist + 1 });
                    ck[tx][ty] = 1;
                }
            }
        }
    }

    return food;
}

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                s.x = i;
                s.y = j;
                arr[i][j] = 0;
            }
        }
    }
    
    int t = 0;
    int cnt = 2;

    while (1) {
        fish food = BFS(s.x,s.y);
        //cout << "food\n";
        //cout << food.x << " " << food.y << "\n";

        //잡아먹을 수 있는 물고기가 없다면
        if (food.x == s.x && food.y == s.y) {
            break;
        }
        //잡아먹을 수 있는 물고기가 존재한다면
        else {
            s.x = food.x;
            s.y = food.y;

            arr[s.x][s.y] = 0;
            t += food.dist;

            cnt--;
            if (cnt == 0) {
                s.size++;
                cnt = s.size;
            }
        }
    }

    cout << t << "\n";

    return 0;
}