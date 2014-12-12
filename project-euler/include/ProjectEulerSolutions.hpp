#ifndef _PROJECT_EULER_SOLUTIONS_
#define _PROJECT_EULER_SOLUTIONS_

/*--------------------- CONSTANTS --------------------*/

#define MAXIMUM_NUMBER_SOLUTIONS 100 // actual number of problems + 2; using problem numbers as
                                     //  the array index and ignoring the 0th entry 


/*--------------------- FUNCTION PROTOTYPES --------------------*/
void SolveProblem001(void);
void SolveProblem009(void);
void SolveProblem011(void);


/*--------------------- FUNCTION POINTER TABLE --------------------*/

void (*solutions[MAXIMUM_NUMBER_SOLUTIONS])(void) = {
    NULL,               // SolveProblem000
    SolveProblem001,
    NULL,
    NULL,
    NULL,
    NULL,               // SolveProblem005
    NULL,
    NULL,
    NULL,
    SolveProblem009,
    NULL,               // SolveProblem010
    SolveProblem011,
    NULL
};


#endif // _PROJECT_EULER_SOLUTIONS_
