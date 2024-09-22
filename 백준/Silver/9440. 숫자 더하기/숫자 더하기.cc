#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

int main()
{
    // 코드를 작성해주세요

    while (1) {
        int N;
        cin >> N;
        if (N == 0)break;

        vector<int>num;

        int zero = 0;
        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            if (temp == 0)zero++;
            else num.push_back(temp);
        }

        sort(num.begin(), num.end());

        int number[2] = { num[0],num[1] };

        int i = 0;
        for (i = 0; i < zero; i++) {
            number[i % 2] *= 10;
        }
        for (int j = 2; j < num.size(); j++) {
            number[(i + j) % 2] *= 10;
            number[(i + j) % 2] += num[j];
        }

        //cout << number[0] << " " << number[1] << "\n";

        cout << number[0] + number[1] << "\n";

    }

    return 0;
}