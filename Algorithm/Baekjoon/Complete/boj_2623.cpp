#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int>Graph[32001];
int N, M;
int degree[32001]={0,};	//���� ������ ���� ���� ����
int result[1001]={0,};	//���� ���� ����

//���� ����
int topology_sort() {
	queue<int>Q;

	//������ 0�� ������ ť�� ����
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			Q.push(i);
		}
	}

	//������ ���簡�鼭 0�� ������ ť�� ����
	for (int i = 1; i <= N; i++) {
		if (Q.empty()) {
			cout << 0 << "\n";
			return 0;
		}

		int x = Q.front();	//������ 0�� ����
		Q.pop();			//������ ��� ���ŵ� ���� ť���� ��
		result[i] = x;		//���� ���� result�� ����

		//�ش� ��忡 ����� ���� ��� ������ ������ 0�̵� ������ Q�� ����
		for (int j = 0; j < Graph[x].size(); j++) {
			if (--degree[Graph[x][j]] == 0) {
				Q.push(Graph[x][j]);
			}
		}
	}

	return 1;
}

int main() {

	cin >> N >> M;

	//a �� b���� �տ� �־����
	for (int i = 0; i < M; i++) {
		int num,a,b;
		cin >> num;
		cin >> a;
		for (int n = 0; n < num-1; n++) {
			cin >> b;
			Graph[a].push_back(b);	//������ �� ���� ��忡 ���� ���� ��� ����
			degree[b]++;				//���� ����
			a = b;						//������ �°� ����
		}
	}

	if (topology_sort()) {
		for (int i = 1; i <= N; i++) {
			cout << result[i] << "\n";
		}
	}

	

	return 0;
}