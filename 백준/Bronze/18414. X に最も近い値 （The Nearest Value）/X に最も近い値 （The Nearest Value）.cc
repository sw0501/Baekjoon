#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    
    vector<int>v;
    int a,b,c;
    cin >> a >> b >> c;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    
    sort(v.begin(),v.end());
    
    cout << v[1];
    
    return 0;
}