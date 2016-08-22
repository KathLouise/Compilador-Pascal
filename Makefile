$DEPURA=1
REDIRECT= 2> /dev/null

compilador: lex.yy.c y.tab.c compilador.o compilador.h
	@echo "Gerando Compilador"
	@gcc -g lex.yy.c compilador.tab.c tab_simbolos.c pilha.c compilador.o -o compilador -ll -ly -lc $(REDIRECT)
	@echo "Compilador gerado com sucesso."

lex.yy.c: compilador.l compilador.h
	@echo "Executando Flex"
	@flex compilador.l $(REDIRECT)

y.tab.c: compilador.y compilador.h
	@echo "Executando Bison"
	@bison compilador.y -d -v $(REDIRECT)

compilador.o : compilador.h compiladorF.c
	@echo "Compilando funcoes do compilador"
	@gcc -c -g compiladorF.c -o compilador.o $(REDIRECT)

clean : 
	@echo "Removendo executaveis...."
	@rm -f compilador 
	@echo "Removendo objetos...."
	@rm -f *.o *~ *.bak
	@echo "Removendo lixo...."
	@rm -f compilador.tab.* lex.yy.c 
