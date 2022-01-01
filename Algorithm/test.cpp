#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

int n, s; 
vector<int> v; 
vector<int> v1, v2; 
int temp; 

void dfs(int index, int sum, int end, vector<int> &a) { 
    if (index == end) { a.push_back(sum); return; } 
    dfs(index + 1, sum, end, a); 
    dfs(index + 1, sum + v[index], end, a); 
} 

long long moveRight(vector<int> &a, int index) { 
    //같은 수가 몇개인지 리턴 
    long long ans = 1; if (index == a.size() - 1) return ans; 
    while (a[index] == a[index + 1]) { 
        ans++; index++; if (index == a.size() - 1) return ans; 
    } return ans; 
} 
int main(void) { 
    cin.tie(nullptr); 
    cout.tie(nullptr); 
    ios_base::sync_with_stdio(false); 
    cin >> n >> s; 
    for (int i = 0; i < n; ++i) { 
        int num; cin >> num; v.push_back(num); 
    } //부분수열의 합을 둘로 나눠서 각각 구한후 정렬. 
    dfs(0, 0, n / 2, v1); 
    dfs(n / 2, 0, n, v2); 
    long long ans = 0; 
    int start1 = 0; 
    int start2 = 0; 
    sort(v1.begin(), v1.end()); 
    sort(v2.begin(), v2.end()); 
    reverse(v2.begin(), v2.end()); 
    while (start1 < v1.size() && start2 < v2.size()) { 
        int sum = v1[start1] + v2[start2]; if (sum == s) { 
            long long s1 = moveRight(v1, start1); 
            long long s2 = moveRight(v2, start2); start1 += s1; 
            start2 += s2; ans += s1 * s2; 
            //같은 수가 여러개 일경우 곱 
        } 
        else if (sum > s) { 
            long long s2 = moveRight(v2, start2); start2 += s2; 
        } 
        else { 
            long long s1 = moveRight(v1, start1); start1 += s1; 
        } 
    } if (s == 0) ans--; 
    cout << ans; 
}

