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

#include <stdio.h> // printf() etc.
#include <string.h> // strcpy(), strlen() etc.

//
// i #define array lengths so i only have to change them in one place
#define NUM_TEST_KEYS 9
#define MAX_KEY_LENGTH 16
#define HASH_TABLE_SIZE_M 17

//
// -- the hash table itself --
char hash_table[HASH_TABLE_SIZE_M][MAX_KEY_LENGTH];

//
// -- example hash function skeleton --
// if it finds the key in the table it should return that index
// otherwise return the appropriate empty index or -1 if table is full
int hash_function(const char *key, int table_size ) {
	int index = 0;
    int probes = 0;

	//simple hash function
    for(int j=0; j<MAX_KEY_LENGTH; j++){
        index += key[j];
    }
    index = index % table_size;
    
    int found = 0;
    while(found == 0){
        //check if index is filled
        if(hash_table[index][0] == '-'){
            found = 1;
        }
        else if(strcasecmp(hash_table[index], key)==0){
            found = 2;
        }
        else if(probes >= table_size){
            index = -1;
            found = 1;
        }
        else{
            int hash_type = 2;
            //first hash - plus one
            if(hash_type == 1)
            {
                if(index < table_size){
                    index++;
                }
                else{
                    index = 0;
                }
            }//second hash
            else if(hash_type == 2)
            {
                for(int j=0; j<MAX_KEY_LENGTH; j++){
                    index += key[j]*j;
                }
                index = (index+probes) % table_size;
            }
            probes++;
        }   
    }
    printf("%i probes", probes);
    if(index != -1){
        strcpy(hash_table[index], key);
    }
	return index;
}

int main() {
    //empty hash table
    memset(hash_table,'-', sizeof(char)*HASH_TABLE_SIZE_M*MAX_KEY_LENGTH);
    //eo empty


	//
	// example: array of test strings to use as keys
	char test_strings[NUM_TEST_KEYS][MAX_KEY_LENGTH] = {
		"prince adam", "orko", "cringer", "teela", "aleet", "alete", "princess adora", "orko", "a"
	};

	//
	// example: store each key in the table and print the index for each test key
	printf(
		"             key      table index\n-----------------------------------\n" );
	for ( int i = 0; i < NUM_TEST_KEYS; i++ ) {
		int index = hash_function( test_strings[i], HASH_TABLE_SIZE_M );
		
		//
		// i would check for errors and store the keys in the table here
		//

		// the %16s means print a string (%s) but pad it to 16 spaces
		printf( "%16s %6i\n", test_strings[i], index );
	}
    //eo print

	// calculate table load here
    double table_load = 0;
    for(int i = 0; i<HASH_TABLE_SIZE_M; i++)
    {
        if(hash_table[i][1] != '-')
        {
            table_load += 1;
        }
    }
    table_load = table_load/HASH_TABLE_SIZE_M;

    printf("Table load is %f \n", table_load);
	// eo table load

	return 0;
}