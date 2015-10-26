rm execut
clear
clear
gcc main.c floodfill.c matriz.c pilha.c -o execut
./execut circulo.pgm 100 87 saida1.pgm
./execut quadrado.pgm 54 70 saida2.pgm
./execut maze.pgm 25 10 saida3.pgm