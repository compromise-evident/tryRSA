Requirement: GNU Multiple Precision Arithmetic Library.
Just do ```apt install libgmp-dev``` then append "-lgmp" to both compile & build
commands in Geany, or then compile using ```g++ /path_to_this.cpp -lgmp```

<br>
<br>

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/tryRSA/main/Other/Terminal_f85d6d0899f04a8861d2a3643c972e5f.png">
</p>

<br>
<br>

# Semiprimes have perfect-secrecy-like nature

Play with [RSA_difficulty_demo.cpp](https://github.com/compromise-evident/tryRSA/blob/main/Other/Factorization_theory/RSA_difficulty_demo.cpp#L33)
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

# The case for cryptanalysis through combinatoric correctness

<p align="center">
  <img src="">
</p>

In combinatorics, this sample image has a name or index
that is somewhere between 1 and 2^n inclusive where n
is the number of total squares. And the index of this
image WITHOUT artifacting can be incomprehensibly distant
from the same image index WITH artifacting.
The same can be said for differences in digit styles,
colors, and legibility boundaries.

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
"It's this idea that any simple picture, made of vertices and segments--
whatever you can draw in this way--that there's a natural connection
between each and every one of those drawings
and an actual equation with coefficients
that are algebraic numbers--and this is so weird."
