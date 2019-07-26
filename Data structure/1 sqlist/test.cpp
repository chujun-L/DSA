#include <iostream>
#include <graphics.h>
#include <ctime>
#include "include/sqlist.h"


void init_star(star_t &s)
{
	unsigned rgb;

	s.x = rand() % SCREEN_WIDTH;
	s.y = rand() % (SCREEN_HEIGHT - BOTTOM_MARGIN);
	s.radius = 1 + rand() % MAX_RADIUS;	// range 1 ~ 3
	s.step = 1 + rand() % MAX_STEP;		// range 1 ~ 5
	rgb = 255 * s.step / MAX_STEP;
	s.color = RGB(rgb, rgb, rgb);
}

void draw_screen(sqlist &l)
{
	unsigned i;

	for (i = 0; i < l.length; ++i) {
		setfillcolor(l.elems[i].color);
		solidcircle(l.elems[i].x, l.elems[i].y, l.elems[i].radius);
	}
}

void count_num_sqlist(sqlist &l)
{
	//char count[16];

	//sprintf(count, "%d", l.length);
	outtextxy(130, 380, l.length / 10 + '0');
	outtextxy(150, 380, l.length % 10 + '0');
	//outtextxy(130, 380, count);
}

void move_star(sqlist &l)
{
	unsigned i;

	for (i = 0; i < l.length; ++i) {
		count_num_sqlist(l);

		if (l.elems[i].y < 10) {
			setfillcolor(BLACK);
			solidcircle(l.elems[i].x, l.elems[i].y, l.elems[i].radius);

			delete_elem_sqlist(l, i);
			i--;		// 删除后，i要复位
		} else {
			setfillcolor(BLACK);
			solidcircle(l.elems[i].x, l.elems[i].y, l.elems[i].radius);

			l.elems[i].y -= l.elems[i].step;
		}
	}
	
	count_num_sqlist(l);		// 将l.length = 0 显示
}


int main()
{
	sqlist l;
	star_t s;
	unsigned i;

	srand((unsigned)time(NULL));

	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);
	settextstyle(18, 0, _T("黑体"));
	settextcolor(RED);
	outtextxy(0, 380, _T("剩余的星星数："));
	

	if (!init_sqlist(l))
	{
		cout << "init sqlist fail" << endl;
		return -1;
	}

	for (i = 0; i < SQLIST_MAX_SIZE; ++i) {
		init_star(s);
		add_sqlist(l, s);
	}

	while (l.length) {
		move_star(l);
		draw_screen(l);
		Sleep(50);
	}

	destroy_sqlist(l);
	//closegraph();
	system("pause");
	return 0;
}