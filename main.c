#include <stdio.h>
#include <stdlib.h>

#define N 6

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int gameboard[N][N];

void main(...)
{
	/*�ʿ��� ���� ���� */
	init_othello(); /*���� �ʱ�ȭ*/ 
	
	while (isGameEnd()==0)
	{
		print_othello(); /*��ġ ���� ���*/ 
		if (/*��ġ�� ������ ĭ�� �ִ��� Ȯ��*/)
			continue;
		/*��ġ�� ��ǥ �Է� �ޱ�*/ 
		if (/*�Է���ǥ�� �������� üũ*/)
			if (/*������ �õ�*/)
			{
				/*� ���������� ���*/
				/*�� �ٲ�*/ 
			}
		else
			/*�������� �Է����� ���*/ 
	}
	check_result(); /*��� ���*/ 
}


int main(int argc, char *argv[]) {
	return 0;
}
