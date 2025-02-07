//Marisol Morales
//CECS 325 - 03
//Proj 3 - Sort Contest
//Due Date: 10/15/2024
//
//I certify that this program is my own original work. I didn not copy any part of this program from
//any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>

using namespace std;

const int maxNum = 1000000;

void bubbleSort(int A[], int size){

    for(int i = 0; i < (size - 1); ++i){

        for(int j = 0; j < (size - i - 1); ++j){

            //comparing two array elements, if out of place, then swap!
            // logicially this statement is checking for is a lesser number is placed below a greater number!
            // 2 1 --> 1 2
            if(A[j] > A[j + 1]){

                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;

            }

        }
    }

}

int main(int argc, char *argv[]){

    if(argc != 3){

        cout << "Error: Did not enter 2 parameters.\n";
        cout << "Please enter 2 parameters. Given the following guidelines.\n";
        cout << "Parameter 1: input file.\n";
        cout << "Parameter 2: output file.\n";
        cout << "Input the parameters in the following order on your terminal.\n";
        cout << "$ mysort Parameter 1  Parameter 2";

        exit(EXIT_FAILURE); //exiting program due to error (similar to doing return 1;)
    }

    ofstream outputFile;
    ifstream inputFile;
    int numsA[maxNum];
    int count = 0;

    inputFile.open(argv[1]);
    outputFile.open(argv[2]);

    while(inputFile >> numsA[count]){
        count++;
    }
    //since now down reading file we should close said file as well!
    inputFile.close();

    cout << "Starting Array bubble sort with " << count << " items\n";

    //now use our bubblesort algor to sort it
    bubbleSort(numsA, count);

    cout << "Ending bubble sort\n";

    //now write sorted numbers into our output file, keep in mind we already opened our output file!
    for(int i = 0; i < count; i++){

        outputFile << numsA[i] << endl;

    }

    //now down with writing our sorted numbers into output file we are able to close the file
    outputFile.close();

    return 0;
}
