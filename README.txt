---------------------------------------------------------------------------------------------------------
------------------------------------- OOP2 Ex01 - Sets Calculator ---------------------------------------
---------------------------------------------------------------------------------------------------------
------------------------------------------- Students and IDs -------------------------------------------- 
-------- Samah Rajabi (student number: 211558556) & Saja Abu Maizar (student number: 208072371) ---------
---------------------------------------------------------------------------------------------------------
----------------------------------------  General Description  ------------------------------------------
---------------------------------------------------------------------------------------------------------
The program "Sets calculator" preforms mathmatical operations on sets.
It runs in the terminal where, in a loop, it recieves input from the user and calculates and displays
the results of the calculation.
It calculates the results of a requested operation on a group of sets of integers, it can preform Union,
intersection or difference between two sets.
The user can also create more complex operations and add them to the calculator and then request
a calculation of their operation on certain sets.
In addition to the operation, the program recieves from the user sets of numbers where the first number
of each set represents the size of the set and the rest of the numbers are the members.
It turns the input into an appropriate set by removing duplicates, and saves the sets temporary
in order to preform the calculation, finally it prints the result in the terminal and waits for a new
request. The user can choose to exit the calculator by choosing the "operation" exit. 
---------------------------------------------------------------------------------------------------------
------------------------------------------------- Design ------------------------------------------------
---------------------------------------------------------------------------------------------------------
In the main, a controller object is built, it calls for its public function run() that manages the
calculator in a while loop. Each iteration, the controller prints the updated list of operations to
the terminal and waits for an input, it checks the user's input then calls for one of the operations
accordingly. The controller has private members of the classes: "Operator", "Union", "Difference",
and more operations so it approches the operations' functions via its private members.
Reading input for the operations from the terminal, such as reading the integers to create a set,
is also done by the controller. Mainly, the i\o commands are done by the controller while 
the calculations (the evaluation) and memory allocation are done by the "Operation".
Calculating the result of an "eval" action is done by a recursive function that recieves
a string (the mathmatical operation). For each iteration, the function counts the number of left brackets
compared to the right brackets in order to detect sub-strings, for the string ((AUB) * (A^B)), the right
sub-strings (AUB) is calculated first, secondly, the left sub-strings (A^B), then finally, the function
returns the result of the calculation ((AUB) * (A^B)).
---------------------------------------------------------------------------------------------------------
--------------------------------------------- List of Files ---------------------------------------------
---------------------------------------------------------------------------------------------------------
Source files:-
--------------
 ● main.cpp: starts the calculator by creating a Controller object and calling for Controller.run().
 ● Controller.cpp: runs the calcolator in a loop, manages the i/o operations, calls for funtions of 
   the "Action" class in order to preform the calculations.
 ● Action.cpp: includes functions that preform the calculations or allocate memory for new sets.
 ● Set.cpp: creates a set by recieving a vector of integers. Preforms operator[] and operator<< on sets.
 ● Operator.cpp: includes the functions .
 ● Union.cpp: includes the function Union.
 ● Intersuction.cpp: includes the function Intersuction.
 ● Difference.cpp: includes the function Difference.
 ● Production.cpp: includes the function Production.
 ● Composite.cpp: includes the function Composite.

Headers:-
---------
 ● Set.h: contains the class Set and its functions.
 ● Action.h: contains the class Action.
 ● Controller.h: contains the class Controller. 
 ● Operator.h: contains the class Operator.
 ● Union.h: contains the class Union.
 ● Intersuction.h: contains the class Intersuction.
 ● Difference.h: contains the class Difference.
 ● Production.h: contains the class Production.
 ● Composite.h: contains the class Composite.
 
Resources:
----------
Help.txt: contains the content of the "Action" help.
---------------------------------------------------------------------------------------------------------
-------------------------------------------- Data Structures --------------------------------------------
---------------------------------------------------------------------------------------------------------
Classes:
--------
 ● Set: creates a set by recieving a vector of integers. Preforms operator[] and operator<< on sets.
 ● Controller: runs the calcolator in a loop, manages the i/o operations, has a class Action private 
   member, it calls for funtions of the Action class in order to preform the calculations.
 ● Operator: includes functions that preform memory allocation or mathmatical calculations.
 ● Action: An abstract class. Has offsprings: Union, Difference, ...
 ● Union: inherates from Action.
 ● Production: inherates from Action.
 ● Intersection: inherates from Action.
 ● Difference: inherates from Action.
 ● Composite: inherates from Action.

Vectors:
--------
A vector that stores the original opirations of the calculator and the operstions that the user creates.
A vactor that stores the number of sets that are needed to preform each operation.
More temporary vectors are used to store data while preforming a calculation.
Unique ptrs:
------------
Sets are stored in a vector of unique pointers, where each cell points at set.
---------------------------------------------------------------------------------------------------------
------------------------------------------ Noteable Algorithms ------------------------------------------
---------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------
---------------------------------------------- Known Bugs -----------------------------------------------
---------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------
------------------------------------------- Additional Notes --------------------------------------------
---------------------------------------------------------------------------------------------------------
