#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <cstdint>
#include <cstring>

using namespace std;

class FloatHexConverter {
public:
    static float hexToFloat(const string& hexStr) {
        uint32_t hexVal = stoul(hexStr, nullptr, 16);
        float result;
        memcpy(&result, &hexVal, sizeof(result));
        return result;
    }

    static string floatToHex(float val) {
        uint32_t hexVal;
        memcpy(&hexVal, &val, sizeof(hexVal));
        stringstream ss;
        ss << hex << setw(8) << setfill('0') << hexVal;
        return ss.str();
    }
};

class Operations {
public:
    static uint32_t nandOperation(uint32_t a, uint32_t b) {
        return ~(a & b);
    }

    static float fusedMultiplyAdd(float a, float b, float c) {
        return fmaf(a, b, c);
    }

    static float lookupTable(const vector<float>& LUT, uint32_t mask) {
        return LUT[mask];
    }
};

class Processor {
    vector<float> results;

public:
    void process() {
        int T;
        cin >> T;

        while (T--) {
            string C0_hex;
            cin >> C0_hex;
            float C0 = FloatHexConverter::hexToFloat(C0_hex);

            int L;
            cin >> L;
            vector<vector<float>> LUTs(L);

            for (int i = 0; i < L; ++i) {
                int size;
                cin >> size;
                LUTs[i].resize(size);

                for (int j = 0; j < size; ++j) {
                    string lutValHex;
                    cin >> lutValHex;
                    LUTs[i][j] = FloatHexConverter::hexToFloat(lutValHex);
                }
            }

            int Q;
            cin >> Q;
            vector<float> C = {C0};

            for (int q = 0; q < Q; ++q) {
                char cmd;
                cin >> cmd;
                if (cmd == 'L') {
                    int i, j, b;
                    cin >> i >> j >> b;
                    uint32_t C0_bits;
                    memcpy(&C0_bits, &C[0], sizeof(C0_bits));
                    uint32_t mask = (C0_bits >> j) & ((1 << b) - 1);
                    C.push_back(Operations::lookupTable(LUTs[i], mask));
                } else if (cmd == 'N') {
                    int i, j;
                    cin >> i >> j;
                    uint32_t Ci = *reinterpret_cast<uint32_t*>(&C[i]);
                    uint32_t Cj = *reinterpret_cast<uint32_t*>(&C[j]);
                    uint32_t result = Operations::nandOperation(Ci, Cj);
                    float nandResult;
                    memcpy(&nandResult, &result, sizeof(result));
                    C.push_back(nandResult);
                } else if (cmd == 'F') {
                    int i, j, k;
                    cin >> i >> j >> k;
                    float a = C[i];
                    float b = C[j];
                    float c = C[k];
                    C.push_back(Operations::fusedMultiplyAdd(a, b, c));
                } else if (cmd == 'C') {
                    string hexVal;
                    cin >> hexVal;
                    C.push_back(FloatHexConverter::hexToFloat(hexVal));
                }
            }

            results.push_back(C.back());
        }

        for (const float result : results)
            cout << FloatHexConverter::floatToHex(result) << endl;
    }
};

int main() {
    Processor processor;
    processor.process();
    return 0;
}
