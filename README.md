<!--
Attempt factorization of 100-100k-digit semiprimes used in
cryptography. Curated for hands-free distributed effort.
-->



Requirement: GNU Multiple Precision Arithmetic Library.
Just do ```apt install libgmp-dev``` then append "-lgmp" to both compile & build
commands in Geany, or then compile using ```g++ /path_to_this.cpp -lgmp```

<br>
<br>

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/tryRSA/main/Other/Terminal_3efa9701225cdf16a4d3355fe645531f3dcda95d2bc5766d98ef9a5c6235f6d4.png">
</p>

[Auditing in the browser?](https://coliru.stacked-crooked.com/a/ff2f3014f5a4faa1)

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

<br>
<br>

# Closer look at 18-digit semiprime

<p align="center">
  <img src="https://raw.githubusercontent.com/compromise-evident/tryRSA/main/Other/Factorization_theory/Closer_look_at_18-digit_semiprime_840a1c7c2325b815413b269b7635c43a0442b48a6f7eb8ff23e460b7e023dee3.png">
</p>
