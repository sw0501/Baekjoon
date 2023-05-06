#include<iostream>

using namespace std;

int main(){
    
    string str;
    double score;
    string rank;
    
    double total = 0;
    double total_rank= 0;
    for(int i=0;i<20;i++){
        cin >> str >> score >> rank;
        total += score;
        if(rank=="A+"){
            total_rank += score*4.5;
        }
        else if(rank=="A0"){
            total_rank += score*4.0;
        }
        else if(rank=="B+"){
            total_rank += score*3.5;
        }
        else if(rank=="B0"){
            total_rank += score*3.0;
        }
        else if(rank=="C+"){
            total_rank += score*2.5;
        }
        else if(rank=="C0"){
            total_rank += score*2.0;
        }
        else if(rank=="D+"){
            total_rank += score*1.5;
        }
        else if(rank=="D0"){
            total_rank += score*1.0;
        }
        else if(rank=="F"){
            total_rank += score*0;
        }
        else if(rank=="P"){
            total -= score;
        }
    }
    
    cout << total_rank / total << "\n";
    
    return 0;
}