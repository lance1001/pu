#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void f(FILE **fp);

int main()
{
	int i;
	pid_t pid;
	char cmd[80];

	FILE *fp;

	printf("A\n");
	f(&fp);

	printf("=> [%x]\n", fp);
	fprintf(fp, "ALO\n\n\n\n\nALO\n\n\n\n\nFIM\n\n");
	fclose(fp);

	printf("Passou\n");

	char p[10][4];

	for(i=0; i<10; i++)
		strcpy(p[i], "123");
	for(i=0; i<10; i++)
		printf("=>[%s] [%d]\n", p[i], sizeof(p));

	pid = getppid();

	long *pFila;

	pFila = calloc(3, sizeof(long));
	pFila[0] = 10;
	pFila[1] = 20;

	printf("[%ld] [%ld]\n", pFila[0], pFila[1]);

	free(pFila);

	printf("pid=[%d]\n", pid);
	printf("[%*c]\n", 200, 'x');

	printf("[%s]\n", getenv("USER"));

	//getchar();

	//sprintf(cmd, "kill -9 %d", pid);
	//system(cmd);

	return 0;
}
void f(FILE **fp)
{
	FILE *fp1;


	printf("=> [%x] [%x]\n", fp, fp1);
	if((fp1=fopen("teste2.txt", "w")))
	{
		*fp = fp1;
		printf("OK [%x] [%x]\n", fp, fp1);
	}
	else
		printf("ERRO\n");
}
