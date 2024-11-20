#include<bits/stdc++.h>

using namespace std;

//hashmap?? 
string name[15] = { "rat", "cow", "tiger", "rabbit", "dragon", "snake", "horse", "sheep", "monkey", "chicken", "dog", "pig", "lion", "giraffe", "cat" };
string animal[1441];

struct Schedule {
	int t;
	int period;
};

struct compare {
    bool operator()(const Schedule& s1, const Schedule& s2) {
        if (s1.t == s2.t) {
            return s1.period > s2.period;
        }
        return s1.t > s2.t; 
    }
};

priority_queue<Schedule, vector<Schedule>, compare>planner;

int main() {

	int N;
	cin >> N;

	int idx = -1;
	//동물 시간 기록
	for (int i = 0; i < 1440; i++) {
		if (i % 96 == 0) {
			idx++;
		}
		animal[i] = name[idx];
	}

	for (int i = 0; i < N; i++) {
		int H, M;
		int process;
		cin >> H >> M >> process;

		int t = H * 60 + M;

		planner.push({ t,process });
	}

	int delay = 0;

	while (!planner.empty()) {
		Schedule s = planner.top();

		planner.pop();
		
		//지연 시간
		if (delay > s.t) {
			s.t = delay;
		}
		delay = s.t + s.period;

		//자정이 되기 전에 일처리를 못하는 경우
		if (s.t + s.period >= 1440) {
			planner.push(s);
			break;
		}

		int startH = s.t / 60;
		int startM = s.t % 60;

		int endH = (s.t + s.period) / 60;
		int endM = (s.t + s.period) % 60;

		string startName = animal[s.t];
		string endName = animal[s.t + s.period];

		//걸치는 동물 이름 출력
		int idx = 0;
		while (startName != name[idx]) {
			idx++;
		}
		do {
			cout << name[idx] << " ";
		} while (endName != name[idx++] && idx < 15);
		cout << "\n";

		printf("%02d:%02d %02d:%02d\n", startH, startM, endH, endM);
	}

	if (!planner.empty())
		cout << planner.size();


	return 0;
}