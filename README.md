<!--
Attempt factorization of 100-100k-digit semiprimes used in cryptography.
-->



Just do ```apt install libgmp-dev``` then append "-lgmp" to both compile & build commands in Geany, or then compile using ```g++ /path_to/ProximitySieve.cpp -lgmp```

<br>
<br>

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/tryRSA/main/Other/Terminal_28e98225f8fb1a15978bbd3db90098b85eb7115d5bd53a10ba22b372f01dfe9e.png">
</p>

[Auditing in the browser?](https://coliru.stacked-crooked.com/a/ed4fcd0c40158487)

<br>
<br>

# Distributed effort

Currently, srand() eats time(0) which is Unix time. Make sure that either,
each instance begins at a unique second of time in relation to time(0),
or simply feed srand() any unique unsigned int. That's a range of 0 to 4,294,967,295.
