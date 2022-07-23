/*
prove: the nth fibonacci number is given by F(n) = (1+√5)^n - (1-√5)^n / 2^n√5

Base case for n=1 and n=2
RHS = LHS, true for n=1

Inversive Hypothesis
Assume: F(k) = (1+√5)^k - (1-√5)^k / 2^k√5

RTP:    F(k+1) = (1+√5)^k+1 - (1-√5)^k+1 / 2^k+1√5                     RTP: required to prove
LHS = F(k+1)
    = F(k) + F(k-1) by definition of the Fibonacci sequence.
    = (1+√5)^k - (1-√5)^k / 2^k√5  +  (1+√5)^k - (1-√5)^k / 2^k√5

    = 1. combine the deliminator as  2^k+1√5
    = 2. combine two (1+√5) ,and two (1-√5)
    = 3. greatest common factor (make all exponents as k-1)
    = 4. 2+2√5+4 = 1 + 2√5 + 5 = (1+√5)^2
    = 5. (1+√5)^k-1 * (1+√5)^2 - ...
    =    (1+√5)^k
    = RHS
    
    Thus, true for n = k+1 if true for n=k.
    Hence, by PMI, statement is true for all positive integers.        PMI: principle of mathmatical induction


































*/