NAME        :=      ex00

CXX         :=      c++
CXXFLAGS    :=      -Wall -Wextra -Werror -std=c++17
INC			:=      -I include

OBJDIR      :=      obj

VPATH       :=      src

SRC         :=      main.cpp

OBJ         :=      $(addprefix $(OBJDIR)/, $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) -o $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re