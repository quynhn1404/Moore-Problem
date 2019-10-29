# Moore-Problem
Gordon Moore is credited with noticing a trend in Hardware. Simply put he theorized that the 
efficiency of computer designs would double roughly every other year. 
Mordon G. Nautareal, professor, noticed that this trend varies depending on hardware component. 
Mordon would like to grade his class as quickly as possible. The number of students Mordon can grade
per year is dependent on how many years he waits to purchase his components. If Mordon waits n 
(potentially floating point) years to grade k students, then the amount of years to grades to grade the 
students is 

        **k/H^sqrt(n)**

where H is a constant determined by the component Mordon is purchasing.
## Example
Suppose Mordon has 20 students, and H is 4. By waiting 1 year Mordon can grade the students in 6 
years total. Mordon will not grade in the first year. After the first year Mordon will grade 4 students per
year taking exactly 5 years to finish. The answer is 6 because of the 1 waiting year and the 5 grading years.
Mordon would like to know, if he uses only one machine that he purchases once, how many years does 
it take to grade the students.
Mordon will give you a Hardware factor and a number of students, you need to compute the least 
number of years to grade all the students. 
## Input Specification
The input will begin with a single positive integer, t (t < 10^5), representing the number of cases. Each 
case will contain exactly two values. The first value will be a positive integer, 
k (k < 10^9), representing how many students Mordon has. The second value will be a real value, H (H < 10^9), representing the 
hardware factor for the given component
## Output
For each case output the minimum number of years needed to grade all the students on its own line. 
The output will be considered correct if it is within 10^-5 of the correct answer (absolute or relative).
