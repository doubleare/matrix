NAME = s21_matrix_oop.a

LIST = s21_matrix.cc s21_metods.cc peregruzka.cc

UNIT = unit

OBJECT = $(patsubst %.cc,%.o, $(LIST))

FLAGS = -std=c++17 -Wall -Wextra -Werror

all : $(NAME)
	@make clean

$(NAME) : $(OBJECT)
	@ar rc $(NAME) $?
	@ranlib $(NAME)
%.o : %.cc
	@g++ $(FLAGS) -c $< -o $@

clean : 
	@rm -f $(OBJECT) $(UNIT)

test : all
	@g++ $(FLAGS) $(UNIT).cc -L. $(NAME) -lgtest -o $(UNIT)
	./$(UNIT)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

clang:
	@cp ../materials/linters/.clang-format .clang-format
	@clang-format -i *.cc *.h
	clang-format -n *.cc *.h
	@rm .clang-format

leaks:
	CK_FORK=no leaks --atExit -- ./$(UNIT)
