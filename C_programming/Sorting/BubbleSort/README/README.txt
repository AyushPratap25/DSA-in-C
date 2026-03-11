/*
NOTE: var declaration in for loop, ex:
for (int i = 0; ; );
is compatible for C99 but older compiler wont't accept it.
To make it universal declare at the top
int i;
*/

/*
Bubble Sort Mathematical Formulas

Number of passes (iterations):
  P = n - 1

Number of comparisons in pass k (where k = 0, 1, 2, ..., n-2):
  C_k = n - 1 - k

Total number of comparisons for sorting n elements:
  C_total = Σ(k=0 to n-2) (n - 1 - k) = (n × (n - 1)) / 2

Summary:
- Outer loop runs (n - 1) times.
- Inner loop runs (n - 1 - k) times in the k-th pass.
- Total comparisons = n(n - 1) / 2.
*/

//
Initial Array:
| 5 | | 3 | | 8 | | 4 | | 2 |

Pass 1:
Compare |5| and |3| -> Swap!
| 3 | | 5 | | 8 | | 4 | | 2 |

Compare |5| and |8| -> No Swap
| 3 | | 5 | | 8 | | 4 | | 2 |

Compare |8| and |4| -> Swap!
| 3 | | 5 | | 4 | | 8 | | 2 |

Compare |8| and |2| -> Swap!
| 3 | | 5 | | 4 | | 2 | | 8 |  <-- 8 bubbled to right

Pass 2:
Compare |3| and |5| -> No Swap
| 3 | | 5 | | 4 | | 2 | | 8 |

Compare |5| and |4| -> Swap!
| 3 | | 4 | | 5 | | 2 | | 8 |

Compare |5| and |2| -> Swap!
| 3 | | 4 | | 2 | | 5 | | 8 |  <-- 5 bubbled

Pass 3:
Compare |3| and |4| -> No Swap
| 3 | | 4 | | 2 | | 5 | | 8 |

Compare |4| and |2| -> Swap!
| 3 | | 2 | | 4 | | 5 | | 8 |

Pass 4:
Compare |3| and |2| -> Swap!
| 2 | | 3 | | 4 | | 5 | | 8 |  <-- Sorted!
