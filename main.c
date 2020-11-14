#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "othello.h"

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
