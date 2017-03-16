#include"tmp.h"



ull tp(ull i) {
	//0 ~ 18
	ull ret = 1;
	for (int j = 0; j < i; ++j) {
		ret *= 10ull;
	}
	return ret;
}

ull getDiff(ull c, ull j) {
	if (c > j) return c - j;
	else return j - c;
}
ull getDiff(pair<ull, ull> p) {
	return getDiff(p.second, p.first);
}

tuple<ull, ull, ull> ansTie(pair<ull, ull> p) {
	return make_tuple(getDiff(p), p.first, p.second);
}
tuple<ull, ull, ull> ansTie(ull c, ull j) {
	return make_tuple(getDiff(c,j), c,j);
}


pair<string,string> makeans(string c, string j) {
	string cans, jans;
	int n = c.size();
	ull cVal=0, jVal=0;

	for (int i = 0; i < n; ++i) {
		if (c[i] == '?' || j[i] == '?' || c[i] == j[i])
			continue;

		int i_ = n - 1 - i;
		cVal += tp(i_) * (c[i] - '0');
		jVal += tp(i_) * (j[i] - '0');
	}

	//cout << cVal << ' ' << jVal << endl;

	for (int i = 0; i < n; ++i) {
		int i_ = n - 1 - i;

		if (c[i] != '?' && j[i] != '?') {
			continue; // �Ѵ� ���ڰ� �� �ִ� ��, �̹� ������ ���ڸ� �߰��߽��ϴ�.
		}

		// �ϴ� ���� �ٸ��� Ȯ���� cVal == jVal ���� ������ ���� ã�ƿ��� ����
		if (i == n-1) {
			if (cVal < jVal) {
				if (c[i] == '?') c[i] = '9';
				if (j[i] == '?') j[i] = '0';
			}
			else {
				if (c[i] == '?') c[i] = '0';
				if (j[i] == '?') j[i] = '9';
			}
			cVal += tp(i_) * (c[i] - '0');
			jVal += tp(i_) * (j[i] - '0');
			continue;
		}

		if (c[i] == '?' && j[i] == '?') {
			// �̹� ���������� Ȯ���մϴ�.
			if (getDiff(cVal, jVal) / tp(i_)) {
				if (cVal > jVal) {
					c[i] = '0';
					j[i] = '9';
				}
				else {
					c[i] = '9';
					j[i] = '0';
				}
			}
			else { // ���� �������� �ʾҽ��ϴ�.
				if (getDiff(cVal, jVal)  <= 5 * tp(i_ - 1)) { // ũ�Ⱑ ���� ���̳��� �ʴ´ٸ� �Ѵ� �Ȱ��� ���� �ִ� ���� �����ϴ�.
					c[i] = '0';
					j[i] = '0';
				}
				else if (cVal > jVal) {
					c[i] = '0';
					j[i] = '1';
				}
				else {
					c[i] = '1';
					j[i] = '0';
				}
			}
		}
		else if (c[i] == '?') {


			// �̹� ���������� Ȯ���մϴ�.
			if (getDiff(cVal, jVal) / tp(i_)) {
				if (cVal > jVal) {
					c[i] = '0';
				}
				else {
					c[i] = '9';
				}
			}
			else { // ���� �������� �ʾҽ��ϴ�.
				if (getDiff(cVal, jVal) == 5 * tp(i_ - 1)) {
					c[i] = max((char)(j[i] - 1), '0');
				}
				else if (getDiff(cVal, jVal) < 5 * tp(i_ - 1)) { // ũ�Ⱑ ���� ���̳��� �ʴ´ٸ� �Ѵ� �Ȱ��� ���� �ִ� ���� �����ϴ�.
					c[i] = j[i];
				}
				else if (cVal > jVal) { // c���� j���� ���� ����
					c[i] = max((char)(j[i]-1), '0');
				}
				else { // j���� ū ����
					c[i] = min((char)(j[i]+1), '9');
				}
			}


		}
		else { // j[i] == '?'

			   // �̹� ���������� Ȯ���մϴ�.
			if (getDiff(cVal, jVal) / tp(i_)) {
				if (cVal > jVal) {
					j[i] = '9';
				}
				else {
					j[i] = '0';
				}
			}
			else { // ���� �������� �ʾҽ��ϴ�.
				if (getDiff(cVal, jVal) == 5 * tp(i_ - 1)) {
					j[i] = max((char)(c[i] - 1), '0');
				}
				else if (getDiff(cVal, jVal) < 5 * tp(i_ - 1)) { // ũ�Ⱑ ���� ���̳��� �ʴ´ٸ� �Ѵ� �Ȱ��� ���� �ִ� ���� �����ϴ�.
					j[i] = c[i];
				}
				else if (cVal > jVal) { // j���� c���� ū ����
					j[i] = min((char)(c[i] + 1), '9');
				}
				else {
					j[i] = max((char)(c[i] - 1), '0');
				}
			}

		}
		cVal += tp(i_) * (c[i] - '0');
		jVal += tp(i_) * (j[i] - '0');
	}

	return make_pair(c,j);
}



int main() {

	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	cin.sync_with_stdio(false);
	int TC; cin >> TC;

	for (int tc = 1; tc <= TC; ++tc) {
		string c, j;
		cin >> c >> j;
		int n = c.size();

		bool canBeSame = true;
		bool cIsBiggerInFixedPart = false;
		bool isFirstDiff = true;
		int firstDiff = -1;
		for (int i = 0; i < n; ++i) {
			if (c[i] != '?' && j[i] != '?') {
				if (c[i] != j[i]) {
					canBeSame = false;
					if (isFirstDiff) {
						cIsBiggerInFixedPart = c[i] > j[i];
						isFirstDiff = false;
						firstDiff = i;
					}
				}
			}
		}

		
		
		string cAns = "", jAns = "";
		if (canBeSame) {
			string ans = "";
			for (int i = 0; i < n; ++i) {

				if (c[i] == '?' && j[i] == '?') {
					ans += "0";
				}
				else if (c[i] != '?') {
					ans += c[i];
				}
				else {
					ans += j[i];
				}
			}
			cAns = jAns = ans;
			cout << "Case #" << tc << ": " << cAns << ' ' << jAns << endl;
		}
		else {
			tie(cAns, jAns) = makeans(c, j);

			cout << "Case #" << tc << ": " << cAns << ' ' << jAns << endl;
		}

	}
	return 0;
}