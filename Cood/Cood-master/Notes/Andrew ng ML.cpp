Andrew ng ML.cpp

Supervised(Give data with "right" answer) 
-univariate Linear regression = using one variable

Cost (Squared error) function- quantifies the difference between our prediction & the right answer.
=> instead of abs, use sq- Sum.m((h.i - y)^2)/2m;
=> is already sums over all x,it varies with Theta. While h(x) is a fn of x at const Theta.

-multivariate l.r. = multiple features(more parameters with their weightages                                                                                                                                                                                                                                                                                                                                                                                                                                                                ) 
 ;=> convenient to use vector "h(x)=Theta.(dot).X" //later we scale the xi to unskew 0i
 =>h = hypothesis vector. with x0=1 (convention)
cost function becomes= J(0)=1/2m*(sum((hi -yi)^2));

Gradient descent=>
Repeatedly update each 0j := 0j - L*(partial der.)J(00,01...0n); 
this way we reach global min. **L is learning rate (alpha)


Feature scaling=> To scale the 01,02 so that the h(01,02) forms circular contours from elliptical  
*recommended scaling = keep -|xi|~1;
;eg: x1= ~2000 sq feet, x2= ~5 Bedrooms. so this is skewed scale which "makes it longer to find global minimum
- That is because we are geometrically finding distances on the graph!".
then scale them to "x1= (x1-avg(x1))/range(x1)" ;//range(x1)= Max(x1)-Min(x1)
*/ How does gradient descent travel straight in circular contours?
"How many iterations it takes to converge J(0)?"
=> Plot graph in J(0) vs No of iterations & it shall be a decreasing plot. [else you modify the L. Try smaller if they go up. But too small alpha will make it decrese slowly]

+Non linear - Polynomial regression:
simply make features xi= x1^i, so that h will still be linear with xi

Normal equation method: this does not need Scaling/choosing L, as you 
directly compute(solve for) 0i in one step; But takes O(n^3) time to find inverse of (X'X)  
So, it is good for use till n~10000.
"KIM that J is a fn(0) while h is a fn(x)"'

**Non invertible=> The pinv method in Octave will compute what you want, than inv which will error if it was non invertible.
**less eg than feat! => reduce(redundant first(linearly dep)) feat, or use "regularisation";
vs
unsupervised(Only give data, it will cluster it.)



**uSING Octave-
KIM about ~= & xor() and &&, and % is comment.
this also has PS1()
+ sprintf -> DISPLAYS STRING, it supports format strings
+ disp('this also shows');
making a matrix- X=[1 25;43 2;323 23], V=[2 3 4], I=eye(4);
also z= zeros(2,3). ones(3,1), magic(N), rand(3,3), randn(3.1), //negatives;

using a row vector also, you can assign a lot of values to a variable, then plot its histogram with host(w,20)/ no of sticks.
a row vector is like an array,
BUT max(A) gives column wise max of A, for taking by ROW wise, use max(A,1), 

1:15 is range of fifteen. It can be put anywhere like a macro.
1:0.2:2 will give the range with steps of 0.2
A(2,:) gives you access to second row of A.
A([1 3 5],:) gives 1st, 3rd rows of a.
A=[A, 1; 2; 3] //for 3 rowed matrice
C=[A,B]
C=[A;B]
size function tells dimens of matrix size(A,i) guves ith dim
length gives longer dim

**Compute-
to write a function, you need to type it in a fnName.m file. & specify its path, using addpath('C:Users/sai/Desktop/')
in the file, write-
function y= getSQ(x)
y=x^2;
eg2 : function [y1,y2] = funName(arg1,arg2)
y1=arg1+arg2; y2=arg1-arg2;
for i=1:10, A(i)=2^i, end;
while true,
	i=i+1,
	if i==4
	 break;
	end;
end;

**operations-
* = multiply
1/A = inverse,
pinv = pseudoinv, more general.
flipud = flip up down rowwise.
. = elementwise operation, eg A.*B, A.^2 (every elem squared),
1./A = elementwise inverse.
A.+B same as A+B,
more elementwise : A+1, -A, log(A), abs(A), A<3; max(A,B) gives elementwise max between A & B;

**Plotting to get a sense of data-
hold on; will keep the plotter on without clearing it.
plot(x,y,'c') 'c' is color code : 'r','b',etc.
title(''),xlabel(''),ylabel('y'), legend(sin,cos,..) //as many plots are there
print -dpng 'myPlot.png'
subplot(1,3,1);plot(x,y);
figure(2);plot(x,y);
**VISUALIZE : imagesc(A) will give colorified plot showing darker colors for larger values. 
imagesc(A),colorbar,colormap gray;


**Moving data
who -> shows variables in current memory.
load('path') will load a file into memory.
use that loaded file simply using its filename.
whos -> details about all vars & sizes.
save myVars.dat v //v is optional to save a single var.
by default saves in binary format => compressed data 
to save in readable => save hello.txt -ascii