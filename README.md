# Mutexes-Vs-Semaphores

An experiment that tests the time performance of mutexes and semaphors for my Parallel Programming class
Language: C

Conclusion taken from many_semaphores

+ * Results:  Mutex results with 1 penguin nodes
 + *                8.987060e-01s
 + *                7.890031e-01s
 + *                8.127439e-01s
 + *           Semophores results with 1 penguin nodes
 + *                1.439553e+01s
 + *                1.432214e+01s
 + *                1.424277e+01s
 + *           Mutex results on lab computer
 + *                8.656139e-01s
 + *                8.284121e-01s
 + *                9.090199e-01s
 + *           Semaphores results on lab computer
 + *                5.774460e+00s
 + *                5.884847e+00s
 + *                5.742924e+00s
 + * Conclusion: If we compare the worse run times for
 + *             all tests, we see that semaphores perform
 + *             worse than mutexes in general. Also, semaphores perform 
 + *             worse on server nodes than on local (lab) computers with 
 + *             drastically longer run times.
