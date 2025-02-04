#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<long long> arr;
vector<long long> tree;

long long make_segment_tree(long long node, int start, int end){
    if(start == end) return tree[node] = arr[start];

    int mid = (start + end)/2;
    
    long long left = make_segment_tree(node*2, start, mid);
    long long right = make_segment_tree(node*2 + 1, mid + 1, end);
    return tree[node] = (left * right) % 1000000007;
}

long long multifly(long long node, int start, int end, int left, int right){
    if(left > end || right < start) return 1;
    
    if(left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    
    long long left_result = multifly(node*2,start,mid,left,right);
    long long right_result = multifly(node*2 + 1,mid+1,end,left,right);
    
    return (left_result * right_result) % 1000000007;
    
}

long long update(long long node, int start, int end, int index, long long diff){
    if(index < start || end < index) return tree[node];
    
    if(start == end){
        return tree[node] = diff;
    }
    
    int mid = (start + end) /2;
        
    long long left_result = update(node*2,start,mid,index,diff);
    long long right_result = update(node*2+1,mid+1,end,index,diff);
        
    return tree[node] = (left_result * right_result) % 1000000007;
}

int main() 
{
    // 코드를 작성해주세요
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N,M,K;
    cin >> N >> M >> K;
    
    long long tree_height = (long long)ceil(log2(N));
    long long tree_size = (1 << (tree_height + 1));
    
    arr.resize(N+1);
    tree.resize(N*4 );
        
    for(int i=1;i<=N;i++){
        long long num;
        cin >> num;
        
        arr[i] = num;
    }
    
    make_segment_tree(1,1,N);
    
    for(int i=0;i<M+K;i++){
        int op;
        int b,c;
        cin >> op >> b >> c;
        
        if(op==1){        
            arr[b] = c;
            update(1,1,N,b,c);
        }
        
        else {
            cout << multifly(1,1,N,b,c) << "\n";
        }
    }
    
    return 0;
}
