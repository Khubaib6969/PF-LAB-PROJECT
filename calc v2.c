#include <stdio.h>
#include <math.h>
#include <stdlib.h>


double MatA[50][50] ;
double MatB[50][50];
double MatResult[50][50];
static int ActiveDegree = 1;
static double ActiveCoeffs[5] = {0};
typedef double (*MathFunc)(double);

//BASIC ARTHEMETIC
void BasicArthemeticDisplay();
double addition(double a, double b);
double subtraction(double a, double b);
double multiplication(double a, double b);
double division(double a, double b);
// xxxxxxx

//MATRIX
void MatrixDisplay();
void MatrixAddition(int row, int column);
void MatrixSubtraction(int row, int column);
void ScalarMultiplication(double x, int row, int column);
void MatrixMultiplication(int rowA, int columnA, int rowB, int columnB);
void MatrixTranspose(int row, int column);
void MatrixInput(int rowA, int rowB, int columnA, int columnB);
void MatrixOutput(int row, int column);
// xxxxxxxxxxx


//DIFFERENTIATION
void DifferentiationDisplay();
double DerivativeCentral(MathFunc f, double x, double h)
{
    return (f(x + h) - f(x - h)) / (2.0 * h);
}
double customPoly(double x)
{
    double result = ActiveCoeffs[0];
    for (int i = 1; i <= ActiveDegree; i++)
    {
        result = result * x + ActiveCoeffs[i];
    }
    return result;
}
//xxxxxxxxxx


//INTEGRATION
void IntegrationDisplay();
double IntegrateRiemann(MathFunc f, double a, double b, int n)
{
    if (n <= 0) return 0.0;

    double dx = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; i++)
    {
        double x_mid = a + (i + 0.5) * dx;
        sum += f(x_mid);
    }

    return sum * dx;
}
//xxxxxxxxxx


int main()
{
    int choice;
    do
    {
        printf("Scientific Calculator\n");
        printf("  [1] Basic Arthmetic\n");
        printf("  [2] Matrix Operations\n");
        printf("  [3] Numerical Differentiation\n");
        printf("  [4] Numerical Integration\n");
        printf("  [5] Exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            BasicArthemeticDisplay();
            break;
            case 2:
            MatrixDisplay();
            break;
            case 3:
            DifferentiationDisplay();
            break;
            case 4:
            IntegrationDisplay();
            break;
            case 5:
            printf("Exiting.... BYE");
            return 0;
            default:
            printf("Please enter a number between (1 and 5) inclusive!");
            break;
        }
    }while(choice != 5);
}


void BasicArthemeticDisplay()
{
    int input;
    double a , b;
    printf("BASIC ARITHMETIC\n");
    printf("  [1] Addition        (a + b)\n");
    printf("  [2] Subtraction     (a - b)\n");
    printf("  [3] Multiplication  (a * b)\n");
    printf("  [4] Division        (a / b)\n");
    printf("  [5] Power           (a ^ b)\n");
    printf("  [6] Back to Main Menu\n");
    scanf("%d",&input);
    while(input < 1 || input > 6)
    {
        printf("Input must be between 1 and 6 inclusive! please enter again: ");
        scanf("%d",&input);
    }
    switch(input)
    {
        case 1:
        printf("Enter A: ");
        scanf("%lf",&a);
        printf("Enter B: ");
        scanf("%lf",&b);
        printf("Result: %0.2lf\n", addition(a,b));
        BasicArthemeticDisplay();
        break;
        case 2:
        printf("Enter A: ");
        scanf("%lf",&a);
        printf("Enter B: ");
        scanf("%lf",&b);
        printf("Result: %0.2lf\n", subtraction(a,b));
        BasicArthemeticDisplay();
        break;
        case 3:
        printf("Enter A: ");
        scanf("%lf",&a);
        printf("Enter B: ");
        scanf("%lf",&b);
        printf("Result: %0.2lf\n", multiplication(a,b));
        BasicArthemeticDisplay();
        break;
        case 4:
        printf("Enter A: ");
        scanf("%lf",&a);
        printf("Enter B: ");
        scanf("%lf",&b);
        while(b==0)
        {
            printf("Division by zero is not possible! Enter B again: ");
            scanf("%lf",&b);
        }
        printf("Result: %0.2lf\n", division(a,b));
        BasicArthemeticDisplay();
        break;
        case 5:
        printf("Enter A: ");
        scanf("%lf",&a);
        printf("Enter B: ");
        scanf("%lf",&b);
        printf("Result: %0.2lf\n", pow(a,b));
        BasicArthemeticDisplay();
        break;
        case 6:
        return;
    }
}


