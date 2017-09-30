/****************************************************************************
*****************************************************************************
       Name:  Xiaozhu Jin
 Assignment:  5
     Course:  CSC 319 Parallel Computing
 Instructor:  Ken Gamradt
*****************************************************************************
Description: The program performs the following operations:
             1.  Read Basic data from user
             2.  Calculate the heights of all mid positions
             3.  Using openMP way to integrately calculate the PI value
             4.  Calculate the time used for the computation
             5.  Display the result to the monitor
*****************************************************************************
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

/*user-defined constants*/
#define PI 3.1415926535897932384626433

/*function prototype*/
void introduction(void);
void getData(int , char *[], double *, double *, long int * , int *);
double calcPI(long int , double , double , int );
double calcHeight(double );
void display(long int, double, double , double );

/*main function*/
int main(int argc, char *argv[])
{
    int thread_count = 0;
    long int partition = 0;
    double start_x = 0.0, end_x =0.0, est_pi = 0.0, start_ti = 0.0, end_ti = 0.0;

    system("clear");

    getData(argc, argv, &start_x, &end_x, &partition, &thread_count);
    start_ti = omp_get_wtime();
    est_pi = calcPI(partition, start_x, end_x, thread_count);
    end_ti = omp_get_wtime();
    display(partition, est_pi, start_ti, end_ti);

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
    printf("2.  Calculate the heights of all mid positions\n");
    printf("3.  Calculate the PI value by using integration\n");
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
void getData(int argc, char *argv[], double *startX, double *endX, long int *numP, int *thread_count)
{
    if(argc == 5)
    {
        *startX = atof(argv[1]);
        *endX = atof(argv[2]);
        *numP = atol(argv[3]);
        *thread_count = atoi(argv[4]);
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
        printf("Please thread_count: ");
        scanf("%d", &(*thread_count));
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
double calcPI(long int numP, double start_x, double end_x, int thread_count)
{
    int my_rank = 0;
    double height = 0.0, width = 0.0, mid = 0.0, area = 0.0, sumpi = 0.0;
    long int count = 0;
	int threadLoad = 0;

    #pragma omp parallel num_threads(thread_count) reduction(+: height)\
    default(none) private(mid, count, my_rank) shared(width, numP, start_x, end_x, thread_count, threadLoad)
    {
        if( numP%thread_count == 0)
        {
            threadLoad = numP/thread_count;
        }
        else
        {
            threadLoad = numP/thread_count + 1;
        }

        my_rank = omp_get_thread_num();
        width = (end_x - start_x) / numP;
        mid = (start_x + my_rank * threadLoad * width) + (width / 2);

        #pragma omp for
        for(count = 0; count < numP; count++)
        {
            height += calcHeight(mid);
            mid += width;

		printf("Thread %d, mid %f, area %f\n", my_rank, mid, height * width);
        }
    }

    area = width * height;
    sumpi = 4 * area;

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

    height = 1 / (1 + (mid * mid));

    return height;
}

/****************************************************************************
*****************************************************************************
   Function: display
*****************************************************************************
Description: Display the results to the screen.
*****************************************************************************
****************************************************************************/
void display(long int numP, double sumpi, double s_ti, double e_ti)
{
    printf("\nNumber of partition: %40ld\n", numP);
    printf("Excepted PI value is: %56.16f\n", PI);
    printf("Calculated PI value is: %54.16f\n", sumpi);
    printf("The difference between two values: %43.16f\n", PI - sumpi);
    printf("Time used to calculate PI value: %45.16f\n", e_ti - s_ti);

    return ;
}
