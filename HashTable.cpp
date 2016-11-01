//
//Richard Lynch
// 12302202
// Data Structures and Algorithms
// Hash Tables Assignment
//

#include "HashTable.hpp"

HashTable::HashTable(int MAX_KEY_LENGTH, int HASH_TABLE_SIZE_M, int DOUBLE_HASHING)
{
    max_key_length = MAX_KEY_LENGTH;
    table_size = HASH_TABLE_SIZE_M;
    double_hashing = DOUBLE_HASHING;//set the hash type which will determine if the linear probing or double hashing is used
    hash_table = new string[table_size];//allocate memory for hash table
    Collisions_Index = new int[table_size];
    Filled = new int[table_size];
    Collisions_Filled = new int[table_size];
    //empty table
    for (int i = 0; i < table_size; i++)
    {
        hash_table[i] = '-';
        Collisions_Index[i] = 0;
        Filled[i] = 0;
        Collisions_Index[i] = 0;
    }
    filled_cells = 0;
    collisions = 0;
    //eo empty
}

HashTable::~HashTable()
{
    delete[] hash_table;
    delete[] Collisions_Index;
    delete[] Filled;
}

double HashTable::table_load()
{
    double load = (double(filled_cells) / table_size) * 100;
    return load;
}

int HashTable::hash_function(const char *key)
{
    long long index = 0; //the index which will be returned
    int probes = 0;      //the number of probes required to find

    //-simple hash function-
    //index = sum of each ascii value of the key put to the power of its position in the key
    for (int j = 0; j < max_key_length; j++)
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
        if (hash_table[index][0] == '-')
        {
            found = 1;      //if the index being checked is empty set found flag to 1
            filled_cells++; //add one to the number of filled cells(this is the first time we've added this key)
        }
        else if (strcasecmp(&hash_table[index][0], key) == 0)
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
            if (double_hashing == 0)
            {
                index = (index + 1) % table_size; //increment by 1 and go to 0 if greater than table size

            } //second hash type - double hashing
            else if (double_hashing == 1)
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
        strcpy(&hash_table[index][0], key);
        collisions += probes;
        Collisions_Index[index] = probes;
        Filled[index] = 1;
        Collisions_Filled[filled_cells] = probes;
    }

    return index;
}