void MatrixDisplay()
{
    int input, rowA, rowB, columnA, columnB, row, column;
    double x;
    printf("MATRIX OPERATIONS\n");
    printf("  [1] Matrix Addition       (A + B)\n");
    printf("  [2] Matrix Subtraction    (A - B)\n");
    printf("  [3] Scalar Multiplication (k * A)\n");
    printf("  [4] Matrix Multiplication (A * B)\n");
    printf("  [5] Matrix Transpose      (A^T)\n");
    printf("  [6] Back to Main Menu\n");

    scanf("%d",&input);
    while(input < 1 || input > 6)
    {
        printf("Input must be between 1 and 6 inclusive! please enter again: ");
        scanf("%d",&input);
    }
    
    switch (input)
    {
    case 1://Matrix Addition
    printf("Enter number of rows in Matrix A and B: ");
    scanf("%d",&row);
    while(row < 1 || row > 50)
    {
        printf("Number of rows must be greater than 0 and lesser than 50, Please enter again: ");
        scanf("%d",&row);
    }
    printf("Enter number of columns in Matrix A and B: ");
    scanf("%d",&column);
    while(column < 1 || column > 50)
    {
        printf("Number of columns must be greater than 0 and lesser than 50, Please enter again: ");
        scanf("%d",&column);
    }
    MatrixInput(row,row,column,column);
    MatrixAddition(row, column);
    MatrixOutput(row, column);
    MatrixDisplay();
    break;
    case 2:
    printf("Enter number of rows in Matrix A and B: ");
    scanf("%d",&row);
    while(row < 1 || row > 50)
    {
        printf("Number of rows must be greater than 0 and lesser than 50, Please enter again: ");
        scanf("%d",&row);
    }
    printf("Enter number of columns in Matrix A and B: ");
    scanf("%d",&column);
    while(column < 1 || column > 50)
    {
        printf("Number of columns must be greater than 0 and lesser than 50, Please enter again: ");
        scanf("%d",&column);
    }
    
    MatrixInput(row,row,column,column);
    MatrixSubtraction(row, column);
    MatrixOutput(row, column);
    MatrixDisplay();
    break;
    case 3:
    printf("Enter the number of rows in Matrix: ");
    scanf("%d",&row);
    while(row < 1 || row > 50)
    {
        printf("Number of rows must be greater than 0 and lesser than 50, Please enter again: ");
        scanf("%d",&row);
    }
    printf("Enter the number of columns in Matrix: ");
    scanf("%d",&column);
    while(column < 1 || column > 50)
    {
        printf("Number of columns must be greater than 0 and lesser than 50, Please enter again: ");
        scanf("%d",&column);
    }
    
    
    MatrixInput(row,0,column,0);
    printf("Enter the scalar multiple: ");
    scanf("%lf",&x);
    ScalarMultiplication(x,row,column);
    MatrixOutput(row,column);
    MatrixDisplay();
    break;
    case 4:
    printf("Enter the number of rows in Matrix A: ");
    scanf("%d",&rowA);
    while(rowA < 1 || rowA > 50)
    {
        printf("Number of rows must be greater than 0 and lesser than 50, Please enter again: ");
        scanf("%d",&rowA);
    }
    printf("Enter the number of columns in Matrix A: ");
    scanf("%d",&columnA);
    while(columnA < 1 || columnA > 50)
    {
        printf("Number of columns must be greater than 0 and lesser than 50, Please enter again: ");
        scanf("%d",&columnA);
    }
    printf("Enter the number of rows in Matrix B: ");
    scanf("%d",&rowB);
    while(rowB < 1 || rowB > 50)
    {
        printf("Number of rows must be greater than 0 and lesser than 50, Please enter again: ");
        scanf("%d",&rowB);
    }
    printf("Enter the number of columns in Matrix B: ");
    scanf("%d",&columnB);
    while(columnB < 1 || columnB > 50)
    {
        printf("Number of columns must be greater than 0 and lesser than 50, Please enter again: ");
        scanf("%d",&columnB);
    }
    if(columnA != rowB)
    {
        printf("Matrix Multiplication not Possible, number of columns in A should be equal to number of rows in B!\n");
        MatrixDisplay();
    }
    else
    {
        MatrixInput(rowA,rowB,columnA,columnB);
        MatrixMultiplication(rowA,columnA,rowB,columnB);
        row = rowA;
        column = columnB;
        MatrixOutput(row,column);
        MatrixDisplay();
    }
    break;
    case 5:
    printf("Enter the number of rows in Matrix: ");
    scanf("%d",&row);
    while(row < 1 || row > 50)
    {
        printf("Number of rows must be greater than 0 and lesser than 50, Please enter again: ");
        scanf("%d",&row);
    }
    printf("Enter the number of columns in Matrix: ");
    scanf("%d",&column);
    while(column < 1 || column > 50)
    {
        printf("Number of columns must be greater than 0 and lesser than 50, Please enter again: ");
        scanf("%d",&column);
    }
    MatrixInput(row,0,column,0);
    MatrixTranspose(row,column);
    MatrixOutput(column,row);
    MatrixDisplay();
    break;
    case 6:
    return;
    }
}

double addition(double a, double b)
{
    return a + b;
}

double subtraction(double a, double b)
{
    return a - b;
}

double multiplication(double a, double b)
{
    return a * b;
}

double division(double a, double b)
{
    return a / b;
}


