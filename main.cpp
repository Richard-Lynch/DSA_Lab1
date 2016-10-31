//
// hash table starter implementation
// First v. 20 Oct 2016. Dr Anton Gerdelan <gerdela@scss.tcd.ie>
// Written in C99
//
// considerations:
// * remember to put your own name and date on your file(s)
// * start with the easiest and simplest approach, and build up from that.
// * i just have an array for the table and a function, but you
//   might prefer to put these in a c++ class - just as good.
// * i just have one hash function for both searching and storing
//   operations, and i would do the actual storing in main().
//   you might find it tidier to make separate functions for each task.
// * my hash table just stores fixed-length strings, but you might prefer to
//   store structs, or even pointers to dynamically allocated memory
// * when you upgrade to a double hashing function you are vulnerable
//   to some new errors - incomplete coverage and being stuck in an
//   infinite loop. some light reading may be required!
// * if you get stuck in an infinite loop CTRL+C is the code to force quit
//   your program if it's in a terminal
//

#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
#include "HashTable.cpp"
#include "Read_Write.cpp"
using namespace std;

#define NUM_TEST_KEYS 10

int main()
{
    const int size = 17;
    HashTable test_hash(16, size, 1);

    Read_Write TestStrings();
    string names = "Names/Names.txt";
    string teststrings2[test_hash.table_size];
    int Num_Keys = 0;
    Files.readFile(names, &teststrings2[0], &Num_Keys, teststrings2.size());


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