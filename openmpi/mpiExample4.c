#include <stdio.h>
#include "mpi.h"
#define NUM_THREADS 4
int main(int argc,char *argv[]){
	int i, sum = 0, sumTotal = 0, upToVal;
	int start, end, size, rank;
	unsigned long prod = 0;

	upToVal = 40;

	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	start = rank*(upToVal/size) + 1;
    	if(rank==(size-1)){
    		end = upToVal;
    	}else{
    		end = start + (upToVal/size)-1;
    	}
    	
    	for(i=start; i<= end; i++){
    		sum = sum +i;
    	}
    	
	MPI_Reduce(&sum, &sumTotal, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	MPI_Reduce(&sum, &prod, 1, MPI_LONG, MPI_PROD, size-1, MPI_COMM_WORLD);

    	printf("\nRank: %d, sum: %d, sumTotal: %d, partial product: %ld, start: %d, end: %d\n", rank, sum, sumTotal, prod, start, end);
	
	MPI_Finalize();
	
	return 0;
}
