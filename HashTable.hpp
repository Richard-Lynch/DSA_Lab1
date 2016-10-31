#include <stdio.h>  // printf() etc.
#include <string.h> // strcpy(), strlen() etc.
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

class HashTable{
    public:
    int max_key_length;    //Max Length of a Key
    int table_size;    //Size of the hash table
    int double_hashing;
    int filled_cells;
    int collisions;
    int* Collisions_Index;
    int* Filled;
    string* hash_table;

    int hash_function(const char *key);
    double table_load();
    HashTable(int MAX_KEY_LENGTH, int HASH_TABLE_SIZE_M, int DOUBLE_HASHING);
    ~HashTable();
};