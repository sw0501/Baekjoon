#include <iostream>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <stack>


using namespace std;

int fibo[45];

int main()
{
    
    int T;
    cin >> T;

    fibo[0] = 0;
    fibo[1] = 1;
    for (int i = 2; i < 45; i++) {
        fibo[i] = fibo[i - 2] + fibo[i - 1];
    }
    

    for (int t = 0; t < T; t++) {

        stack<int>s;

        int num;
        cin >> num;

        for (int i = 44; i >= 1; i--) {
            if (num >= fibo[i]) {
                s.push(fibo[i]);
                num -= fibo[i];
            }
        }


        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << "\n";
    }

    return 0;
}