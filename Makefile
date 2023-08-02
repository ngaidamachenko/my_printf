#macro definitions
TARGET = my_printf
FILES = main my_printf my_itoa reverse_string my_putstr    
CFLAGS = -Wall -Wextra -Werror
HEADERS = my_printf.h

# adds .c file extension
SRC = $(addsuffix .c,$(FILES))
# adds .o file extension
OBJ = $(addsuffix .o,$(FILES))

CFLAGS += -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJ)
	gcc -o $(TARGET) $(OBJ)

$(OBJ): $(SRC)
	gcc -c $(CFLAGS) $< -o $@

crun : all
	./$(TARGET)

clean:
	rm -f $(OBJ)

fclean: clean	
	rm -f $(TARGET)

#remove everything and recompile
re: fclean all

############################################
# all : $(TARGET)

# $(TARGET) : $(TARGET).c
# 	gcc $(CFLAGS) -o $(TARGET) $(TARGET).c

# $(OBJ) : $(SRC)
# 	gcc $(CFLAGS) -c $(SRC)

# clean:
# 	rm -f *.o

# fclean: clean
# 	rm -f $(TARGET)

# re: fclean all