#include <iostream>
#include <vector>
#include <list>

using namespace std;

ostream& operator<<(ostream &ostr, list<int>& inputList){
  for(auto &i: inputList){
    ostr << " " << i;
  }
  return ostr;
}

int main()
{
  list<int> inputList = {10, 5, -3, -3, 1, 4, -4, 1, -1, 5, 3, -9, 1};
  vector <list<int>> removedList;
  
  cout << "Initial Input List: [" << inputList << "]\n";
  
  // Algorithm starts
  auto it_begin = inputList.begin();
  auto it_temp = it_begin;
  while(it_begin != inputList.end()){
    // cout << "it_b: " << *it_begin << "\n";
    int sum = (*it_begin);
    it_temp++;
    while(it_temp != inputList.end()){
      // cout << "it_t: " << *it_temp << "\n";
      sum += (*it_temp);
      // cout << "sum: " << sum << "\n";
      it_temp++;
      if(sum == 0){
        list<int> tempList;
        auto pos = tempList.end();
        tempList.splice(pos, inputList, it_begin, it_temp);
        // cout << "templist: " << tempList << "\n";
        removedList.push_back(tempList);
        it_begin = it_temp;
      }
    }
    if(it_begin == inputList.end()){
      break;
    }
    it_begin++;
    it_temp = it_begin;
  }
  cout << "Removed Consecutive Node List: \n";
  for(auto rl: removedList){
    cout << "[" << rl << "] ";
  }
  cout << "\nInput List After Operation: [" << inputList << "]\n"; 

  return 0;
}