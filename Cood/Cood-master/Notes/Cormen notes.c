Cormen notes-
Chapter 1:
NP-complete algorithms: for which no efficient algo is known. but their non-existence is also not proved.
eg: Travelling Salesman problem. Given stopping points, find order of them so that min distance is travelled.
sorting- Ranking stuff. Shortest route also requires giving min dist, but it is between 2 diff points & not all points need be touched.
determining best order for multn- *Economy model- order of deals for profit max.
finding convex hull- to get boundaries which contain your pillars.
<Stacks>- very useful for LIFO types- brackets, function calls, but have a certain limit on input

ONLY BEST SOLN REQ- Min/Max profit, a DNA seq be determined exactly & not approxly. 
APPROX REQ- to keep expenses "less than" a limit.

Chap 2:
boolean operators "and" and "or" are short circuiting. i.e. smart savers.
Analyzing algo= finding resources req.

merge sort - Divide & Conquer algo- is. better.
	merging is NOT done by binary search! 
	Its by looping parallely & placing each successive element from there.
	for n elements, merging subroutines is atmost 6n+6nlogn; 
ANALYSIS > by recursion tree method.
		> for each merging of 2 arrays of size m, we req atmost 6m (than 4m+2) operations.
		> at each level j, no of sub-problems doubles & size of array halves, leading to a time indep of j.
		> so T<= 6n*(logn+1); //no of levels

ASYMPTOTIC analysis - Analyzing what happens when N->infinity
		Merge sort is better than insertion sort for large N(>=90). (6n+6nlogn) < (n^2)/2

insertion sort -  arranging Cards. O(n^2);
selection sort - our natural way. 
Bubble sort - swapper O(n^2);






KIM anothers-
The break statement has the following two usages in C++:
	When the break statement is encountered inside a loop, 
	the loop is immediately terminated and program control resumes 
	at the next statement following the loop.
	
	It can be used to terminate a case in the switch statement (covered in the next chapter).
If you are using nested loops, the break statement will stop the execution 
of the innermost loop and start executing the next line of code after the block.

#Sieve of Eratoris : 
is simply 'marking' the composite 'k' to avoid 'k' operations. This is very efficient way to find big primes.
mark the composites in bool array. (so size <= 10^6).