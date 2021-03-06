/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Evgenii Balai
 */

#include <iostream>
#include <fstream>

#include <iostream>
#include<string>

using namespace std;

class TaskA {
public:
    void solve(std::istream &in, std::ostream &out) {
        int n;
        in >> n;
        int count[26];
        int countD[26];
        for (int i = 0; i < n; i++) {
            string s;
            in >> s;
            for (int j = 0; j < 26; j++) {
                count[j] = 0;
                countD[j] = 0;
            }
            for (char c: s) {
                count[c - 'A']++;
            }

            // count zeros:
            int countZ = count['Z' - 'A'];
            countD[0] += countZ;
            count['Z' - 'A'] -= countZ;
            count['E' - 'A'] -= countZ;
            count['R' - 'A'] -= countZ;
            count['O' - 'A'] -= countZ;

            // count six:
            int countX = count['X' - 'A'];
            countD[6] += countX;
            count['S' - 'A'] -= countX;
            count['I' - 'A'] -= countX;
            count['X' - 'A'] -= countX;

            //2:

            int countW = count['W' - 'A'];
            countD[2] += countW;
            count['T' - 'A'] -= countW;
            count['W' - 'A'] -= countW;
            count['O' - 'A'] -= countW;

            //4:
            int countU = count['U' - 'A'];
            countD[4] += countU;
            count['F' - 'A'] -= countU;
            count['O' - 'A'] -= countU;
            count['U' - 'A'] -= countU;
            count['R' - 'A'] -= countU;

            //3:

            int countR = count['R' - 'A'];
            countD[3] += countR;
            count['T' - 'A'] -= countR;
            count['H' - 'A'] -= countR;
            count['R' - 'A'] -= countR;
            count['E' - 'A'] -= 2 * countR;

            //8:
            int countH = count['H' - 'A'];
            countD[8] += countH;
            count['E' - 'A'] -= countH;
            count['I' - 'A'] -= countH;
            count['G' - 'A'] -= countH;
            count['H' - 'A'] -= countH;
            count['T' - 'A'] -= countH;

            //5:

            int countF = count['F' - 'A'];
            countD[5] += countF;
            count['F' - 'A'] -= countF;
            count['I' - 'A'] -= countF;
            count['V' - 'A'] -= countF;
            count['E' - 'A'] -= countF;

            countD[1] = count['O' - 'A'];
            countD[7] = count['S' - 'A'];
            countD[9] = count['I' - 'A'];

            out << "Case #" << (i + 1) << ": ";
            for (int j = 0; j <= 9; j++) {
                for (int k = 0; k < countD[j]; k++) {
                    out << j;
                }
            }
            out << endl;

        }

    }
};


int main() {
    TaskA solver;
    std::istream &in(std::cin);
    std::ofstream out("a.out");
    solver.solve(in, out);
    return 0;
}

