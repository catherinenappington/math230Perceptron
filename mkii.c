#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perceptron.h"

int main(int argc, char *argv[])
{
    int i, j, network, max_iterations;
    double learning_rate, threshold;
    char * tempStr = malloc(sizeof(char) * 20);
    perceptron percy;
    perceptron * tempPerc = malloc(sizeof(perceptron));
    FILE * perceptronInput = fopen(argv[1],"r");
    training_set * ptr = malloc(sizeof(training_set));
    ptr = percy.head;
    learning_rate = atoi(argv[2]) / 1000;
    threshold = atoi(argv[3]) / 100;
    max_iterations = atoi(argv[4]) * 1000;
    initialize_weights(tempPerc);

    if(perceptronInput == NULL)
    {
        printf("An error has occurred. Unable to accept the input from the file.\n");
        return -1;
    }
    for(i = 0;fgets (tempStr, 20, perceptronInput)!= NULL; i++)
    {
        add(ptr, tempStr, tempPerc);
        ptr = ptr->next;
    }
    fclose(perceptronInput);
    percy.error_count = 1;
    ptr = percy.head;
    for(i = 0;percy.error_count != 0 || i < max_iterations; i++)
    {
        printf(" Iteration:  %d  ************************************************************\n", i);
        percy.error_count = 0;
        for(j = 0; j < percy.num_training_set; j++)
        {
            network = dot_product(*ptr, percy) > threshold ? 1 : 0;
            percy.error = ptr->desired_output - network;
            if(percy.error != 0)
                percy.error_count++;
            updateWeights(*ptr, tempPerc, learning_rate);
            showAll(tempPerc, learning_rate);
        }
    }
    free(tempStr);
    free(ptr);
    free(tempPerc);
    printf("STOP************\nLearning Rate: %f\n", learning_rate);
    return 0;
}
