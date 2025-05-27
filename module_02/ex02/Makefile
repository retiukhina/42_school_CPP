# Name of the program
NAME = fixedpoint

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source and object files
SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/Fixed.cpp $(SRC_DIR)/setRawbits.cpp $(SRC_DIR)/getRawbits.cpp $(SRC_DIR)/toFloat.cpp $(SRC_DIR)/toInt.cpp
OBJ_DIR = build
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Default rule
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Rule to compile .cpp to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

# Rule to clean everything
fclean: clean
	rm -f $(NAME)

# Rule to rebuild everything
re: fclean all

.PHONY: all clean fclean re
