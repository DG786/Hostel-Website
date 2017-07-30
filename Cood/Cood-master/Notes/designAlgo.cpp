designAlgo.cpp
Doing multiplication faster-
using carry= O(n^2). can we do better? Yes! break it into left&right half of digits i.e.
X=10^n/2*a+b,Y=10^n/2*c+d; so that X*Y = 10^nac+10^n/2(ad+bc)+bd; & solve this recursively (10^n means append n zeros)! 

Counting inversions of an array-
Brute force= O(n^2);
Can we do better?
Yes. Follow the way of merge sort (Divide & Conquer & Combine);

What is Piggy Back-> Copying already established algo such as merge sort
 make of recursive calls. (Sort the array along with Counting Inversions)
=>Coz this sorting is cheap & it is helping in Combine step! 
=>cheap means it will only cost a const times the time we are aiming(nlogn)
**The thing here is, 'merging' step involves comparing the exact numbers req to count split inv 
(only when 2 subarrs are sorted).
	
When a number from other array is copied to it before the first array, it means other one was lesser than first
i.e. The remaining terms from first will show split inversions(as it is sorted). 
[How to count without merging further?!]

COol terms:
Strassen's algo- completely non-trivial, & fastens a fundamental problem in computers= Matrix multiplication(req lot of times).
we see that min time req will be atleast(not worst case) O(n^2), (T(n) = omega(n^2) ).
Matrix Multn:
brute force= O(n^3); n is Matrix size,  it shall be input size i.e. n^2
'Divide & Conquer paradigm:' //paradigm is thinking this way
make smaller matrices(how?)= That's the cool thing!
0. split matrice into 4 quadrants, their multn is just like normal.
1. recursively compute 8 necessary products O(n^2). [actually linear in no of entries.];
2. combine this product.
Above this also takes O(n^3), so its of no difference

So, Strassen's algorithm => Cleverly chosen products for speeding up Matrix multn. 

Like in Gauss' trick, there are 3 recursive calls than 4. 
Reducing recursive calls helps so much(25% for n. more for n^2)!
strassen : 7 Matrices using the quadrants.
P1: A(F-H)
P2: (A+B)H
P3: (C+D)E
P4: A(F-H)
P5: (A+D)(E+H)
P6: (B-D)(G+H)
P7: (A-C)(E+F)


