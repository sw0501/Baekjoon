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
    return tree[node] = (left + right);
}

long long Sum(long long node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    
    if(left <= start && end <= right) return tree[node];
    
    int mid = (start + end) / 2;
    
    long long left_result = Sum(node*2,start,mid,left,right);
    long long right_result = Sum(node*2 + 1,mid+1,end,left,right);
    
    return (left_result + right_result);
    
}

void update(long long node, int start, int end, int index, long long diff){
    
    if (index<start || index>end)return;
    tree[node] += diff;
    if(start != end){
        int mid = (start + end) /2;
        
        update(node*2,start,mid,index,diff);
        update(node*2+1,mid+1,end,index,diff);
            
    }
}

int main() 
{
    // 코드를 작성해주세요
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int N,M;
    cin >> N >> M;
    
    long long tree_height = (long long)ceil(log2(N));
    long long tree_size = (1 << (tree_height + 1));
    
    arr.resize(N+1);
    tree.resize(tree_size);
    
    make_segment_tree(1,1,N);
    
    for(int i=0;i<M;i++){
        int op, a, b;
        cin >> op >> a >> b;
               
        if(op){
            long diff = b - arr[a];
            arr[a] = b;
            update(1,1,N,a,diff);
        }
        else{
            if(a>b){
                int tmp = a;
                a = b;
                b = tmp;
            }
            cout << Sum(1,1,N,a,b) << "\n";
        }
    }
    
    return 0;
}
