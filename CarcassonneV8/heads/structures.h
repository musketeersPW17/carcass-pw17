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
