#include <stdio.h>
void MakeSVGFile(int width, int height, FILE * f)//creates the header of the SVG file
{
    fprintf(f,
            "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%d\" height=\"%d\">\n",
            width, height);
}

void EndSVGFile(FILE * f)//closes the SVG file with the </svg> tag. Not exactly worth being made into a function but helpful
{
    fprintf(f, "</svg>\n");
}


struct SVGRect//structure for storing the details of a rectangle
{
    int rect_x;//the x co-ordinate of the rectangle
    int rect_y;//the y co-ordinate of the rectangle
    int rect_radius_x;
    int rect_radius_y;
    int rect_width;//width of the rectangle
    int rect_height;//height of the rectangle
    int rect_fill[3];//the color to be filled inside the rectangle
    int rect_stroke[3];//the color to be filled in the boundary of the rectangle, not required if rect_stroke_width is 0
    int rect_stroke_width;//the width of the boundary of the rectangle
    float rect_fill_opacity;//opacity of the color inside the rectangle, can be from 0 to 1
    float rect_stroke_opacity;//opacity of the color of the boundary of the rectangle, can be from 0 to 1
};

void Init_Rect(struct SVGRect * rect)//function essential to initialize all the values of the rectangle struct as 0
{
    rect->rect_x = 0;
    rect->rect_y = 0;
    rect->rect_radius_x = 0;
    rect->rect_radius_y = 0;
    rect->rect_width = 0;
    rect->rect_height = 0;
    rect->rect_fill[0] = 0;
    rect->rect_fill[1] = 0;
    rect->rect_fill[2] = 0;
    rect->rect_stroke[0] = 0;
    rect->rect_stroke[1] = 0;
    rect->rect_stroke[2] = 0;
    rect->rect_stroke_width = 0;
    rect->rect_fill_opacity = 0.0;
    rect->rect_stroke_opacity = 0.0;
}

void Make_Rect(struct SVGRect * rect, FILE * f)//function to write all the details of the rectangle into an SVG file
{
    fprintf(f,
            "<rect x=\"%d\" y=\"%d\" rx=\"%d\" ry=\"%d\" width=\"%d\" height=\"%d\" fill=\"rgb(%d, %d, %d)\" stroke=\"rgb(%d, %d, %d)\" stroke-width=\"%d\" fill-opacity=\"%f\" stroke-opacity=\"%f\"/>\n",
            rect->rect_x, rect->rect_y, rect->rect_radius_x, rect->rect_radius_y, rect->rect_width, rect->rect_height, rect->rect_fill[0],
            rect->rect_fill[1], rect->rect_fill[2], rect->rect_stroke[0], rect->rect_stroke[1], rect->rect_stroke[2],
            rect->rect_stroke_width, rect->rect_fill_opacity, rect->rect_stroke_opacity);
}

struct SVGCircle//structure for storing the details of a circle
{
    int circle_x;//the x of the circle,
    int circle_y;
    int circle_rad;//radius of the circle
    int circle_stroke[3];//the color of the boundary of the circle
    int circle_stroke_width;//width of the boundary of the circle
    int circle_fill[3];//color inside the circle
    float circle_fill_opacity;//opacity of the color inside the circle, can be from 0 to 1
    float circle_stroke_opacity;//opacity of the color of the boundary of the circle, can be from 0 to 1
};

void Init_Circle(struct SVGCircle * circle)//same thing, initializing all the values as 0
{
    circle->circle_x = 0;
    circle->circle_y = 0;
    circle->circle_rad = 0;
    circle->circle_stroke[0] = 0;
    circle->circle_stroke[1] = 0;
    circle->circle_stroke[2] = 0;
    circle->circle_stroke_width = 0;
    circle->circle_fill[0] = 0;
    circle->circle_fill[1] = 0;
    circle->circle_fill[2] = 0;
    circle->circle_fill_opacity = 0.0;
    circle->circle_stroke_opacity = 0.0;
}

void Make_Circle(struct SVGCircle * circle, FILE * f)
{
    fprintf(f,
            "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"rgb(%d, %d, %d)\" stroke-width=\"%d\" fill=\"rgb(%d, %d, %d)\" fill-opacity=\"%f\" stroke-opacity=\"%f\"/>\n",
            circle->circle_x, circle->circle_y, circle->circle_rad, circle->circle_stroke[0], circle->circle_stroke[1], circle->circle_stroke[2],
            circle->circle_stroke_width, circle->circle_fill[0], circle->circle_fill[1], circle->circle_fill[2], circle->circle_fill_opacity, circle->circle_stroke_opacity);
}

struct SVGEllipse
{
    int ellipse_x;
    int ellipse_y;
    int ellipse_rx;
    int ellipse_ry;
    int ellipse_fill[3];
    int ellipse_stroke[3];
    int ellipse_stroke_width;
};

void Init_Ellipse(struct SVGEllipse * ellipse)
{
    ellipse->ellipse_x = 0;
    ellipse->ellipse_y = 0;
    ellipse->ellipse_rx = 0;
    ellipse->ellipse_ry = 0;
    ellipse->ellipse_fill[0] = 0;
    ellipse->ellipse_fill[1] = 0;
    ellipse->ellipse_fill[2] = 0;
    ellipse->ellipse_stroke[0] = 0;
    ellipse->ellipse_stroke[1] = 0;
    ellipse->ellipse_stroke[2] = 0;
    ellipse->ellipse_stroke_width = 0;
}

