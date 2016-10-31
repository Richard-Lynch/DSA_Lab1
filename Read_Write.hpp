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

    bool readFile(string Input, string Output[], int* NUM_TEST_KEYS2, int Output_Size);
    //bool readToStored(string Input);
    bool writeFile(string Output, string Input[], int Num_Entries);
    //bool writeFromStored(String Output)
    Read_Write(int MAX_KEY_LENGTH, int HASH_TABLE_SIZE_M, int DOUBLE_HASHING);
    ~Read_Write();
};