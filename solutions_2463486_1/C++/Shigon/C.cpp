#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long LL;
typedef long double LD;

LL tab[]={0LL, 1LL, 2LL, 3LL, 11LL, 22LL, 101LL, 111LL, 121LL, 202LL, 212LL, 1001LL, 1111LL, 2002LL, 10001LL, 10101LL, 10201LL, 11011LL, 11111LL, 11211LL, 20002LL, 20102LL, 100001LL, 101101LL, 110011LL, 111111LL, 200002LL, 1000001LL, 1001001LL, 1002001LL, 1010101LL, 1011101LL, 1012101LL, 1100011LL, 1101011LL, 1102011LL, 1110111LL, 1111111LL, 2000002LL, 2001002LL, 10000001LL, 10011001LL, 10100101LL, 10111101LL, 11000011LL, 11011011LL, 11100111LL, 11111111LL, 20000002LL, 100000001LL, 100010001LL, 100020001LL, 100101001LL, 100111001LL, 100121001LL, 101000101LL, 101010101LL, 101020101LL, 101101101LL, 101111101LL, 110000011LL, 110010011LL, 110020011LL, 110101011LL, 110111011LL, 111000111LL, 111010111LL, 111101111LL, 111111111LL, 200000002LL, 200010002LL, 1000000001LL, 1000110001LL, 1001001001LL, 1001111001LL, 1010000101LL, 1010110101LL, 1011001101LL, 1011111101LL, 1100000011LL, 1100110011LL, 1101001011LL, 1101111011LL, 1110000111LL, 1110110111LL, 1111001111LL, 2000000002LL, 10000000001LL, 10000100001LL, 10000200001LL, 10001010001LL, 10001110001LL, 10001210001LL, 10010001001LL, 10010101001LL, 10010201001LL, 10011011001LL, 10011111001LL, 10100000101LL, 10100100101LL, 10100200101LL, 10101010101LL, 10101110101LL, 10110001101LL, 10110101101LL, 10111011101LL, 10111111101LL, 11000000011LL, 11000100011LL, 11000200011LL, 11001010011LL, 11001110011LL, 11010001011LL, 11010101011LL, 11011011011LL, 11011111011LL, 11100000111LL, 11100100111LL, 11101010111LL, 11101110111LL, 11110001111LL, 11110101111LL, 20000000002LL, 20000100002LL, 100000000001LL, 100001100001LL, 100010010001LL, 100011110001LL, 100100001001LL, 100101101001LL, 100110011001LL, 100111111001LL, 101000000101LL, 101001100101LL, 101010010101LL, 101011110101LL, 101100001101LL, 101101101101LL, 101110011101LL, 110000000011LL, 110001100011LL, 110010010011LL, 110011110011LL, 110100001011LL, 110101101011LL, 110110011011LL, 111000000111LL, 111001100111LL, 111010010111LL, 111100001111LL, 200000000002LL, 1000000000001LL, 1000001000001LL, 1000002000001LL, 1000010100001LL, 1000011100001LL, 1000012100001LL, 1000100010001LL, 1000101010001LL, 1000102010001LL, 1000110110001LL, 1000111110001LL, 1001000001001LL, 1001001001001LL, 1001002001001LL, 1001010101001LL, 1001011101001LL, 1001100011001LL, 1001101011001LL, 1001110111001LL, 1001111111001LL, 1010000000101LL, 1010001000101LL, 1010002000101LL, 1010010100101LL, 1010011100101LL, 1010100010101LL, 1010101010101LL, 1010110110101LL, 1010111110101LL, 1011000001101LL, 1011001001101LL, 1011010101101LL, 1011011101101LL, 1011100011101LL, 1011101011101LL, 1100000000011LL, 1100001000011LL, 1100002000011LL, 1100010100011LL, 1100011100011LL, 1100100010011LL, 1100101010011LL, 1100110110011LL, 1100111110011LL, 1101000001011LL, 1101001001011LL, 1101010101011LL, 1101011101011LL, 1101100011011LL, 1101101011011LL, 1110000000111LL, 1110001000111LL, 1110010100111LL, 1110011100111LL, 1110100010111LL, 1110101010111LL, 1111000001111LL, 1111001001111LL, 2000000000002LL, 2000001000002LL, 10000000000001LL, 10000011000001LL, 10000100100001LL, 10000111100001LL, 10001000010001LL, 10001011010001LL, 10001100110001LL, 10001111110001LL, 10010000001001LL, 10010011001001LL, 10010100101001LL, 10010111101001LL, 10011000011001LL, 10011011011001LL, 10011100111001LL, 10100000000101LL, 10100011000101LL, 10100100100101LL, 10100111100101LL, 10101000010101LL, 10101011010101LL, 10101100110101LL, 10110000001101LL, 10110011001101LL, 10110100101101LL, 10111000011101LL, 11000000000011LL, 11000011000011LL, 11000100100011LL, 11000111100011LL, 11001000010011LL, 11001011010011LL, 11001100110011LL, 11010000001011LL, 11010011001011LL, 11010100101011LL, 11011000011011LL, 11100000000111LL, 11100011000111LL, 11100100100111LL, 11101000010111LL, 11110000001111LL, 20000000000002LL, 100000000000001LL, 100000010000001LL, 100000020000001LL, 100000101000001LL, 100000111000001LL, 100000121000001LL, 100001000100001LL, 100001010100001LL, 100001020100001LL, 100001101100001LL, 100001111100001LL, 100010000010001LL, 100010010010001LL, 100010020010001LL, 100010101010001LL, 100010111010001LL, 100011000110001LL, 100011010110001LL, 100011101110001LL, 100011111110001LL, 100100000001001LL, 100100010001001LL, 100100020001001LL, 100100101001001LL, 100100111001001LL, 100101000101001LL, 100101010101001LL, 100101101101001LL, 100101111101001LL, 100110000011001LL, 100110010011001LL, 100110101011001LL, 100110111011001LL, 100111000111001LL, 100111010111001LL, 101000000000101LL, 101000010000101LL, 101000020000101LL, 101000101000101LL, 101000111000101LL, 101001000100101LL, 101001010100101LL, 101001101100101LL, 101001111100101LL, 101010000010101LL, 101010010010101LL, 101010101010101LL, 101010111010101LL, 101011000110101LL, 101011010110101LL, 101100000001101LL, 101100010001101LL, 101100101001101LL, 101100111001101LL, 101101000101101LL, 101101010101101LL, 101110000011101LL, 101110010011101LL, 110000000000011LL, 110000010000011LL, 110000020000011LL, 110000101000011LL, 110000111000011LL, 110001000100011LL, 110001010100011LL, 110001101100011LL, 110001111100011LL, 110010000010011LL, 110010010010011LL, 110010101010011LL, 110010111010011LL, 110011000110011LL, 110011010110011LL, 110100000001011LL, 110100010001011LL, 110100101001011LL, 110100111001011LL, 110101000101011LL, 110101010101011LL, 110110000011011LL, 110110010011011LL, 111000000000111LL, 111000010000111LL, 111000101000111LL, 111000111000111LL, 111001000100111LL, 111001010100111LL, 111010000010111LL, 111010010010111LL, 111100000001111LL, 111100010001111LL, 200000000000002LL, 200000010000002LL, 1000000000000000LL, 1000000110000000LL, 1000001001000000LL, 1000001111000000LL, 1000010000100000LL, 1000010110100000LL, 1000011001100000LL, 1000011111100000LL, 1000100000010000LL, 1000100110010000LL, 1000101001010000LL, 1000101111010000LL, 1000110000110000LL, 1000110110110000LL, 1000111001110000LL, 1001000000001000LL, 1001000110001000LL, 1001001001001000LL, 1001001111001000LL, 1001010000101000LL, 1001010110101000LL, 1001011001101000LL, 1001100000011000LL, 1001100110011000LL, 1001101001011000LL, 1001110000111000LL, 1010000000000100LL, 1010000110000100LL, 1010001001000100LL, 1010001111000100LL, 1010010000100100LL, 1010010110100100LL, 1010011001100100LL, 1010100000010100LL, 1010100110010100LL, 1010101001010100LL, 1010110000110100LL, 1011000000001100LL, 1011000110001100LL, 1011001001001100LL, 1011010000101100LL, 1011100000011100LL, 1100000000000010LL, 1100000110000010LL, 1100001001000010LL, 1100001111000010LL, 1100010000100010LL, 1100010110100010LL, 1100011001100010LL, 1100100000010010LL, 1100100110010010LL, 1100101001010010LL, 1100110000110010LL, 1101000000001010LL, 1101000110001010LL, 1101001001001010LL, 1101010000101010LL, 1101100000011010LL, 1110000000000110LL, 1110000110000110LL, 1110001001000110LL, 1110010000100110LL, 1110100000010110LL, 1111000000001110LL, 2000000000000000};

int main()
{
	ios::sync_with_stdio(0);

	const int ile=sizeof(tab)/sizeof(LL);

	int Testow; cin>>Testow;
	for (int nrTestu=1; nrTestu<=Testow; ++nrTestu)
	{
		LL A,B; cin>>A>>B;
		LL odkad=(LL)ceil(sqrt((LD)A));
		LL dokad=(LL)floor(sqrt((LD)B));
		
		LL* pozA = lower_bound(tab,tab+ile,odkad);
		LL* pozB = upper_bound(tab,tab+ile,dokad);

		int wynik=(int)(pozB-pozA);
		cout<<"Case #"<<nrTestu<<": "<<wynik<<endl;
	}

	return 0;
}