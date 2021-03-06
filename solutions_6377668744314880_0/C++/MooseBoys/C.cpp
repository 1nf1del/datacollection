////////////////////////////////////////////////////////////////
//                                                            //
//  Google Code Jam Template                                  //
//  by MooseBoys                                              //
//                                                            //
////////////////////////////////////////////////////////////////

////////////////////////////////////////////////
//                                            //
//  Generic Code                              //
//                                            //
////////////////////////////////////////////////

////////////////////////////////
//  Standard Includes         //
////////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <map>
#include <functional>
#include <random>


////////////////////////////////
//  Non-Standard Includes     //
////////////////////////////////

#include <Windows.h>
#include "BigIntegerLibrary.hh" // from http://mattmccutchen.net/bigint/
//#include "boost/math/common_factor.hpp" // from http://www.boost.org/


////////////////////////////////
//  Typedefs and Macros       //
////////////////////////////////

typedef long long           LL;
typedef unsigned long long  ULL;


////////////////////////////////
//  Debug Helpers             //
////////////////////////////////

// colored console messages
#define GoodMessage(message) {setColor(GOOD);std::cout<<message<<std::endl;setColor(NORMAL);}
#define BadMessage(message) {setColor(BAD);std::cout<<message<<std::endl;setColor(NORMAL);}
#define ImportantMessage(message) {setColor(IMPORTANT);std::cout<<message<<std::endl;setColor(NORMAL);}
enum consoleColor{ NORMAL, GOOD, BAD, IMPORTANT };
inline void setColor(consoleColor c)
{
    WORD wAttributes = 0x07;
    if (c == GOOD) wAttributes = 0x0A;
    if (c == BAD) wAttributes = 0x0C;
    if (c == IMPORTANT) wAttributes = 0xF9;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wAttributes);
}


////////////////////////////////
//  Common Functions          //
////////////////////////////////

// find and open a problem input
int loadProblemFile(std::ifstream &inputFile, std::string &inputFileName)
{
    for (char cProblem = 'A'; cProblem <= 'Z'; cProblem++)
    {
        inputFileName = std::string(1, cProblem) + "-test";
        inputFile.open(inputFileName + ".in", std::ifstream::in);
        if (inputFile.is_open()) return 0;
        inputFileName = std::string(1, cProblem) + "-large";
        inputFile.open(inputFileName + ".in", std::ifstream::in);
        if (inputFile.is_open()) return 0;
        for (char cAttempt = '9'; cAttempt >= '0'; cAttempt--)
        {
            inputFileName = std::string(1, cProblem) + "-small-attempt" + cAttempt;
            inputFile.open(inputFileName + ".in", std::ifstream::in);
            if (inputFile.is_open()) return 0;
        }
    }
    return -1;
}

// load and create problem input and output streams
int getProblemIO(std::ifstream &input, std::ofstream &output)
{
    std::string fileName;
    if (loadProblemFile(input, fileName)){ BadMessage("could not find any input files to load"); return -1; }
    else{ GoodMessage("successfully loaded input file \"" << fileName << ".in\""); }
    output.open(fileName + ".out", std::ofstream::out);
    if (output.is_open()){ GoodMessage("successfully created output file \"" << fileName << ".out\""); }
    else{ BadMessage("could not create output file \"" << fileName << ".out\""); return -1; }
    return 0;
}


////////////////////////////////////////////////
//                                            //
//  Problem-Specific Code                     //
//                                            //
////////////////////////////////////////////////

using namespace std;

inline bool cut(int mask, int i)
{
    return ((1 << i) & mask) != 0;
}

inline int totalCuts(int mask)
{
    int count = 0;
    for (int i = 0; i < 20; i++)
    {
        if (cut(mask, i)) count++;
    }
    return count;
}

struct Point
{
    long long x;
    long long y;
};

Point operator-(const Point& a, const Point& b)
{
    Point r;
    r.x = a.x - b.x;
    r.y = a.y - b.y;
    return r;
}

bool operator<(const Point& a, const Point& b)
{
    if (a.x < b.x) return true;
    if (a.x > b.x) return false;
    return a.y < b.y;
}

enum class Curve
{
    Right,
    Straight,
    Left,
    Unknown
};

Curve curve(const Point& a, const Point& b, const Point& c)
{
    Point u = b - a;
    Point v = c - b;
    long long det = u.y * v.x - u.x * v.y;
    if (det < 0) return Curve::Right;
    if (det == 0) return Curve::Straight;
    if (det > 0) return Curve::Left;
    return Curve::Unknown;
}

vector<int> GetHullIndices(const vector<Point>& trees, const vector<int>& indices)
{
    // Algorithm from http://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain
    vector<pair<Point, int>> v(trees.size());
    for (int i = 0; i < (int)trees.size(); i++)
    {
        v[i].first = trees[i];
        v[i].second = indices[i];
    }
    sort(v.begin(), v.end(), [](const pair<Point, int>& a, const pair<Point, int>& b){return a < b; });
    vector<int> upper;
    vector<int> lower;
    int N = v.size();
    for (int i = 0; i < N; i++)
    {
        while (lower.size() >= 2 && curve(v[lower[lower.size() - 2]].first, v[lower[lower.size() - 1]].first, v[i].first) == Curve::Right)
        {
            lower.pop_back();
        }
        lower.push_back(i);
    }
    for (int i = N - 1; i >= 0; i--)
    {
        while (upper.size() >= 2 && curve(v[upper[upper.size() - 2]].first, v[upper[upper.size() - 1]].first, v[i].first) == Curve::Right)
        {
            upper.pop_back();
        }
        upper.push_back(i);
    }

    vector<int> ret;
    for (int i = 0; i < (int)lower.size(); i++) ret.push_back(v[lower[i]].second);
    for (int i = 0; i < (int)upper.size(); i++) ret.push_back(v[upper[i]].second);
    return ret;
}

// problem entrypoint
int CodeJamMain()
{
    ifstream input;
    ofstream output;

    if (getProblemIO(input, output)) return -1;
    cout << fixed << setprecision(16);
    output << fixed << setprecision(16);

    int T;
    input >> T;
    for (int caseNum = 0; caseNum < T; caseNum++)
    {
        int N;
        input >> N;

        vector<Point> trees(N);
        for (int i = 0; i < N; i++) input >> trees[i].x >> trees[i].y;

        vector<int> minCuts(N, 20);

        for (int mask = 0; mask < (1 << N); mask++)
        {
            vector<Point> rtrees;
            vector<int> indices;
            for (int i = 0; i < N; i++) if (!cut(mask, i)) rtrees.push_back(trees[i]), indices.push_back(i);
            auto hull = GetHullIndices(rtrees, indices);
            int cuts = totalCuts(mask);
            for (auto vert : hull)
            {
                if (cuts < minCuts[vert]) minCuts[vert] = cuts;
            }
        }

        ostringstream oss;
        for (auto m : minCuts) oss << endl << m;
        string answer = oss.str();

        output << "Case #" << caseNum + 1 << ":";
        output << answer << endl;
        GoodMessage("Case #" << caseNum + 1 << ":" << answer);
    }

    return 0;
}

////////////////////////////////////////////////
//                                            //
//  Generic Entrypoint                        //
//                                            //
////////////////////////////////////////////////

int main(int argc, char* argv [])
{
    SetConsoleTitle(L"C");
    int ret = CodeJamMain();
    if (ret == 0){ GoodMessage(">>>> SUCCESS <<<<"); }
    else{ BadMessage(">>>> FAILURE <<<<"); }
    system("pause");
    return ret;
}
