echo "compilando..."
make -f Makefile
echo "gerando MEPA..."
./compilador teste5.pas 
if [ $? == 0 ]; then
	echo "montando..."
	if [ "$2" = "64" ]; then
		as mepa64.s -o mepa.o --64 -g
		if [ $? == 0 ]; then
			echo "ligando..."
			ld -melf_x86_64 mepa.o -o mepa -lc -dynamic-linker /lib/ld-linux-x86-64.so.2 -g
			if [ $? == 0 ]; then
				echo "Executando"
				./mepa
			fi
		fi
	else
		as mepa.s -o mepa.o --32 -g
		if [ $? == 0 ]; then
			echo "ligando..."
			ld -melf_i386 mepa.o -o mepa -lc -dynamic-linker /lib/ld-linux.so.2 -g
			if [ $? == 0 ]; then
				echo "Executando"
				./mepa
			fi
		fi
	fi
	echo "FIM"
fi
