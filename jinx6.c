/****************************************************************************
*****************************************************************************
       Name:  Xiaozhu Jin
 Assignment:  5
     Course:  CSC 319 Parallel Computing
 Instructor:  Ken Gamradt
*****************************************************************************
Description: The program performs the following operations:
             1.  Read Basic data from user
             2.  Using MPI way to calculate pi value by using Monte Carlo
                 algorithm
             3.  Calculate the time used for the computation
             4.  Display the result to the monitor
*****************************************************************************
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

/*user-defined constants*/
#define PI 3.1415926535897932384626433

/*function prototype*/
void introduction(void);
void getData(int , char *[], long int *);
double calcPI(long int , int );
void display(long int , long int , double , double , double );

/*main function*/
int main(int argc, char *argv[])
{
    int comm_size = 0, my_rank = 0, time = 0, count = 0;
    double est_pi = 0.0, start_ti = 0.0, end_ti = 0.0;
    long int sample = 0, local_sample = 0, local_hit = 0, total_hit = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    if(my_rank == 0)
    {
        introduction();
        getData(argc, argv, &sample);
        start_ti = MPI_Wtime();

        for(time = 1; time < comm_size; time++)
        {
            MPI_Send(&sample, 1, MPI_LONG, time, 0, MPI_COMM_WORLD);
        }

    }
    else
    {
        MPI_Recv(&sample, 1, MPI_LONG, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    local_sample = sample / comm_size;
    local_hit = calcPI(local_sample, my_rank);

    if(my_rank != 0)
    {
        MPI_Send(&local_hit, 1, MPI_LONG, 0, 1, MPI_COMM_WORLD);
    }
    else
    {
        printf("Precess %d hit count: %ld\n", my_rank, local_hit);
        total_hit = local_hit;
        for(count = 1; count < comm_size; count++)
        {
            MPI_Recv(&local_hit, 1, MPI_LONG, count, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Process %d hit count: %ld\n", count , local_hit);
            total_hit += local_hit;
        }
    }

    end_ti = MPI_Wtime();

    est_pi = calcPI(total_hit, sample);

    display(sample, local_sample, est_pi, start_ti, end_ti);

    MPI_Finalize();

    return 0;
}

/****************************************************************************
*****************************************************************************
   Function: introduction
*****************************************************************************
Description: Used to display a detailed description of the program on
             the screen for the user.
*****************************************************************************
****************************************************************************/
void introduction(void)
{
    printf("The program performs the following operations:\n");
    printf("1.  Read Basic data from user\n");
    printf("2.  Using MPI way to calculate pi value by using Monte Carlo\n");
    printf("    algorithm\n");
    printf("3.  Calculate the time used for the computation\n");
    printf("4.  Display the result to the monitor\n");

    return ;
}

/****************************************************************************
*****************************************************************************
   Function: getData
*****************************************************************************
Description: Used to obtain the number of sample to calculate
             PI value
*****************************************************************************
****************************************************************************/
void getData(int argc, char *argv[], long int *sample)
{
    if(argc == 1)
    {
        *sample = atol(argv[1]);

    }
    else
    {
        printf("Please enter the number of sample: ");
        scanf("%ld", &(*sample));
    }

    return ;
}

/****************************************************************************
*****************************************************************************
   Function: calcPI
*****************************************************************************
Description: Used to calculate PI value by using Monte Carlo method
*****************************************************************************
****************************************************************************/
double calcPI(long int sample, int my_rank)
{
    int time = 0,count = 0, nsample = 0;
    double x = 0.0, y = 0.0, z = 0.0;
    unsigned int myseed = (unsigned int) my_rank;

    for(time = 1; time <= nsample; time++)
    {
        x = ((double)rand_r(&myseed)/(double)RAND_MAX);
        y = ((double)rand_r(&myseed)/(double)RAND_MAX);
        z = x * x + y * y;

        if(z <= 1)
        {
            count++;
        }
    }

    return count;
}

/****************************************************************************
*****************************************************************************
   Function: display
*****************************************************************************
Description: Display the results to the screen.
*****************************************************************************
****************************************************************************/
void display(long int sample, long int local_sample, double sumpi, double s_ti, double e_ti)
{
    printf("\nNumber of sample: %40ld\n", sample);
    printf("\nCount during process: %40ld\n", local_sample);
    printf("Excepted PI value is: %56.16f\n", PI);
    printf("Calculated PI value is: %54.16f\n", sumpi);
    printf("The difference between two values: %43.16f\n", PI - sumpi);
    printf("Time used to calculate PI value: %45.16f\n", e_ti - s_ti);

    return ;
}
