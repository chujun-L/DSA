#ifndef _STAR_H_
#define _STAR_H_

//#define MAX_STAR_NUM		100
#define SCREEN_WIDTH		640
#define SCREEN_HEIGHT		480
#define BOTTOM_MARGIN		100
#define MAX_RADIUS		3
#define MAX_STEP			5

enum DIR { up, down, left, right };

typedef struct {
	unsigned x;
	unsigned y;
	unsigned radius;
	unsigned step;
	unsigned color;

}star_t, elem_type;


#endif // !_STAR_H_
