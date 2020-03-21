# Cpp Challange :
- Find the largest path in Labyrinth
- Given a file descibing walls and holes in a txt file take the file as input
- Output the path length of the largest path and also the order in the 2d array itself
- Used FloodFilling algorithm to accomplish the logic
- Also provide a CMakeList.txt/make file to compile the project

- Instruction to run the Code 
```
# clone the repo
cd JDEAssignments/cppChalange/
cmake
make
cppChallange testCpp
```

Result :
- Input<br>
##.##.#<br>
#..##.#<br>
#.#####<br>
#..####<br>
##.####<br>

- Output<br>
7<br>
##0##.#<br>
#21##.#<br>
#3#####<br>
#45####<br>
##6####<br>
