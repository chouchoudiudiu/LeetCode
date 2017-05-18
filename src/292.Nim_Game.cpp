class Solution {
public:
    bool canWinNim(int n) {
        return n%4; //as long as n%4 == 0 you lose
    }
};

//只要能把4个的情况留给对方选，就可以胜利
//只要是4的倍数，就看最上面的4个，对方都可以得到第四个，之后又是你选，对方又可以得到第二组4个的最后一个，以此类推。
//其他不是4的倍数，第一个mod4, 就是2或3，自己取了，把4留给对方啦