Closest pair problem : Finding two points which are closest to each other than rest of the given set of points.
Its a very cool Divide & Conquer algo.
First mark the Obv algo- brute force one (get all distances, remember the min. For n points, 
	it calcs nC2 distances(which takes time indep of n) so its O(n2);
**See that it 'seems' we 'fundamentally' have to calc all the distances.But admit that 
in counting the inversions, we used sorting to help this out(Piggy back)! So there are these ways to think upon.->
	Can we do better? Yes!! /* Just see that we can divide prob into closest L,R & split pair.*/

*/Getting close to nlogn will require Piggyback to merge sort mostly.
See that in the 1-D version, where n different points are shown, sorting + linear scan gives nlogn ! while brute still reqs nC2.
Now in 2D version, see that sorting copies of the point wrt X coords & Y coords will not affect our O(nlogn) target.
So lets have Px & Py, the sorted coord pairs.
Then Divide them into halves Q & R of Px by X coords. then further into Qx Qy & Rx Ry sorted by their X & Y. (P =->(Px -/> (Q=-> Qx Qy) R..) Py..)
Now, find closest pair recursively in left Half Q & right half R.
so that ClosestPair(Q) & ClosestPair(R) & ClosestSplitPair(P) will ALWAYS give us the ans.
for split pair, form the middle vertical line at P[n/2] with delta range.
	then Sy= Py's within delta range will contain our pair (filtered)
	then only check for 7 points(proved by rect boxes of delta/2).
	[**That is where we make use of sorted array to run it in n time instead of n^2].


TIPS:
#In the Divide step, try to see if your array can be divided into halves & solved recursively. Then see how these 
two solved results can be used to produce output.( takes some time to figure out!)  .

*/ Master Theorem- Blackbox with a format as input & time growth as output of Divide & Conquer stuff,
*/ Master Method shall click you in the formula : O(n^d logn | n^d (faster when a<b^d) | n^(log.b.(a)(base is b));
->requires the subproblems to be of equal size. For (Linear time selection )unbalanced sizes, diff method req.
T(n)=max no of operations req;
"Recurrence format": Tn <= aT(n/b) + O(n^d);
a=no of recursive calls
b=input shrinking format
d=order of time for Combine step. 
'The Master Method' gives : T(n)=O(n^d * logn) if a=b^d,O(n^d * 1) if a<b^d, O(n^logb(a)) if a>b^d,
write the base case time. 
in base case- T(1)=constant(as one digit multn).
in halved case: n>1: T(n)<=4T(n/2) + O(n);
**using Gauss' trick, we can reduce it to 3 Calls per time.    
so T(n)<=3T(n/2) + O(n); ' Lets see how this affects the time taken
(proving merge sort takes nlogn)
Merge sort- T(n)<=2T(n/2) + O(n);  will show nlogn time.
**Strassen's : a=7, b=2 (as input size is being deterr by n & not n^2)'
*/PROOF OF MASTER - click r=a/b^d
uses 3 diff Recurrence trees. KIM that in Recurrence trees, the sum at level 2 may not be equal to n at level 1.		
see that Work at level j will be simply a^j*(n/b^j)^d => c*n^d*(a/b^d)^j
a = rate of subproblem growth.
b^d = denotes the factor work shrinks by per subproblem O(n^d) goes into O((n/b)^d) i.e. shrinks by b*d
If both above rates are equal => same work c*n^d at each level j. Which gives n^d * logm
If less work each level (b^d>a)=> r<1, so (1/1-r(a constant))*n^d => O(n^d)
If more work each level(more subprobs a>b^d) => r^k (the work at leaves dominates => no of leaves * work at leaves)
(the last term dominates/bounds the sum) the last term is at j=log.b.n which shall simplify stuff to O(a^log.b.n)
 = which is equal to O(n^log.b.a);


*/GRAPH DOS, randomised algos, contraction algos
 */useful in maps- road networks-shortest route, Internet (V= Page,directed E= hyperlink), Social sites, prescedence constraints (path considering One-Ways).
 terms: vertices(V, aka nodes), edges (E, a pair of Vs : can be directe d, can be parallel if join same 2 points), cut= non empty partition of set V, crossing edges (directed counts only from left to right)
 		connected graph=> can reach from any pts A to B via atleast 1 route.
 Minimum cut problem (MinCut value) - Minimum no of edges which have to be cut thru for making a "cut". It helps in finding weak spots(easy disrupt) in network. Finding common interests,etc in social networks. & weakly connected features,
 image segmentations(the magic wand(using edge weights))
>Degree of vartex = no of edges passing thru it.
>Size of graph : n Vertices & m Edges => size=m+n ?!
>Min Cuts : k denotes min degree of vertices.
	k<= 2m/n (since Sum(degree(V)) = 2m & each degree >= k.) 
>sparse graphs= less edges m closer to Omega(n) & dense graphs => m is O(n^2).
>Adjacency matrix = A 0-1 nxn matrix, Aij is 1 when there is edge between pts Pi & Pj.
>Adjacency list = array of vertices & array of edges, which are cross referenced toeach other. each edge points to its end points. each vertex points to its edges.
	Useful in graph search.

rdm Contraction algo-> by Karger.
=> contract a rdm edge, until 2 pts left. then make 2 grps- points merged in A, & pts in B. Then make a cut.
*/ This algo doesn't work always! But it doesn't work iff it "contracts a Crossing edge".
P[S1]=k/m <=2/n. P[S2]=k/(remaining edges = m-1 - self loops) [but rem edges >= k*(n-1)/2 or k/rem edges <= 2/(n-1)]

*/ success Probablity comes out to be 2/(n)(n-1). STILL IT IS MUCH BETTER THAN Brute method (2^n) [picking random cut]
*/ BUT- this algo is quite fast(n-2 iterations) i.e. cheap. (fail fast). so we can repeat it easily at low cost.
Lets make success probab high by Repeated trials : 

Probablity Review : Sample space Strassen, random variable(function of variable outcomes), event(= subset of S), expectation of an event, lin. exp.
for a random split, giving a 25-75 or better split is at 1/2 probab.
expectation E(X) = Sum(Xi.Pi. is 'weighted avg of all outcomes of var X'
Lin Exp of event E = E[Sum(Xj)] = Sum(E[Xj]); //proof is easy by expanding the sums. seeing that P(i) of ith outcome is indep of variables Xj

Load balancing : assigning n processes to n servers.
=> if we randomly allot the processes, a server might get multiple processes at a time, but on avg still it will have 1 process to handle.
	Sample space = n^n ways of assigning processes. each equally likely
=> To find no of processes assigned on a server, calc E[processes assigned on 1st server];
	 we can use concept of Lin Exp => define variables Xj=(jth process assigned to 1st server)?(1):(0)
	 then E[Y]=E[Sum(Xj)]=Sum(E[Xj]); 

Conditional Probablity -
*/ KIM :P(A given B)=P(A & B)/P(B) [as sample space reduced to B]
Independence of events :
*/ KIM : Intuition of 2 vars being indep are OFTEN WRONG.
If they are independent by defination, then it'll go OK.
But if there is any slight doubt, then you shall check by formula : P(X&Y)=P(X)*P(Y).'

Independence of rdm variables :
two rdm vars A & B are said indep <=> events P[A=a] & P[B=b] are indep for all a,b <=> P[A=a&B=b] = P(A=a)*P(B=b).
Claim: if A,B are indep, E[A*B]=E[A]*E[B];

*/ ANALYSIS OF QUICK SORT : Definitely a "greatest hit" algo. Beautiful analysis-
*/ It works 'In-place' as opposed to merge sort. It does not merge.
Hoare Tony received highest honour in CSE-  ACM turn* award
Steps : 
1.Choose a pivot.Partition the array around pivot. [PARTITIONING INVOLVES Repeated Swaps for rearranging < & > nums.]
2.Recurse on part b4 & after.
** Involves no combine work !!
Runtime depends on which pivot point gets chosen.

We use Induction to prove correctness of Quicksort.
P(1) is true, if P(k) true for ALL k<n, P(n) is true.

How to choose pivots for good avg performance?
	BIG IDEA : RANDOM pivots !
remember- Probablity of getting a 25-75 split on random choice is 1/2  (proved by lin. expectation/recursion tree)!

using Lin Exp in proof of Quicksort-
Looking at the defination (sum of exp= exp of sum), we see that Lin of Exp is usable when we require exp of a rdm variable "which can be expressed as a sum of simpler rdm vars".
so C(n)=Sum(Xij) is perfect for this.
*/This is general decomposition principle. 1] Find rdm var that u care about,then 2] divide itin\\ in sums of simpler. 4] apply lkn exp

