# Name of the program
NAME = Bureaucrat

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wreorder -std=c++98

# Source and object files
SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp \
	$(SRC_DIR)/Bureaucrat.cpp \
	$(SRC_DIR)/Form.cpp	

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

test: $(NAME)
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re
