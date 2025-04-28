# Name of the program
NAME = megaphone

# Compiler and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Source and object files
SRC = megaphone.cpp
OBJ_DIR = build
OBJ = $(OBJ_DIR)/$(SRC:.cpp=.o)

# Default rule
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Rule to compile .cpp to .o
$(OBJ_DIR)/%.o: %.cpp
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
