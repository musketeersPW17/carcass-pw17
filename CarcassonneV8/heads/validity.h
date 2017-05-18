#ifndef VALIDITY_H
#define VALIDITY_H
int choicevalid(int chosen,int typesoftiles);
int ifempty(int a, int b, int coordx,  int coordy, int set[a][b]);
int placementvalid(int a, int b, int coordx,  int coordy, int set[a][b]);
int rotationchoice(int ch);
#endif
