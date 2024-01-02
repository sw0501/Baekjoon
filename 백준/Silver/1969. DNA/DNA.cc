#include<iostream>

using namespace std;

string arr[1000];

int main() {

	string H = "";
	int cnt = 0;

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int j = 0; j < M; j++) {
		int t = 0;
		int a = 0;
		int c = 0;
		int g = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i][j] == 'T')t++;
			else if(arr[i][j] == 'A')a++;
			else if (arr[i][j] == 'C')c++;
			else if (arr[i][j] == 'G')g++;
		}
		
		if (t > a && t > c && t > g) {
			H += "T";
			cnt += a + c + g;
		}
		else if (g > a && g > c && g >= t) {
			H += "G";
			cnt += a + c + t;
		}
		else if (c > a && c >= g && c >= t) {
			H += "C";
			cnt += a + g + t;
		}
		else if (a >= c && a >= g && a >= t) {
			H += "A";
			cnt += g + c + t;
		}
	}

	cout << H << "\n" << cnt << "\n";

	return 0;
}