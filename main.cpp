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
#include "Read_Write.cpp"
using namespace std;

#define NUM_TEST_KEYS 10

int main()
{
    const int max_size = 22943;
    int Num_Keys = 0;
    string names = "Names/Names.txt";
    string teststrings2[max_size];
    
    Read_Write Test;
    Test.readFile(names, &teststrings2[0], &Num_Keys, max_size);

    HashTable* test_hash;
    int Array_Size[3] = {17, 5101, 22943};
    int divisors[3] = {2, 5, 9};
    string Files[] = {
        "Small_20.csv", "Small_50.csv", "Small_90.csv", "Med_20.csv", "Med_50.csv", "Med_90.csv", "Lrg_20.csv",
         "Lrg_50.csv", "Lrg_90.csv"};


    for(int i = 0; i < 3; i++)
    {
        test_hash = new HashTable(16, Array_Size[i], 1);
        for(int j = 0; j < 3; j++)
        {
            int fill_level = int((Array_Size[i]/10)*divisors[j]);
            //
            // -Store each key in the table and print the index for each test key-
            printf("\n                   key    table index\n-----------------------------------\n");
            for (int k = 0; k < fill_level; k++)
            {
                //pass each of the test strings to the hash function to find index
                int index = test_hash->hash_function(&teststrings2[k][0]);
                // the %16s means print a string (%s) but pad it to 16 spaces
                printf("%16s %6i\n", &teststrings2[k][0], index);
            }
            // -eo print-
            //

            //
            // -calculate table load here-
            printf("\nFilled Cells:%d\nTable Size:%d\nTable Load:%f\n\n", int(test_hash->filled_cells), int(test_hash->table_size), double(test_hash->table_load()));
            string output = "Test_Results/";
            output.append(Files[(3*i)+j]);
            Test.writeFile2(output, test_hash->Collisions_Index,test_hash->Filled, test_hash->table_size);
            if(j == 2){
                Test.writeFile("Collisions_Over_Time.csv", test_hash->Collisions_Index, test_hash->filled_cells);
            }
            // -eo table load-
            //
        }
    }


    return 0;
}