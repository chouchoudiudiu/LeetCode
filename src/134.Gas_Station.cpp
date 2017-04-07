class Solution {
public: //greedy
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0, start = 0, total = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += gas[i] - cost[i];
            if (sum < 0) {
                sum = gas[i] - cost[i];
                start = i;
            }
            else {
                sum += gas[i] - cost[i];
            }
        }
        return total >= 0 ? start : -1;
    }
};

/*
我们模拟一下过程：
a. 最开始，站点0是始发站，假设车开出站点p后，油箱空了，假设sum1 = diff[0] +diff[1] + ... + diff[p]，可知sum1 < 0；
b. 根据上面的论述，我们将p+1作为始发站，开出q站后，油箱又空了，设sum2 = diff[p+1] +diff[p+2] + ... + diff[q]，可知sum2 < 0。
c. 将q+1作为始发站，假设一直开到了未循环的最末站，油箱没见底儿，设sum3 =diff[q+1] +diff[q+2] + ... + diff[size-1]，可知sum3 >= 0。
要想知道车能否开回 q 站，其实就是在sum3 的基础上，依次加上 diff[0] 到 diff[q]，看看sum3在这个过程中是否会小于0。但是我们之前已经知道diff[0] 到 diff[p-1] 这段路，油箱能一直保持非负，因此我们只要算算sum3 + sum1是否 <0，就知道能不能开到 p+1站了。如果能从p+1站开出，只要算算sum3 + sum1 + sum2 是否 < 0，就知都能不能开回q站了。
因为 sum1, sum2 都 < 0，因此如果sum3 + sum1 + sum2 >=0 那么sum3 + sum1 必然 >= 0，也就是说，只要sum3 + sum1 + sum2 >=0，车必然能开回q站。而sum3 + sum1 + sum2 其实就是 diff数组的总和 Total，遍历完所有元素已经算出来了。因此 Total 能否 >= 0，就是是否存在这样的站点的 充分必要条件。
*/
