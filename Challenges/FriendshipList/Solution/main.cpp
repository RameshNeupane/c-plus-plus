#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

ostream& operator<<(ostream& ostr, vector<int>& friends){
  ostr << "[";
  for(auto &e: friends){
    ostr << " " << e;
  }
  ostr << " ]";

  return ostr;
}

int main()
{
  map<int, vector<int>> friendshipList; // to store input list
  int numNodes; // unique number of nodes
  cout << "Number of friend nodes: ";
  cin >> numNodes;
  cout << "Enter node and values associated with each node: \n";
  for(int i = 0; i < numNodes; i++){
    int key, val;
    vector<int> friends{}; // friend nodes for the particular node
    cout << "Node: ";
    cin >> key;
    cout << "No. of friends of node " << key << ": ";
    int signal;
    cin >> signal;
    if(signal > 0){
      cout << "Friends: ";
      for(int i = 0; i < signal; i++){
        cin >> val;
        friends.push_back(val);
        }
      }
    friendshipList.insert(make_pair(key, friends));
  } 
  
  cout << "Friendship List: \n";
  for(auto it = friendshipList.begin(); it != friendshipList.end(); ++it){
    cout << it->first << ": " << it->second << "\n";
  }

  vector <set <int>> friendGroup;
  set <int> group; // contains the nodes that satisfies transitive closure
  set <int> visited; // stores the nodes that are visited once
  auto itr = friendshipList.begin(); // itetator begin
  while(itr != friendshipList.end()){
    if(visited.count(itr->first) == 0){ // If the node is not visited yet
      group.insert(itr->first);         // then add it to the new group  
      auto itrTemp = itr;
      while(itrTemp != friendshipList.end()){ 
          if(group.count(itrTemp->first) == 1){ // if the node is in group, then
            for(auto &e: itrTemp->second){ // add all the values(friends) of that node to group
              group.insert(e);
            }
            visited.insert(itrTemp->first); // add particular node to set 'visited'
          }
          itrTemp++; // 
      }
      if(!group.empty()){
        friendGroup.push_back(group); // add group to the friends group list
      }
      if(group.size() == numNodes){ // if the recent group contains all the nodes 
        visited = group; // then no need further iteration 
        break;
      }
      group.clear();
    }
    if(visited.size() == numNodes){ // end main loop
      break;
    }
    itr++; 
  }

// Display friends group
  cout << "Friends Group:\n[";
  for(const auto &g: friendGroup){
    cout << "[ ";
    for(const auto &e: g){
      cout << e << " ";
    }
    cout << "]";
  }
  cout << "]\n";

  cout << "No. of groups are: " << friendGroup.size() << "\n";
  return 0;
}