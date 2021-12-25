Cellular Automata
=============


Contents
--------

- The function named "get_line_sum" takes a string representing a line of CA and return an int that is the sum of all the CA digits.
- The function named "get_next_state" returns a char and takes two strings. The first string represents a neighborhood of a cell (always length 3). The second parameter is a multiline string like the following:<br />
<br />
001 -> 2 <br />
010 -> 1 <br />
100 -> 3 <br />
002 -> 1 <br />
<br />
- If the neighborhood is "001" the result of this function is a '2'. A neighborhood of "100" returns a '3'.
- An unspecified neighborhood (like "111") returns the default state of '0'.
- The function named "update_line", takes two string parameters, but returns nothing. The first parameter is a string denoting a line/row of cells, the second parameter is a multiline string of rules (see the previous function). Instead of returning a newline, the first parameter is  altered to represent updating each cell for the next generation.
- The function named "run_cellular_automata" takes a multiline string of rules (see previous), an int denoting the number of iterations/generations to update the CA, and a string representing the starting state of the line.
- This function "run_cellular_automata" returns a multiline string with a line for each update (and the sum of the digits).
- The main function reads in from standard in a multiline string denoting rules, a period on its own line denotes the end of the rules, then an int denoting the number of lines of output, then a string denoting the starting line. It outputs the result from run_cellular_automata.
