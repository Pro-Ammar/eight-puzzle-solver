# eight-puzzle-solver
This a program tries to solve the eight puzzle built in C++/Qt

It is programmed to solve the eight puzzle as an AI problem using A* Algorithm.

The actual cost here is the number of moves from the initial move.
I used a composite heuristic which consists of the number of nodes which are not in their place.
The second one was the number of inversions divided by 2 to make it admissible.
The sum of the two is then divided by two too, for ensuring admissibility.

Note: The number of inversions = count( (a,b) ) such that a and b are nodes but not the same,
and Current_Position(a) < Current_Position(b) and Final_Position(a) > Final_Position(b)

The program can estimate if the puzzle is solvable or not by counting the number of inversions
as it must be an even number. There is a proof for that by analyzing the accepted actions,
as they adds or subtract 2 or 0 for every move, 
so to reach zero inversions the number must be an even one.

I tried to guess some good heuristics and that is what I reached, of course there are a better ones,
but I just tried to solve the full problem without searching for the way 
as I do not want to know if I could implement the solution rather than reaching my own and implementing it.

and finally it worked, Note The GUI is not that good so I may edit it later.

The program sees the sloution as a path consists of moves, each move consists of an 9-permutation of nodes.
each node has its own value and the final position where it should be. The moves also is represented
as a string by listing the values separated by ','. Helping the program to store the visited moves 
and not to visit them again.

So the program choose the path who has the least cost and explore it again and again 
untill that path, which was choosen as it has the least cost, reaches the goal then it terminates and 
make the user able to see the moves and move between them.

Examples of solved puzzles : [ ,1,3,4,2,5,7,8,6] => [1,2,3,4,5,6,7,8, ]

[1,2,3,8, ,4,7,6,5] => [2,8,1, ,4,3,7,6,5]

[2,8,1,4,6,3, ,7,5] => [1,2,3,8, ,4,7,6,5]

Examples of unsolvable puzzles : 

[1,2,3,4,5,6,7,8, ] => [1,2,3,4,5,6,8,7, ]
