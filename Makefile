NAME	=	philo
FLAG	=	-Wall -Wextra -Werror# -pthread -fsanitize=thread -g

SRC	=	./src/checker/check_death.c \
		./src/checker/checker.c \
		./src/free/free_everything.c \
		./src/ft_output/ft_message.c \
		./src/get_time/get_time.c \
		./src/libft/ft_atoi.c \
		./src/main/eat.c \
		./src/main/main.c \
		./src/sets/set_philo.c \
		./src/sets/set_table.c


all: $(NAME)

$(NAME):
	@gcc $(FLAG) $(SRC) -o $(NAME)
	@rm -rf philo.dSYM
	@printf "\n\033[92m   Downloading... \033[0m\n  "
	@printf "\033[92m █"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "\033[0m\n\n"
	@echo "   GitHub    ~>  \033[4;1;34menverbey\033[0m"
	@echo "   42 Intra  ~>  \033[4;1;34menvyilma\033[0m \n"
clean:
	@rm -rf $(OBJ)
	@printf "\n\033[91m   Deleting... \033[0m\n  "
	@printf "\033[91m █"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "█"
	@sleep 0.01
	@printf "\033[0m\n\n"
#@echo "\n \033[91m   ->files deleted by AVCI<-\033[91m\n "

line:
	@printf "ᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓᚓ\n"

fclean: clean
	@rm -rf $(NAME)

char = 127

re: fclean line all

.PHONY: all clean fclean re