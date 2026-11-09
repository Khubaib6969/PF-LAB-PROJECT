#include<stdio.h>
#include<math.h>





int DisplayMenu(){
    printf("\n===== Calculator =====\n");
    printf("1.Basic Arthemetic\n");
    printf("2.Matrix Calculation\n");
    printf("3.Differentiation\n");
    printf("4.Integration\n");
    printf("5.Exit\n");
    int choice;
    printf("Enter choice (1-5): ");
    scanf("%d",&choice);
    while(choice < 1 || choice > 5){
        printf("Choice must be between 1 and 5 inclusive ! Enter again: ");
        scanf("%d",&choice);
    }
    return choice;
}

double BasicArthemetic(){
    int option;
    double a,b,toReturn;
    printf("\n===== Basic Arthemetic =====\n");
    printf("1.Addition (a + b)\n");
    printf("2.Subtraction (a - b)\n");
    printf("3.Multiplication (a * b)\n");
    printf("4.Division (a / b)\n");
    printf("5.Exponent (a ^ b)\n");
    printf("Enter option (1 - 5): ");
    scanf("%d",&option);
    
    while(option < 1 || option > 5){
        printf("Option must be between 1 and 5 inclusive ! Enter again: ");
        scanf("%d",&option);
    }

    printf("\nEnter a: ");
    scanf("%lf",&a);
    printf("Enter b: ");
    scanf("%lf",&b);
    
    switch(option){
        case 1://Addition
        toReturn = a + b;
        break;
        case 2://Subtraction
        toReturn = a - b;
        break;
        case 3://Multiplication
        toReturn = a * b;
        break;
        case 4://Division
        toReturn = a / b;
        break;
        case 5://Exponent
        while(b < 0){
            printf("b must be greator than or equal to zero for exponential calculation ! Enter b again: ");
            scanf("%d",&b);
        }
        toReturn = pow(a,b);
        break;
    }
    return toReturn;
}




int main(){
    int option;
    int a, b, Arthemetic;

    option = DisplayMenu();
    while(option != 5){
        switch(option){
            case 1:

            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
        }
    }

    printf("\n%d",exponent(5,2));
}