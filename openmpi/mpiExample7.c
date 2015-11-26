#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]){
    int i,rank,size;
    int root,count;
    int buffer[5];
    long sum = 0;
    MPI_Status status;
    MPI_Request request;

    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    root=0;
    count=5;
    if(rank== root){
      for(i=0;i<count;i++){
        buffer[i]=i;
      }
    }

   //MPI_Allreduce(&buffer, &sum, count, MPI_LONG, MPI_SUM, MPI_COMM_WORLD);	
   MPI_Bcast(buffer, count, MPI_INT, root, MPI_COMM_WORLD);    

    printf("Rank is: %d, Value at buffer[%d] is: %d\n ",rank, count-1, buffer[count-1]);

    printf("\n");
    MPI_Finalize();
    return 0;
}
