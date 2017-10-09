#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void getPrimesProduct(vector<int>& nums, vector<int>& res) {
    res.push_back(1);
    sort(nums.begin(), nums.end());
    int product, idx, n;
    for(size_t i = 0; i < nums.size(); ++i) {
        if(i > 0 && nums[i] == nums[i - 1])
            idx = n;
        else
            idx = 0;
        n = res.size();
        for(size_t j = idx; j < n; ++j) {
            product = res[j]*nums[i];
            res.push_back(product);
        }
    }
    //res.erase(res.begin());
}
 

    void helper(vector<int>& nums, vector<int>& res, int product, int curIdx) { //use output, no & since no pop_back()
        if (curIdx == nums.size()) {
            res.push_back(product);
            return;
        }
        int nextPos = curIdx;
        while (nextPos < nums.size() && nums[curIdx] == nums[nextPos])
            ++nextPos;
        helper (nums, res, product, nextPos);
        helper (nums, res, product*nums[curIdx], curIdx + 1);
    }

// Driver Program to test above function
int main()
{
  vector<int> primes = {2,11,3,2,3};
  vector<int> res, res1;
  getPrimesProduct(primes, res1);
  sort(res1.begin(), res1.end());
  for(auto v : res1)
      cout<<v<<" ";
  cout<<endl;
  helper(primes, res, 1, 0);
  sort(res.begin(), res.end());
  for(auto v : res)
      cout<<v<<" ";
  
  return 0;
}
