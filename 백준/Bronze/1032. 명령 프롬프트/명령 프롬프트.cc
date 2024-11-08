#include <iostream>

using namespace std;

string arr[51];
int main()
{
    // 코드를 작성해주세요
    string str = "";

    int N;
    int len = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    len = arr[0].size();

    for (int i = 0; i < len; i++) {
        char c = arr[0][i];
        int flag = 0;
        for (int j = 1; j < N; j++) {
            if (arr[j][i] != c) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            str += "?";
        }
        else {
            str += c;
        }
    }

    cout << str << "\n";

    return 0;
}
