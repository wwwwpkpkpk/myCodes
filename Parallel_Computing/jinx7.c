/****************************************************************************
*****************************************************************************
       Name:  Xiaozhu Jin
 Assignment:  7
     Course:  CSC 319 Parallel Computing
 Instructor:  Ken Gamradt
*****************************************************************************
Description: The program performs the following operations:
             1.  Read Basic data from user
             2.  Using MPI way to calculate integration in multi-
                 processors
             3.  Calculate the pi by using openMP method
             4.  Calculate the time used for the computation
             5.  Display the result to the monitor
*****************************************************************************
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <mpi.h>

/*user-defined constants*/
#define PI 3.1415926535897932384626433

/*function prototype*/
void introduction(void);
void getData(int , char *[], double *, double *, long int *);
double calcPI(long int , double , double );
double calcHeight(double );
void display(long int , double , double , double , double , double );

/*main function*/
int main(int argc, char *argv[])
{
    int my_rank = 0, comm_size = 0;
    double start_x = 0.0, end_x =0.0, local_pi = 0.0, est_pi = 0.0, start_ti = 0.0, end_ti = 0.0;
    double local_st = 0.0, local_ed = 0.0;
    long int sample = 0;
    double process_wid = 0.0;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    if(my_rank == 0)
    {
        introduction();
        getData(argc, argv, &start_x, &end_x, &sample);
        start_ti = MPI_Wtime();
    }

    MPI_Bcast(&start_x, 1, MPI_DOUBLE,0, MPI_COMM_WORLD);
    MPI_Bcast(&end_x, 1, MPI_DOUBLE,0, MPI_COMM_WORLD);
    MPI_Bcast(&sample, 1, MPI_LONG,0, MPI_COMM_WORLD);

    process_wid = (end_x - start_x) / comm_size;

    local_st = start_x + (my_rank * process_wid);
    local_ed = local_st + process_wid;

    local_pi = calcPI(sample, local_st, local_ed);

    MPI_Reduce(&local_pi, &est_pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(my_rank == 0)
    {
        end_ti = MPI_Wtime();
        display(sample, est_pi, start_ti, end_ti, start_ti, end_ti);
    }


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
    printf("1.  Read number of partition from user\n");
    printf("2.  Using MPI way to calculate integration in multi-");
    printf("    processors\n");
    printf("3.  Calculate the pi by using openMP method\n");
    printf("4.  Calculate the time used for the computation\n");
    printf("5.  Display the result to the monitor\n");
}

/****************************************************************************
*****************************************************************************
   Function: getData
*****************************************************************************
Description: Used to obtain the number of partition, start x value,
             end x value and number of threads to calculate
             integrated PI value
*****************************************************************************
****************************************************************************/
void getData(int argc, char *argv[], double *startX, double *endX, long int *numP)
{
    if(argc == 4)
    {
        *startX = atof(argv[1]);
        *endX = atof(argv[2]);
        *numP = atol(argv[3]);
    }
    else
    {
        printf("The starting X, ending X, number of partition and thread_count are unknown\n");
        printf("Please enter starting X: ");
        scanf("%lf", &(*startX));
        printf("Please enter ending X: ");
        scanf("%lf", &(*endX));
        printf("Please enter number of partition: ");
        scanf("%ld", &(*numP));
    }

    return ;
}

/****************************************************************************
*****************************************************************************
   Function: calcPI
*****************************************************************************
Description: Used to calculate integrated PI value by summing areas
             from mid value using onpenMP for loop
*****************************************************************************
****************************************************************************/
double calcPI(long int numP, double start_x, double end_x)
{
    double height = 0.0, width = 0.0, mid = 0.0, area = 0.0, sumpi = 0.0;
    long int count = 0;

    width = (end_x - start_x) / numP;

    #pragma omp parallel for reduction(+: height)\
    default(none) private(mid, count) shared(width, numP, start_x)
    for(count = 0; count < numP; count++)
    {
        mid = start_x + (width / 2.0) + count * width;
        height += calcHeight(mid);
    }

    area = width * height;
    sumpi = 4.0 * area;

    return sumpi;
}

/****************************************************************************
*****************************************************************************
   Function: calcHeight
*****************************************************************************
Description: Used to calculate height in the mid position
*****************************************************************************
****************************************************************************/
double calcHeight (double mid)
{
    double height = 0.0;

    height = 1.0 / (1.0 + (mid * mid));

    return height;
}

/****************************************************************************
*****************************************************************************
   Function: display
*****************************************************************************
Description: Display the results to the screen.
*****************************************************************************
****************************************************************************/
void display(long int numP, double sumpi, double s_ti, double e_ti, double startX, double endX)
{
    printf("\nStarting X: %66.16f\n", startX);
    printf("Ending X: %68.16f\n", endX);
    printf("Number of partition: %40ld\n", numP);
    printf("Excepted PI value is: %56.16f\n", PI);
    printf("Calculated PI value is: %54.16f\n", sumpi);
    printf("The difference between two values: %43.16f\n", PI - sumpi);
    printf("Time used to calculate PI value: %45.16f\n", e_ti - s_ti);

    return ;
}
