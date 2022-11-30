#include <stdio.h>
//hi
int main()
{
	
	signed int siA;	
	unsigned int unA;
	signed int sumS;
	unsigned int sumU;
	fscanf(stdin, "%d", &siA);
	fprintf(stdout, "Signed Inteager : %d\n", siA);
	unA = siA;
	fprintf(stdout, "Unsigned Inteager : %u\n", unA);
	fprintf(stdout, "Unsigned Inteager percent d : %d\n", unA);
	fprintf(stdout, "Unsigned Inteager percent d : %u\n", siA);
	
	/*
	 * Signed Inteager : -1
	 * Unsigned Inteager : 4294967295
	 * Unsigned Inteager percent d: -1
	 * signed Inteager percent u : 4294967295
	 * */

	fprintf(stdout, "UnSigned Inteager : %u\n", unA);
	siA = unA;
	fprintf(stdout, "signed Inteager : %d\n", siA);

	sumS = siA + unA;
        sumU = siA + unA;
	fprintf(stdout, "sumS %%d %d\n", sumS);	
	fprintf(stdout, "sumS %%u %u\n", sumS);	
	fprintf(stdout, "sumS %%d %d\n", sumU);	
	fprintf(stdout, "sumS %%u %u\n", sumU);	
	return siA;
}

