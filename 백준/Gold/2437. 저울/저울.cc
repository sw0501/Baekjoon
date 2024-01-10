#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int arr[1000] = { 0, };

int main(){

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + N);
	
	int weight = 1;

	for (int i = 0; i < N; i++) {
		if (weight < arr[i]) {
			break;
		}
		weight += arr[i];
	}

	cout << weight << "\n";
	

	return 0;
}
