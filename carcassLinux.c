#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

struct Tiles
{
    char segments[5];
    char special[10];
    int quantity;
    int id;
};
struct Tilesplaced
{
    char segments[5];
    char special[10];
    int id;
};
struct Tilesscore
{
    char segments[5];
    char special[10];
    int id;
};
struct Placement
{
    int x;
    int y;
};
struct Tiles tile[300];
struct Tilesplaced tileplaced[300];
struct Tilesscore tilescore[300];
struct Placement place[300];


void tileset(int a,int b,int set[a][b], int typesoftiles)
{
    int t,y,q=0,l=0,c=0,e=0,d,lx,ly;
    for(y=0;y<a;y++)
    {
        for(t=0;t<b;t++)
        {
            if(set[t][y]==0)
            {
                q++;
            }
            else
            {
                t=b;
                l++;
                if(l==1)
                {
                    d=e;
                    e=b+1;
                }
            }
            if(q==b)
            {
                if(l<1)
                    e++;
                else
                    e--;
            }
        }
        q=0;
    }
    ly=e;
    e=0;
    l=0;
    for(y=0;y<b;y++)
    {
        for(t=0;t<a;t++)
        {
            if(set[y][t]==0)
            {
                q++;
            }
            else
            {
                t=a;
                l++;
                if(l==1)
                {
                    c=e;
                    e=a+1;
                }
            }
            if(q==(a-1))
            {
                if(l<1)
                    e++;
                else
                    e--;
            }
        }
        q=0;
    }
    lx=e;
    printf("\n     ");
    for(t=c; t<lx-1; t++)
    {
        if(t<10)
            printf("   %d  ",t);
        if(t<100&&t>9)
            printf("  %d  ",t);
        if(t<1000&&t>99)
            printf("  %d ",t);
    }
    printf("\n");
    for(t=d; t<ly-1; t++)
    {
        printf("\n     ");
        for(y=c; y<lx-1; y++)
        {
            printf("   %c  ",tileplaced[set[y][t]].segments[0]);
        }
        printf("\n ");
        if(t<10)
            printf("%d   ",t);
        if(t<100&&t>9)
            printf("%d  ",t);
        if(t<1000&&t>99)
            printf("%d ",t);
        for(y=c; y<lx; y++)
        {
            printf(" %c ",tileplaced[set[y][t]].segments[3]);
            if(strcmp(tileplaced[set[y][t]].special, "Temple")==0)
            {
                printf("%c",'T');
                printf(" %c",tileplaced[set[y][t]].segments[1]);
            }
            else if(strcmp(tileplaced[set[y][t]].special, "Crossroad")==0)
            {
                printf("%c",'X');
                printf(" %c",tileplaced[set[y][t]].segments[1]);
            }
            else if(strcmp(tileplaced[set[y][t]].special, "Fullcity")==0)
            {
                printf("%c",'O');
                printf(" %c",tileplaced[set[y][t]].segments[1]);
            }
            else
            {
                printf("  %c",tileplaced[set[y][t]].segments[1]);
            }
        }
        printf("\n     ");
        for(y=c; y<lx; y++)
        {
            printf("   %c  ",tileplaced[set[y][t]].segments[2]);
        }
    }
    printf("\n");
}
void tilesetscore(int a,int b,int set[a][b], int typesoftiles)
{
    int t,y,q=0,l=0,c=0,e=0,d,lx,ly;
    for(y=0;y<a;y++)
    {
        for(t=0;t<b;t++)
        {
            if(set[t][y]==0)
            {
                q++;
            }
            else
            {
                t=b;
                l++;
                if(l==1)
                {
                    d=e;
                    e=b+1;
                }
            }
            if(q==b)
            {
                if(l<1)
                    e++;
                else
                    e--;
            }
        }
        q=0;
    }
    ly=e;
    e=0;
    l=0;
    for(y=0;y<b;y++)
    {
        for(t=0;t<a;t++)
        {
            if(set[y][t]==0)
            {
                q++;
            }
            else
            {
                t=a;
                l++;
                if(l==1)
                {
                    c=e;
                    e=a+1;
                }
            }
            if(q==(a-1))
            {
                if(l<1)
                    e++;
                else
                    e--;
            }
        }
        q=0;
    }
    lx=e;
    printf("\n     ");
    for(t=c; t<lx-1; t++)
    {
        if(t<10)
            printf("   %d  ",t);
        if(t<100&&t>9)
            printf("  %d  ",t);
        if(t<1000&&t>99)
            printf("  %d ",t);
    }
    printf("\n");
    for(t=d; t<ly-1; t++)
    {
        printf("\n     ");
        for(y=c; y<lx-1; y++)
        {
            printf("   %c  ",tilescore[set[y][t]].segments[0]);
        }
        printf("\n ");
        if(t<10)
            printf("%d   ",t);
        if(t<100&&t>9)
            printf("%d  ",t);
        if(t<1000&&t>99)
            printf("%d ",t);
        for(y=c; y<lx; y++)
        {
            printf(" %c ",tilescore[set[y][t]].segments[3]);
            if(strcmp(tilescore[set[y][t]].special, "Temple")==0)
            {
                printf("%c",'T');
                printf(" %c",tilescore[set[y][t]].segments[1]);
            }
            else if(strcmp(tilescore[set[y][t]].special, "Crossroad")==0)
            {
                printf("%c",'X');
                printf(" %c",tilescore[set[y][t]].segments[1]);
            }
            else if(strcmp(tilescore[set[y][t]].special, "Fullcity")==0)
            {
                printf("%c",'O');
                printf(" %c",tilescore[set[y][t]].segments[1]);
            }
            else
            {
                printf("  %c",tilescore[set[y][t]].segments[1]);
            }
        }
        printf("\n     ");
        for(y=c; y<lx; y++)
        {
            printf("   %c  ",tilescore[set[y][t]].segments[2]);
        }
    }
    printf("\n");
}


