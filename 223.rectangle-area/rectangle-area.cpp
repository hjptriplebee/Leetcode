class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaA = (C - A) * (D - B);
        int areaB = (G - E) * (H - F);
        if(C < E || A > G || B > H || D < F) return areaA + areaB;
        int inter = (min(D, H) - max(B, F)) * (min(G, C) - max(A, E));
        return areaA + areaB - inter;
    }
};