void Make_Ellipse(struct SVGEllipse * ellipse, FILE * f)
{
    fprintf(f,
            "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"rgb(%d, %d, %d)\" stroke=\"rgb(%d, %d, %d)\" stroke-width=\"%d\"/>\n",
            ellipse->ellipse_x, ellipse->ellipse_y, ellipse->ellipse_rx, ellipse->ellipse_ry, ellipse->ellipse_fill[0], ellipse->ellipse_fill[1],
            ellipse->ellipse_fill[2], ellipse->ellipse_stroke[0], ellipse->ellipse_stroke[1], ellipse->ellipse_stroke[2],
            ellipse->ellipse_stroke_width);
}

struct SVGLine
{
    int line_x1;
    int line_y1;
    int line_x2;
    int line_y2;
    int line_stroke[3];
    int line_stroke_width;
};

void Init_Line(struct SVGLine * line)
{
    line->line_x1 = 0;
    line->line_y1 = 0;
    line->line_x2 = 0;
    line->line_y2 = 0;
    line->line_stroke[0] = 0;
    line->line_stroke[1] = 0;
    line->line_stroke[2] = 0;
    line->line_stroke_width = 0;
}

void Make_Line(struct SVGLine * line, FILE * f)
{
    fprintf(f,
            "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"%d\"/>\n",
            line->line_x1, line->line_y1, line->line_x2, line->line_y2, line->line_stroke[0], line->line_stroke[1], line->line_stroke[2],
            line->line_stroke_width);
}

struct SVGPolygon
{
    int polygon_fill[3];
    int polygon_stroke[3];
    int polygon_stroke_width;
    char polygon_points[];
};

void Init_Polygon(struct SVGPolygon * polygon)
{
    polygon->polygon_fill[0] = 0;
    polygon->polygon_fill[1] = 0;
    polygon->polygon_fill[2] = 0;
    polygon->polygon_stroke[0] = 0;
    polygon->polygon_stroke[1] = 0;
    polygon->polygon_stroke[2] = 0;
    polygon->polygon_stroke_width = 0;
}

void Make_Polygon(struct SVGPolygon * polygon, FILE * f, char polygon_points[])
{
    fprintf(f, "<polygon points=\"%s\"", polygon_points);
    fprintf(f, " fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"%d\"/>\n",
            polygon->polygon_fill[0], polygon->polygon_fill[1], polygon->polygon_fill[2], polygon->polygon_stroke[0], polygon->polygon_stroke[1],
            polygon->polygon_stroke[1], polygon->polygon_stroke_width);
}

struct SVGPolyline
{
    int polyline_stroke[3];
    int polyline_stroke_width;
};

void Init_Polyline(struct SVGPolyline * polyline)
{
    polyline->polyline_stroke[0] = 0;
    polyline->polyline_stroke[1] = 0;
    polyline->polyline_stroke[2] = 0;
    polyline->polyline_stroke_width = 0;
}

void Make_Polyline(struct SVGPolyline * polyline, FILE * f, char polyline_points[])
{
    fprintf(f, "<polyline points=\"%s\"",polyline_points);
    fprintf(f, " fill=\"none\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"%d\"/>\n",
            polyline->polyline_stroke[0], polyline->polyline_stroke[1], polyline->polyline_stroke[2], polyline->polyline_stroke_width);
}

struct SVGGradient
{
    int gradient_id;
    int gradient_x;
    int gradient_y;
    int gradient_r;
    int gradient_fx;
    int gradient_fy;
    int gradient_color1[3];
    int gradient_color2[3];
    float gradient_fill_opacity;
};

void Init_Gradient(struct SVGGradient * grad)
{
    grad->gradient_id = 0;
    grad->gradient_x = 0;
    grad->gradient_y = 0;
    grad->gradient_r = 0;
    grad->gradient_fx = 0;
    grad->gradient_fy = 0;
    grad->gradient_color1[3] = 0;
    grad->gradient_color2[3] = 0;
    grad->gradient_fill_opacity = 0.0;
}

void Make_Gradient(struct SVGGradient * grad, FILE * f)
{
    fprintf(f,"<defs>\n<radialGradient id=\"grad%d\" cx=\"%d%\" cy=\"%d%\" r=\"%d%\" fx=\"%d%\" fy=\"%d%\">\n<stop offset=\"0%\" style=\"stop-color:rgb(%d,%d,%d);stop-opacity:0\"/><stop offset=\"100%\" style=\"stop-color:rgb(%d,%d,%d);stop-opacity:1\"/>\n</radialGradient>\n</defs>\n"
            ,grad->gradient_id, grad->gradient_x,
            grad->gradient_y, grad->gradient_r,
            grad->gradient_fx, grad->gradient_fy,
            grad->gradient_color1[0], grad->gradient_color1[1],
            grad->gradient_color1[2], grad->gradient_color2[0],
            grad->gradient_color2[1], grad->gradient_color2[2]);
}

struct SVGCurve
{
    int curve_fill[3];
    int curve_stroke[3];
    int curve_stroke_width;
};

void Init_Curve(struct SVGCurve * curve)
{
    curve->curve_fill[0] = 0;
    curve->curve_fill[1] = 0;
    curve->curve_fill[2] = 0;
    curve->curve_stroke[0] = 0;
    curve->curve_stroke[1] = 0;
    curve->curve_stroke[2] = 0;
    curve->curve_stroke_width = 0;
}

void Make_Curve(struct SVGCurve * curve, FILE * f, char * curve_points[])
{
    fprintf(f, "<path d=\"%s\"",curve_points);
    fprintf(f, "Z\" fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"%d\"/>\n",
            curve->curve_fill[0], curve->curve_fill[1], curve->curve_fill[2], curve->curve_stroke[0], curve->curve_stroke[1],
            curve->curve_stroke[2], curve->curve_stroke_width);
}
