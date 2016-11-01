//
//Richard Lynch
// 12302202
// Data Structures and Algorithms
// Hash Tables Assignment
//



#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
#include "HashTable.cpp"
using namespace std;

#define NUM_TEST_KEYS 10

//~~~~~~~~~~~~~~~~~NB~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define DoubleHashing 1 //This value will switch the hashing algorithm from double hashing
                        // if DoubleHashing == 1 and Linear Probing is DoubleHashing == 0
//~~~~~~~~~~~~~~~~~NB~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main()
{
    const int size = 17;
    HashTable test_hash(16, size, DoubleHashing);

    string teststrings[size] = {
        "Richard", "Stephen", "Sarah", "Alexandra", "Alex", "Richie", "Ste", "Katie", "Katy", "Richie"};

    //
    // -Store each key in the table and print the index for each test key-
    printf("\n                   key    table index\n-----------------------------------\n");
    for (int i = 0; i < NUM_TEST_KEYS; i++)
    {
        //pass each of the test strings to the hash function to find index
        int index = test_hash.hash_function(&teststrings[i][0]);
        // the %16s means print a string (%s) but pad it to 16 spaces
        printf("%16s %6i\n", &teststrings[i][0], index);
    }
    // -eo print-
    //

    //
    // -calculate table load here-
    printf("\nFilled Cells:%d\nTable Size:%d\nTable Load:%f\n\n", int(test_hash.filled_cells), int(test_hash.table_size), double(test_hash.table_load()));
    // -eo table load-
    //

    return 0;
}