Quicksort Theorem- for every input array of length n, avg running time of QS is O(nlogn)
Sample space of all psble outcomes from rdm pivots. 
Running time deps only on no of comparision
C(s)= No of comparisions in two input elements given those pivot points. E[C]=The calculation of exp (avg value) of "no of comparisions between two input elements"
We get that E[C]=Sum(Pr(Xij is 1))
Pr(Xij is 1) = 2/(j-i+1)

*/The selection problem - Finding the Zi, the ith order statistic. [Will help finding Z(n/2) = the median for QS]
ith smallest number in the array.
Brute force : Pick a number from start, partition around it,(stop if no's less than it cross i+1). keep searching till get Zi.
This gives O(n^2) time. [(n-1)*n] .
Well, if this problem is really reduced to sorting the array. Then fastest is the nlogn soln => apply merge sort, return ith element.
Can we do better? YES!'
LINEAR SOLN => Do the same : partition around, but then 'Deterministically choose' which part(left or right) to recurse on.
& randomize the choice of pivot[which must take O(1 or n) time ?!].

*/Analysis of Randomized Selection (Rselect- choose rdm pivot, partition to find i of this pivot, recurse in appropriate partition.)
define phase(j) of current array size between (3/4)^(j+1) & (3/4)^j;['3/4 is chosen for using the split idea below']. And call Xj= number of recursive calls in phase j.
above defn allows us to distinguish each operation & find an upper bound on time.
Finding Xj in a phase j = Analogy with coin flipping i.e
1. If choosing a pivot giving 25-75 split or better, the phase will end (as new sub array at most 75% of old length).
	getting this split is analogus to getting a heads(50%). No of times to repeat to get this split will be Xj.
2. E[Xj]=E[No of times to flip coin to get heads]; E[n]=1+1/2(E[n]). =>E[Xj]=2.
3. T(n) <= E[cn*(Sum(3/4^j*Xj))] = cn*Sum(3/4^j*E[Xj]) = 8cn = O(n) for Randomized Selection.
*/The above is used in QS, to get best pivot = median.

Deterministic Selection (DSelect)=> Is at most & avg O(n), but its got bigger constants of O(n) & not inplace.
Step 1: make groups of 5 each. Sort each using merge sort, == CONSTANT TIME !
Step 2: join them into a new array of n/5. recursively find medians of their medians(3rd element in each grp)
Step 3:after getting the median, partition around it & find just like in Rselect.

*/ANALYSIS of DSelect.
T(n)<= T(n/5)+cn+T(?)
for the '?' use the following lemma -
upshot - can replace ? by 7/10n
let k=n/5 = # of groups
if Xi = ith smallest of k middle elems.
then for Xk/2 we get atleast 30-70 split!
proof is by making a grid of 5 rows & n/5 cols. Then arranging (in mind) columns in order to get Xk/2.
Then see that 3/5 of 50% (left down) is less than Xk/2(the median of medians).
also the same for larger than Xk/2 element

*/Upper bound on Comparision based sorting algos = nlogn prrof-
out of n! permutations, one permutation is correct.
Let k number of comparisions give the sorted array.
Pigeon Hole principle here- pigeons = n! < holes = 2^k i.e. each permutation shall have a UNIQUE number & order of comparisions.
& so 2^k >= n! >= (n/2)^(n/2)

*/ Bucket sort [uniformly (not randomly) distributed array divided in n bukets of size 1/n. Each bucket has 1-2 tiny number of elements to be sorted.] = O(n)
*/ Count sort 
*/ Radix sort = sort by 'nth bit' using 
