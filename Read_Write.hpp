#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

class Read_Write{
    public:
    string max_key_length;    //Max Length of a Key
    int table_size;    //Size of the hash table
    int double_hashing;
    int filled_cells;
    int collisions;
    string *hash_table;

    int hash_function(const char *key);
    double table_load();
    Read_Write(int MAX_KEY_LENGTH, int HASH_TABLE_SIZE_M, int DOUBLE_HASHING);
    ~Read_Write();
};