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
using namespace std;

//
// -- Definitions -- 
#define MAX_KEY_LENGTH 16       //Max Length of a Key
#define HASH_TABLE_SIZE_M 17    //Size of the hash table
#define NUM_TEST_KEYS 10        //number of test keys
#define hash_type 2             // hash type 1 = linear, hash type 2 = double hashing
// -- eo Definitions -- 
//

//
// -- Hash Function --
// if it finds the key in the table it should return that index
// otherwise return the appropriate empty index(and add to the table) or -1 if table is full
int hash_function(const char *key, int table_size, string hash_table2[], int* filled_cells)
{
    long long index = 0; //the index which will be returned
    int probes = 0;      //the number of probes required to find

    //-simple hash function-
    //index = sum of each ascii value of the key put to the power of its position in the key
    for (int j = 0; j < MAX_KEY_LENGTH; j++)
    {
        index += pow(int(key[j]), j%6);
    }

    index = index % table_size; //index is index mod table size to make sure it fits in the table
    index = llabs(index);   //gets absolute value of mod
    //-eo simple-
    //

    //
    //-search hash table-
    int found = 0; //flag - have we found the corrected index
    while (found == 0)
    {
        //check if index being checked is empty
        if (hash_table2[index][0] == '-')
        {
            found = 1;      //if the index being checked is empty set found flag to 1
            (*filled_cells)++; //add one to the number of filled cells(this is the first time we've added this key)
        }
        else if (strcasecmp(&hash_table2[index][0], key) == 0)
        {
            found = 2; //if the index being checked containts the key, set found flag to 1
            //we have found the key in the table, we dont need to add 1 to filled
        }
        else if (probes >= table_size)
        {
            index = -1; //if we have probed every cell and found no space, set index to -1 to show the table is full
            found = 3;  //set found flag to 3 to exit loop
        }
        else
        {
            //either of these hashing types can be enabled at the top of the program by setting hash_type
            //first hash type - linear probing
            if (hash_type == 1)
            {
                index = (index + 1) % table_size; //increment by 1 and go to 0 if greater than table size

            } //second hash type - double hashing
            else if (hash_type == 2)
            {
                //increment the index by the first char in the key mod table_size(+1 to ensure it is never 0)
                //aka the increment is (key[0]%table_size) +1
                index = (index + 1 + (key[0] % table_size)) % table_size;
            }
            probes++; //if we have incremenented the index add one to probe
        }
    }
    //-eo search-
    //

    //-print the number of probes we needed to find the index-
    printf("%i probes", probes);

    //-if the table wasnt full(we found an available index) copy the key to the table-
    if (index != -1)
    {
        strcpy(&hash_table2[index][0], key);
    }

    return index;
}

int main()
{
    //
    // -Empty Hash Table-
    string hash_table[HASH_TABLE_SIZE_M];
    int filled_cells = 0; 
    for (int i = 0; i < HASH_TABLE_SIZE_M; i++)
    {
        hash_table[i] = '-';
    }
    filled_cells = 0;
    // -eo empty-
    //

    string teststrings[HASH_TABLE_SIZE_M] = {
        "Richard", "Stephen", "Sarah", "Alexandra", "Alex", "Richie", "Ste", "Katie", "Katy", "Richie"};

    //
    // -Store each key in the table and print the index for each test key-
    printf("\n                   key    table index\n-----------------------------------\n");
    for (int i = 0; i < NUM_TEST_KEYS; i++)
    {
        //pass each of the test strings to the hash function to find index
        int index = hash_function(&teststrings[i][0], HASH_TABLE_SIZE_M, &hash_table[0], &filled_cells);
        // the %16s means print a string (%s) but pad it to 16 spaces
        printf("%16s %6i\n", &teststrings[i][0], index);
    }
    // -eo print-
    //

    //
    // -calculate table load here-
    double table_load = 0; 
    table_load = (double(filled_cells) / HASH_TABLE_SIZE_M) * 100;
    printf("\nFilled Cells:%d\nTable Size:%d\nTable Load:%f\n\n", int(filled_cells), HASH_TABLE_SIZE_M, table_load);
    // -eo table load-
    //

    return 0;
}