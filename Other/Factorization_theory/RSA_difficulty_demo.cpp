/* Prints which two numbers multiplied recreate n last digits of your semiprime.
Increase the number of semiprime digits you want recreated.  Listed p*q are the
plausible ending digits of the factors.  Modify semiprime ending digits as well.


It seems impossible to know any semiprime factor digit, unless you have a factor
whole.  You cannot eliminate  any factor (plaus)ibilities because  multiplicands
and multipliers listed are simply all numbers ending in 1, 3, 7, 9. For example,
given the last few digits of semiprime pq,  primes p are listed as every integer
1+ but ending in 1, 3, 7, & 9  (as primes should, other than 2 & 5.) Now, for q,
the same exact numbers are listed as multipliers for p, in a different order. */


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
	long long    number_of_ending_digits_to_crack =                  5; //          <------------------------Begin at 1 and increase!
	
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





/*#######*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*##########
#####'`                                                                  `'#####
###'                              TLDR: run it                              '###
##                                                                            ##
#,                                                                            ,#
#'                              apt install g++                               '#
##                           g++ /path/this_file.cpp                          ##
###,                          /path/resulting_file                          ,###
#####,.                                                                  .,#####
##########*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#######*/

/*How to alter this code - Software package repositories for GNU+Linux operating
systems have all the tools you can imagine. Open a terminal and use this command
as root to install Geany and g++ on your computer: apt install geany g++   Geany
is a fast & lightweight text editor and Integrated Development Environment where
you can write and run code. g++ is the GNU compiler for C++  (industry standard)
which creates an executable file out of written code. It also displays errors in
code as you will see in the lower Geany box. Make a new folder somewhere on your
machine. Paste this code into Geany. For clarity in auditing, enable indentation
guides: go to View >> Show Indentation Guides. Save the document as anything.cpp
within the newly-created folder. Use these shortcuts to run the program: F9, F5.
Once  F9  is used, it needs not be used again unless you had modified this code.
You may paste over this code with other  .cpp files, or open a new tab & repeat.
Additionally, executables created by the  F9  command can be drag & dropped into
terminals (lazy directory pasting) so the executable can run.  exe is in folder.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
How to make an executable with g++  -  Save this program as anything.cpp, open a
terminal, and type g++ then space. Drag & drop this saved file into the terminal
and its directory will be  appended to your pending entry. Click on the terminal
and press enter.   a.out now resides in the user directory, you may rename it to
anything.  To run that executable, simply drag and drop it into a terminal, then
click on the terminal and press enter.  Reminder:  executable's effect-directory
is /home/user or where you put the executable. Opening  .cpp  files in Geany and
hitting F9 creates the same executable--movable, renameable, drag & droppable.*/
