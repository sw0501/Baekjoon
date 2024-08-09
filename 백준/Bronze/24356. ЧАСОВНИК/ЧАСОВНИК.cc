#include<iostream>
#include<cmath>

using namespace std;

int main(){
    
    int t1,m1,t2,m2;
    cin >> t1 >> m1 >> t2 >> m2;
    
    int time1, time2;
    time1 = t1 * 60 + m1;
    time2 = t2 * 60 + m2;
    
    if(time1 > time2){
        time1 = time1 - 24 * 60;
    }
    
    int count = (time2 - time1)/30 ;
    
    cout << time2 - time1  << " " << count << "\n";
    
    return 0;
}