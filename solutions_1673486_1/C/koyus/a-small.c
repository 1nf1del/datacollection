#include <stdio.h>
#include <float.h>

int keyStrokes(int bkSpNum, int A, int B, int Err) {

	//Enter
	if (bkSpNum == -1) {
		//���S�ɐ���
		if (Err == 0 && A == B) return 1;
		else return 1+B+1;
	}

	//Enter�Ȃ�
	//error�Ȃ�
	if (Err == 0) return bkSpNum*2 + B - A + 1;
	else return bkSpNum*2 + B - A + 1 + B +1;

}

double calNoErrProb(double *p, int errCheckIndex) {
	double r = 1;
	int i;
	for (i = 0; i < errCheckIndex; i++) 
		r *= p[i];
	return r;
}

int main() {
	int T, i, A, B, j;
	double optimalStroke;
	double tmpStroke;
	double p[100000];
	int bkSpNum;
	int errCheckIndex;
	double P;
	double errProb;
	double noErrProb;
	FILE *in, *out;

	in = fopen("A-large.in", "r");
	out = fopen("output.txt", "w");

	fscanf(in, "%d", &T);

	for(i = 0; i < T; i++) {

		// �eCase�̓ǂݍ���
		fscanf(in, "%d", &A);
		fscanf(in, "%d", &B);
		for (j = 0; j < A; j++) {
			fscanf(in, "%lf", &p[j]);
		}

		optimalStroke = DBL_MAX;
		// �S�p�^�[���̊��Ғl�v�Z
		for (bkSpNum = 0; bkSpNum <= A; bkSpNum++) {

			errCheckIndex = A - bkSpNum;

			noErrProb = calNoErrProb(p, errCheckIndex);
			errProb = 1 - noErrProb;

			tmpStroke = noErrProb * keyStrokes(bkSpNum, A, B, 0)
				+ errProb * keyStrokes(bkSpNum, A, B, 1);

			if (optimalStroke > tmpStroke) optimalStroke = tmpStroke;
		}

		// Enter�p�^�[��
		noErrProb = calNoErrProb(p, A);
		errProb = 1 - noErrProb;
		tmpStroke = noErrProb * keyStrokes(-1, A, B, 0)
				+ errProb * keyStrokes(-1, A, B, 1);

		if (optimalStroke > tmpStroke) optimalStroke = tmpStroke;

		fprintf(out, "Case #%d: %f\n", i+1, optimalStroke);
	}
	fclose(in);
	fclose(out);
}
