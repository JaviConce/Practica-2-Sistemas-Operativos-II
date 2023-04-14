DIROBJ := obj/
DIREXE := exec/
DIRHEA := include/
DIRSRC := src/
DIRRES := resources/

CFLAGS := -I$(DIRHEA) -c 
LDLIBS := -lpthread -lrt
CC := g++

all : dirs ssooiicle

dirs:
	mkdir -p $(DIROBJ) $(DIREXE)

ssooiicle: $(DIROBJ)ssooiigle.o 
	$(CC) -o $(DIREXE)$@ $^ $(LDLIBS)

$(DIROBJ)%.o: $(DIRSRC)%.cpp
	$(CC) $(CFLAGS) $^ -o $@

test:
	./$(DIREXE)ssooiicle $(DIRRES)/prueba.txt david 5


solution1: 
	./$(DIREXE)ssooiicle $(DIRRES)/17-LEYES-DEL-TRABJO-EN-EQUIPO.txt ley 100

solution2: 
	./$(DIREXE)ssooiicle $(DIRRES)/21-LEYES-DEL-LIDERAZGO.txt ley 100

solution3: 
	./$(DIREXE)ssooiicle $(DIRRES)/SEAMOS-PERSONAS-DE-INFLUENCIA.txt personas 100

clean : 
	rm -rf *~ core $(DIROBJ) $(DIREXE) $(DIRHEA)*~ $(DIRSRC)*~