#include <stdio.h>
#include <stdlib.h>

double dot_product(int x[], double y[]);

int main()
{
    int i, j, k, network, error;
    double threshold = 0.5, learning_rate = 0.1, sum;
    double weights[] = {0, 0, 0};
    int training_set[4][3] = { {1, 0, 0},
                          {1, 0, 1},
                          {1, 1, 0},
                          {1, 1, 1}
                          };
    int desired_output[] = {1, 1, 1, 0};
    int error_count = 1;

    for(i = 0;error_count != 0; i++)
    {
        error_count = 0;
        printf("Iteration %d ***************\n", i);
        printf("%.1f %.1f %.1f\n", weights[0], weights[1], weights[2]);
        for(j = 0; j < 4; j++)
        {
            sum = dot_product(training_set[j], weights);

            if(sum > threshold)
                network = 1;
            else
                network = 0;

            error = desired_output[j] - network;

            if(error != 0)
                error_count++;

            for(k = 0; k < 3; k++)
            {
                weights[k] += learning_rate * error * training_set[j][k];
            }
        }

    }
    return 0;
}

double dot_product(int sensor_values[], double initial_weights[])
{
    return (sensor_values[0] * initial_weights[0] + sensor_values[1]
            * initial_weights[1] + sensor_values[2] * initial_weights[2]);
}
