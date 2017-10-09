/*1. Friends of Friends. 给一个get_friend_list()的API，要求implement一个function，输入是user，输出是，这个user的所有二度好友，并按共同好友数排序。
链接: https://instant.1point3acres.com/thread/196984
来源: 一亩三分地
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_set<int> getFriends(int id) {//sorted?
    return {};
}
unordered_set<int> getMutualFriends(int id1, int id2) {
   unordered_set<int> nums1 = getFriends(id1);
   unordered_set<int> nums2 = getFriends(id2);
   unordered_set<int> user(nums1.begin(), nums1.end());
   unordered_set<int> res;
   for (auto v : nums2) {
        if (user.find(v) != user.end()) {
            res.insert(v);
            user.erase(v);
        }
    }
    return res;
}

vector<int> friendsOfFriends(int id1, int id2, int k) {
   unordered_set<int> nums1 = getFriends(id1);
   unordered_map<int, int> friendMap; //id, mutual friend count
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //minheap
   for(auto v1 : nums1) {
       unordered_set<int> nums2 = getFriends(v1);
       for(auto v2 : nums2) {
           if(v2 == id1 || nums1.find(v2) != nums1.end())
               continue;
           else {
               unordered_set<int> mutual = getMutualFriends(id1, v2);
               friendMap[v2] = (int)mutual.size();
           }
       } 
   }
    
   vector<int> res;
   for(auto v : friendMap) {
       if(pq.size() < k)
           pq.push({v.second, v.first});
       else {
           if(pq.top().first < v.second) {
               pq.pop();
               pq.push({v.second, v.first});
           }
       }
       
   }
    
   while(!pq.empty()) {
       res.push_back(pq.top().second);
       pq.pop();
   }
   return res;
}