void rotationpre(int rotations, int tileid)
{
    char c[10];
    rotations=rotations % 4;
    c[(0+rotations) % 4]=tile[tileid].segments[0];
    c[(1+rotations) % 4]=tile[tileid].segments[1];
    c[(2+rotations) % 4]=tile[tileid].segments[2];
    c[(3+rotations) % 4]=tile[tileid].segments[3];
    printf("\n   %c",c[0]);
    printf("\n %c ",c[3]);
    if(strcmp(tile[tileid].special, "Temple")==0)
    {
        printf("%c",'T');
        printf(" %c",c[1]);
    }
    else if(strcmp(tile[tileid].special, "Crossroad")==0)
    {
        printf("%c",'X');
        printf(" %c",c[1]);
    }
    else if(strcmp(tile[tileid].special, "Fullcity")==0)
    {
        printf("%c",'O');
        printf(" %c",c[1]);
    }
    else
    {
        printf("  %c",c[1]);
    }
    printf("\n   %c\n\n",c[2]);
}

void rotation(int rotations, int tileid)
{
    int t,o;
    char v1,v2;
    for(t=0;t<rotations;t++)
    {
        v1=tile[tileid].segments[1];
        tile[tileid].segments[1]=tile[tileid].segments[0];
        v2=tile[tileid].segments[2];
        tile[tileid].segments[2]=v1;
        v1=tile[tileid].segments[3];
        tile[tileid].segments[3]=v2;
        tile[tileid].segments[0]=v1;
    }
}


void tileinfoall( struct Tiles *tile )
{
    printf( "Tile Segments : %s		", tile->segments);
    printf( "Special : %s	", tile->special);
    printf( "Quantity : %d		", tile->quantity);
    printf( "ID : %d\n",tile->id);
}
void tileinfoavilable( struct Tiles *tile )
{
    if(tile->quantity>0)
    {
        printf( "Tile Segments : %s		", tile->segments);
        printf( "Special : %s		", tile->special);
        printf( "Quantity : %d		", tile->quantity);
        printf( "ID : %d\n",tile->id);
    }
}
void yourtiles(int tot)
{
    int t=1;
    for(t;t<=tot;t++)
        tileinfoavilable(&tile[t]);
}
int quantitycheck(int typesoftiles)
{
    int number=0;
    int t;
    for(t=1;t<=typesoftiles;t++)
    {
        number=number+tile[t].quantity;
    }
    return number;
}
void menu(int clear, int autotileset, int autotilelist)
{
    printf("1. Tileset,\n2. Tile list,\n3. Place a tile,\n4. Clear console,\n");
    printf("5. Auto-clear,		(%d)\n6. Auto-tileset,	(%d)\n7. Auto-tilelist,	(%d)\n",clear,autotileset,autotilelist);
}

int ifcross(int choice)
{
    int roads=0;
    if(tile[choice].segments[0]=='R')
        roads++;
    if(tile[choice].segments[1]=='R')
        roads++;
    if(tile[choice].segments[2]=='R')
        roads++;
    if(tile[choice].segments[3]=='R')
        roads++;
    if(roads>2)
        return 1;
    else
        return 0;
}
int segcross(char seg[])
{
    int roads=0;
    if(seg[0]=='R')
        roads++;
    if(seg[1]=='R')
        roads++;
    if(seg[2]=='R')
        roads++;
    if(seg[3]=='R')
        roads++;
    if(roads>2)
        return 1;
    else
        return 0;
}
int ifcity(int choice)
{
    int city=0;
    if(tile[choice].segments[0]=='S'||tile[choice].segments[0]=='C')
        city++;
    if(tile[choice].segments[1]=='S'||tile[choice].segments[1]=='C')
        city++;
    if(tile[choice].segments[2]=='S'||tile[choice].segments[2]=='C')
        city++;
    if(tile[choice].segments[3]=='S'||tile[choice].segments[3]=='C')
        city++;
    if(city==4)
        return 1;
    else
        return 0;
}
int segcity(char seg[])
{
    int city=0;
    if(seg[0]=='S'||seg[0]=='C')
        city++;
    if(seg[1]=='S'||seg[1]=='C')
        city++;
    if(seg[2]=='S'||seg[2]=='C')
        city++;
    if(seg[3]=='S'||seg[3]=='C')
        city++;
    if(city==4)
        return 1;
    else
        return 0;
}


