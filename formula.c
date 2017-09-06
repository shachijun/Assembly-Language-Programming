
#include "formula.h"

int timeval_subtract(struct timeval start, struct timeval end){
    return (end.tv_sec - start.tv_sec)*1000000 + (end.tv_usec - start.tv_usec);
}
int main(int argc, char **argv)
{
    int n, r;
    char *pN;
	if(argc!=2){
	printf("Invilide Inpute");
	return 0;
	}
	if ( strcmp(argv[1], "-h") == 0){
        fprintf(stderr, "Usage: formula <positive integer>\n");
        return 0;
    }

    pN = argv[1];
    while (*pN != '\0'){
        if (*pN > '9' || *pN < '0'){
            fprintf(stderr, "input should be integer\n");
            return 0;
        }
        pN++;
    }

    n = atoi(argv[1]);

    if (n >= 13){
        fprintf(stderr, "The input should be less than 13\n");
        return 0;
    }
    
    struct timeval start,end;

    gettimeofday(&start, NULL);
    printf("(1+x)^%d = 1 ", n);
    for (r = 1; r <= n; ++r){
        printf("+ %d*x^%d ", nCr(n, r), r);
    }

    printf("\n");

    gettimeofday(&end, NULL);

    printf("Time Required = %d microsecond\n", timeval_subtract(start, end));

    return 0;

}
