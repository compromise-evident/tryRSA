/* Exposing that it seems impossible to know any  semiprime factor digit  unless
the whole factor is known. This tool prints all possible ways two numbers can be
multiplied in order to recreate some last few digits of your semiprime. It's not
possible to eliminate any factorization possibilities  because the multiplicands
and multipliers listed are simply all numbers ending in 1, 3, 7, 9. For example,
given the last few digits of semiprime pq,  primes p are listed as every integer
1+ but ending in 1, 3, 7, & 9  (as primes should, other than 2 & 5.) Now, for q,
the same numbers are listed verbatim as multipliers for p, in a different order.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
It seems RSA has the perfect secrecy-like nature of the  One-time pad's  all-way
function. As if RSA starts at a One-time pad then takes steps down from there.*/


#include <iostream>
using namespace std;

int main()
{	//                               user knobs
	
	/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  /////////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\    ////////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\      ///////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\        //////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\            ////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\              ///////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\                  /////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\                      ///////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\                              ///////////////////////
	\\\\\\\\\\\\\\\\\\                                        ////////////////*/
	
	long long   last_few_digits_of_your_semiprime = 423446789015381147; //Must end in 1, 3, 7, 9
	long long    number_of_ending_digits_to_crack =                  5; //Range: 1+     <------------------------Begin at 1 and increase!
	
	/*////////////////                                        \\\\\\\\\\\\\\\\\\
	///////////////////////                              \\\\\\\\\\\\\\\\\\\\\\\
	///////////////////////////                      \\\\\\\\\\\\\\\\\\\\\\\\\\\
	/////////////////////////////                  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	///////////////////////////////              \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	////////////////////////////////            \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	//////////////////////////////////        \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	///////////////////////////////////      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	////////////////////////////////////    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	/////////////////////////////////////  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	//////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
	
	long long number_of_ending_digits_via_mod = 1;
	for(long long a = 0; a < number_of_ending_digits_to_crack; a++) {number_of_ending_digits_via_mod *= 10;}
	last_few_digits_of_your_semiprime %= number_of_ending_digits_via_mod;
	
	long long p_duplicate_watch = 0;
	long long q_duplicate_watch = 0;
	
	long long quantity = 1;
	for(long long p = 0; p < number_of_ending_digits_via_mod; p++)
	{	for(long long q = 0; q < number_of_ending_digits_via_mod; q++)
		{	if(((p % 10) == 1)
			|| ((p % 10) == 3)
			|| ((p % 10) == 7)
			|| ((p % 10) == 9))
			{	if(((q % 10) == 1)
				|| ((q % 10) == 3)
				|| ((q % 10) == 7)
				|| ((q % 10) == 9))
				{	long long product = (p * q);
					product %= number_of_ending_digits_via_mod;
					
					if(product == last_few_digits_of_your_semiprime)
					{	long long max_length_reference = (number_of_ending_digits_via_mod - 1);
						max_length_reference /= 10;
						
						cout << "possibility_";
						for(int temp = max_length_reference, a = 0; a < (number_of_ending_digits_to_crack - 1); a++)
						{	if(quantity <= temp) {cout << "_";}
							temp /= 10;
						}
						cout << quantity << ":    ";
						
						for(int temp = max_length_reference, a = 0; a < (number_of_ending_digits_to_crack - 1); a++)
						{	if(p <= temp) {cout << " ";}
							temp /= 10;
						}
						cout << p << " * ";
						
						for(int temp = max_length_reference, a = 0; a < (number_of_ending_digits_to_crack - 1); a++)
						{	if(q <= temp) {cout << " ";}
							temp /= 10;
						}
						cout << q << "    = ..." << product << " (semiprime)\n";
						
						p_duplicate_watch += p;
						q_duplicate_watch += q;
						quantity++;
					}
				}
			}
		}
	}
	
	if(p_duplicate_watch != q_duplicate_watch) {cout << "\n\nFAILED! Cryptographic semiprimes end in 1, 3, 7, or 9."; return 0;}
	
	cout << "\n\n\nQuantity is always 4*10^n because 40% of numbers end in 1, 3, 7, 9."
	     << "\n\n~Half are duplicates, as in a*b and b*a."
	     << "\n\nInterestingly, sums are always 2*10^n and always equal:"
	     << "\nsum(all p) = " << p_duplicate_watch 
	     << "\nsum(all q) = " << q_duplicate_watch;
}
