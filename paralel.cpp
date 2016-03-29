#include <iostream>
#include <stdio.h>  
#include <stdlib.h>
#include <time.h>

using namespace std;

#define MAX 3000

double A[MAX][MAX], x[MAX], y[MAX];

/*double **A;
double *x;
double *y;*/

int main(int argc, char const *argv[])
{
	/*A=new double*[MAX];
	for (int i = 0; i < MAX; ++i)
		A[i]=new double[MAX];
	x=new double[MAX];
	y=new double[MAX];*/


	clock_t t_ini1, t_fin1;
  	clock_t t_ini2, t_fin2;


	srand (time(NULL));
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
			A[i][j]=rand()%10;

		x[i]=rand()%10;
		//y[i]=0;
	}





	for (int i = 0; i < MAX; ++i)
		y[i]=0;
	double secs1=0;
	t_ini1 = clock();
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
			y[i] += A[i][j]*x[j];
	}
	t_fin1= clock();
	secs1 = (double)(t_fin1 - t_ini1) / CLOCKS_PER_SEC;
	printf("%.16g milisegundos\n", secs1 * 1000.0); // fila a columna



	for (int i = 0; i < MAX; ++i)
		y[i]=0;
	double secs2=0;
	t_ini2 = clock();
	for (int j = 0; j < MAX; ++j)
	{
		for (int i = 0; i < MAX; ++i)
			y[i] += A[i][j]*x[j];
	}
	t_fin2 = clock();
	secs2 = (double)(t_fin2 - t_ini2) / CLOCKS_PER_SEC;
	printf("%.16g milisegundos\n", secs2 * 1000.0); // columna a fila



	/*for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
			cout<<A[i][j]<<"\t";
		cout<<endl;
	}*/


	return 0;
}