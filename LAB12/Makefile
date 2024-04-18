part1: p1.cpp
	g++ p1.cpp list.cpp -o part1
part2: p2.cpp 
	g++ p2.cpp list.cpp -o part2
part3: p3.cpp 
	g++ p3.cpp list.cpp -o part3
part4: p4.cpp 
	g++ p4.cpp list.cpp -o part4

############# DON'T TOUCH BELOW ################
run%: part%
	@valgrind ./part$* 2> out; python3 val.py