void MatrixAddition(int row, int column)
{
    for (int i=0;i< row;i++)
    {
        for(int j=0; j<column; j++)
        {
            MatResult[i][j] = MatA[i][j] + MatB[i][j];           
        }    
    }
}


void MatrixSubtraction(int row, int column)
{
    for (int i=0;i< row;i++)
    {
        for(int j=0; j<column; j++)
        {
            MatResult[i][j] = MatA[i][j] - MatB[i][j];           
        }    
    }
}


void ScalarMultiplication(double x, int row, int column)
{
    for(int i=0; i < row; i++)
    {
        for(int j=0; j < column; j++)
        {
            MatResult[i][j] = x * MatA[i][j];
        }
    }
}

void MatrixMultiplication(int rowA, int columnA, int rowB, int columnB)
{
    for(int i =0; i<rowA;++i){
        for(int j=0;j<columnB;++j){
            MatResult[i][j] = 0;
            for (int k=0;k<columnA;++k){
                    MatResult[i][j] += MatA[i][k] * MatB[k][j]; 
            }
        }
    }
}

void MatrixTranspose(int row, int column)
{
    for(int i =0; i< column; i++)
    {
        for(int j = 0; j< row; j++)
        {
            MatResult[i][j] = MatA[j][i]; 
        }
    }
}


void MatrixInput(int rowA, int rowB, int columnA, int columnB)
{
    printf("Enter %d elements (row by row) for Matrix A: \n",(rowA*columnA));
    if (rowA > 0)
    {
        for(int i = 0; i < rowA; i++)
        {
            for(int j=0 ; j < columnA; j++)
            {
                scanf("%lf",&MatA[i][j]);
            }
        }
    }


    if (rowB > 0)
    {
        printf("Enter %d elements (row by row) for Matrix B: \n",(rowB*columnB));
        for(int i = 0; i < rowB; i++)
        {
            for(int j=0 ; j < columnB; j++)
            {
                scanf("%lf",&MatB[i][j]);
            }
        }
    }
}

void MatrixOutput(int row, int column)
{
    for(int i =0;i<row;i++)
    {
        printf("[");
        for(int j=0;j<column;j++)
        {
            printf("%9.2lf",MatResult[i][j]);
        }
        printf("    ]\n");
    }
}


void DifferentiationDisplay()
{
    //printf("Enter degree (1 to 4): ");
    printf("  [1] Linear Polynomial : f(x) = ax + b\n");
    printf("  [2] Quadratic Polynomial : f(x) = a*x^2 + b*x + c\n");
    printf("  [3] Cubic Polynomial : f(x) = a*x^3 + b*x^2 + c*x + d\n");
    printf("  [4] Quartic Polynomial : f(x) = a*x^4 + b*x^3 + c*x^2 + d*x + e\n");
    printf("  [5] Return to Menu\n");
    scanf("%d", &ActiveDegree);
    while (ActiveDegree < 1 || ActiveDegree > 5)
    {
        printf("Please enter a number between 1 and 5 (inclusive) !");
        scanf("%d",  &ActiveDegree);
    }
    if (ActiveDegree == 5)
    {
        return;
    }
    else
    {

    
    for (int i = 0; i <= ActiveDegree; i++)
    {
        printf("Enter coeff for x^%d: ", ActiveDegree - i);
        scanf("%lf", &ActiveCoeffs[i]);
    }

    
    double x;
    printf("Enter x: ");
    scanf("%lf",&x);
    
    printf("f'(%.2f) = %.8f\n", x, DerivativeCentral(customPoly, x, 1e-5));
    DifferentiationDisplay();
    }
}

void IntegrationDisplay()
{   
    
    printf("  [1] Linear Polynomial : f(x) = x + a\n");
    printf("  [2] Quadratic Polynomial : f(x) = a*x^2 + b*x + c\n");
    printf("  [3] Cubic Polynomial : f(x) = a*x^3 + b*x^2 + c*x + d\n");
    printf("  [4] Quartic Polynomial : f(x) = a*x^4 b*x^3 + c*x^2 + d*x + e\n");
    printf("  [5] Return to Menu\n");
    scanf("%d", &ActiveDegree);
    while (ActiveDegree < 1 || ActiveDegree > 5)
    {
        printf("Please enter a number between 1 and 5 (inclusive) !");
        scanf("%d", &ActiveDegree);
    }
    if (ActiveDegree == 5)
    {
        return;
    }
    else
    {    
        for (int i = 0; i <= ActiveDegree; i++)
        {
            printf("Enter coeff for x^%d: ", ActiveDegree - i);
            scanf("%lf", &ActiveCoeffs[i]);
        }
        double a, b;
        int n = 100000;
        printf("\nEnter lower limit (a) and upper limit (b) for integration: ");
        scanf("%lf %lf", &a, &b);

        double area = IntegrateRiemann(customPoly, a, b, n);
        printf("Integral from %.2f to %.2f = %.8f\n", a, b, area);
        IntegrationDisplay();
    }
}