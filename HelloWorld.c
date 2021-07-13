#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main (int argc, char* argv[])
{
    int rank, size, i, result=0, sum=0;
    double pi=0.0, inicio=0.0, fim=0.0, x, y;
    
    MPI_Init (&argc, &argv);
    
    //id do processo
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    
    //numero do proceso
    MPI_Comm_size (MPI_COMM_WORLD, &size);
    
    //sincronizando os processos
    MPI_Barrier(MPI_COMM_WORLD);
    printf("---- \n");
    printf("size> %d \n",size);
    printf("rank> %d \n",rank);
    printf("---- \n");
    
    
    
    //sincronizar os processos
    MPI_Barrier(MPI_COMM_WORLD);

    
    
    MPI_Finalize();
    
    return 0;
}