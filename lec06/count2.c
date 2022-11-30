#include <stdio.h>
// Count numbr of 1 (binary)
int count_one(int in_a)
{
	int i=32, count=0;
	int const value_one = 1;
	int static numCalls = 0;
        while (i > 0 )
        {
		count += in_a & value_one;
		in_a >>=value_one;
	        i--;	
		// c = a >> 1 + b
		// c = (a >> 1) + b
		// c = a >> (1 + b)
	}

	fprintf(stderr, "Call: %d\n", numCalls);
	numCalls++;
	return count;
}

int main()
{
        int i;
	unsigned int in_a;

        fscanf(stdin, "%u", &in_a);
	fprintf(stdout, "%u \t : ", in_a);
        for (i = 31; i >= 0; i--)
        {
                fprintf(stdout,"%d", ((in_a>>i) & 1));
                if (i % 4 == 0)
                        fprintf(stdout, " ");
        }
	count_one(in_a);
	count_one(in_a);
	count_one(in_a);
	count_one(in_a);
        fprintf(stdout," %d\n", count_one(in_a));
}

