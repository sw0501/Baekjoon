#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int>arr;
vector<int>minTree;

int Make_MinSegementTree(int node, int start, int end) {
    if (start == end) return minTree[node] = start;

    int mid = (start + end) / 2;
    int left = Make_MinSegementTree(node * 2, start, mid);
    int right = Make_MinSegementTree(node * 2 + 1, mid + 1, end);

    if(left==0)left = 0;
    if(right==0)right = 0;
    
    if(arr[left] == arr[right]){
        minTree[node] = min(left,right);
    }
    else{
        minTree[node] = (arr[left] < arr[right] ? left : right);    
    }
    
    return minTree[node];
}

int Min(int node, int start, int end, int left, int right) {
    if (left > end || right < start)return 0;
    if (left <= start && end <= right) return minTree[node];

    int mid = (start + end) / 2;
    int left_result = Min(node * 2, start, mid, left, right);
    int right_result = Min(node * 2 + 1, mid + 1, end, left, right);
    
    if(arr[left_result] == arr[right_result]){
        return min(left_result,right_result);
    }
    
    else{
        return (arr[left_result] < arr[right_result] ? left_result: right_result);    
    }
}

int Update(int node, int start, int end, int index){
    
    if(index < start || index > end) return minTree[node];
    
    if(start == end) return minTree[node];
    
    int mid = (start + end) / 2;
    int left = Update(node*2,start,mid,index);
    int right = Update(node*2+1,mid+1,end,index);
    
    if(arr[left] == arr[right]){
        return minTree[node] = min(left,right);
    }
    
    else{
        return minTree[node] = (arr[left] < arr[right] ? left: right);    
    }
    
}

int main()
{

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, M;

    cin >> N;
    
    int h = (int)ceil(log2(N));
    int tree_size = (1 << (h + 1));

    minTree.resize(tree_size);
    
    arr.resize(N+1);
    arr[0] = 1000000001;
    
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    Make_MinSegementTree(1, 1, N);
    
    cin >> M;
    for (int i = 0; i < M;i++) {
        int op, a, b;
        cin >> op >> a >> b;
        
        if(op==1){
            arr[a] = b;
            Update(1,1,N,a);
        }
        else{
            cout << Min(1,1,N,a,b) << "\n";
        }
        
    }

    return 0;
}