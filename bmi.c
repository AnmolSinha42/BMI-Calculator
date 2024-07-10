//OBJECTIVE : Calculate BMI and display status (overweight, normal, underweight)
//SOLVE problem in existing : provide in ranges to give rough value than exact (currently none does it)


/*STEPS:
1.input data
2.provide necessary range
3.calculate bmi
4.calulate with range
4.show status
5.what must improve (weight,height and by how much)
*/

#include <stdio.h>
#include <string.h>

int userinput(int initial, char* text,char* unit);
float calculate(int weight, int height, int wrange, int hrange);

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
    float bmi = calculate(weight, height, wrange, hrange);
    printf("bmi: %f\n",bmi);
    
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

float calculate(int weight, int height, int wrange, int hrange){
    //mid 
    float bmi = weight/((float)(height*height)/10000);
    bmi = (float)((int)(bmi*10))/10;
    return bmi;
}