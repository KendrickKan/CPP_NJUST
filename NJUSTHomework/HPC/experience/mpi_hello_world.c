#include <mpi.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	MPI_Init(NULL, NULL);
	int size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	char processorName[MPI_MAX_PROCESSOR_NAME];
	int nameLen;
	MPI_Get_processor_name(processorName, &nameLen);
	printf("Hello 919106840420阚东 from processor %s, rank %d, total %d processors\n",
		   processorName, rank, size);
	// Finalize the MPI environment. No more MPI calls can be made after this
	MPI_Finalize();
}
