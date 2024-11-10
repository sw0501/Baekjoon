#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int kind[10] = { 0, };
int main()
{
    // 코드를 작성해주세요
    int N;
    cin >> N;

    queue<int> fruit;

    int cnt = 0;
    int ans = 0;
    for (int i = 0; i <N; i++) {
        int num;
        cin >> num;
        
        //0,1개 거나 이미 꽂아둔 과일이라면
        if (cnt < 2 || kind[num]) {
            if(!kind[num])cnt++;
            fruit.push(num);
            kind[num]++;
            
            ans = max((int)fruit.size(), ans);
        }
        else {
            kind[num]++;
            fruit.push(num);
            cnt++;

            while (!fruit.empty() && cnt > 2) {
                int n = fruit.front();
                fruit.pop();
                kind[n]--;
                if (!kind[n])cnt--;
            }
            
            ans = max((int)fruit.size(), ans);
        }
    }
    ans = max((int)fruit.size(), ans);

    cout << ans << "\n";
    return 0;
}