#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<cassert>

using namespace std;

typedef pair<int, int> pii;

int dataSet[6][2] = { {0,0}, {30,3} , {1,10} ,{0,0}, {2,20}, {0,0} , };

int main()
{
	int N, a, b;

	N = 5;

	cout << N << "\n";

	vector<pii> G;
	for (int i = 1; i <= N; i++) {
		
		a = dataSet[i][0];
		b = dataSet[i][1];

		assert(0 <= a && a <= 1000 && 0 <= b && b <= 1000);
		G.push_back(pii(a, b));
	}
	sort(G.begin(), G.end(), [](const pii& l, const pii& r) { return l.first * r.second < l.second * r.first; });

	bool ch = false;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			ch |= G[i].first * G[j].second > G[i].second * G[j].first;
		}
	}
	
	for (int i = 0; i < N; i++) {
		cout << G[i].first << " " << G[i].second << "\n";
	}

	return 0;
}