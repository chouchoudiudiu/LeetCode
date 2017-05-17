class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1)%9; //a number between 1 - 9
    }
};

/*
digital root
https://en.wikipedia.org/wiki/Digital_root
https://www.zhihu.com/question/30972581
Let’s take a number like 12345. That’s the same as 1 × 10,000 + 2 × 1,000 + 3 × 100 + 4 × 10 + 5.

Now, 10 is 9 + 1; 100 is 99 + 1, and so on. So let’s rewrite:

12,345 = 1 × (9,999 + 1) + 2 × (999 + 1) + 3 × (99 + 1) + 4 × (9 + 1) + 5.

Multiply out the brackets and rearrange a bit; you get:

12,345 = (1 × 9,999 + 2 × 999 + 3 × 99 + 4 × 9) + (1 + 2 + 3 + 4 + 5).
*/
