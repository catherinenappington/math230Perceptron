#ifndef PERCEPTRON_FUNCTIONS_H_INCLUDED
#define PERCEPTRON_FUNCTIONS_H_INCLUDED

double dot_product(int sensor_values[], double initial_weights[])
{
    return (sensor_values[0] * initial_weights[0] + sensor_values[1]
            * initial_weights[1] + sensor_values[2] * initial_weights[2]);
}

void update_weights(double * weights, double correction, int sensor_values[], int err_cnt)
{
    int k;
    for(k = 0; k < 3; k++)
    {
        *(weights + k) += correction * sensor_values[k];
    }
    printf("%.1f %.1f %.1f\t iterationError = %.5f\n", weights[0], weights[1], weights[2], (err_cnt / 4.0));
}

#endif // PERCEPTRON_FUNCTIONS_H_INCLUDED
