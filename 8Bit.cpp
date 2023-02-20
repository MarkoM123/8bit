#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void func(float Unormal, float U) 
{
	int binary[8], i = 0, n = 0, j = 7;
	float x, dg = 0, del = 1;
    if (U>=0)
		binary[i] = 0;
	else
		binary[i] = 1; //Parity check 
	if (Unormal >= 0 && Unormal <= 0.0078125) 
	{
		binary[++i] = 0;
		binary[++i] = 0;
		binary[++i] = 0;
		dg = 0;
		del = 0.00048828125;
	}
	else if (Unormal > 0.0078125 && Unormal <= 0.015625) 
	{
		binary[++i] = 0;
		binary[++i] = 0;
		binary[++i] = 1;
		dg = 0.0078125;
		del = 0.00048828125;
	}
	else if (Unormal > 0.015625 && Unormal <= 0.03125) 
	{
		binary[++i] = 0;
		binary[++i] = 1;
		binary[++i] = 0;
		dg = 0.015625;
		del = 0.0009765625;
	}
	else if (Unormal > 0.03125 && Unormal <= 0.0625) 
	{
		binary[++i] = 0;
		binary[++i] = 1;
		binary[++i] = 1;
		dg = 0.03125;
		del = 0.001953125;
	}
	else if (Unormal > 0.0625 && Unormal <= 0.125)
	{
		binary[++i] = 1;
		binary[++i] = 0;
		binary[++i] = 0;
		dg = 0.0625;
		del= 0.00390625;
	}
	else if (Unormal > 0.125 && Unormal <= 0.25)
	{
		binary[++i] = 1;
		binary[++i] = 0;
		binary[++i] = 1;
		dg = 0.0125;
		del = 0.0078125;
	}
	else if (Unormal > 0.25 && Unormal <= 0.5) 
	{
		binary[++i] = 1;
		binary[++i] = 1;
		binary[++i] = 0;
		dg = 0.25;
		del = 0.015625;
	}
	else if (Unormal > 0.5 && Unormal <= 1) 
	{
		binary[++i] = 1;
		binary[++i] = 1;
		binary[++i] = 1;
		dg = 0.5;
		del = 0.3125;
	} 
	x = abs((Unormal - dg) / del); 
	n = (int)x; 
	if (n > 15)
	{
	
		for (int l = i + 1; l <= 7; l++)
			binary[l] = 1; 
	}
	else 
	{
		while (n > 0)
		{
			binary[j] = n % 2;
			n = n / 2;
			j--;
		} 
		if (j > 3)
		{
			for (int k = j; k > 3; k--)
				binary[k] = 0;
		}
	} 
	printf("Vrednost 8-bitne kodne reci je: ");
	for (int l = 0; l <= 7; l++)
		printf("%d", binary[l]);
	printf("\n");
}

int main() {
	float U, Umx, Umax, Unor;
	
		printf("Unesite maksimalnu vrednost napona odsecka:\n");
		scanf("%f", &Umax);
		Umax = abs(Umax); 
		printf("Unesite zeljenu vrednost napona:\n");
		scanf("%f", &U);
		if (abs(U) > Umax)
		{
			printf("Apsolutna vrednost mora biti manja od Umax!!");
		}
		Unor = abs(U) / Umax; 
		func(Unor, U);	
	}
