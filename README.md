Run it: ```apt install g++ geany libgmp-dev```. Open the .cpp in Geany.<br>
Append ```-lgmp``` to Geany's compile & build commands. Hit F9 once. F5 to run.

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/tryRSA/refs/heads/main/Other/Terminal_6678cd93713ea9452261edb38cbc7cff.png">
</p>

<br>
<br>

# Semiprimes have perfect-secrecy-like nature

Play with [RSA_difficulty_demo.cpp](https://github.com/compromise-evident/tryRSA/blob/main/Other/Factorization_theory/RSA_difficulty_demo.cpp#L29)
as it prints which two numbers multiplied recreate n last digits of your semiprime.
Increase the number of semiprime digits you want recreated. Listed p*q
are the plausible ending digits of the factors.

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/tryRSA/main/Other/Factorization_theory/Terminal_6119bb0725fc8e02cae4bdf4578296cb1d0360daa24db8256e32db2042f180d7.png">
</p>

<br>
<br>

# Closer look at 18-digit semiprime

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/tryRSA/main/Other/Factorization_theory/Closer_look_at_18-digit_semiprime_840a1c7c2325b815413b269b7635c43a0442b48a6f7eb8ff23e460b7e023dee3.png">
</p>

<br>
<br>

# Physical semiprime factorization

String length = pq. If string end is at B, and if A & B are integer-apart, then p = distance A to B, q = segment quantity.

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/tryRSA/main/Other/Factorization_theory/String_folding_279cdc202129ed49fb5e4a27af50c18f5a1dc8af793d5d6dff7d3e0d8332155e.png">
</p>

<br>
<br>

## The case for cryptanalysis through combinatoric correctness

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/tryRSA/main/Other/Factorization_theory/Combinatoric_correctness.png">
</p>

In combinatorics, this sample image has a name or index
that is somewhere between 1 and 2^n inclusive where n
is the number of total squares. And the index of this
image WITHOUT artifacting can be incomprehensibly distant
from the same image index WITH artifacting.
The same can be said for differences in digit styles and legibility boundaries.

Are there consistent and scalable relationships between
similar images? Can these relationships help you jump to
nearby similar images and group them together?
If so, how would you manipulate the actual index values?
And most importantly, how quickly can you find this
sample image given only "493" as pixelated above?
What if there's something about the sample correctness
that makes it stand out... Can you find what it is
or prove that it's nothing?

Here's a quote by mathematician Leila Schneps
on Grothendieck's example of Galios theory applied to relationships:
"It's this idea that any simple picture, made of vertices and segments--whatever
you can draw in this way--that there's a natural connection
between each and every one of those drawings
and an actual equation with coefficients
that are algebraic numbers--and this is so weird."

<br>
<br>

# Database compromise through inference

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/tryRSA/main/Other/Factorization_theory/Database_compromise_through_inference.png">
</p>

Dog owners are split by 2 categories of income.
Dog owners earning 200k don't play music,
therefore your target makes 200k--a detail meant to sit
confidential on the compiling server.

Suppose you discover that some target of yours participated
in this particular study. So far, you know they own a dog
and don't play music, but you wish to know how much money they're making.
In this example, you compromised the database and got what you wanted to know,
by asking only 5 questions. This is possible even if
the numbers are imperfect where you must then infer from
quite a few new questions to ensure perfect sums.
And there are heavily-researched, applied (US army,)
and theoretical formulas which determine compromise for n questions,
however, by fudging results, this can be made nearly impossible.

The point is, you can extend this attack and try extracting
what emerges from any other database such as a range of primes
who failed to factor 1 or more semiprimes.
Might 1 tested prime cluster say something about another untested?
Can you prove it's impossible for whatever function in question?
And most importantly, are extensions of this attack bound
to any particular functions--extensions dependent on function particularities?

<br>
<br>

# Semiprimes appear only twice in their curve

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/tryRSA/main/Other/Factorization_theory/The_curve.png">
</p>

<br>
<br>

# Join the challenge

https://en.wikipedia.org/wiki/RSA_Factoring_Challenge

"The RSA numbers were generated on a computer with no network connection of any kind.
The computer's hard drive was subsequently destroyed so that no record would exist,
anywhere, of the solution to the factoring challenge."
