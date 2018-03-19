# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rnugroho <rnugroho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/01 20:07:00 by rnugroho          #+#    #+#              #
#    Updated: 2018/03/18 15:43:37 by rnugroho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME:= lem-in
FILES:= main \
		options \
		parsing \
		data_processing \
		validation_1 validation_2 \
		pathfinding_1 pathfinding_2 \
		node_route_manager \
		map_visualizer_1 map_visualizer_2 \
		utilities_1 utilities_2 utilities_3 utilities_4 \
		free

# ----- Libft ------
LFTDIR:=./libft
# ==================

# ------------------
COMPILER:=clang
SRCPATH:=src/
HDRPATH:=include/
CCHPATH:=obj/
IFLAGS:=-I $(HDRPATH) -I $(LFTDIR)/include
LFLAGS:=-L $(LFTDIR) -lft
CFLAGS:=-Wall -Wextra $(IFLAGS)
# ==================

# ----- Colors -----
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
CYAN:="\033[1;35m"
PURPLE:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"
# ==================

# ------ Auto ------
SRC:=$(addprefix $(SRCPATH),$(addsuffix .c,$(FILES)))
OBJ:=$(addprefix $(CCHPATH),$(addsuffix .o,$(FILES)))
# ==================
CCHF:=.cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@cd $(LFTDIR) && $(MAKE)
	@echo $(CYAN) " - Compiling $@" $(RED)
	@$(COMPILER) $(CFLAGS) $(SRC) $(LFLAGS) -o $(NAME)
	@echo $(GREEN) " - OK" $(EOC)

$(CCHPATH)%.o: $(SRCPATH)%.c | $(CCHF)
	@echo $(PURPLE) " - Compiling $< into $@" $(EOC)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

%.c:
	@echo $(RED)"Missing file : $@" $(EOC)

$(CCHF):
	@mkdir $(CCHPATH)
	@touch $(CCHF)

clean:
	@rm -rf $(CCHPATH)
	@rm -f $(CCHF)
	@cd $(LFTDIR) && $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM/
	@cd $(LFTDIR) && $(MAKE) fclean

re: fclean
	@$(MAKE) all

debug: $(NAME)
	@echo "Files :" $(FILES)
	@$(COMPILER) -g $(IFLAGS) $(SRC) $(LFLAGS) -o $(NAME)

test: $(NAME)
	./lem-in < resources/no-room.map
	./lem-in < resources/no-ants.map
	./lem-in < resources/no-start.map
	./lem-in < resources/no-end.map
	./lem-in < resources/no-solutions.map
	./lem-in < resources/comments.map

test_leaks: $(NAME)
	valgrind ./lem-in < resources/no-room.map 2>&1 | grep lost
	valgrind ./lem-in < resources/no-ants.map 2>&1 | grep lost
	valgrind ./lem-in < resources/no-start.map 2>&1 | grep lost
	valgrind ./lem-in < resources/no-end.map 2>&1 | grep lost
	valgrind ./lem-in < resources/no-solutions.map 2>&1 | grep lost
	valgrind ./lem-in < resources/comments.map 2>&1 | grep lost

test_algo: $(NAME)
	./lem-in -vf resources/1.map
	./lem-in -vf resources/4.map
	./lem-in -vf resources/7.map
	./lem-in -vf resources/10.map
	./lem-in -vf resources/7.1.map
	./lem-in -vf resources/7.2.map
	./lem-in -vf resources/7.3.map
	./lem-in -vf resources/7.4.map
	./lem-in -vf resources/7.5.map
	./lem-in < resources/20.map

norm:
	@echo $(RED)
	@norminette $(SRC) $(HDRPATH) | grep -v	Norme -B1 || true
	@echo $(END)
	@cd $(LFTDIR) && $(MAKE) norm

.PHONY: all clean fclean re test norme
