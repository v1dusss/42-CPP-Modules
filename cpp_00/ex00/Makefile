# Variables
NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Rules
all: $(NAME)

$(NAME): megaphone.cpp
	$(CXX) $(CXXFLAGS) -o $(NAME) megaphone.cpp

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all
