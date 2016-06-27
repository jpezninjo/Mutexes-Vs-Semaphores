## Mutexes-Vs-Semaphores

An experiment that tests the time performance of mutexes and semaphors for my Parallel Programming class
Language: C

Conclusion taken from many_semaphores

Results:  


|Mutex results with 1 penguin nodes|
|:---------------------------------------|
|8.987060e-01s|
|7.890031e-01s|
|8.127439e-01s|


|Semophores results with 1 penguin nodes|
|:---------------------------------------|
|1.439553e+01s|
|1.432214e+01s|
|1.424277e+01s|


|Mutex results on lab computer|
|:---------------------------------------|
|8.656139e-01s|
|8.284121e-01s|
|9.090199e-01s|


|Semaphores results on lab computer|
|:---------------------------------------|
|5.774460e+00s|
|5.884847e+00s|
|5.742924e+00s|
 
Conclusion: If we compare the worse run times for
 all tests, we see that semaphores perform
          worse than mutexes in general. Also, semaphores perform 
      worse on server nodes than on local (lab) computers with 
 + *             drastically longer run times.



##Block Vs Cyclic Distribution

An experiment that tests the time performance of cyclic distribution and block distribution among pthreads for my Parallel Programming class
Language: C


Conclusion taken from pth_mat_vect_rand.c

 *    Number of threads: 4
block-distribution followed by  cyclic-distribution

|8,000,000 x 8 |8,000 x 8,000 |8 x 8,000,000 |
|--------------|:--------------:|------------|
|1.203341e-01 s|1.089160e-01 s|2.285080e-01 s|
|1.165550e-01 s|1.126268e-01 s|2.270670e-01 s|
|--------------|--------------|--------------|
|1.356111e-01 s|6.590509e-02 s|2.043180e-01 s|
|9.272599e-02 s|6.575704e-02 s|2.283041e-01 s|


   Results:
 Overrall it looks like pthreads struggle with block-distribution. Cylic-
    distribution has slightly faster run-times.




##Scaling of Block-Row distribution

An experiment that tests the scalability of block-row distribution using **very large** matrixes and MPI on USF's Penguin cluster node network for my Parallel Programming class
Language: C

Conclusion taken from parallel_mat_vect.c 

 * Notes:  
 *     1.  Local storage for A, x, and y is dynamically allocated.
 *     2.  Number of processes (p) should evenly divide both m and n.
 *     3.  Omg I finished and everyone else in the lab rn can't even do penguin cluster
 *     4.  The results below are for one test of each case and do no represent
                true timings for testing an x by x matrix with n processors
 *
 *     TEST RESULTS
 *     Processors   500x500     1000x1000       2000x2000
 *          1       0.003480    0.013639       0.053689
 *          2       0.001866    0.006997        0.027409    
 *          4       0.001060    0.003797        0.013929    
