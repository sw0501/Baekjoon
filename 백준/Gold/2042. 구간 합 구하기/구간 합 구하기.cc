#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<long long>arr;
vector<long long>tree;

long long Make_SegementTree(long long node, int start, int end) {
    if (start == end) return tree[node] = arr[start];

    int mid = (start + end) / 2;
    long long left = Make_SegementTree(node * 2, start, mid);
    long long right = Make_SegementTree(node * 2 + 1, mid + 1, end);

    tree[node] = left + right;

    return tree[node];
}

long long Sum(long long node, int start, int end, int left, int right) {
    if (left > end || right < start)return 0;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    long long left_result = Sum(node * 2, start, mid, left, right);
    long long right_result = Sum(node * 2 + 1, mid + 1, end, left, right);
    return left_result + right_result;
}

void Update(long long node, int start, int end, int index, long long diff) {
    if (index<start || index>end)return;

    tree[node] = tree[node] + diff;

    if (start != end) {
        int mid = (start + end) / 2;
        Update(node * 2, start, mid, index, diff);
        Update(node * 2 + 1, mid + 1, end, index, diff);
    }
}


int main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M, K;

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        long long num;
        cin >> num;
        arr.push_back(num);
    }

    long long h = (long long)ceil(log2(N));
    long long tree_size = (1 << (h + 1));

    tree.resize(tree_size);

    Make_SegementTree(1, 0, N - 1);

    for (int i = 0; i < M + K;i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int idx;
            long long num;
            cin >> idx >> num;
            long long diff = num - arr[idx - 1];
            arr[idx - 1] = num;
            Update(1, 0, N - 1, idx - 1, diff);
        }
        else {
            int start, end;
            cin >> start >> end;
            cout << Sum(1, 0, N - 1, start-1, end-1) << "\n";
        }
    }

    return 0;
}
