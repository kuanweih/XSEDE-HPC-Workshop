#include <stdio.h>
#include "mpi.h"

int main(int argc, char** argv){

    int my_PE_num, numbertoreceive, numbertosend=100;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_PE_num);

    if (my_PE_num==7){
        MPI_Send( &numbertosend, 1, MPI_INT, 0, 10, MPI_COMM_WORLD );
    } // if 
    else{ 
        MPI_Send( &numbertosend, 1, MPI_INT, my_PE_num+1, 10, MPI_COMM_WORLD );
    } // else
  
    MPI_Recv( &numbertoreceive, 1, MPI_INT, MPI_ANY_SOURCE, 10, MPI_COMM_WORLD, &status );
    printf("PE %d received %d.\n", my_PE_num, numbertoreceive);

  MPI_Finalize();

} // main
