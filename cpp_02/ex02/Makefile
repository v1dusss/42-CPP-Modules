NAME        :=      ex02

CXX         :=      c++
CXXFLAGS    :=      -Wall -Wextra -Werror -std=c++17

OBJDIR      :=      obj

SRC         :=      main.cpp \
					Fixed.cpp
OBJ         :=      $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re