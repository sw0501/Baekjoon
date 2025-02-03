#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<long long>arr;
vector<long long>maxTree;
vector<long long>minTree;

long long Make_MaxSegementTree(long long node, int start, int end) {
    if (start == end) return maxTree[node] = arr[start];

    int mid = (start + end) / 2;
    long long left = Make_MaxSegementTree(node * 2, start, mid);
    long long right = Make_MaxSegementTree(node * 2 + 1, mid + 1, end);

    maxTree[node] = max(left,right);

    return maxTree[node];
}

long long Make_MinSegementTree(long long node, int start, int end) {
    if (start == end) return minTree[node] = arr[start];

    int mid = (start + end) / 2;
    long long left = Make_MinSegementTree(node * 2, start, mid);
    long long right = Make_MinSegementTree(node * 2 + 1, mid + 1, end);

    if(left==0)left = 1000000001;
    if(right==0)right= 1000000001;
    minTree[node] = min(left,right);

    return minTree[node];
}

long long Max(long long node, int start, int end, int left, int right) {
    if (left > end || right < start)return 0;
    if (left <= start && end <= right) return maxTree[node];

    int mid = (start + end) / 2;
    long long left_result = Max(node * 2, start, mid, left, right);
    long long right_result = Max(node * 2 + 1, mid + 1, end, left, right);
    return max(left_result,right_result);
}

long long Min(long long node, int start, int end, int left, int right) {
    if (left > end || right < start)return 0;
    if (left <= start && end <= right) return minTree[node];

    int mid = (start + end) / 2;
    long long left_result = Min(node * 2, start, mid, left, right);
    long long right_result = Min(node * 2 + 1, mid + 1, end, left, right);
    
    if(left_result ==0)left_result = 1000000001;
    if(right_result ==0)right_result = 1000000001;
    
    return min(left_result,right_result);
}


int main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M, K;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;
        arr.push_back(num);
    }

    long long h = (long long)ceil(log2(N));
    long long tree_size = (1 << (h + 1));

    maxTree.resize(tree_size);
    minTree.resize(tree_size);

    Make_MaxSegementTree(1, 0, N - 1);
    Make_MinSegementTree(1, 0, N - 1);

    for (int i = 0; i < M;i++) {
        int start, end;
        cin >> start >> end;
        cout << Min(1, 0, N - 1, start-1, end-1) << " " << Max(1, 0, N - 1, start-1, end-1) << "\n";
    }

    return 0;
}
