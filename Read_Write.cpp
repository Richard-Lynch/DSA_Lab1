#include "Read_Write.hpp"

Read_Write::Read_Write()
{
    Stored = NULL;
    Num_Stored = 0;
}

//readFile(names, &teststrings[0], &NUM_TEST_KEYS);
//
// --Read in test data--
bool Read_Write::readFile(string Input, string Output[], int* Num_Entries, int Output_Size)
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
        string Line;
        getline(*In, Line);
        for (Line; (i < Output_Size); getline(*In, Line))
        {
            Output[i] = Line;
            //(*NUM_TEST_KEYS2)++;
            i++;
        }
        *Num_Entries = i;
        In->close();
        return true;
    }
}
//--eo Read Test Data--//

bool Read_Write::writeFile(string Output, int Input1[], int Num_Entries)
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
        for (int i = 0; i < Num_Entries; i++)
        {
            *Out << i << ", " << Input1[i] << endl;
        }
        *Out << endl;
        Out->close();
        return true;
    }
}

bool Read_Write::writeFile2(string Output, int Input1[], int Input2[], int Num_Entries)
{
    ofstream *Out = new ofstream;
    Out->open(Output, std::ofstream::app);
    if (Out->fail()) //if fail outout error
    {
        cout << "Could not open Output file." << endl;
        Out->close();
        return false;
    }
    else
    {
        cout << "Output file opened successfully." << endl;
        for (int i = 0; i < Num_Entries; i++)
        {
            *Out << Input1[i] << "," << Input2[i] << endl;
        }
        *Out << endl;
        Out->close();
        return true;
    }
}