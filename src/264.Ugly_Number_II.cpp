class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return 0;
        vector<int> uglyNumbers(n, 1);
        int p2 = 0, p3 = 0, p5 = 0;
        int i = 1; //the first ugly number
        
        while (i < n) {//每一个较小的丑数，后面都要乘以2,3,5得到一个数看是否比较小
            int ugly2 = uglyNumbers[p2]*2;
            int ugly3 = uglyNumbers[p3]*3;
            int ugly5 = uglyNumbers[p5]*5;
            int minVal = min(ugly2, min(ugly3, ugly5));
            
            if (ugly2 == minVal)
                ++p2;
            if (ugly3 == minVal)
                ++p3;
            if (ugly5 == minVal)
                ++p5;
            uglyNumbers[i++] = minVal;
        }
        return uglyNumbers[n - 1];
    }
};
/*
每个子列表都是一个丑陋数分别乘以2,3,5，而要求的丑陋数就是从已经生成的序列中取出来的，我们每次都从三个列表中取出当前最小的那个加入序列
(1) 1×2, 2×2, 3×2, 4×2, 5×2, …
(2) 1×3, 2×3, 3×3, 4×3, 5×3, … //3*2与2*3都等于6 == minVal，p2++, p3++
(3) 1×5, 2×5, 3×5, 4×5, 5×5, …*/

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq; //minheap
        pq.push(1);
        while(--n > 0) {
            auto tmp = pq.top();
            pq.pop();
            while(!pq.empty() && pq.top() == tmp)
                pq.pop();
            pq.push(tmp*2);
            pq.push(tmp*3);
            pq.push(tmp*5);
        }
        return pq.top();
    }
};

/*
            pq.push(res*2);
            pq.push(res*3);
            pq.push(res*5);
            can have duplicate...
*/
