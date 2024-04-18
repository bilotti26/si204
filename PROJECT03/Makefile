part1: p1.cpp 
	g++ p1.cpp easycurses.cpp Pos.cpp board.cpp -l ncurses -o part1
part2: 

part3: 
	
part4: 

part5: 

test: test.cpp
	g++ test.cpp easycurses.cpp Pos.cpp board.cpp -l ncurses -o test
################## DON'T TOUCH BELOW ##################
run1: part1
	@./part1
run_%: %
	@test -f $* && echo "$*: Code compiled successfully" 

