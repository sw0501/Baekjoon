#include<bits/stdc++.h>
using namespace std;


int number[128];

string code[10] = {
    "063", "010", "093", "079", "106", "103", "119", "011", "127", "107"
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    number[63] = 0;
    number[10] = 1;
    number[93] = 2;
    number[79] = 3;
    number[106] = 4;
    number[103] = 5;
    number[119] = 6;
    number[11] = 7;
    number[127] = 8;
    number[107] = 9;

    while (1) {
        string str;
        string ans = "";

        int ans_number = 0;

        cin >> str;

        if (str == "BYE")break;

        int len = str.length();
        int i = 0;
        
        int num = 0;
        while (i < len) {
            int temp = 0;
            if ('0' <= str[i] && str[i] <='9') {
                for (int j = 0; j < 3; j++) {
                    temp *= 10;
                    temp += (int)(str[i + j] - '0');
                }
                num *= 10;
                num += number[temp];
                i += 3;
            }

            else {
                i++;
                ans_number += num;
                num = 0;
            }
        }

        cout << str;

        stack<string> st;
        while (ans_number > 0) {
            st.push(code[ans_number % 10]);
            ans_number /= 10;
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        cout << ans << "\n";
    }
    
    
    return 0;
}