/// tryRSA - attempt factorization of 100-100k-digit semiprimes used in         Run it: "apt install g++ geany". Open this in Geany. Hit F9 once. F5 to run.
///          cryptography. Curated for hands-free distributed effort;
///          randomness sprouts from garbage RAM and Unix time.


/* Version 2.0.0
#########*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##########
#####'`                                                                  `'#####
###'                                                                        '###
##         You'll need the GNU Multiple Precision Arithmetic Library.         ##
#,                                                                            ,#
#'       Do apt install libgmp-dev then append "-lgmp" to both compile &      '#
##        build commands. Or then compile: g++ /path_to_this.cpp -lgmp        ##
###,                                                                        ,###
#####,.                                                                  .,#####
##########*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#######*/

#include <fstream>
#include <gmp.h> //For GMP.
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
	
	char semiprime[100001] = {"22112825529529666435281085255026230927612089502470015394413748319128822941402001986512729726569746599085900330031400051170742204560859276357953757185954298838958709229238491006703034124620545784566413664540684214361293017694020846391065875914794251435144458199"};
	//You may replace this semiprime (RSA-260 challenge.)  Range: 3-100k digits.
	//Try the 18-digit semiprime: 344542676882192473    = 392762459 × 877229147.
	
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
	
	ofstream out_stream;
	
	//Finds semiprime digit length.
	int semiprime_digit_length = 0;
	for(int a = 0; semiprime[a] != '\0'; a++) {semiprime_digit_length++;}
	
	//Sets appropriate digit length of candidate factor. (If semiprime
	//length is even, then half. If semiprime length is odd, then half + 0.5)
	int candidate_factor_digit_length = (semiprime_digit_length / 2);
	if((semiprime_digit_length % 2) == 1) {candidate_factor_digit_length++;}
	
	//Sets a seed based on RAM garbage and Unix time. (Good for duplicate-free multi-instance.)
	unsigned int RAM_garbage[100000];
	long long seed_based_on_RAM_garbage_and_Unix_time = time(0);
	for(int a = 0; a < 100000; a++)
	{	seed_based_on_RAM_garbage_and_Unix_time += RAM_garbage[a];
		seed_based_on_RAM_garbage_and_Unix_time %= 4294967296;
	}
	unsigned int final_seed = seed_based_on_RAM_garbage_and_Unix_time;
	srand(final_seed);
	
	//Creates a random candidate factor (to be modified automatically.)
	char candidate_factor[50001] = {'\0'};
	for(int a = 0; a < candidate_factor_digit_length; a++)
	{	candidate_factor[a] = (rand() % 10);
		candidate_factor[a] += 48;
	}
	
	
	
	
	
	//Begins.
	cout << "\n";
	system("date");
	cout << "Factoring " << semiprime_digit_length << "-digit semiprime."
	     << "\nLooking for " << candidate_factor_digit_length << "-digit prime.\n";
	
	mpz_t dividend        ; mpz_init(dividend        );
	mpz_t divisor         ; mpz_init(divisor         );
	mpz_t remainder       ; mpz_init(remainder       );
	mpz_t wanted_remainder; mpz_init(wanted_remainder);
	int zero = 0;
	
	mpz_set_si (wanted_remainder, zero );
	mpz_set_str(dividend, semiprime, 10);
	
	int temp = (candidate_factor_digit_length - 1);
	for(;;)
	{	//..........Modifies candidate_factor and ensures it does not begin with 0, and that it ends in 1, 3, 7, or 9.
		//..........Only one randomly-chosen digit is changed at a time (on the candidate factor.)
		int random_index = (rand() % candidate_factor_digit_length);
		
		     if(random_index ==    0) {candidate_factor[           0] = ((rand() %  9) + 49);}
		else if(random_index  < temp) {candidate_factor[random_index] = ((rand() % 10) + 48);}
		else
		{	candidate_factor[temp] = (rand() % 4);
			if((candidate_factor[temp] % 2) == 0) {candidate_factor[temp] += 7;}
			candidate_factor[temp] += 48;
		}
		
		//..........Mod operation.
		mpz_set_str(divisor, candidate_factor, 10);
		mpz_mod    (remainder, dividend, divisor );
		
		//..........Stops if remainder is zero.
		int comparison_of_wanted_remainder_with_zero = mpz_cmp(wanted_remainder, remainder);
		if(comparison_of_wanted_remainder_with_zero == 0)
		{	//..........Writes factor to file.
			out_stream.open("FACTOR", ios::app);
			for(int a = 0; a < candidate_factor_digit_length; a++) {out_stream.put(candidate_factor[a]);}
			out_stream << "\n";
			out_stream.close();
			
			//..........Prints factor if 400 digits or less.
			cout << "\n";
			system("date");
			cout << "Done! Prime appended to file \"FACTOR\"";
			if(candidate_factor_digit_length <= 400)
			{	cout << ":\n\n";
				for(int a = 0; a < candidate_factor_digit_length; a++) {cout << candidate_factor[a];}
			}
			else {cout << ".\n\n";}
			
			return 0;
		}
	}
}
