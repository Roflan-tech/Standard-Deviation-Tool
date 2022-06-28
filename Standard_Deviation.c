#include <stdio.h>
#include <math.h>

#define EXC EOF||\n

void input(size_t * sample, double * dataArray, int * number)
{
    size_t i = 0;
    int tmp;
    printf("Is the data a sample of larger data?(0 for not sample, 1 for sample)\n");
    scanf("%zu", sample);
    printf("Input data points:\n");
    while((scanf(" %lf", &dataArray[i])) != EOF)
        i++;
    *number = i;
}

void calculate(size_t *sample, double *dataArray, int *number)
{
    double mean = 0;
    double sum = 0;
    for (size_t i = 0; i < *number; i++)
    {
        mean += dataArray[i];
    }
    mean = mean / *number;
    printf("Mean: %lf\n", mean);
    for (size_t i = 0; i < *number; i++)
    {
        sum += (dataArray[i] - mean) * (dataArray[i] - mean);
    }
    if(*sample == 1)
        printf("Res: %lf\n", sqrt(sum / (*number - 1)));
    else
        printf("Res: %lf\n", sqrt(sum / *number));
    
}

int main()
{
    size_t sample = 0; // if 0 no sample, if 1 sample
    double dataArray[100];
    int number = 0;
    input(&sample, dataArray, &number);
    calculate(&sample, dataArray, &number);
}