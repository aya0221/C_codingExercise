/*
Question 5.

==========a==========

    RTP: P(n): n^3 + 2n = 3m where n and m are positive integers

    Base case: n=1
        LHS:
        RHS:
        Therefore, LHS = RHS.
        Hence, base case P(n=1) holds.

    Inductive Hypothesis: 
        Assume P(k) is true for some k where k = n, then
        k^3 + 2k = 3m

    Inductive Step:
        I will prove P(k+1) is true:
        (k+1)^3 + 2(k+1) = 3m
        LHS:  (k+1)^3 + 2(k+1)
             = (k^3 + 3K^2 + 3k + 1) + 2K + 2
             = 3m + 3K^2 + 3k + 3
             = 3 (m + K^2 + k + 1)
                let m = (m + K^2 + k + 1)
             = 3m
             = RHS
        Therefore, LHS = RHS.
        Hence, P(k+1) is true whenever P(k) is true where k=n.

    Hence, by PMI, statement n^3 + 2n = 3m is true for all positive integer.


==========b==========
    RTP: n = a * b where a and b are both integers.
        for all positive integers n where n >= 2

    Bace case: n=2
        LHS:2
        RHS: 1 * 2 = 2
        Therefore LHS = RHS.
        Hence, base case P(n=1) holds.

    Inductive Hypothesis:
        Assume P(k) is true for some k where k = n, then
        k = a * b

    Inductive step:
        I will prove P(k+1) is true:
        k+1 = (a * b) + 1   (1 is a prime number)
        LHS:  k+1
            = P(k) + 1
            = a * b + 1 using inversive hypothesis
            = RHS
        Therefore LHS = RHS.
        Hence, P(k+1) holds.

    Hence, by PMI, the statement is true for all positive integers >= 2.
*/