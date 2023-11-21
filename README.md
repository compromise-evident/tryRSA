<!--
Attempt factorization of 100-100k-digit semiprimes used in cryptography.
-->



Requirement: GNU Multiple Precision Arithmetic Library.
Just do ```apt install libgmp-dev``` then append "-lgmp" to both compile & build
commands in Geany, or then compile using ```g++ /path_to/tryRSA.cpp -lgmp```

<br>
<br>

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/tryRSA/main/Other/Terminal_28e98225f8fb1a15978bbd3db90098b85eb7115d5bd53a10ba22b372f01dfe9e.png">
</p>

[Auditing in the browser?](https://coliru.stacked-crooked.com/a/ed4fcd0c40158487)

<br>
<br>

# Distributed-effort-friendly

srand() eats RAM garbage + time(0). No instance duplicates effort.

<br>
<br>

# Semiprimes have perfect-secrecy-like nature

Play with [RSA_difficulty_demo.cpp](https://github.com/compromise-evident/tryRSA/blob/main/Other/Factorization_theory/RSA_difficulty_demo.cpp#L33)
as it prints which two numbers multiplied recreate n last digits of your semiprime.
Increase the number of semiprime digits you want recreated. Listed p*q
are the plausible ending digits of the factors.

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/tryRSA/main/Other/Factorization_theory/Terminal_a0f8d87dcaa7faa13a8066d6749b5dfc8758ce90d017e94fc0b52237a5719c1e.png">
</p>
