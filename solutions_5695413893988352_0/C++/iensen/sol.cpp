/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Evgenii Balai
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include<string>
#include <limits>
#include <array>
#include <vector>
#include<math.h>
#include<algorithm>

using namespace std;

class TaskB {

public:
    std::vector<int> digitsC, digitsJ;


    long long best;
    vector<int> v1;
    vector<int> v2;

    long long getNumber(std::vector<int> digits) {
        long long res = 0;
        long long mult = 1;
        for (int j = digits.size() - 1; j >= 0; j--) {
            res += mult * digits.at(j);
            mult *= 10;
        }
        return res;
    }

    void go(std::vector<int> digitsC, std::vector<int> digitsJ, int index, int greater) {
        if (index == digitsC.size()) {
            long long n1 = getNumber(digitsC);
            long long n2 = getNumber(digitsJ);
            if (abs(n1 - n2) < best) {
                best = abs(n1 - n2);
                v1 = digitsC;
                v2 = digitsJ;
            }
            return;
        }

        if (greater > 0) {
            if (digitsC[index] == -1)
                digitsC[index] = 0;
            if (digitsJ[index] == -1)
                digitsJ[index] = 9;
            go(digitsC, digitsJ, index + 1, greater);
        }
        if (greater < 0) {
            if (digitsC[index] == -1)
                digitsC[index] = 9;
            if (digitsJ[index] == -1)
                digitsJ[index] = 0;
            go(digitsC, digitsJ, index + 1, greater);
        }

        if (greater == 0) {
            if (digitsC[index] == -1 && digitsJ[index] == -1) {
                digitsC[index] = 0;
                digitsJ[index] = 0;
                go(digitsC, digitsJ, index + 1, 0);
                digitsC[index] = 0;
                digitsJ[index] = 1;
                go(digitsC, digitsJ, index + 1, -1);
                digitsC[index] = 1;
                digitsJ[index] = 0;
                go(digitsC, digitsJ, index + 1, 1);
                return;
            }

            if (digitsC[index] == -1) {
                for (int d = max(0, digitsJ[index] - 1); d <= min(9, digitsJ[index] + 1); d++) {
                    digitsC[index] = d;
                    go(digitsC, digitsJ, index + 1, digitsC[index] - digitsJ[index]);
                }
                return;

            }

            if (digitsJ[index] == -1) {
                for (int d = max(0, digitsC[index] - 1); d <= min(9, digitsC[index] + 1); d++) {
                    digitsJ[index] = d;
                    go(digitsC, digitsJ, index + 1, digitsC[index] - digitsJ[index]);
                }
                return;
            }

            go(digitsC, digitsJ, index + 1, digitsC[index] - digitsJ[index]);

        }

    }

    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;

        for (int t = 0; t < n; t++) {
            string C, J;
            in >> C >> J;
            digitsC.clear();
            digitsJ.clear();
            for (int i = 0; i < C.length(); i++) {
                if (C[i] == '?') digitsC.push_back(-1);
                else digitsC.push_back(C[i] - '0');

                if (J[i] == '?') digitsJ.push_back(-1);
                else digitsJ.push_back(J[i] - '0');

            }
            best = std::numeric_limits<long long>::max();
            go(digitsC, digitsJ, 0, 0);
            out << "Case #" << (t + 1) << ": ";
            for (int i = 0; i < v1.size(); i++) {
                out << v1[i];
            }
            out << " ";
            for (int j = 0; j < v2.size(); j++) {
                out << v2[j];
            }
            out << std::endl;

        }

    }
};


int main() {
    TaskB solver;
    std::istream &in(std::cin);
    std::ofstream out("b.out");
    solver.solve(in, out);
    return 0;
}
