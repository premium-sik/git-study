#include <stdio.h>
#define VALUE_ONE 1
// Count numbr of 1 (binary)

int count_one(unsigned int in_a)
{
	int count=0;
	int static numCalls = 0;
	while (in_a != 0 )
        {
		count += in_a & VALUE_ONE;
		in_a >>=VALUE_ONE;
	}

	fprintf(stderr, "Call: %d\n", numCalls);
	numCalls++;
	return count;
}

int main()
{
        int i;
 	int in_a;

        fscanf(stdin, "%u", &in_a);
	fprintf(stdout, "%u \t : ", in_a);
        for (i = 31; i >= 0; i--)
        {
                fprintf(stdout,"%d", ((in_a>>i) & 1));
                if (i % 4 == 0)
                        fprintf(stdout, " ");
        }
        fprintf(stdout," %d\n", count_one(in_a));
	fprintf(stdout, "%d\n", in_a);
}

