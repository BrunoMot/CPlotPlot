OBJ = main.o SFMLLine.o Axis.o Figure.o
SRC = main.cpp SFMLLine.cpp Axis.cpp Figure.cpp
INC = 

SRCWP = $(addprefix src/, $(SRC))

CXX = g++
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

#all: $(INC) $(OBJ)
#	$(CXX) -o main $(OBJ) $(LDLIBS)

main: $(SRCWP)
	$(CXX) -o $@ $^ $(LDLIBS)

test: src/test.cpp src/SFMLLine.cpp
	$(CXX) -o $@ $^ $(LDLIBS)


clean: 
	$(RM) main $(OBJ)




