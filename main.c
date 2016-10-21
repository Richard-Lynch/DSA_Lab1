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
#define NUM_TEST_KEYS 7
#define MAX_KEY_LENGTH 16
#define HASH_TABLE_SIZE_M 17

//
// -- the hash table itself --
char hash_table[HASH_TABLE_SIZE_M][MAX_KEY_LENGTH];

//
// -- example hash function skeleton --
// if it finds the key in the table it should return that index
// otherwise return the appropriate empty index or -1 if table is full
int hash_function( const char *key, int table_size ) {
	int index = 0;

	//
	// write your hash function here
	//

	//
	// consider counting the number of probes it takes to store
	// your key and printing that out

	return index;
}

int main() {

	//
	// example: array of test strings to use as keys
	char test_strings[NUM_TEST_KEYS][MAX_KEY_LENGTH] = {
		"prince adam", "orko", "cringer", "teela", "aleet", "princess adora", "orko"
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

	//
	// calculate table load here
	//

	return 0;
}