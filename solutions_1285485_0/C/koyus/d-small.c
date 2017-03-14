#include<stdio.h>
#include<string.h>

int x, y;
int D;
char pos[30][30];

// ������������
int symbol(int a) {
	if (a == 0) return 0;
	else if (a > 0) return 1;
	else return -1;
}

// ��Βl
double abst(double a) {
	if (a>=0) return a;
	else return -a;
}

// �e�����̃`�F�b�N
int checkEachDirection(int direct_x, int direct_y){
	int cur_x, cur_y;	//���݂̈ʒu
	int k = 0;			//���S�ʉ߉�
	int cost;				//����
	int x_change = symbol(direct_x);	//�i�s����x
	int y_change = symbol(direct_y);	//�i�s����y

	int next_x;			//#����px
	int next_y;			//#����py
	double tmp_x;		//x�̈ړ�����
	double tmp_y;		//x��.5�̎���y
	double next_tmp_y;	//y�̈ړ�����

	cur_x = x;
	cur_y = y;

	for(k = 1; ; k++){
		//���S�ʉ߈ʒu����

		//�����͓��Ŕ���
		cost = k * k * ((direct_x * direct_x) + (direct_y * direct_y));
		if (cost > D * D) break;

		//���݈ʒu�X�V
		next_tmp_y = 0.5;
		for (tmp_x = 0.5; tmp_x < abst(direct_x); tmp_x+=1){	//���S�ɂ���܂�x�ړ�
			tmp_y = abst((double)(tmp_x * direct_y) / (double)direct_x);

			while (tmp_y > next_tmp_y) {	//x��.5�̎��܂ł�y��.5�ɂȂ��Ă���cur_y�X�V
				next_y = cur_y + y_change;

				//#-check
				if (pos[cur_x][next_y] != '#') cur_y = next_y;
				else y_change *= -1;

				next_tmp_y += 1;
			}

			if (tmp_y == next_tmp_y) {			//x��.5��y��.5����������cur_x, cur_y�X�V
				// x,y-move
				next_x = cur_x + x_change;
				next_y = cur_y + y_change;

				//#-check
				if (pos[next_x][next_y] == '#') {	//�s���悪#��������
					if (pos[cur_x][next_y] != '#' && pos[next_x][cur_y] != '#') {	//�ւ��݊p��������destroy
						return 0;
					}
					if (pos[cur_x][next_y] == '#') {	//y�ɕǂ���������cur_y�͂��̂܂܂Ō����ύX
						next_y = cur_y;
						y_change *= -1;
					}
					if (pos[next_x][cur_y] == '#') {	//x�ɕǂ���������cur_x�͂��̂܂܂Ō����ύX
						next_x = cur_x;
						x_change *= -1;
					}
				}
				//cur_x, cur_y�X�V
				cur_x = next_x;
				cur_y = next_y;

				next_tmp_y += 1;

			}else{		//x������.5�ɂȂ�����cur_x�X�V
				// x-move
				next_x = cur_x + x_change;

				//#-check
				if (pos[next_x][cur_y] != '#') cur_x = next_x;
				else x_change *= -1;

			}
		}

		for ( ; next_tmp_y < abst(direct_y); next_tmp_y += 1) {	//���S�ɂ���܂�y�ړ�

			next_y = cur_y + y_change;

			//#-check
			if (pos[cur_x][next_y] != '#') cur_y = next_y;
			else y_change *= -1;
		}

		// position-check
		if (x == cur_x && y == cur_y) {	//���݂̒��S�ʒu���X�^�[�g�Ɠ����������琬��
			return 1;
		}
	}
	return 0;
}

int checkFourDirection(int direct_x, int direct_y){
	int count = 0;
	count += checkEachDirection(direct_x, direct_y);
	count += checkEachDirection(direct_x, direct_y * (-1));
	count += checkEachDirection(direct_x * (-1), direct_y);
	count += checkEachDirection(direct_x * (-1), direct_y * (-1));

	return count;
}

int checkAllCombi(int direct_x, int direct_y) {
	int count = 0;
	count += checkFourDirection(direct_x, direct_y);
	if (direct_x != direct_y)
		count += checkFourDirection(direct_y, direct_x);
	return count;
}

int checkEachZeroDirection(int direct_x, int direct_y){
	int cur_x, cur_y;
	int next_x, next_y;
	int x_change, y_change;
	int k = 0;
	int cost;

	x_change = symbol(direct_x);
	y_change = symbol(direct_y);

	cur_x = x;
	cur_y = y;

	for(k = 1; ; k++){
		cost = k * k * ((direct_x * direct_x) + (direct_y * direct_y));
		if (cost > D * D) break;

		// move
		next_x = cur_x + x_change;
		next_y = cur_y + y_change;

		// #-check
		if (pos[next_x][next_y] == '#') {
			x_change *= -1;
			y_change *= -1;
		}else{
			cur_x = next_x;
			cur_y = next_y;
		}

		// position-check
		if (x == cur_x && y == cur_y){
			return 1;
		}
	}
	return 0;
}

int minimum(int a, int b) {
	if (a < b) return a;
	else return b;
}

int checkCommonDivisor(int a, int b){
	int i;
	int min = minimum(a,b);
	for (i = 2; i <= min; i++) {
		if (a % i == 0 && b % i == 0) return 1;
	}
	return 0;
}

int main() {
	int T, H, W;
	int i, j, k;
	int direct_x, direct_y;
	int count;
	FILE *in, *out;

	in = fopen("D-small-attempt5.in", "r");
	out = fopen("output.txt", "w");

	fscanf(in, "%d", &T);
	for (i = 0; i < T; i++) {
		fscanf(in, "%d %d %d", &H, &W, &D);

		for (j = 0; j < H; j++) {
			fscanf(in, "%s", pos[j]);
			for (k = 0; k < W; k++){
				if (pos[j][k] == 'X'){
					x = j;
					y = k;
					break;
				}
			}
		}

		count = 0;
		
		// 0check
		count += checkEachZeroDirection(0, 1);
		count += checkEachZeroDirection(0, -1);
		count += checkEachZeroDirection(1, 0);
		count += checkEachZeroDirection(-1, 0);

		// other check
		for (direct_x = 1; direct_x < D; direct_x++) {
			for (direct_y = 1; ; direct_y++) {

				// check common divisor
				if (checkCommonDivisor(direct_x, direct_y)) continue;

				// cost-check
				if ((direct_x * direct_x) + (direct_y * direct_y) > D * D) break;

				count += checkFourDirection(direct_x, direct_y);
			}
		}
		fprintf(out, "Case #%d: %d\n", i+1, count);
	}
	fclose(in);
	fclose(out);

}
