#include <iostream>
#include<vector>
#include<stack>
//#include <list> //연결리스트 모듈
//#include <unordered_set> //세트 모듈

using namespace std;

//스택 문제를 연결리스트로 구현하지 않고 걍 vector로 쉽게 푸는게
//양심에 찔리지만 코테도 뭐 이렇게 하지 않을까..?

//https://cocoon1787.tistory.com/231
//https://travelbeeee.tistory.com/69

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   stack<int> stack1;
   vector<char> pm;
   int n, i, j, input1;

   cin >> n;

   if (n > 100000)
   {
      return 0;
   }


   //int* seq = new int[n];
   int seq[100001];

   for (i = 0;i < n;i++)
   {
      cin >> seq[i];
   }

   int cnt1 = 1;

   i = 0;
   while (cnt1 <= n)
   {
      stack1.push(cnt1);
      pm.push_back('+');

      while (!stack1.empty())
      {
         if (stack1.top() == seq[i]) {
            stack1.pop();
            pm.push_back('-');
            i++;
         }
         else break;
      }
      cnt1++;
   }

   if (!stack1.empty())
   {
      cout << "NO";
   }
   else
   {
      for (i = 0;i < pm.size();i++)
      {
          cout << pm[i] << "\n";
      }
   }
   
   return 0;
}