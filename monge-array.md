##Monge Array
_wikipedia:_
An m-by-n matrix is said to be a __Monge array__, for all _i,j,k,l_ such that</br>
  1<=_i_<=_k_<=_m_ and 1<=_j_<=l<=_n_</br>
one obtains</br>
  A[_i,j_] + A[_k,l_] <= A[_i,l_] + A[_k,j_]</br>
So for any two rows and two columns of a Monge array (a 2×2 sub-matrix) the four elements at the intersection 
points have the property that the sum of the upper-left and lower right elements
 (across the main diagonal) is less than or equal to the sum of the lower-left
  and upper-right elements (across the antidiagonal)
  
####e.g.
This matrix is a Monge array:</br>
![img](https://cloud.githubusercontent.com/assets/9131176/9570311/797c74ae-4fba-11e5-9da4-d650d0246257.png)</br>
For example, take the intersection of rows 2 and 4 with columns 1 and 5.</br>
The sum of the upper-left and lower right elements is less than or equal to the sum of the lower-left and 
upper-right elements.
