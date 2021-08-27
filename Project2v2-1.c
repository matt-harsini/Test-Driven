#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define CONVERT_ARRAY_TO_POINTER(pointerArray, twoDArray, size) \
    pointerArray = malloc(size*sizeof(int)); \
    for(int i = 0; i < size; i++) {pointerArray[i] = twoDArray[i];}
void testPass(double input, double expected, char* string) {
    printf("Pass: %s\n", string);
    printf("Input is correct! Expected %f and got %f\n", input, expected);
}
void testFailure(double input, double expected, char* string) {
    printf("Fail: %s\n", string);
    printf("Input was %f but expected %f\n", input, expected);
}
void printArray(int **arrayOne, int sizeA, int sizeAcol) {
    int i, j;
    for (i = 0; i < sizeA; i++) {
        for (j = 0; j < sizeAcol; j++) {
                printf("%d ", arrayOne[i][j]);
        }
        printf("\n"); 
    }
}
void print1DIntArray(int* arrayOne, int size) {
    int i;
    for(i=0; i<size;i++) {
        printf("%d", arrayOne[i]);
    }
    printf("\n");
}
int arrayIsEqual(int** arrayOne, int** arrayTwo, int sizeA, int sizeAcol) {
    int i, j;
    for (i = 0; i < sizeA; i++) {
        for (j = 0; j < sizeAcol; j++) {
                if(arrayOne[i][j]!=arrayTwo[i][j]) {
                    return 0;
                }
        } 
    }
    return 1;
}
void test (double input, double expected, char* string) {
    if (input == expected) {
        testPass(input, expected, string);

    }
    else {
        testFailure(input, expected, string);
    }
}
void testMatrixAddition(int** matrixOne, int** matrixTwo, char* String, int sizeA, int sizeAcol) {
    if(arrayIsEqual(matrixOne, matrixTwo, sizeA, sizeAcol)) {
        //testPass(String);
        printf("\x1b[32mArrays are equal for matrix addition!\x1b[0m\nExpected:\n");
        printArray(matrixOne, sizeA, sizeAcol);
        printf("and got:\n");
        printArray(matrixTwo, sizeA, sizeAcol);
    }
    else {
        printf("\x1b[31mTest failure for matrix addition!\x1b[0m\nExpected:\n");
        printArray(matrixOne, sizeA, sizeAcol);
        printf("but got:\n");
        printArray(matrixTwo, sizeA, sizeAcol);
    }
}
void testIdentityMatrix(int** matrixOne, int size) {
    int i, j;
    for(i =0;i<size;i++){
        for(j=0;j<size;j++){
            if (i==j){
                if(matrixOne[i][j]!=1){
                    printf("\x1b[31mArray is not valid for identity matrix!\x1b[0m\n");
                    printf("Expected:\n");
                    printArray(matrixOne, size, size);
                    printf("but got:\n");
                    printArray(matrixOne, size, size);
                    return;
                }
            }
            if(i!=j){
                if(matrixOne[i][j]!=0){
                    printf("Array is not equal to zero\n.");
                    return;
                }
            }
        }
    }
    printf("\x1b[32mArrays are equal for identity matrix!\x1b[0m\n");
    printf("Expected:\n");
    printArray(matrixOne, size, size);
    printf("and got:\n");
    printArray(matrixOne, size, size);
}
int lengthOf1DArray(int* array){
    return sizeof(array)/sizeof(array[0]);
}
int lengthOf2DArray(int** array){
    printf("%ld\n", sizeof(array)/sizeof(array[0]));
    return sizeof(array)/sizeof(array[0]);
}
char * int2dArrayToString(int** input, int sizeA, int sizeAcol) {
    int i, j;
    char** result = (char**)malloc(sizeof(char*)*sizeA);
    for (i = 0; i < sizeA; i++) {
        result[i] = (char*)malloc(sizeof(char)*8*sizeAcol+1);
        sprintf(result[i],"%s", "");
        for (j = 0; j < sizeAcol; j++) {
                char * number = malloc(sizeof(char)*8);
                sprintf(number,"%6d",input[i][j]);
                strcat(result[i],number);
                free(number);
        }
        strcat(result[i],"\n"); 
    }
    char * resultAsString = (char*)malloc(sizeof(char*)*sizeA*sizeAcol*8+1);
    sprintf(resultAsString,"%s", "");
    for(i = 0; i < sizeA; i++){
        strcat(resultAsString,result[i]);
        free(result[i]);
    }
    free(result);
    return resultAsString;
}
void int2dArraytoStringTest(char* matrixOne, char* matrixTwo){
    if(strcmp(matrixOne,matrixTwo) == 0) {
        printf("\x1b[32m\nThe matrices are equal for int2dArraytoString test case!\n\x1b[0mExpected:\n");
        printf("\"\n%s\"\nand got: \"\n%s\"",matrixOne,matrixTwo);
    } else {
        printf("\x1b[31m\nMatrices are not equal for the int2dArraytoString test case!\n\x1b[0mExpected:");
        printf("\"%s\"\nand got: \"%s\"\n",matrixOne,matrixTwo);
    }
}
int** mAdd(int** matrixA, int** matrixB,int sizeA, int sizeB, int sizeAcol, int sizeBcol) {
    if((sizeA != sizeB) && (sizeAcol) != (sizeBcol)) return NULL;
    int** result = (int**)malloc(sizeof(int)*sizeA);
    int i, j;
    for (i = 0; i < sizeA; i++) {
        result[i] = (int*)malloc(sizeof(int)*sizeAcol);        
    }
    for (i = 0; i < sizeA; i++) {
        for (j = 0; j < sizeAcol; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];  
        } 
    }
    return result;
}
int** iN(int n){
    int i, j;
    int counter;
    int** result = (int**)malloc(sizeof(int*)*n);
    for(i =0;i<n;i++){
        result[i] = (int*)malloc(sizeof(int)*n); 
        for(j=0;j<n;j++){
            if (i==j){
                result[i][j] = 1;
            }
            else {
                result[i][j] = 0;
            }
        }
    }
    return result;
}
double average(int** input, int sizeA, int sizeAcol){
    double sum = 0;
    int i, j;
    for(i = 0; i < sizeA; i++) { 
        for(j = 0; j < sizeAcol; j++) {
            sum += input[i][j];
        }
    }
    return (double)sum/(sizeA*sizeAcol);
}
int* question(int*input, int sizeA){
    int* result = (int*)malloc(sizeof(int)*sizeA);
    int i, j;
    for(i=0; i<sizeA;i++){
        result[i] = 0;
        for(j = i; j<sizeA; j++){
            result[i] += input[j];
        }
    }
    return result;
}
int arraysAreEqual(int*matrixOne, int*matrixTwo, int sizeA){
    int i;
    for(i=0;i<sizeA; i++){
        if(matrixOne[i]!=matrixTwo[i]){
            return -1;
        }
    }
    return 0;
}
void questionTest(int*expected, int*input, int sizeA){
    int* array = question(input, sizeA);
    if(arraysAreEqual(expected ,array,sizeA)==0){
        printf("\x1b[32mArrays are equal for sum of numbers in each row.\x1b[0m\nInput was:\n");
        print1DIntArray(input, sizeA);
        printf("and expected:\n");
        print1DIntArray(expected, sizeA);
    } else {
        printf("\x1b[31mArrays are not equal for the sum of numbers in each row!\x1b[0m\nExpected:\n");
        print1DIntArray(expected, sizeA);
        printf("but got:\n");
        print1DIntArray(input, sizeA);
    }
}
int main(int argc, char *argv[])
{   //matrix declaration 
    int matrix1[2][0]; 
    int matrix2[3][5] = {{1,2,3,4,5},{3,4,5,6,1},{1,4,6,2,4}};
    int matrix3[3][5] = {{8,1,2,3,7},{4,7,8,2,4},{2,1,2,3,9}};
    int matrix4[3][5] = {{1,2,3,4,5},{3,4,5,6,1},{1,4,6,9,4}};
    int sumOfmatrix23[3][5] = {{9,3,5,7,12},{7,11,13,8,5},{3,5,8,5,13}};
    int sumOfmatrix24[3][5] = {{2,4,6,8,10},{6,8,10,12,2},{2,8,12,11,8}};
    int matrix5[2][2] = {{1,2}, {3,4}};
    int matrix6[2][2] = {{1,0}, {3,4}};
    //pointer declaration
    int **matrix9, **matrix10, **matrix11, **matrix12,**matrix13;
    //pointer declaration for mAdd
    int** mAdd1, ** mAdd2,** mAdd3,** mAdd4,** sum,** sum24,**identityMatrix;
    //testing for average
    CONVERT_ARRAY_TO_POINTER(matrix9, matrix5, 2);
    test(average(matrix9, 2, 2), 2.5, "\x1b[32mAverage is correct!\x1b[0m");
    CONVERT_ARRAY_TO_POINTER(matrix10, matrix4, 3);
    test(average(matrix10, 3, 5), 3.8, "\x1b[31mAverage is incorrect!\x1b[0m");
    CONVERT_ARRAY_TO_POINTER(matrix11, matrix3, 3);
    test(average(matrix11, 3, 5), 4.1, "\x1b[31mAverage is incorrect!\x1b[0m");
    CONVERT_ARRAY_TO_POINTER(matrix12, matrix2, 3);
    test(average(matrix12, 3, 5), 3.4, "\x1b[32mAverage is correct!\x1b[0m");
    //testing for mAdd
    CONVERT_ARRAY_TO_POINTER(mAdd2, matrix2, 3);
    CONVERT_ARRAY_TO_POINTER(mAdd3, matrix3, 3);
    CONVERT_ARRAY_TO_POINTER(mAdd4, matrix4, 3);
    CONVERT_ARRAY_TO_POINTER(sum, sumOfmatrix23, 3);
    CONVERT_ARRAY_TO_POINTER(sum24, sumOfmatrix24, 3);
    testMatrixAddition(mAdd(mAdd3, mAdd2, 3, 3, 5, 5), sum, "\x1b[32mSum of matrices\x1b[0m", 3, 5);
    testMatrixAddition(mAdd(mAdd4, mAdd2, 3, 3, 5, 5), sum24, "\x1b[32mSum of matrices\x1b[0m", 3, 5);
    testMatrixAddition(mAdd(mAdd4, mAdd3, 3, 3, 5, 5), sum24, "Sum of matrices", 3, 5);
    testMatrixAddition(mAdd(mAdd4, mAdd3, 3, 3, 5, 5), sum, "Sum of matrices", 3, 5);
    testIdentityMatrix(iN(5),5);
    CONVERT_ARRAY_TO_POINTER(identityMatrix, sumOfmatrix23,3);
    testIdentityMatrix(identityMatrix, 3);
    testIdentityMatrix(iN(1),1);
    testIdentityMatrix(iN(4),4);
    int ** emptyMatrix;
    int emptyArray[0][0] = {};
    CONVERT_ARRAY_TO_POINTER(emptyMatrix, emptyArray,0);
    char * matrix5asAString = "     1     2\n     3     4\n";
    char * matrix6asAString = "     1     0\n     3     4\n";
    char * identityMatrixTest = "     1     0\n     0     1\n";
    char * emptyString = "";
    int2dArraytoStringTest(int2dArrayToString(matrix9, 2,2), matrix5asAString);
    CONVERT_ARRAY_TO_POINTER(matrix13, matrix6, 2);
    int2dArraytoStringTest(int2dArrayToString(matrix13, 2,2), matrix6asAString);
    int2dArraytoStringTest(int2dArrayToString(iN(2), 2,2), identityMatrixTest);
    int2dArraytoStringTest(int2dArrayToString(emptyMatrix, 0,0), "Hello.");
    int questionTest1[3] = {3,2,1};
    int questionTest2[3]={1,1,0};
    int questionTest3[3]={1,1,1};
    questionTest(questionTest1, questionTest2,3);
    questionTest(questionTest1, questionTest3,3);
    questionTest(questionTest3, questionTest2,3);
    questionTest(questionTest3, questionTest2,4);
    return 0;
}