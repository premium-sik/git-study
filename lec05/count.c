#include <stdio.h>

//Count number of 1 (binary)
int count_one(int in_a)
{
        int i, count = 0;
        for(i = 31; i>=0; i--)
        {
                if((in_a>>i) & 1)
                        count++;
        }
        return count;
}


int main()
{
	int i;
	unsigned int in_a;
	fscanf(stdin, "%u", &in_a);
	fprintf(stdout, "%u \t: ", in_a);
	for(i=31; i>=0; i--)
	{
		fprintf(stdout, "%d", ((in_a>>i) & 1));
		if(i % 4==0)
		{
			fprintf(stdout, " ");
		}
	}
	fprintf(stdout,": %d \n", count_one(in_a));
}
