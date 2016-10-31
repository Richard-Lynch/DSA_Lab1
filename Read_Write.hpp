#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

class Read_Write{
    public:
    string* Stored;
    int Num_Stored;

    bool readFile(string Input, string Output[], int* Num_Entries, int Output_Size);
    //bool readToStored(string Input);
    bool writeFile(string Output, int Input1[], int Input2[], int Num_Entries);
    Read_Write();
    //bool writeFromStored(String Output)
};