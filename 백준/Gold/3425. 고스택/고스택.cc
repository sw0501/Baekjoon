#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>
#include<cmath>

using namespace std;

stack<long long int> st;
vector<string>op;
vector<long long int>opNum;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		int flag = 1;
		int cnt = 0;

		op.clear();
		opNum.clear();

		//명령어 입력
		while (1) {
			
			string  str;
			cin >> str;
			if (str == "QUIT") {
				flag = 0;
				return 0;
			}
			else if (str == "END") {
				break;
			}
			else if (str == "NUM") {
				cnt++;
				long long int num;
				cin >> num;
				opNum.push_back(num);
			}
			op.push_back(str);
		}
		if (!flag) {
			break;
		}

		//명령 실행
		int N;
		
		cin >> N;
		for (int j = 0; j < N; j++) {
			while (!st.empty()) {
				st.pop();
			}
			long long int num;
			cin >> num;

			int error = 0;
			st.push(num);
			int idx = 0;
			for(int i=0;i<op.size();i++){
				if (op[i] == "NUM") {
					st.push(opNum[idx++]);
				}
				else if (op[i] == "MUL") {
					if (st.size()<2) {
						error = 1;
						break;
					}
					long long int temp = st.top();
					st.pop();

					long long int temp2 = st.top();
					st.pop();

					st.push(temp * temp2);

					if ((abs(st.top()) > 1000000000)) {
						error = 1;
						break;
					}
				}
				else if (op[i] == "POP") {
					if (st.empty()) {
						error = 1;
						break;
					}
					st.pop();
				}
				else if (op[i] == "INV") {
					if (st.empty()) {
						error = 1;
						break;
					}
					st.top() = -st.top();
				}
				else if (op[i] == "SWP") {
					if (st.size()<2) {
						error = 1;
						break;
					}
					long long int temp1 = st.top();
					st.pop();
					long long int temp2 = st.top();
					st.pop();

					st.push(temp1);
					st.push(temp2);
				}
				else if (op[i] == "ADD") {
					if (st.size() < 2) {
						error = 1;
						break;
					}
					long long int temp = st.top();
					st.pop();
					st.top() += temp;

					if ((abs(st.top()) > 1000000000)) {
						error = 1;
						break;
					}
				}
				else if (op[i] == "SUB") {
					if (st.size() < 2) {
						error = 1;
						break;
					}
					long long int temp = st.top();
					st.pop();

					st.top() -= temp;

					if ((abs(st.top()) > 1000000000)) {
						error = 1;
						break;
					}
				}
				else if (op[i] == "DUP") {
					if (st.size() < 1) {
						error = 1;
						break;
					}
					st.push(st.top());
				}
				else if (op[i] == "DIV") {
					if (st.size() < 2) {
						error = 1;
						break;
					}

					long long int temp = st.top();
					st.pop();

					if (temp == 0) {
						error = 1;
						break;
					}

					int tempCnt = 0;
					if (temp < 0) {
						tempCnt++;
					}
					if (st.top() < 0) {
						tempCnt++;
					}

					st.top() = abs(st.top())/ temp;
					if (tempCnt == 1)st.top() = abs(st.top())* (-1);
					else {
						st.top() = abs(st.top());
					}
					if ((abs(st.top()) > 1000000000)) {
						error = 1;
						break;
					}
				}
				else if (op[i] == "MOD") {
					if (st.size() < 2) {
						error = 1;
						break;
					}
					long long int temp = st.top();
					st.pop();

					if (temp == 0) {
						error = 1;
						break;
					}

					int sign = (st.top() > 0 ? 1 : 0);

					st.top() = (abs(st.top()) % temp);
					if (sign) {
						st.top() = abs(st.top());
					}
					else {
						st.top() = -abs(st.top());
					}

					if ((abs(st.top()) > 1000000000)) {
						error = 1;
						break;
					}
				}

			}

			if (error || st.size() != 1) {
				cout << "ERROR" << "\n";
			}
			else {
				cout << st.top() << "\n";
			}

		}
		cout << "\n";
	}
	

	return 0;
}