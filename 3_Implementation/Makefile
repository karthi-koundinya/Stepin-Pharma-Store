PROJECT_NAME = all.exe
SRC = pharma.c\
src\pharma_add.c\
src\pharma_delete.c\
src\pharma_display.c\
src\pharma_add.c\
src\pharma_goto.c\
src\pharma_menu.c\
src\pharma_modify.c\
src\pharma_search.c\

INC = inc

$(PROJECT_NAME): $(SRC)
	gcc -I $(INC) $(SRC) -o all.exe
	
run: $(PROJECT_NAME)
	$(PROJECT_NAME)
	
clean:
	del /q *.exe
