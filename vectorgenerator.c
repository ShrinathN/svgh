#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "shapes.h"
int main(int argc, char *argv[])
{
	if (argc < 5)
	{
		printf
			("%s [number of elements] [height] [width] [number of files] [specific element, leave empty if randomized] [square side, for element 8 only]\nElements\n0\trectangle\n1\tcircle\n2\tellipse\n3\tline\n4\tpolygon\n5\tpolyline\n6\tcurve\n7\tgradient, wont be randomized\n8\trandom squares of color\n",
			 argv[0]);
		return 0;
	}
	int cycles = atoi(argv[1]), length = atoi(argv[2]), width = atoi(argv[3]), chance, turn =
		0, nfil = 0, polycount = 0, polycounter = 0, curvetype;
	int a, b, c, d, e;
	long ti = time(NULL);
	char curv[10], filname[10];
	FILE *fil;
	srand(ti);
	while (nfil < atoi(argv[4]))
	{
		ti++;
		srand(ti);
		turn = 0;
		sprintf(filname, "%d.svg", nfil);
		fil = fopen(filname, "w");
		memset(filname, 0, sizeof(filname));
		MakeSVGFile(width, length, fil);
		MakeWallpaper(width, length, fil);
		while (turn < cycles)
		{
			ti++;
			srand(ti);
			if (argv[5] == NULL)
			{
				chance = rand() % 7;
			}
			else
			{
				chance = atoi(argv[5]);
			}
			if (chance == 0)	// rect
			{
				MakeRectangle(width, length, fil);
			}
			if (chance == 1)	// circle
			{
				MakeCircle(width, length, fil);
			}
			if (chance == 2)	// ellipse
			{
				MakeEllipse(width, length, fil);
			}
			if (chance == 3)	// line
			{
				MakeLine(width, length, fil);
			}
			if (chance == 4)	// polygon
			{
				MakePolygon(width, length, fil);
			}
			if (chance == 5)	// polyline
			{
				MakePolyline(width, length, fil);
			}
			if (chance == 6)	// curve
			{
				MakeCurve(width, length, fil);
			}
			if (chance == 7)	// gradient
			{
				MakeGradient(width, length, fil);
			}
			if (chance == 8)	// random rects
			{
				cycles = 1;
				a = 0;
				b = 0;
				while (a < width)
				{
					while (b < length)
					{
						c = rand() % 256;
						d = rand() % 256;
						e = rand() % 256;
						fprintf(fil,
								"<rect width=\"%d\" height=\"%d\" x=\"%d\" y=\"%d\" fill=\"rgb(%d,%d,%d)\"/>\n",
								atoi(argv[6]), atoi(argv[6]), a, b, c, d, e);
						b += atoi(argv[6]);
					}
					b = 0;
					a += atoi(argv[6]);
				}
			}
			polycounter = 0;
			polycount = 0;
			turn++;
		}
		EndSVGFile(fil);
		fclose(fil);
		turn = 0;
		nfil++;
	}
}
