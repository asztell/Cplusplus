#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cctype>
#include <string>
#include <time.h>
using namespace std;

void fillarraywithinput( int array[], int& size );
void dump( int sum, int numadds, int numincs, int numass, 
		   int numcmps, string algorithm );

// maximum sequence sum
void maxseqsumn3( int array[], int size, 
				  int& sum,           // the sequeunce sum
				  int& numadds,       // the number of adds performed
				  int& numincs,       // the number of increments
				  int& numass,        // the number of assignments 
				  int& numcmps );     // the number of comparisons

void maxseqsumn2( int array[], int size, 
				  int& sum,        // the sequeunce sum
				  int& numadds,    // the number of adds performed
				  int& numincs,    // the number of increments
				  int& numass,     // the number of assignments 
				  int& numcmps );  // the number of comparisons

void maxseqsumn(  int array[], int size, 
				  int& sum,        // the sequeunce sum
				  int& numadds,    // the number of adds performed
				  int& numincs,    // the number of increments
				  int& numass,     // the number of assignments 
				  int& numcmps );  // the number of comparisons

typedef int* intArrayPtr;

int main() {
	// build an array to hold values
	int size = 128;
	intArrayPtr dataarray = new int[ size ];
	// various algorithm counters
	int sum = 0, numadds = 0, numincs = 0, numass = 0, numcmps = 0;

	// acquire data values
	fillarraywithinput( dataarray, size );

	// calculate the maximum sequence sum
	maxseqsumn3( dataarray, size, sum, numadds, numincs, numass, 
				 numcmps );
	// dump counters
	dump( sum, numadds, numincs, numass, numcmps, "O(n*n*n)" );

	// calculate the maximum sequence sum
	maxseqsumn2( dataarray, size, sum, numadds, numincs, numass, 
				 numcmps );
	// dump counters
	dump( sum, numadds, numincs, numass, numcmps, "O(n*n)" );

	// calculate the maximum sequence sum
	maxseqsumn( dataarray, size, sum, numadds, numincs, numass, 
				 numcmps );
	// dump counters
	dump( sum, numadds, numincs, numass, numcmps, "O(n)" );

	return( 0 );
}


void fillarraywithinput( int array[], int& size ) {
	string data;
	int k = 0;
	unsigned int startcntr = 0;
	unsigned int endcntr = 0;
	cout << "Enter a sequence of integers to find max subsequence:" << endl;
	getline( cin, data );
	data += " ";  // in case string does not end with whitespace
	for (endcntr = 0; endcntr < data.length(); ++endcntr) {
		if (isspace(data.at(endcntr)) && startcntr <= endcntr) {
			string bit = data.substr( startcntr, endcntr - startcntr + 1 );
			if (isspace( bit.at(0) )) {
				startcntr = endcntr + 1;
				continue;
			}
			int value = atoi( bit.c_str() );
			array[ k++ ] = value;
			startcntr = endcntr + 1;
		}	
	}
	size = k;
}

void maxseqsumn3( int array[], int size, 
				  int& sum,            // the sequeunce sum
				  int& numadds,        // the number of adds performed
				  int& numincs,        // the number of increments
				  int& numass,         // the number of assignments
				  int& numcmps ) {     // the number of comparisons
	int thisSum = 0, i, j, k;

	sum = 0;
	numadds = 0;
	numincs = 0;
	numass = 0;
	numcmps = 0;

	// perform the O(N*N*N) algorithm
	for (i = 0; i < size; i++) {
		++numcmps; ++numincs;         // update counters
		for (j = i; j < size; j++) {
			++numcmps; ++numincs;     // update counters
			thisSum = 0;
			++numass;                 // update counters
			for (k = i; k <= j; k++) {
				++numcmps; ++numincs; // update counters
				thisSum += array[k];
				++numadds; ++numass;  // update counters
			}
			if (thisSum > sum) {
				sum = thisSum;
				++numass;             // update counters
			}
			++numcmps;                // update counters
		}
	}
}

void maxseqsumn2( int array[], int size, 
				  int& sum,        // the sequeunce sum
				  int& numadds,    // the number of adds performed
				  int& numincs,    // the number of increments
				  int& numass,     // the number of assignments
				  int& numcmps  ) {// the number of comparisons
	int thisSum = 0, i, j;

	sum = 0;
	numadds = 0;
	numincs = 0;
	numass = 0;
	numcmps = 0;

	// perform the O(N*N) algorithm
	for (i = 0; i < size; i++) {
		++numcmps; ++numincs;         // update counters
		thisSum = 0;
		++numass;
		for (j = i; j < size; j++) {
			++numcmps; ++numincs;     // update counters
			thisSum += array[ j ];
			++numadds; ++numass;      // update counters
			if (thisSum > sum) {
				sum = thisSum;
				++numass;             // update counters
			}
			++numcmps;                // update counters
		}
	}

}

void maxseqsumn(  int array[], int size, 
				  int& sum,        // the sequeunce sum
				  int& numadds,    // the number of adds performed
				  int& numincs,    // the number of increments
				  int& numass,     // the number of assignments
				  int& numcmps  ) {// the number of comparisons
	int thisSum = 0, i, j;

	sum = 0;
	numadds = 0;
	numincs = 0;
	numass = 0;
	numcmps = 0;

	// perform the O(N) algorithm
	for (i = 0, j = 0; j < size; j++) {
		++numcmps; ++numincs;         // update counters
		thisSum += array[ j ];
		++numass; ++numadds;
		if (thisSum > sum) {
			sum = thisSum;
			++numass; ++numcmps;      // update counters
		}
		else if (thisSum < 0) {
			i = j + 1;
			thisSum = 0;
			++numcmps; ++numcmps;     // update counters
			++numass; ++numass;
		}
		else {
			++numcmps; ++numcmps;     // update counters
		}
	}

}

void dump( int sum, int numadds, int numincs, int numass, 
		  int numcmps, string algorithm ) {
	cout << "------" << algorithm << "------" << endl;
	cout << "sequence sum = " << sum << endl;
	cout << "  adds=" << numadds << "  incs=" << numincs;
	cout << "  assigns=" << numass << "  comps=" << numcmps;
	cout << "  TOTAL:" << numadds + numincs + numass + numcmps;
	cout << endl;
}


