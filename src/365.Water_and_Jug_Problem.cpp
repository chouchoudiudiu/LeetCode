class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
    }
    int gcd(int x, int y) {
        return y == 0 ? x : gcd(y, x % y); //gcd(x, y) = gcd(y, x mod y)
    }
};

//x = 3, y = 5, z = 4
//5中倒满，接着将5中水倒入3中，应剩余2，将3中水全部倒出，倒入5中剩余的2，将5装满，倒入3中，应该倒出1（3中已有2），5中剩余4
//z = m*x + n*y; 4 = (-2)*3 + 2*5 
/*
根据裴蜀定理，ax + by = d的解为 d = gcd(x, y)，只要z % d == 0，上面的等式就有解，所以问题就迎刃而解了，只要看z是不是x和y的最大公约数的倍数就行了，限制条件x + y >= z，因为x和y不可能称出比它们之和还多的水
https://www.cnblogs.com/drizzlecrj/archive/2007/09/14/892340.html
*/
