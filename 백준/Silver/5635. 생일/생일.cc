#include<iostream>
#include<algorithm>

using namespace std;

typedef struct birth {
    string name;
    int date;
    int month;
    int year;
}Birth;

bool compare(Birth a, Birth b) {
    if (a.year > b.year) {
        return true;
    }
    else if (a.year == b.year) {
        if (a.month > b.month) {
            return true;
        }
        else if (a.month == b.month) {
            if (a.date > b.date) {
                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

int main() {

    int N;
    cin >> N;

    Birth birth[100];
    for (int i = 0; i < N; i++) {
        cin >> birth[i].name >> birth[i].date;
        cin >> birth[i].month >> birth[i].year;
    }

    sort(birth, birth + N, compare);

    cout << birth[0].name << "\n";
    cout << birth[N - 1].name << "\n";

    return 0;
}