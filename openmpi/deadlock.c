#include <stdio.h>
#include "mpi.h"
#include <ctype.h>

int main(int argc,char *argv[]){
        int size, rank, dest, source, count, tag=1;
        char inmsg, outmsg='s';
        MPI_Status Stat;

        MPI_Init(&argc,&argv);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        if (rank == 0) {
          dest = 1;
          source = 1;
	  printf("Before reception rank 0 \n");
	  fflush(stdout);
          MPI_Recv(&inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &Stat);
          MPI_Send(&outmsg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
          printf("init out msg: %c \n", outmsg);
        }else if (rank == 1) {
          dest = 0;
          source = 0;
          printf("Before reception rank 1 \n");
	  fflush(stdout);
          MPI_Recv(&inmsg, 1, MPI_CHAR, source, tag, MPI_COMM_WORLD, &Stat);
          outmsg = toupper(inmsg);
          MPI_Send(&outmsg, 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
          printf("final out msg: %c \n", outmsg);
         }

        MPI_Finalize();
}
