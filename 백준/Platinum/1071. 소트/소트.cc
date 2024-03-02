#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>


using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int arr[51] = { 0, };
    int count[1001] = { 0, };
    vector<int>cnt;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        count[arr[i]]++;
    }

    //vector에 저장
    for (int i = 0; i <= 1000; i++) {
        if (count[i] > 0) {
            cnt.push_back(i);
        }
    }

    int numCnt = 0;
    int size = cnt.size();
    
    int preNum = -2;
    while(numCnt < size -1) {

        //수 선택
        for (int i = 0; i < size; i++) {
            //이전 수 + 1 || 이미 다 처리한 숫자인 경우
            if (cnt[i] == preNum + 1 || count[cnt[i]] <= 0) {
                continue;
            }

            int flag = 0;

            //뒤에 추가할 수 있는 숫자가 있는지 체크
            for (int j = 0; j < size; j++) {
                if (i != j && count[cnt[j]] > 0 && cnt[j] != cnt[i] + 1) {
                    flag = 1;
                    break;
                }
            }

            if (flag) {
                count[cnt[i]]--;
                preNum = cnt[i];
                cout << cnt[i] << " ";
                //수 저장
                if (count[cnt[i]] == 0) {
                    numCnt++;
                }
                break;
            }
        }
    }

    for (int i = 0; i <= 1000; i++) {
        if (count[i] > 0) {
            while (count[i]-- > 0) {
                cout << i << " ";
            }
        }
    }

    return 0;
}