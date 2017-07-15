class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        if(sum%(machines.size()) != 0)
            return -1;
        int res = 0, cnt = 0, avg = sum/machines.size();
        for(auto m : machines) {
            cnt += m - avg;
            res = max(res, max(abs(cnt), m - avg));
        }
        return res;
    }
};

/*
有四个洗衣机，装的衣服数为[0, 0, 11, 5]，最终的状态会变为[4, 4, 4, 4]，那么我们将二者做差，得到[-4, -4, 7, 1]，这里负数表示当前洗衣机还需要的衣服数，正数表示当前洗衣机多余的衣服数。我们要做的是要将这个差值数组每一项都变为0，对于第一个洗衣机来说，需要四件衣服可以从第二个洗衣机获得，那么就可以把-4移给二号洗衣机，那么差值数组变为[0, -8, 7, 1]，此时二号洗衣机需要八件衣服，那么至少需要移动8次。然后二号洗衣机把这八件衣服从三号洗衣机处获得，那么差值数组变为[0, 0, -1, 1]，此时三号洗衣机还缺1件，就从四号洗衣机处获得，此时差值数组成功变为了[0, 0, 0, 0]，成功。那么移动的最大次数就是差值数组中出现的绝对值最大的数字，8次
For example, your machines[] is [0,0,11,5]. So your total is 16 and the target value for each machine is 4. Convert the machines array to a kind of gain/lose array, we get: [-4,-4,7,1]. Now what we want to do is go from the first one and try to make all of them 0.
To make the 1st machines 0, you need to give all its "load" to the 2nd machines.
So we get: [0,-8,7,1]
then: [0,0,-1,1]
lastly: [0,0,0,0], done.
You don't have to worry about the details about how these machines give load to each other. In this process, the least steps we need to eventually finish this process is determined by the peak of abs(cnt) and the max of "gain/lose" array. In this case, the peak of abs(cnt) is 8 and the max of gain/lose array is 7. So the result is 8.
Some other example:
machines: [0,3,0]; gain/lose array: [-1,2,-1]; max = 2, cnt = 0, -1, 1, 0, its abs peak is 1. So result is 2.
machines: [1,0,5]; gain/lose array: [-1,-2,3]; max = 3, cnt = 0, -1, -3, 0, its abs peak is 3. So result is 3.
*/
