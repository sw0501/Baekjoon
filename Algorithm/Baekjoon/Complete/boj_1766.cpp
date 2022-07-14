#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>Graph[32001];
int N, M;
int degree[32001]={0,};	//���� ������ ���� ���� ����

bool compare(int a,int b) {
	return a > b;
}

//���� ����
void topology_sort() {
	priority_queue<int,vector<int>,greater<int>>Q;

	//������ 0�� ������ ť�� ����
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			Q.push(i);
		}
	}

	//������ ���簡�鼭 0�� ������ ť�� ����
	for (int i = 1; i <= N; i++) {
		if (Q.empty())continue;
		int x = Q.top();	//������ 0�� ����
		Q.pop();	//������ ��� ���ŵ� ���� ť���� ��
		cout << x << " ";

		//�ش� ��忡 ����� ���� ��� ������ ������ 0�̵� ������ Q�� ����
		for (int j = 0; j < Graph[x].size(); j++) {
			if (--degree[Graph[x][j]] == 0) {
				Q.push(Graph[x][j]);
			}
		}
	}
}

int main() {

	cin >> N >> M;

	//a �� b���� �տ� �־����
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Graph[a].push_back(b);	//������ �� ���� ��忡 ���� ���� ��� ����
		degree[b]++;				//���� ����
	}

	topology_sort();

	return 0;
}