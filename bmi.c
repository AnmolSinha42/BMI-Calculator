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
#include <math.h>


int userinput(int initial, char* text,char* unit);
float calculate(int weight, int height);
int *range(int weight, int height, int wrange, int hrange);
void find_ideal(int weight, int height, int bmi);

int main(void)
{
    //input data
    int weight = userinput(1000,"weight","kg");
    int height = userinput(1000,"height","cm");
    printf("\n");

    //range (arbitary)
    const int wrange = 2;
    const int hrange = 5;

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
    printf("BMI: %.2f\n",((int)(bmi*10))/10.0); // 2f for 2 decimal places
    printf("Range: %i-%i\n",llimit, rlimit);
    printf("\n");

    int index;
    int values[10] = {0,16,17,18,25,30,35,40,1000};
    for (int i=0; i<9; i++){
        if (bmi<=values[i]){
            index = i;
            break;
        }
    }
    //iterate all possiblities
    printf("Chart:\n");
    if (index <= 2){
        printf("Severe Thinness : <16\n");
    }
    if (index <= 3){
        printf("Moderate Thinness : 16-17\n");
    }
    if ((index > 1)&&(index < 5)){
        printf("Mild Thinness : 17-18\n");
    }
    if ((index > 2)&&(index < 6)){
        printf("Normal : 18-25\n");
    }
    if ((index > 3)&&(index < 7)){
        printf("Overweight : 25-30\n");
    }
    if ((index > 4)&&(index < 8)){
        printf("Obese Class I : 30-35\n");
    }
    if ((index > 5)&&(index < 9)){
        printf("Obese Class II : 35-40\n");
    }
    if ((index > 6)&&(index < 10)){
        printf("Obese Class III : >40\n");
    }
    printf("\n");

    //improve (BMI - 22)
    //let height be normal find weight and vice versa

    const int ideal = 22;
    if ((int)(bmi+0.5) == ideal){
        printf("You have a perfect BMI! Keep it up!");
    }
    else{
        find_ideal(weight, height, ideal);
    }

    printf("\n");

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

void find_ideal(int weight, int height, int bmi){
    float wimprove;
    wimprove = weight - (bmi*((float)(height*height)/10000));
    printf("Need to ");
    if (wimprove>0){
        printf("Lose");
    }
    else{
        printf("Gain");
        wimprove = wimprove*(-1);
    }
    printf(" %.2f kg\n",((int)(wimprove*10))/10.0);

}



