#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define N 10E8

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
    
    //pegando o tempo de inicio
    inicio = MPI_Wtime();
    
    srand((int)time(0));
    
    //calculando cada parte da somatoria    
    for (i=rank; i<N; i+=size)
    {
        x=rand()/(RAND_MAX+1.0);
        y=rand()/(RAND_MAX+1.0);
        if(x*x+y*y<1.0)
            result++;
    }
    
    //somando os resultados
    MPI_Reduce(&result, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    
    //sincronizar os processos
    MPI_Barrier(MPI_COMM_WORLD);

    //pegar o tempo fim
    fim = MPI_Wtime();
    
    //Caculate and print PI
    if (rank==0)
    {
        pi=4.*(result*size)/N;
        printf("np=%2d\n", size);
        printf("Time=%fs\n", fim-inicio);        
        printf("PI=%0.4f\n", pi);                
    }
    
    MPI_Finalize();
    
    return 0;
}