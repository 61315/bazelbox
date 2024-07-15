# Ceres

```
bazel run //src:helloworld
```

```
INFO: Running command line: bazel-bin/src/helloworld
iter      cost      cost_change  |gradient|   |step|    tr_ratio  tr_radius  ls_iter  iter_time  total_time
   0  4.512500e+01    0.00e+00    9.50e+00   0.00e+00   0.00e+00  1.00e+04        0    4.41e-05    9.20e-05
   1  4.511598e-07    4.51e+01    9.50e-04   9.50e+00   1.00e+00  3.00e+04        1    1.60e-04    3.11e-04
   2  5.012552e-16    4.51e-07    3.17e-08   9.50e-04   1.00e+00  9.00e+04        1    7.39e-05    4.17e-04
Ceres Solver Report: Iterations: 3, Initial cost: 4.512500e+01, Final cost: 5.012552e-16, Termination: CONVERGENCE
x : 0.5 -> 10
```