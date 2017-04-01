#include<stdio.h>
#include<windows.h>

void ColorSet(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

int main()
{
	ColorSet(0);
	printf("Tile unavilable, choose other0\n\n");
	ColorSet(1);
	printf("Tile unavilable, choose other1\n\n");
	ColorSet(2);
	printf("Tile unavilable, choose other2\n\n");
	ColorSet(3);
	printf("Tile unavilable, choose other3\n\n");
	ColorSet(4);
	printf("Tile unavilable, choose other4\n\n");
	ColorSet(5);
	printf("Tile unavilable, choose other5\n\n");
	ColorSet(6);
	printf("Tile unavilable, choose other6\n\n");
	ColorSet(7);
	printf("Tile unavilable, choose other7\n\n");
	ColorSet(8);
	printf("Tile unavilable, choose other8\n\n");
	ColorSet(9);
	printf("Tile unavilable, choose other9\n\n");
	ColorSet(10);
	printf("Tile unavilable, choose other10\n\n");
	ColorSet(11);
	printf("Tile unavilable, choose other11\n\n");
	ColorSet(12);
	printf("Tile unavilable, choose other12\n\n");
	ColorSet(13);
	printf("Tile unavilable, choose other13\n\n");
	ColorSet(14);
	printf("Tile unavilable, choose other14\n\n");
	ColorSet(15);
	printf("Tile unavilable, choose other15\n\n");
	
	
}
