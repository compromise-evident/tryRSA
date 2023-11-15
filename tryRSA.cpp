/// tryRSA - attempt factorization of 100-100k-digit semiprimes used in cryptography.
/// Nikolay Valentinovich Repnitskiy - License: WTFPLv2+ (wtfpl.net)


/* Version 1.0.0
Only one randomly-chosen  digit is changed at a time (on the  candidate factor.)
Actually, lower limit semiprime length is 3 digits.  Run-times always differ. */

#include <fstream>
#include <gmp.h> //For GMP
//(GNU Multiple Precision Arithmetic Library)
//To get GMP running, do apt install libgmp-dev
//then append "-lgmp" to both compile & build commands.
#include <iostream>
using namespace std;

int main()
{	ifstream in_stream;
	ofstream out_stream;
	
	//Gets path to file from user.
	cout << "\nPlace the 100-100k-digit semiprime in a file."
	     << "\nDrag & drop file into terminal or enter path:\n";
	
	char  path_to_file[10000] = {'\0'};
	cin.getline(path_to_file, 10000);
	if(path_to_file[0] == '\0') {cout << "\nNo path given.\n"; return 0;}
	
	//Fixes path to file if drag & dropped (removes single quotes for ex:)   '/home/nikolay/my documents/RSA-260'
	if(path_to_file[0] == '\'')
	{	for(int a = 0; a < 10000; a++)
		{	path_to_file[a] = path_to_file[a + 1];
			if(path_to_file[a] == '\'')
			{	path_to_file[a    ] = '\0';
				path_to_file[a + 1] = '\0';
				path_to_file[a + 2] = '\0';
				break;
			}
		}
	}
	
	//Checks if file exists (failure can be bad path info as well.)
	in_stream.open(path_to_file);
	if(in_stream.fail() == true) {in_stream.close(); cout << "\n\nNo such file or directory.\n";             return 0;}
	char sniffed_one_file_character;
	in_stream.get(sniffed_one_file_character);
	if(in_stream.eof() == true) {in_stream.close();  cout << "\n\nNothing to process, the file is empty.\n"; return 0;}
	in_stream.close();
	
	//Gets location of the first encountered end-null coming from the left in path_to_file[].
	int path_to_file_null_bookmark;
	for(int a = 0; a < 10000; a++) {if(path_to_file[a] == '\0') {path_to_file_null_bookmark = a; break;}}
	
	//Gets the semiprime from file.
	char semiprime[100001] = {'\0'};
	char garbage_byte;
	int semiprime_digit_length = 0;
	
	in_stream.open(path_to_file);
	in_stream.get(garbage_byte);
	for(int a = 0; in_stream.eof() == false && garbage_byte != '\n' && garbage_byte != ' '; a++)
	{	semiprime[a] = garbage_byte;
		in_stream.get(garbage_byte);
		semiprime_digit_length++;
	}
	in_stream.close();
	
	//Sets appropriate digit length of candidate factor. (If semiprime
	//length is even, then half. If semiprime length is odd, then half + 0.5)
	int candidate_factor_digit_length = (semiprime_digit_length / 2);
	if((semiprime_digit_length % 2) == 1) {candidate_factor_digit_length++;}
	
	//Creates a random candidate factor (to be modified automatically.)
	char candidate_factor[50001] = {'\0'};
	srand(time(0));
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
	
	mpz_set_str(dividend, semiprime, 10);
	
	for(;;)
	{	//..........Modifies candidate_factor.
		int random_index = (rand() % candidate_factor_digit_length);
		int random_value = (rand() % 10                           );
		candidate_factor[random_index] = (random_value + 48);
		
		//..........Ensures candidate factor ends in 1, 3, 7, or 9, and does not begin with 0.
		if(candidate_factor[                                0] == '0') {candidate_factor[                                0] = '1';}
		if(candidate_factor[candidate_factor_digit_length - 1] == '0') {candidate_factor[candidate_factor_digit_length - 1] = '1';}
		if(candidate_factor[candidate_factor_digit_length - 1] == '2') {candidate_factor[candidate_factor_digit_length - 1] = '3';}
		if(candidate_factor[candidate_factor_digit_length - 1] == '4') {candidate_factor[candidate_factor_digit_length - 1] = '7';}
		if(candidate_factor[candidate_factor_digit_length - 1] == '5') {candidate_factor[candidate_factor_digit_length - 1] = '9';}
		if(candidate_factor[candidate_factor_digit_length - 1] == '6') {candidate_factor[candidate_factor_digit_length - 1] = '1';}
		if(candidate_factor[candidate_factor_digit_length - 1] == '8') {candidate_factor[candidate_factor_digit_length - 1] = '3';}
		
		//..........Mod operation.
		mpz_set_str(divisor, candidate_factor, 10);
		mpz_mod(remainder, dividend, divisor);
		
		//..........Stops if remainder is zero.
		int zero = 0;
		mpz_set_si(wanted_remainder, zero);
		int comparison_of_wanted_remainder_with_zero = mpz_cmp(wanted_remainder, remainder);
		if(comparison_of_wanted_remainder_with_zero == 0)
		{	//..........Appends "-FACTOR" to file name.
			path_to_file[path_to_file_null_bookmark     ] = '-';
			path_to_file[path_to_file_null_bookmark +  1] = 'F';
			path_to_file[path_to_file_null_bookmark +  2] = 'A';
			path_to_file[path_to_file_null_bookmark +  3] = 'C';
			path_to_file[path_to_file_null_bookmark +  4] = 'T';
			path_to_file[path_to_file_null_bookmark +  5] = 'O';
			path_to_file[path_to_file_null_bookmark +  6] = 'R';
			
			//..........Writes factor to file.
			out_stream.open(path_to_file);
			for(int a = 0; a < candidate_factor_digit_length; a++) {out_stream.put(candidate_factor[a]);}
			out_stream.close();
			
			//..........Prints factor if 400 digits or less.
			cout << "\n";
			system("date");
			cout << "Factored! Prime saved to file";
			if(candidate_factor_digit_length <= 400)
			{	cout << ":\n\n";
				for(int a = 0; a < candidate_factor_digit_length; a++) {cout << candidate_factor[a];}
			}
			else {cout << ".\n\n";}
			
			return 0;
		}
	}
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
