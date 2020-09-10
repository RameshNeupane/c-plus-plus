#include <iostream>
#include <deque>

using namespace std;

bool is_strobogramatic(deque <int> &input_deque)
{
   bool flag = false;
   while(input_deque.size() > 1) {
      int frnt = input_deque.front();
      input_deque.pop_front();

      int bak = input_deque.back();
      input_deque.pop_back();
      if(frnt == bak) {
         if(frnt == 0 || frnt == 1 || frnt == 8)
            flag = true;
      }
      else if((frnt == 6 && bak == 9) || (frnt == 9 && bak == 6))
         flag = true;
      else {
         flag = false;
         return flag;
      }
   }
   if(input_deque.size() == 1) {
      int frnt = input_deque.front();
      if(frnt == 0 || frnt == 1 || frnt == 8)
         flag = true;
   }
   return flag;
}

int main()
{
   cout << "Enter the input number: ";
   int input;
   cin >> input;
   int temp_input = input;
   deque <int>input_deque;
   do {
      int r = temp_input % 10;
      input_deque.push_front(r);
      temp_input /= 10;
   }while(temp_input > 0);
   if(is_strobogramatic(input_deque))
      cout << input << " is strobogramatic number." << endl;
   else
      cout << input << " is not strobogramatic number." << endl;
   return 0;
}
