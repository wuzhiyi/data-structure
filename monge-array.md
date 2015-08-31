##Monge Array
_wikipedia:_
An m-by-n matrix is said to be a __Monge array__, for all _i,j,k,l_ such that
  1<=_i_<=_k_<=_m_ and 1<=_j_<=l<=_n_
one obtains
  A[_i,j_] + A[_k,l_] <= A[_i,l_] + A[_k,j_]
So for any two rows and two columns of a Monge array (a 2×2 sub-matrix) the four elements at the intersection 
points have the property that the sum of the upper-left and lower right elements
 (across the main diagonal) is less than or equal to the sum of the lower-left
  and upper-right elements (across the antidiagonal)
  
####e.g.
This matrix is a Monge array:

The sum of the upper-left and lower right elements is less than or equal to the sum of the lower-left and 
upper-right elements.
