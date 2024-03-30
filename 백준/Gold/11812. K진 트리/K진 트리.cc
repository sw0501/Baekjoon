#include<iostream>
#include<unordered_map>
#include<queue>
#include<unordered_set>
#include<set>

using namespace std;

long long int height[10000] = { 0, };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	long long int N;
	int K, Q;

	cin >> N >> K >> Q;

	int idx = 1;
	height[idx] = 1;


	if (K != 1) {
		while (height[idx++] <= 1000000000000000) {
			height[idx] = height[idx - 1] * K;
		}

		for (int i = 1; i < idx; i++) {
			height[i] += height[i - 1];
			//cout << height[i] << "\n";
		}

	}
	
	long long int a, b;

	for (int i = 1; i <= Q; i++) {
		cin >> a >> b;

		if (K == 1) {
			cout << (b - a > 0 ? b - a : a - b) << "\n";
		}
		else {
			int aLevel = 1;
			int bLevel = 1;

			//높이 구하기
			while (height[aLevel - 1] <= a - 1) {
				aLevel++;
			}
			aLevel--;

			while (height[bLevel - 1] <= b - 1) {
				bLevel++;
			}
			bLevel--;

			long long int cnt = 0;

			//cout << aLevel << " " << bLevel << "\n";

			//높이 맞춰주기
			while (aLevel > bLevel) {
				//해당 높이 중 순서 구하기
				a = a - (height[aLevel - 1] + 1);

				//부모 번호 찾기
				a /= K;

				//부모로 변환
				a = height[aLevel - 2] + (a + 1);

				aLevel--;
				cnt++;
			}

			while (aLevel < bLevel) {
				//해당 높이 중 순서 구하기
				b = b - (height[bLevel - 1] + 1);

				//부모 번호 찾기
				b /= K;

				//부모로 변환
				b = height[bLevel - 2] + (b + 1);

				bLevel--;
				cnt++;
			}

			//cout << a << " " << b << "\n";

			//같은지 비교
			while (a != b) {
				//cout << a << " " << b << "\n";
				//해당 높이 중 순서 구하기
				a = a - (height[aLevel - 1] + 1);

				//부모 번호 찾기
				a /= K;

				//부모로 변환
				a = height[aLevel - 2] + (a + 1);
				aLevel--;

				//해당 높이 중 순서 구하기
				b = b - (height[bLevel - 1] + 1);

				//부모 번호 찾기
				b /= K;

				//부모로 변환
				b = height[bLevel - 2] + (b + 1);
				bLevel--;


				cnt += 2;
			}

			cout << cnt << "\n";
		}
		
	}
	

	return 0;
}