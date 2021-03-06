#ifndef HEAT_DISTRIBUTION_H
#define HEAT_DISTRIBUTION_H

/* Information that is passed into pthread_create(). 
   Since multiple arguments are passed, a structure is created that contains
   all of the arguments, and then passed a pointer to that structure cast to
   (void *) */
   
struct thread_data
{
    short thread_id;                    /* Stores thread_id */
    short t_thread;                     /* Contains left neighboring thread */
    short b_thread;                     /* Contains right neighboring thread */
    int ceiling;                        /* Contains the top-most row */
    int flr;                            /* Contains the bottom-most row */
    
    /* Variables to check for correctness */
    int columns;                        /* Number of columns in matrix. */
    int rows;                           /* Number of rows in matrix. */
    double max_difference;              /* Max difference after updating the
                                           thread bounds */
};

void update_cell (struct thread_data);
void * update_matrix (void *);

int thread_get_columns (struct thread_data);
void output_matrix (double **, int, int);

#endif /* heat_distribution.h */