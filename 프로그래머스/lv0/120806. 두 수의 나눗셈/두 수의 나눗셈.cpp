#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = (int)((double)(num1) / (double)num2*1000);
    return answer;
}