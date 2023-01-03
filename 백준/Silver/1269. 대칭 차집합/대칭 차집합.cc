#include<iostream>
#include<map>

using namespace std;

int main(){
    
    map<int,int>m;
    
    int a,b;
    
    int c=0;
    cin >> a >> b;
    
    for(int i=0;i<a;i++){
        int num;
		cin >> num;
        m.insert({num,1});
    }
    for(int i=0;i<b;i++){
        int num;
        cin >> num;
        if(m.find(num)!=m.end()){
            c++;
        }
    }
    
    cout << a+b-2*c << "\n";    
    
    return 0;
}