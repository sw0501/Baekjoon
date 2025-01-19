#include <iostream>
#include <stdio.h>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    double t1,t2;
    cin >> t2;
    
    while(1){
        double num;
        cin >> num;
        
        if(num==999){
            break;
        }
        
        t1 = t2;
        t2 = num;
        
        printf("%.2lf\n",t2-t1);
    }
    
    return 0;
}
