#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    
    int T,N;
    cin >> T >> N;
    
    unordered_map<string,int> day;
    
    day.insert({"Mon",0});
    day.insert({"Tue",1});
    day.insert({"Wed",2});
    day.insert({"Thu",3});
    day.insert({"Fri",4});
    
    for(int i=0;i<N;i++){
        string start_day, end_day;
        int start_time, end_time;
        cin >> start_day >> start_time >> end_day >> end_time;
        
        T -= (day[end_day] - day[start_day]) * 24 + (end_time - start_time);
    }
    
    if(T <= 0){
        cout << 0 << "\n";
    }
    else if(T > 48){
        cout << -1 << "\n";
    }
    else {
        cout << T << "\n";
    }
    
    return 0;
}