#include <stdio.h>
#include <stdlib.h>
#include "perceptron_functions.h"
#define threshold 0.5
#define learning_rate 0.1

int main()
{
    double weights[3] = {0, 0, 0};
    int i, j, error, error_count = 1;
    int training_set[4][3] = { {1, 0, 0}, {1, 0, 1}, {1, 1, 0}, {1, 1, 1} };
    int desired_output[] = {1, 1, 1, 0};
    for(i = 0; error_count != 0; i++)
    {
        printf(" Iteration:  %d  ************************************************************\n", i);
        error_count = 0;
        for(j = 0; j < 4; j++)
        {
            error = desired_output[j] - (dot_product(training_set[j], weights) > threshold ? 1 : 0);
            error != 1? : error_count++;
            update_weights(weights, (learning_rate * error), training_set[j], error_count);
        }
    }
    return 0;
}
