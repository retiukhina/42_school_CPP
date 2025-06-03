# Name of the program
NAME = FragTrap
# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

# Source and object files $(SRC_DIR)/newZombie.cpp
SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/ClapTrap.cpp $(SRC_DIR)/ScavTrap.cpp $(SRC_DIR)/FragTrap.cpp $(SRC_DIR)/ClapTrapAttack.cpp $(SRC_DIR)/ScavTrapAttack.cpp
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