int choicevalid(int chosen,int typesoftiles)
{
    int validity=0;
    while(validity==0)
    {
        if(chosen>typesoftiles||chosen<=0)
        {
            printf("Wrong id, try again\n");
            return 0;
        }
        else
        {
            if(tile[chosen].quantity==0)
            {
                printf("Tile unavilable, choose other\n");
                return 0;
            }
            else
                validity=1;
        }
    }
    return 4;
}
int ifempty(int a, int b, int coordx,  int coordy, int set[a][b])
{
    if(set[coordx][coordy]!=0)
        return 0;
    return 1;
}
int placementvalid(int a, int b, int coordx,  int coordy, int set[a][b])
{
    int valid=0,zero=0;
    if(tileplaced[set[coordx][coordy]].segments[3]==tileplaced[set[coordx-1][coordy]].segments[1])
        valid++;
    if(tileplaced[set[coordx][coordy]].segments[3]=='S'&&tileplaced[set[coordx-1][coordy]].segments[1]=='C')
        valid++;
    if(tileplaced[set[coordx][coordy]].segments[3]=='C'&&tileplaced[set[coordx-1][coordy]].segments[1]=='S')
        valid++;
    if(set[coordx-1][coordy]==0)
        zero++;
    
    if(tileplaced[set[coordx][coordy]].segments[1]==tileplaced[set[coordx+1][coordy]].segments[3])
        valid++;
    if(tileplaced[set[coordx][coordy]].segments[1]=='S'&&tileplaced[set[coordx+1][coordy]].segments[3]=='C')
        valid++;
    if(tileplaced[set[coordx][coordy]].segments[1]=='C'&&tileplaced[set[coordx+1][coordy]].segments[3]=='S')
        valid++;
    if(set[coordx+1][coordy]==0)
        zero++;
    
    if(tileplaced[set[coordx][coordy]].segments[2]==tileplaced[set[coordx][coordy+1]].segments[0])
        valid++;
    if(tileplaced[set[coordx][coordy]].segments[2]=='S'&&tileplaced[set[coordx][coordy+1]].segments[0]=='C')
        valid++;
    if(tileplaced[set[coordx][coordy]].segments[2]=='C'&&tileplaced[set[coordx][coordy+1]].segments[0]=='S')
        valid++;
    if(set[coordx][coordy-1]==0)
        zero++;
    
    if(tileplaced[set[coordx][coordy]].segments[0]==tileplaced[set[coordx][coordy-1]].segments[2])
        valid++;
    if(tileplaced[set[coordx][coordy]].segments[0]=='S'&&tileplaced[set[coordx][coordy-1]].segments[2]=='C')
        valid++;
    if(tileplaced[set[coordx][coordy]].segments[0]=='C'&&tileplaced[set[coordx][coordy-1]].segments[2]=='S')
        valid++;
    if(set[coordx][coordy+1]==0)
        zero++;
    
    if(valid+zero==4&&valid>0)
        return 1;
    else {
        return 2;
    }
}
int rotationchoice(int ch)
{
    int punch=0, rota;
    char word;
    while (punch==0)
    {
        printf("Choose number of rotations of the tile\n");
        scanf("%d", &rota);
        rotationpre(rota,ch);
        printf("Place the tile? (y/n)\n");
        scanf(" %c",&word);
        if(word==121)
        {
            rotation(rota,ch);
            punch=1;
        }
        if(word!=110&&word!=121)
        {
            punch=0;
            while(punch==0)
            {
                printf("Wrong command, try again\n");
                scanf(" %c", &word);
                if(word==121)
                {
                    rotation(rota,ch);
                    punch=1;
                }
            }
        }
    }
    return 1;
}


int tileroads(int sometile)
{
    int i,j=0;
    for(i=0;i<4;i++)
    {
        if(tilescore[sometile].segments[i]=='R')
            j++;
    }
    return j;
}

int tilecitys(int sometile)
{
    int i,j=0;
    for(i=0;i<4;i++)
    {
        if(tilescore[sometile].segments[i]=='C'||tilescore[sometile].segments[i]=='S')
            j++;
    }
    return j;
}

int citycontinue(int sometile)
{
    if(tilescore[sometile].segments[0]==0)
        return 0;
    else
    {
        if(tilecitys(sometile)>0)
            return 1;
        else
            return 2;
    }
}

