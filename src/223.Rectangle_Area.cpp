class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int sum = (C - A)*(D - B) + (G - E)*(H - F);
        if (C <= E || G <= A || H <= B || D <= F) //no intersection
            return sum;
        else
            return sum - (min(C, G) - max(A, E))*(min(D, H) - max(B, F));////total - intersect(complement)
    }
};
