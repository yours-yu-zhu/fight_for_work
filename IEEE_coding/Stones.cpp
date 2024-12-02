#include <bits/stdc++.h>
using namespace std;

const int MAX = 41;

double dp_table_global[2][MAX][MAX][MAX][MAX];
bool visited_global_flag[2][MAX][MAX][MAX][MAX];

double getProb(int R1, int B1, int R2, int B2, int isA_Alice) {
    if (R1 <= 0 || B1 <= 0)
        return 0.0; 
    if (R2 <= 0 || B2 <= 0)
        return 1.0; 

    if (visited_global_flag[isA_Alice][R1][B1][R2][B2])
        return dp_table_global[isA_Alice][R1][B1][R2][B2];

    double V1, V2, V3, V4;
    if (isA_Alice) {
        V1 = (R1 > 0) ? getProb(R1 - 1, B1, R2, B2, !isA_Alice) : 0.0;
        V2 = (R2 > 0) ? getProb(R1, B1, R2 - 1, B2, !isA_Alice) : 1.0;
        V3 = (B2 > 0) ? getProb(R1, B1, R2, B2 - 1, !isA_Alice) : 1.0;
        V4 = (B1 > 0) ? getProb(R1, B1 - 1, R2, B2, !isA_Alice) : 0.0;
    }
    else {
        V1 = (R2 > 0) ? getProb(R1, B1, R2 - 1, B2, !isA_Alice) : 1.0;
        V2 = (R1 > 0) ? getProb(R1 - 1, B1, R2, B2, !isA_Alice) : 0.0;
        V3 = (B1 > 0) ? getProb(R1, B1 - 1, R2, B2, !isA_Alice) : 0.0;
        V4 = (B2 > 0) ? getProb(R1, B1, R2, B2 - 1, !isA_Alice) : 1.0;
    }

    double V;

    if (isA_Alice) {
        // 计算B的最优猜测策略q
        double numerator = V4 - V2;
        double denominator = V1 - V3 - V2 + V4;
        double q;
        if (fabs(denominator) > 1e-9) { 
            q = numerator / denominator;
            if (q < 0.0) q = 0.0;
            if (q > 1.0) q = 1.0;
        }
        else {

            q = 0.0;
        }
        V = q * V1 + (1.0 - q) * V2;
    }
    else {
        double numerator = V4 - V3;
        double denominator = V1 - V2 - V3 + V4;
        double p;
        if (fabs(denominator) > 1e-9) { 
            p = numerator / denominator;
            if (p < 0.0) p = 0.0;
            if (p > 1.0) p = 1.0;
        }
        else {

            p = 0.0;
        }
        V = p * V1 + (1.0 - p) * V2;
    }

    visited_global_flag[isA_Alice][R1][B1][R2][B2] = true;
    dp_table_global[isA_Alice][R1][B1][R2][B2] = V;
    return V;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int R1, B1, R2, B2;
    cin >> R1 >> B1;
    cin >> R2 >> B2;
    
    double probability = getProb(R1, B1, R2, B2, 1); 
    cout << fixed << setprecision(10) << probability << "\n";
    
    return 0;
}
