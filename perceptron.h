#ifndef PERCEPTRON_H_INCLUDED
#define PERCEPTRON_H_INCLUDED

typedef struct
{
   int sensor_values[16];
   int desired_output;
   struct training_set * next;
} training_set;

typedef struct
{
    training_set * head;
    unsigned int num_training_set;
    double weights[16];
    int error;
    int error_count;

} perceptron;

void add(training_set * next_set, char * str_vals, perceptron * perc)
{
    int i;
    next_set = malloc(sizeof(training_set));

    for(i = 0; i < 16; i++)
        next_set->sensor_values[i] = atoi(str_vals[i]);
    next_set->desired_output = atoi(str_vals[18]);
    perc->num_training_set++;
}

void initialize_weights(perceptron * wts)
{
    int i;
    for(i = 0; i < 16; i++)
    {
        wts->weights[i] = 0; //change to random later
    }
}

void showAll(perceptron * perc, double lRate)
{
    int i;
    for(i = 0; i < 16; i++)
        printf("wt[%d]: %f\n", i, perc->weights[i]);
    printf("Iteration Error: %f\n", perc->error * lRate);
}

double dot_product(training_set current_set, perceptron perc)
{
    int i;
    double sum;
    for(i = 0; i < 16; i++)
    {
        sum += current_set.sensor_values[i] * perc.weights[i];
    }
    return sum;
}

void updateWeights(training_set current_set, perceptron * perc, double lRate)
{
    int i;
    for(i = 0; i < 16; i++)
        perc->weights[i] += lRate * perc->error * current_set.sensor_values[i];
}
#endif // PERCEPTRON_H_INCLUDED
