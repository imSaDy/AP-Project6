GPP = g++
GPPFLAGS = -std=c++2a -I./include
SRC_DIR = src
OBJ_DIR = obj
EXES = ./utms.out

SOURCES := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))
 
clean:  all
	rm -rf $(OBJ_DIR)/*.o

all : $(EXES)

$(EXES) : $(OBJECTS)
	$(GPP) $(GPPFLAGS) -o $@ $^ $(LFLAGS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp $(wildcard $(SRC_DIR)/*.h)
	mkdir -p $(OBJ_DIR)
	$(GPP) $(GPPFLAGS) -c $< -o $@ 

