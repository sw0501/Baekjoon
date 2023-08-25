#include<iostream>
#include<list>

using namespace std;

int main() {

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string str;

		list<char>L = {};
		list<char>::iterator cursor = L.begin();

		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '>') {
				if (cursor != L.end())cursor++;
			}
			else if (str[i] == '<') {
				if (cursor != L.begin())cursor--;
			}
			else if (str[i] == '-') {
				if (cursor != L.begin())cursor = L.erase(--cursor);
			}
			else {
				cursor = L.insert(cursor,str[i]);
				cursor++;
			}
		}
		
		for (auto c : L) {
			cout << c;
		}
		cout << "\n";
	}


	return 0;
}