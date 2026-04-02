# PUSH SWAP

- assuming argv is a space-separated list of integer values (using ft_split + ft_atoi)
- stacks are doubly-linked lists, with refs to top and bottom

## method

check if it's ordered _beyond_ the edges too, accept looping order (e.g. 1 2 3 4 is the same as 3 4 1 2).

This means first two pushes to b are always in order, and the third push can be put in order with a simple swap.

From there on, rotate & insert with the following rules:
- check how many rotations to drop a->top in the right place (normal and reverse) -> distance_top, distance_bottom.
- if normal 

7 2 
1 3 6 9