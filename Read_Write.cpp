#include "Read_Write.hpp"

//readFile(names, &teststrings[0], &NUM_TEST_KEYS);
//
// --Read in test data--
bool Read_Write::readFile(string Input, string Output[], int* NUM_TEST_KEYS2, int Output_Size)
{
    ifstream *In = new ifstream;
    In->open(Input);

    if (In->fail()) //if fail outout error
    {
        cout << "Could not open Input file." << endl;
        In->close();
        return false;
    }
    else
    {
        cout << "Input file opened successfully." << endl;
        int i = 0;
        for (string Line; getline(*In, Line); (i < Output_Size))
        {
            Output[i] = Line;
            //(*NUM_TEST_KEYS2)++;
            i++;
        }
        *NUM_TEST_KEYS = i;
        In->close();
        return true;
    }
}
//--eo Read Test Data--//

bool Read_Write::writeFile(string Output, string Input[], int Num_Entries)
{
    ofstream *Out = new ofstream;
    Out->open(Output);
    if (Out->fail()) //if fail outout error
    {
        cout << "Could not open Output file." << endl;
        Out->close();
        return false;
    }
    else
    {
        cout << "Output file opened successfully." << endl;
        *Out << Input[0] << endl;
        for (int i = 1; i < Num_Entries; i++)
        {
            *Out << "," << Input[i];
        }
        *Out << endl;
        Out->close();
        return true;
    }
}