DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/

CFLAGS := -I$(DIRHEA) -c -Wall 
LDLIBS := -lpthread -lrt
CC := gcc

all : dirs ssooiicle

dirs:
	mkdir -p $(DIROBJ) $(DIREXE)

ssooiicle: $(DIROBJ)ssooiicle.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

$(DIROBJ)%.o: $(DIRSRC)%.c
	$(CC) $(CFLAGS) $^ -o $@


clean : 
	rm -rf *~ core $(DIROBJ) $(DIREXE) $(DIRHEA)*~ $(DIRSRC)*~