#include <stdio.h>
#include <stdlib.h>

#define threshold 0.5
#define learning_rate 0.1

double dot_product(int[], double[]);
void update_weights(double*, double, int[]);

int main()
{
    int i, j, error, error_count = 1;
    double weights[] = {0, 0, 0};
    int training_set[4][3] = { {1, 0, 0},
                          {1, 0, 1},
                          {1, 1, 0},
                          {1, 1, 1} };
    int desired_output[] = {1, 1, 1, 0};

    for(i = 0; error_count != 0; i++)
    {
        printf(" Iteration:  %d  ************************************************************\n", i);
        error_count = 0;
        for(j = 0; j < 4; j++)
        {
            error = desired_output[j] - (dot_product(training_set[j], weights) > threshold ? 1 : 0);

            if(error != 0)
                error_count++;

            update_weights(weights, (learning_rate * error), training_set[j]);
            printf("%.1f %.1f %.1f\t Correction = %.5f\n", weights[0], weights[1], weights[2], (error * learning_rate));
        }
    }
    return 0;
}

double dot_product(int sensor_values[], double initial_weights[])
{
    return (sensor_values[0] * initial_weights[0] + sensor_values[1]
            * initial_weights[1] + sensor_values[2] * initial_weights[2]);
}

void update_weights(double * weights, double correction, int sensor_values[])
{
    int k;
    for(k = 0; k < 3; k++)
    {
        *(weights + k) += correction * sensor_values[k];
    }
}
