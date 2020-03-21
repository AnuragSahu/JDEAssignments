# Programming tests @ JDE Robots
### This Test has in 3 parts
1. Academy Challange
2. Cpp Challange
3. Python Challange

Summary and results for each challange :
1. Academy Challange: 
- Install JDE Robot
- Install all the related dependencies like gazebo, ros.
- Launch one of the Exercises locally ob our machine.
- Capture the Screen and provide the proof of work.

Result : <a href="https://youtu.be/80YIa4Gwtog">YouTube Link</a><br>
 ![Loading Screenshot](/academyChallange/ss.png)
(*Ignore the Red line this is because screen buffer problem)

2. Cpp Challange :
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

3. Python Challange :

Conway's Game of Life is all about simulating real life rules on some random arrangement of cells in a given environment. The rules are as follows.

    Any live cell with fewer than two live neighbours dies, as if caused by underpopulation
    Any live cell with two or three live neighbours lives on to the next generation
    Any live cell with more than three live neighbours dies, as if by overpopulation
    Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction
- Implement GameOfLife as a python module
- have the configurations saved in a config.json file

- Instructions to run the code 
```
python main.py
```

