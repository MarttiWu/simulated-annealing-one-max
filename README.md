# Simulated Annealing Algorithm



# One-max problem

The one-max problem is a basic problem.

Given a bit string of  0's and 1's, the aim is to find a bit string which contains the most 1's.

# Usage

Open terminal

    make
    
1. Run directly in the terminal by typing the following:

        #./main [algo] [runs] [iter] [bits] [filename]
        ./main sa 30 100 100 ""
    
2. Or if you want to run multiple times, just by opening the "search.sh" and add whatever you want and run by typing


        ./search.sh
    in the terminal.
    
# Customize

You can change the iteration block by modifying 

        const int block=5;
in "execute.hpp".

# Results

![alt text]()