int roadcontinue(int sometile)
{
    if(tilescore[sometile].segments[0]==0)
        return 0;
    else
    {
        if(tileroads(sometile)==1||strcmp(tilescore[sometile].special,"Crossroad")==0)
            return 2;
        else
            return 1;
    }
}
int main()
{
    
    int limit;
    char sts[10];
    int typesoftiles=0;
    int alltiles=0;
    int i=1,ij=0,added=0;
    int segcheck=0;
    int equal=0;
    FILE *read;
    char c[1000];
    read = fopen("input\\testcity2.txt","r");
    if (!read)
        return 1;
    while ( fscanf( read, "%s", c )!=EOF)
    {
        fscanf(read,"%[^\n]", c);
        strcpy (sts, c);
        if(quantitycheck(typesoftiles)==0)
        {
            typesoftiles++;
            tile[typesoftiles].segments[0]=sts[0];
            tile[typesoftiles].segments[1]=sts[1];
            tile[typesoftiles].segments[2]=sts[2];
            tile[typesoftiles].segments[3]=sts[3];
            if(sts[4]-'0'==1)
                strcpy (tile[typesoftiles].special,"Temple");
            if(sts[4]-'0'==0)
                strcpy (tile[typesoftiles].special,"Nothing");
            if(ifcross(typesoftiles)==1)
                strcpy (tile[typesoftiles].special,"Crossroad");
            if(ifcity(typesoftiles)==1)
                strcpy (tile[typesoftiles].special,"Fullcity");
            tile[typesoftiles].id=typesoftiles;
            tile[typesoftiles].quantity++;
            alltiles++;
        }
        else
        {
            for(i=1;i<=typesoftiles;i++)
            {
                for(ij=0;ij<4;ij++)
                {
                    for(segcheck=0;segcheck<4;segcheck++)
                        if(sts[(segcheck+ij)%4]==tile[i].segments[segcheck])
                            equal++;
                    if(sts[4]-'0'==1&&strcmp(tile[i].special, "Temple")==0)
                        equal++;
                    if(sts[4]-'0'==0&&strcmp(tile[i].special, "Nothing")==0)
                        equal++;
                    if(segcross(sts)==1&&ifcross(i)==1)
                        equal++;
                    if(segcity(sts)==1&&ifcity(i)==1)
                        equal++;
                    if(equal==5)
                    {
                        tile[i].quantity++;
                        added=1;
                        i=typesoftiles+1;
                        alltiles++;
                    }
                    equal=0;
                }
            }
            if(added==0)
            {
                typesoftiles++;
                tile[typesoftiles].segments[0]=sts[0];
                tile[typesoftiles].segments[1]=sts[1];
                tile[typesoftiles].segments[2]=sts[2];
                tile[typesoftiles].segments[3]=sts[3];
                if(sts[4]-'0'==1)
                    strcpy (tile[typesoftiles].special,"Temple");
                if(sts[4]-'0'==0)
                    strcpy (tile[typesoftiles].special,"Nothing");
                if(segcross(sts)==1)
                    strcpy (tile[typesoftiles].special,"Crossroad");
                if(segcity(sts)==1)
                    strcpy (tile[typesoftiles].special,"Fullcity");
                tile[typesoftiles].id=typesoftiles;
                tile[typesoftiles].quantity++;
                alltiles++;
            }
            added=0;
        }
    }
    fclose(read);
    limit=2*(quantitycheck(typesoftiles)+2);
    int cityarray[limit/2];
    memset(cityarray, 0, sizeof(cityarray[0]) * (limit/2));
    int map[limit][limit],j,rot,clear=0,autotileset=0,autotilelist=0;
    char letter;
    memset(map, 0, sizeof(map[0][0]) * limit * limit);
    int chosen,validity=0;
    int wish;
    yourtiles(typesoftiles);
    printf("Number of tiles left %d\n",quantitycheck(typesoftiles));
    printf("Choose id of the first tile		(1-%d)\n",typesoftiles);
    scanf("%d", &chosen);
    while(choicevalid(chosen,typesoftiles)==0)
    {
        scanf(" %d", &chosen);
    }
    rotationchoice(chosen);
    int ITP=quantitycheck(typesoftiles)+1, chosenid=1;
    strcpy(tileplaced[chosenid].segments,tile[chosen].segments);
    strcpy(tileplaced[chosenid].special,tile[chosen].special);
    strcpy(tilescore[chosenid].segments,tile[chosen].segments);
    strcpy(tilescore[chosenid].special,tile[chosen].special);
    map[ITP][ITP]=chosenid;
    place[chosenid].x=ITP;
    place[chosenid].y=ITP;
    tile[chosen].quantity--;
    tileset(limit,limit,map,typesoftiles);
    printf("\n\n");
    int chosencoord1,chosencoord2;
    menu(clear,autotileset,autotilelist);
    printf("Number of tiles left		%d\n",quantitycheck(typesoftiles));
    while(quantitycheck(typesoftiles)!=0)
    {
        printf("Choose a command\n");
        scanf("%d",&wish);
        switch (wish)
        {
            case 1:
                tileset(limit,limit,map,typesoftiles);
                break;
            case 8:
                tilesetscore(limit,limit,map,typesoftiles);
                break;
            case 2:
                printf("\n");
                yourtiles(typesoftiles);
                break;
            case 4:
                system("cls");
                menu(clear,autotileset,autotilelist);
                break;
            case 5:
                if(clear==0)
                    clear=1;
                else
                    clear=0;
                printf("auto-clear	%d\n",clear);
                break;
            case 6:
                if(autotileset==0)
                    autotileset=1;
                else
                    autotileset=0;
                printf("auto-tileset	%d\n",autotileset);
                break;
            case 7:
                if(autotilelist==0)
                    autotilelist=1;
                else
                    autotilelist=0;
                printf("auto-tilelist	%d\n",autotilelist);
                break;
            case 3:
                printf("Choose id of a tile\n");
                scanf("%d", &chosen);
                while(choicevalid(chosen,typesoftiles)==0)
                {
                    scanf(" %d", &chosen);
                }
                rotationchoice(chosen);
                printf("Choose coordinates for the tile (x,y) (type -1,-1 to return to menu)\n");
                scanf("%d,%d", &chosencoord1,&chosencoord2);
                if(chosencoord1==-1&&chosencoord2==-1)
                    break;
                int tileval=0;
                while(ifempty(limit,limit,chosencoord1,chosencoord2,map)!=1)
                {
                    printf("There is already a tile at chosen coordinates, try again\n");
                    printf("Choose coordinates for the tile (x,y) 	(type -1,-1 to return to menu)\n");
                    scanf("%d,%d", &chosencoord1,&chosencoord2);
                    if(chosencoord1==-1&&chosencoord2==-1)
                        break;
                }
                chosenid++;
                map[chosencoord1][chosencoord2]=chosenid;
                strcpy(tileplaced[chosenid].segments,tile[chosen].segments);
                strcpy(tileplaced[chosenid].special,tile[chosen].special);
                while(placementvalid(limit,limit,chosencoord1,chosencoord2,map)!=1)
                {
                    map[chosencoord1][chosencoord2]=0;
                    printf("Invalid coordinates, try again \n");
                    printf("Choose coordinates for the tile (x,y) 	(type -1,-1 to return to menu)\n");
                    scanf("%d,%d", &chosencoord1,&chosencoord2);
                    if(chosencoord1==-1&&chosencoord2==-1)
                        break;
                    while(ifempty(limit,limit,chosencoord1,chosencoord2,map)!=1)
                    {
                        printf("There is already a tile at chosen coordinates, try again \n");
                        printf("Choose coordinates for the tile (x,y) 	(type -1,-1 to return to menu)\n");
                        scanf("%d,%d", &chosencoord1,&chosencoord2);
                        if(chosencoord1==-1&&chosencoord2==-1)
                            break;
                    }
                    map[chosencoord1][chosencoord2]=chosenid;
                }
                place[chosenid].x=chosencoord1;
                place[chosenid].y=chosencoord2;
                tile[chosen].quantity--;
                strcpy(tilescore[chosenid].segments,tile[chosen].segments);
                strcpy(tilescore[chosenid].special,tile[chosen].special);
                if(clear==1)
                    system("cls");
                if(autotileset==1)
                    tileset(limit,limit,map,typesoftiles);
                if(autotilelist==1)
                {
                    printf("\n");
                    yourtiles(typesoftiles);
                }
                menu(clear,autotileset,autotilelist);
                printf("Number of tiles left		%d\n",quantitycheck(typesoftiles));
                break;
        }
    }
    printf("FINAL TILESET\n");
    tileset(limit,limit,map,typesoftiles);
    int score=0;
    int templescore;
    int lix,liy;
    printf("\n");
    for(liy=1;liy<limit;liy++)
    {
        for(lix=1;lix<limit;lix++)
        {
            if(map[lix][liy]!=0)
            {
                //temple scoring
                //	printf("lix:	%d\nliy:	%d\ntile order:	%d\n",lix,liy,map[lix][liy]);
                if(strcmp(tileplaced[map[lix][liy]].special,"Temple")==0)
                {
                    int somescore=1;
                    if(map[lix-1][liy-1]!=0)
                        somescore++;
                    if(map[lix-1][liy]!=0)
                        somescore++;
                    if(map[lix-1][liy+1]!=0)
                        somescore++;
                    if(map[lix][liy-1]!=0)
                        somescore++;
                    if(map[lix][liy+1]!=0)
                        somescore++;
                    if(map[lix+1][liy-1]!=0)
                        somescore++;
                    if(map[lix+1][liy]!=0)
                        somescore++;
                    if(map[lix+1][liy+1]!=0)
                        somescore++;
                    printf("score added tem	%d\n",somescore);
                    score+=somescore;
                    tilescore[map[lix][liy]].special=="ScoredT";
                }
                //road scoring
                //	printf("ROADS NUMBER %d\n",tileroads(map[lix][liy]));
                if(tileroads(map[lix][liy])==1||(tileroads(map[lix][liy])>0&&strcmp(tileplaced[map[lix][liy]].special,"Crossroad")==0))
                {
                    int bonus=2;
                    //		printf("initial tile found	%d 	%d\n",lix,liy);
                    int initialtilesegment,nexttilesegment;
                    int roadlength=1;
                    int neightile1 = 0;
                    for(i=0;i<4;i++)
                    {
                        if(tilescore[map[lix][liy]].segments[i]=='R')
                        {
                            roadlength=1;
                            initialtilesegment=i;
                            nexttilesegment=initialtilesegment;
                            int newcoord1=lix,newcoord2=liy,end=0;
                            while(end==0)
                            {
                                neightile1= (nexttilesegment+2)%4;
                                if(neightile1==0)
                                    newcoord2++;
                                else
                                    if(neightile1==1)
                                        newcoord1--;
                                    else
                                        if(neightile1==2)
                                            newcoord2--;
                                        else
                                            if(neightile1==3)
                                                newcoord1++;
                                //					printf("	lix:	%d		liy:	%d\n	co1:	%d		co2:	%d\n",lix,liy,newcoord1,newcoord2);
                                if(map[newcoord1][newcoord2]==0)
                                {
                                    end=1;
                                    bonus=1;
                                }
                                else
                                {
                                    if(roadcontinue(map[newcoord1][newcoord2])==2)
                                    {
                                        roadlength++;
                                        end=1;
                                    }
                                    if(roadcontinue(map[newcoord1][newcoord2])==1&&end==0)
                                    {
                                        roadlength++;
                                        for(i=1;i<4;i++)
                                        {
                                            int forsegment=neightile1;
                                            if(tilescore[map[newcoord1][newcoord2]].segments[((neightile1+i)%4)]=='R')
                                            {
                                                nexttilesegment=(neightile1+i)%4;
                                                i=4;
                                            }
                                        }
                                    }
                                }
                            }
                            score+=roadlength*bonus;
                            printf("length %d   bonus %d	score added		%d\n",roadlength,bonus,roadlength*bonus);
                            tilescore[map[lix][liy]].segments[initialtilesegment]='A';
                            tilescore[map[newcoord1][newcoord2]].segments[neightile1]='A';
                            //				printf("		initial tile %d		final tile %d\n",map[lix][liy],map[newcoord1][newcoord2]);
                        }
                    }
                }
                else
                {
                    printf("	not a valid road staring point\n");
                }
                int citysize=1;
                //city scoring!
                // initaial tile
                //	printf("CITY'S NUMBER %d\n",tilecitys(map[lix][liy]));
                if(tilecitys(map[lix][liy])>0&&cityarray[map[lix][liy]]!=1&&strcmp(tilescore[map[lix][liy]].special,"Fullcity")!=0)
                {
                    int bonus=2;
                    int citysegmentpoints=0;
                    int shieldpoints=0;
                    int endc=0;
                    int oldie;
                    int checkingarray[alltiles];
                    int checkingarrayid[alltiles];
                    int checkingarrayquantity=1;			//with value of checked segments
                    memset(checkingarray, 0, sizeof(checkingarray[0]) * (alltiles));
                    memset(checkingarrayid, 0, sizeof(checkingarrayid[0]) * (alltiles));
                    cityarray[map[lix][liy]]=2;
                    if(tilescore[map[lix][liy]].segments[i]=='S')
                    {
                        shieldpoints++;
                        tilescore[map[lix][liy]].segments[i]='C';
                    }
                    if(tilecitys(map[lix][liy])==2)
                    {
                        if((tilescore[map[lix][liy]].segments[0]=='C'&&tilescore[map[lix][liy]].segments[2]=='C')||\
                           (tilescore[map[lix][liy]].segments[1]=='C'&&tilescore[map[lix][liy]].segments[3]=='C')||\
                           (tilescore[map[lix][liy]].segments[0]=='C'&&tilescore[map[lix][liy]].segments[1]=='C')||\
                           (tilescore[map[lix][liy]].segments[1]=='C'&&tilescore[map[lix][liy]].segments[2]=='C')||\
                           (tilescore[map[lix][liy]].segments[2]=='C'&&tilescore[map[lix][liy]].segments[3]=='C')||\
                           (tilescore[map[lix][liy]].segments[3]=='C'&&tilescore[map[lix][liy]].segments[0]=='C'))
                        {
                            for(i=0;i<4;i++)
                                if(i==0)
                                {
                                    tilescore[map[lix][liy]].segments[0]=='A';
                                    checkingarray[map[lix][liy-1]]=0;
                                }
                            if(i==1)
                            {
                                tilescore[map[lix][liy]].segments[1]=='A';
                                checkingarray[map[lix+1][liy]]=0;
                            }
                            if(i==2)
                            {
                                tilescore[map[lix][liy]].segments[2]=='A';
                                checkingarray[map[lix][liy+1]]=0;
                            }
                            if(i==3)
                            {
                                tilescore[map[lix][liy]].segments[3]=='A';
                                checkingarray[map[lix-1][liy]]=0;
                            }
                            citysegmentpoints++;
                            cityarray[map[lix][liy]]=0;
                        }
                    }
                    else
                    {
                        checkingarrayquantity++;
                        citysegmentpoints+=tilecitys(map[lix][liy]);
                        checkingarray[map[lix][liy]]=0;
                        checkingarrayid[checkingarrayquantity]=map[lix][liy];
                        //	printf("checkingarrayquantity	%d\n",checkingarrayquantity);
                    }
                    //		printf("	loop1\n");
                    int numberofcitytiles=1,chceckedcitytiles=0;
                    //		printf("initial tile found	%d 	%d\n",lix,liy);
                    int initialtilesegment,nexttilesegment;
                    int citysize=1;
                    int neightile1;
                    int endcc=0,ii,iii;
                    while(endcc==0)	// for with number of tiles in the checkingarray
                    {
                        //	printf("		loop2\n");
                        oldie=checkingarrayquantity;
                        for(ii=1;ii<=checkingarrayquantity;ii++)
                        {
                            //	printf("ii		%d\n",ii);				//not fullcity but with C_C_0
                            for(iii=0;iii<4;iii++)
                            {
                                if(tilescore[checkingarrayid[ii]].segments[iii]=='C'||tilescore[checkingarrayid[ii]].segments[iii]=='S')	//go and return
                                {
                                    if(tilescore[checkingarrayid[ii]].segments[iii]=='S')
                                    {
                                        shieldpoints++;
                                        tilescore[checkingarrayid[ii]].segments[iii]='C';
                                    }
                                    int newcoord1=place[checkingarrayid[ii]].x,newcoord2=place[checkingarrayid[ii]].y;
                                    /////////////////////////////////////////////////////////////
                                    
                                    if(iii==2)
                                    {
                                        
                                        if(tilecitys(map[newcoord1][newcoord2+1])==2)
                                        {
                                            printf("/");
                                            if((tilescore[map[newcoord1][newcoord2+1]].segments[0]=='C'||tilescore[map[newcoord1][newcoord2+1]].segments[0]=='S')&&(tilescore[map[newcoord1][newcoord2+1]].segments[2]=='C'||tilescore[map[newcoord1][newcoord2+1]].segments[2]=='S'))
                                            {
                                                if(tilescore[map[newcoord1][newcoord2+1]].segments[0]=='S')
                                                    shieldpoints++;
                                                tilescore[map[newcoord1][newcoord2+1]].segments[0]=='A';
                                                checkingarray[map[lix][liy-1]]=0;
                                            }
                                            if((tilescore[map[newcoord1][newcoord2+1]].segments[0]=='C'||tilescore[map[newcoord1][newcoord2+1]].segments[0]=='S')&&(tilescore[map[newcoord1][newcoord2+1]].segments[1]=='C'||tilescore[map[newcoord1][newcoord2+1]].segments[1]=='S'))
                                            {
                                                if(tilescore[map[newcoord1][newcoord2+1]].segments[0]=='S')
                                                    shieldpoints++;
                                                tilescore[map[newcoord1][newcoord2+1]].segments[0]=='A';
                                                checkingarray[map[lix][liy-1]]=0;
                                            }
                                            if((tilescore[map[newcoord1][newcoord2+1]].segments[0]=='C'||tilescore[map[newcoord1][newcoord2+1]].segments[0]=='S')&&(tilescore[map[newcoord1][newcoord2+1]].segments[3]=='C'||tilescore[map[newcoord1][newcoord2+1]].segments[3]=='S'))
                                            {
                                                if(tilescore[map[newcoord1][newcoord2+1]].segments[0]=='S')
                                                    shieldpoints++;
                                                tilescore[map[newcoord1][newcoord2+1]].segments[0]=='A';
                                                checkingarray[map[lix][liy-1]]=0;
                                            }
                                            citysegmentpoints++;
                                        }
                                        oldie--;
                                    }
                                    if(iii==3)
                                    {
                                        
                                        if(tilecitys(map[newcoord1-1][newcoord2])==2)
                                        {
                                            if((tilescore[map[newcoord1-1][newcoord2]].segments[1]=='C'||tilescore[map[newcoord1-1][newcoord2]].segments[1]=='S')&&(tilescore[map[newcoord1-1][newcoord2]].segments[3]=='C'||tilescore[map[newcoord1-1][newcoord2]].segments[3]=='S'))
                                            {
                                                if(tilescore[map[newcoord1-1][newcoord2]].segments[1]=='S')
                                                    shieldpoints++;
                                                tilescore[map[newcoord1-1][newcoord2]].segments[1]=='A';
                                                checkingarray[map[lix][liy-1]]=0;
                                            }
                                            if((tilescore[map[newcoord1-1][newcoord2]].segments[1]=='C'||tilescore[map[newcoord1-1][newcoord2]].segments[1]=='S')&&(tilescore[map[newcoord1-1][newcoord2]].segments[2]=='C'||tilescore[map[newcoord1-1][newcoord2]].segments[2]=='S'))
                                            {
                                                if(tilescore[map[newcoord1-1][newcoord2]].segments[1]=='S')
                                                    shieldpoints++;
                                                tilescore[map[newcoord1-1][newcoord2]].segments[1]=='A';
                                                checkingarray[map[lix][liy-1]]=0;
                                            }
                                            if((tilescore[map[newcoord1-1][newcoord2]].segments[1]=='C'||tilescore[map[newcoord1-1][newcoord2]].segments[1]=='S')&&(tilescore[map[newcoord1-1][newcoord2]].segments[0]=='C'||tilescore[map[newcoord1-1][newcoord2]].segments[0]=='S'))
                                            {
                                                if(tilescore[map[newcoord1-1][newcoord2]].segments[1]=='S')
                                                    shieldpoints++;
                                                tilescore[map[newcoord1-1][newcoord2]].segments[1]=='A';
                                                checkingarray[map[lix][liy-1]]=0;
                                            }
                                            citysegmentpoints++;
                                        }
                                        oldie--;
                                        
                                    }
                                    
                                    if(iii==0)
                                    {
                                        
                                        if(tilecitys(map[newcoord1][newcoord2-1])==2)
                                        {
                                            if((tilescore[map[newcoord1][newcoord2-1]].segments[2]=='C'||tilescore[map[newcoord1][newcoord2-1]].segments[2]=='S')&&(tilescore[map[newcoord1][newcoord2-1]].segments[0]=='C'||tilescore[map[newcoord1][newcoord2-1]].segments[0]=='S'))
                                            {
                                                if(tilescore[map[newcoord1][newcoord2-1]].segments[2]=='S')
                                                    shieldpoints++;
                                                tilescore[map[newcoord1][newcoord2-1]].segments[2]=='A';
                                                checkingarray[map[lix][liy-1]]=0;
                                            }
                                            if((tilescore[map[newcoord1][newcoord2-1]].segments[2]=='C'||tilescore[map[newcoord1][newcoord2-1]].segments[2]=='S')&&(tilescore[map[newcoord1][newcoord2-1]].segments[3]=='C'||tilescore[map[newcoord1][newcoord2-1]].segments[3]=='S'))
                                            {
                                                if(tilescore[map[newcoord1][newcoord2-1]].segments[2]=='S')
                                                    shieldpoints++;
                                                tilescore[map[newcoord1][newcoord2-1]].segments[2]=='A';
                                                checkingarray[map[lix][liy-1]]=0;
                                            }
                                            if((tilescore[map[newcoord1][newcoord2-1]].segments[2]=='C'||tilescore[map[newcoord1][newcoord2-1]].segments[2]=='S')&&(tilescore[map[newcoord1][newcoord2-1]].segments[1]=='C'||tilescore[map[newcoord1][newcoord2-1]].segments[1]=='S'))
                                            {
                                                if(tilescore[map[newcoord1][newcoord2-1]].segments[2]=='S')
                                                    shieldpoints++;
                                                tilescore[map[newcoord1][newcoord2-1]].segments[2]=='A';
                                                checkingarray[map[lix][liy-1]]=0;
                                            }
                                            citysegmentpoints++;
                                        }
                                        oldie--;
                                        
                                    }
                                    
                                    if(iii==1)
                                    {
                                        
                                        if(tilecitys(map[newcoord1+1][newcoord2])==2)
                                        {
                                            if((tilescore[map[newcoord1+1][newcoord2]].segments[3]=='C'||tilescore[map[newcoord1+1][newcoord2]].segments[3]=='S')&&(tilescore[map[newcoord1+1][newcoord2]].segments[1]=='C'||tilescore[map[newcoord1+1][newcoord2]].segments[1]=='S'))
                                            {
                                                if(tilescore[map[newcoord1+1][newcoord2]].segments[3]=='S')
                                                    shieldpoints++;
                                                tilescore[map[newcoord1+1][newcoord2]].segments[3]=='A';
                                                checkingarray[map[lix][liy-1]]=0;
                                            }
                                            if((tilescore[map[newcoord1+1][newcoord2]].segments[3]=='C'||tilescore[map[newcoord1+1][newcoord2]].segments[3]=='S')&&(tilescore[map[newcoord1+1][newcoord2]].segments[0]=='C'||tilescore[map[newcoord1+1][newcoord2]].segments[0]=='S'))
                                            {
                                                if(tilescore[map[newcoord1+1][newcoord2]].segments[3]=='S')
                                                    shieldpoints++;
                                                tilescore[map[newcoord1+1][newcoord2]].segments[3]=='A';
                                                checkingarray[map[lix][liy-1]]=0;
                                            }
                                            if((tilescore[map[newcoord1+1][newcoord2]].segments[3]=='C'||tilescore[map[newcoord1+1][newcoord2]].segments[3]=='S')&&(tilescore[map[newcoord1+1][newcoord2]].segments[2]=='C'||tilescore[map[newcoord1+1][newcoord2]].segments[2]=='S'))
                                            {
                                                if(tilescore[map[newcoord1+1][newcoord2]].segments[3]=='S')
                                                    shieldpoints++;
                                                tilescore[map[newcoord1+1][newcoord2]].segments[3]=='A';
                                                checkingarray[map[lix][liy-1]]=0;
                                            }
                                            citysegmentpoints++;
                                        }
                                        oldie--;
                                        
                                    }
                                    
                                    /////////////////////////////////////////////////////////////
                                    
                                    printf("%d - %d\n",place[checkingarrayid[ii]].x,place[checkingarrayid[ii]].y);
                                    if(i==2&&tilescore[map[newcoord1][newcoord2+1]].segments[0]!='A')
                                        newcoord2++;
                                    else
                                        if(i==3&&tilescore[map[newcoord1-1][newcoord2]].segments[1]!='A')
                                            newcoord1--;
                                        else
                                            if(i==0&&tilescore[map[newcoord1][newcoord2-1]].segments[2]!='A')
                                                newcoord2--;
                                            else
                                                if(i==1&&tilescore[map[newcoord1+1][newcoord2]].segments[3]!='A')
                                                    newcoord1++;
                                    //	printf("%d-%d\n",newcoord1,newcoord2);
                                    if(cityarray[map[newcoord1][newcoord2]]==0&&tilescore[map[newcoord1][newcoord2]].segments[(i+2)%4]!='A')
                                    {
                                        cityarray[map[newcoord1][newcoord2]]=2;
                                        /*	if(tilecitys(map[newcoord1][newcoord2])==2)
                                         {
                                         if((tilescore[map[newcoord1][newcoord2]].segments[0]=='C'&&tilescore[map[newcoord1][newcoord2]].segments[2]=='C')||\
                                         (tilescore[map[newcoord1][newcoord2]].segments[1]=='C'&&tilescore[map[newcoord1][newcoord2]].segments[3]=='C')||\
                                         (tilescore[map[newcoord1][newcoord2]].segments[0]=='C'&&tilescore[map[newcoord1][newcoord2]].segments[1]=='C')||\
                                         (tilescore[map[newcoord1][newcoord2]].segments[1]=='C'&&tilescore[map[newcoord1][newcoord2]].segments[2]=='C')||\
                                         (tilescore[map[newcoord1][newcoord2]].segments[2]=='C'&&tilescore[map[newcoord1][newcoord2]].segments[3]=='C')||\
                                         (tilescore[map[newcoord1][newcoord2]].segments[3]=='C'&&tilescore[map[newcoord1][newcoord2]].segments[0]=='C')
                                         {
                                         if(i==2)
                                         tilescore[map[newcoord1][newcoord2]].segments[0]=='A';
                                         if(i==3)
                                         tilescore[map[newcoord1][newcoord2]].segments[1]=='A';
                                         if(i==0)
                                         tilescore[map[newcoord1][newcoord2]].segments[2]=='A';
                                         if(i==1)
                                         tilescore[map[newcoord1][newcoord2]].segments[3]=='A';
                                         citysegmentpoints++;
                                         cityarray[map[newcoord1][newcoord2]]=0;
                                         }
                                         }
                                         else
                                         */	{
                                             checkingarrayquantity++;
                                             citysegmentpoints+=tilecitys(map[newcoord1][newcoord2]);
                                             checkingarrayid[checkingarrayquantity]=map[newcoord1][newcoord2];
                                             //	printf("checkingarrayquantity	%d\n",checkingarrayquantity);
                                         }
                                    }
                                    if(map[newcoord1][newcoord2]==0)
                                    {
                                        bonus=1;
                                    }
                                }
                            }
                        }
                        //	printf("quantity and oldie	%d and %d\n",checkingarrayquantity,oldie);
                        if(checkingarrayquantity==oldie)
                            endcc=1;
                    }
                    if(checkingarrayquantity>0)
                    {
                        if(checkingarrayquantity==1)
                            bonus=1;
                        score+=(citysegmentpoints+shieldpoints)*bonus;			//need to ask for confirmation
                        printf("citypoints %d   shieldpoints %d   bonus %d		total %d\n",citysegmentpoints,shieldpoints,bonus,(citysegmentpoints+shieldpoints)*bonus);
                        for(i=1;i<=checkingarrayquantity;i++)
                            cityarray[checkingarrayid[checkingarrayquantity]]=1;
                        shieldpoints=0;
                    }
                }
            }
        }
    }
    printf("FINAL SCORE		%d\n",score);
}
