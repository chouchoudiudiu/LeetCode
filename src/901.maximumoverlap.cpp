/*
Find the point where maximum intervals overlap
Input: arrl[] = {1, 2, 9, 5, 5}
       exit[] = {4, 5, 12, 9, 12}
First guest in array arrives at 1 and leaves at 4, 
second guest arrives at 2 and leaves at 5, and so on.

Output: 5
There are maximum 3 guests at time 5.

(1) find min and max, get bucket, like histogram
*/
void findMaxOverlap(vector<int>& start, vector<int>& end, int n ) {
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    
    //similar to merge two sorted array
    int currentOverlap = 0, maxOverlap = 0;
    int i = 0, j = 0;
    while(i < n && j < n) {
        if(start[i] < end[j]) {
            ++currentOverlap;
            maxOverlap = max(maxOverlap, currentOverlap);
            ++i;
        }
        else {
            --currentOverlap;
            ++j;
        }
    }
    
    cout<<maxOverlap<<" "<<endl;
}

int main() {
    vector<int> start = {0, 3, 4, 7, 1};
    vector<int> end = {2, 7, 6, 8, 5};
    int n = start.size();
    if(n == 0)
        return 0;
    findMaxOverlap(start, end, n);
    return 0;   
}




///////////////////////////////
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<set>
using namespace std;

void findMaxOverlap(vector<int>& start, vector<int>& end, int n ) {
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    
    //similar to merge two sorted array
    int count = 1, maxCount = 1, lastStart = -1;
    unordered_map<int, set<pair<int, int>>> umap; //counter, start;end
    int i = 1, j = 0;
    while(i < n && j < n) {
        if(start[i] <= end[j]) {
            ++count;
            if(count > maxCount) {
                maxCount = count;
                lastStart = start[i];
            }
            ++i;
        }
        else {
            if(count == maxCount)
                umap[maxCount].insert({lastStart, end[j]});//this is trying to get all valid output//problematic... [1, 2] [7, 5] cant quit
            --count;
            ++j;
        }
    }
}

int main() {
    vector<int> start = {1, 2,10, 3, 3, 3};
    vector<int> end = {7, 6, 12, 9, 12, 6};
    int n = start.size();
    if(n == 0)
        return 0;
    findMaxOverlap(start, end, n);
    return 0;   
}
/*
    cout<<maxCount<<" "<<endl;
    for(auto v : umap[maxCount])
        cout<<v.first<<" "<<v.second;
*/
//http://www.zrzahid.com/maximum-number-of-overlapping-intervals/
