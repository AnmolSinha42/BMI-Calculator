//OBJECTIVE : Calculate BMI and display status (overweight, normal, underweight)
//SOLVE problem in existing : provide in ranges to give rough value than exact (currently none does it)


/*STEPS:
1.input data
2.provide necessary range
3.calculate bmi
4.calulate with range
5.show status
6.what must improve (weight,height and by how much)
*/

#include <stdio.h>
#include <stdlib.h>


int userinput(int initial, char* text,char* unit);
float calculate(int weight, int height);
int *range(int weight, int height, int wrange, int hrange);

int main(void)
{
    //input data
    int weight = userinput(1000,"weight","kg");
    int height = userinput(1000,"height","cm");
    printf("\n");

    //range (arbitary)
    const int wrange = 2;
    const int hrange = 2;

    //calculate
    float bmi = calculate(weight, height);
    int rlimit;
    int llimit;
    int *limits = range(weight, height, wrange, hrange);

    if (limits[0]>limits[1]){
        rlimit = limits[0];
    }
    else{
        rlimit = limits[1];
    }
    if (limits[2]<limits[3]){
        llimit = limits[2];
    }
    else{
        llimit = limits[3];
    }

    free(limits);

    //status
    printf("BMI: %f\n",bmi);
    printf("Range: %i-%i\n",llimit, rlimit);

    
}

int userinput(int initial, char* text,char* unit){
    int input = initial;
    while (input>=initial || input<=0){
        printf("%s (in %s): ", text, unit);
        scanf("%i",&input);
        if (input>=initial || input<=0){
            printf("Put in a valid %s (in %s and between 0 and %i).\n", text, unit, initial);
            printf("\n");
        }   
    }
    return input;
}

float calculate(int weight, int height){
    float bmi = weight/((float)(height*height)/10000);
    bmi = (float)((int)(bmi*10))/10;
    return bmi;    
}

int *range(int weight, int height, int wrange, int hrange){
    int *rbmi = malloc(4*sizeof(int));
    if (rbmi == NULL){
        printf("memory not allocated.");
    }
    // rbmi -- max weight, min height, min weight, max height
    //1st 2 items -- largest value, last 2 items -- smallest value
    //the array just makes the data understandable (nothing else)
    rbmi[0] = calculate(weight+wrange, height);
    rbmi[1] = calculate(weight, height-hrange);
    rbmi[2] = calculate(weight-wrange, height);
    rbmi[3] = calculate(weight, height+hrange);
    return rbmi;
}



