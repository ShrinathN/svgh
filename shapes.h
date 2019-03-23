void MakeSVGFile(int width, int height, FILE * f)
{
    fprintf(f,
            "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"%d\" height=\"%d\">\n",
            width, height);
}

void EndSVGFile(FILE * f)
{
    fprintf(f, "</svg>\n");
}

void MakeWallpaper(int width, int height, FILE * f)
{
    int wall_fill_r, wall_fill_g, wall_fill_b;
    wall_fill_r = rand() % 256;
    wall_fill_g = rand() % 256;
    wall_fill_b = rand() % 256;
    fprintf(f, "<rect width=\"%d\" height=\"%d\" fill=\"rgb(%d, %d, %d)\"/>\n", width, height,
            wall_fill_r, wall_fill_g, wall_fill_b);
}

void MakeRectangle(int width, int height, FILE * f)
{
    int rect_x, rect_y, rect_radius_x, rect_radius_y, rect_width, rect_height, rect_fill_r,
        rect_fill_g, rect_fill_b, rect_stroke_r, rect_stroke_g, rect_stroke_b, rect_stroke_width,
        rect_fill_opacity, rect_stroke_opacity;
    rect_x = rand() % width;
    rect_y = rand() % height;
    rect_radius_x = rand() % 101;
    rect_radius_y = rand() % 101;
    rect_width = rand() % width;
    rect_height = rand() % height;
    rect_fill_r = rand() % 256;
    rect_fill_g = rand() % 256;
    rect_fill_b = rand() % 256;
    rect_stroke_r = rand() % 256;
    rect_stroke_g = rand() % 256;
    rect_stroke_b = rand() % 256;
    rect_stroke_width = rand() % 11;
    rect_fill_opacity = rand() % 10;
    rect_stroke_opacity = rand() % 10;
    fprintf(f,
            "<rect x=\"%d\" y=\"%d\" rx=\"%d\" ry=\"%d\" width=\"%d\" height=\"%d\" fill=\"rgb(%d, %d, %d)\" stroke=\"rgb(%d, %d, %d)\" stroke-width=\"%d\" fill-opacity=\"0.%d\" stroke-opacity=\"0.%d\"/>\n",
            rect_x, rect_y, rect_radius_x, rect_radius_y, rect_width, rect_height, rect_fill_r,
            rect_fill_g, rect_fill_b, rect_stroke_r, rect_stroke_g, rect_stroke_b,
            rect_stroke_width, rect_fill_opacity, rect_stroke_opacity);
}

void MakeCircle(int width, int height, FILE * f)
{
    int circle_x, circle_y, circle_rad, circle_stroke_r, circle_stroke_g, circle_stroke_b,
        circle_stroke_width, circle_fill_r, circle_fill_g, circle_fill_b;
    circle_x = rand() % width;
    circle_y = rand() % height;
    circle_rad = rand() % width / 10;
    circle_stroke_r = rand() % 256;
    circle_stroke_g = rand() % 256;
    circle_stroke_b = rand() % 256;
    circle_stroke_width = rand() % 11;
    circle_fill_r = rand() % 256;
    circle_fill_g = rand() % 256;
    circle_fill_b = rand() % 256;
    fprintf(f,
            "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"rgb(%d, %d, %d)\" stroke-width=\"%d\" fill=\"rgb(%d, %d, %d)\"/>\n",
            circle_x, circle_y, circle_rad, circle_stroke_r, circle_stroke_g, circle_stroke_b,
            circle_stroke_width, circle_fill_r, circle_fill_g, circle_fill_b);
}

void MakeEllipse(int width, int height, FILE * f)
{
    int ellipse_x, ellipse_y, ellipse_rx, ellipse_ry, ellipse_fill_r, ellipse_fill_g,
        ellipse_fill_b, ellipse_stroke_r, ellipse_stroke_g, ellipse_stroke_b, ellipse_stroke_width;
    ellipse_x = rand() % width;
    ellipse_y = rand() % height;
    ellipse_rx = rand() % width / 5;
    ellipse_ry = rand() % height / 5;
    ellipse_fill_r = rand() % 256;
    ellipse_fill_g = rand() % 256;
    ellipse_fill_b = rand() % 256;
    ellipse_stroke_r = rand() % 256;
    ellipse_stroke_g = rand() % 256;
    ellipse_stroke_b = rand() % 256;
    ellipse_stroke_width = rand() % 11;
    fprintf(f,
            "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"rgb(%d, %d, %d)\" stroke=\"rgb(%d, %d, %d)\" stroke-width=\"%d\"/>\n",
            ellipse_x, ellipse_y, ellipse_rx, ellipse_ry, ellipse_fill_r, ellipse_fill_g,
            ellipse_fill_b, ellipse_stroke_r, ellipse_stroke_g, ellipse_stroke_b,
            ellipse_stroke_width);
}

void MakeLine(int width, int height, FILE * f)
{
    int line_x1, line_y1, line_x2, line_y2, line_stroke_r, line_stroke_g, line_stroke_b,
        line_stroke_width;
    line_x1 = rand() % width;
    line_y1 = rand() % height;
    line_x2 = rand() % width;
    line_y2 = rand() % height;
    line_stroke_r = rand() % 256;
    line_stroke_g = rand() % 256;
    line_stroke_b = rand() % 256;
    line_stroke_width = rand() % 11;
    if (line_stroke_width < 1)
    {
        line_stroke_width = rand() % 11;
    }
    fprintf(f,
            "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"%d\"/>\n",
            line_x1, line_y1, line_x2, line_y2, line_stroke_r, line_stroke_g, line_stroke_b,
            line_stroke_width);
}

void MakePolygon(int width, int height, FILE * f)
{
    int polygon_sidecount = 0, polygon_sidecounter =
                                0, polygon_width, polygon_height, polygon_fill_r, polygon_fill_g, polygon_fill_b,
                                polygon_stroke_r, polygon_stroke_g, polygon_stroke_b, polygon_stroke_width;
    while (polygon_sidecount < 2)
    {
        polygon_sidecount = rand() % 11;
    }
    fprintf(f, "<polygon points=\"");
    while (polygon_sidecounter < polygon_sidecount)
    {
        polygon_width = rand() % width;
        polygon_height = rand() % height;
        polygon_sidecounter++;
        fprintf(f, "%d,%d ", polygon_width, polygon_height);
    }
    polygon_fill_r = rand() % 256;
    polygon_fill_g = rand() % 256;
    polygon_fill_b = rand() % 256;
    polygon_stroke_r = rand() % 256;
    polygon_stroke_g = rand() % 256;
    polygon_stroke_b = rand() % 256;
    polygon_stroke_width = rand() % 11;
    fprintf(f, "\" fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"%d\"/>\n",
            polygon_fill_r, polygon_fill_g, polygon_fill_b, polygon_stroke_r, polygon_stroke_g,
            polygon_stroke_b, polygon_stroke_width);
}

void MakePolyline(int width, int height, FILE * f)
{
    int polyline_sidecount = 0, polyline_sidecounter =
                                 0, polyline_width, polyline_height, polyline_stroke_r, polyline_stroke_g,
                                 polyline_stroke_b, polyline_stroke_width;
    while (polyline_sidecount < 2)
    {
        polyline_sidecount = rand() % 11;
    }
    fprintf(f, "<polyline points=\"");
    while (polyline_sidecounter < polyline_sidecount)
    {
        polyline_width = rand() % width;
        polyline_height = rand() % height;
        polyline_sidecounter++;
        fprintf(f, "%d,%d ", polyline_width, polyline_height);
    }
    polyline_stroke_r = rand() % 256;
    polyline_stroke_g = rand() % 256;
    polyline_stroke_b = rand() % 256;
    polyline_stroke_width = rand() % 11;
    if (polyline_stroke_width < 1)
    {
        polyline_stroke_width = rand() % 11;
    }
    fprintf(f, "\" fill=\"none\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"%d\"/>\n",
            polyline_stroke_r, polyline_stroke_g, polyline_stroke_b, polyline_stroke_width);
}

void MakeCurve(int width, int height, FILE * f)
{
    int curve_polycount = 0, curve_polycounter =
                              0, curve_point_width, curve_point_height, curve_fill_r, curve_fill_g, curve_fill_b,
                              curve_stroke_r, curve_stroke_g, curve_stroke_b, curve_stroke_width;
    while (curve_polycount < 3)
    {
        curve_polycount = rand() % 11;
    }
    fprintf(f, "<path d=\"");
    fprintf(f, "M%d %d ", width / 2, height / 2);
    while (curve_polycounter < curve_polycount)
    {
        curve_polycounter++;
        curve_point_width = rand() % width;
        curve_point_height = rand() % height;
        fprintf(f, "T%d %d ", curve_point_width, curve_point_height);
    }
    curve_fill_r = rand() % 256;
    curve_fill_g = rand() % 256;
    curve_fill_b = rand() % 256;
    curve_stroke_r = rand() % 256;
    curve_stroke_g = rand() % 256;
    curve_stroke_b = rand() % 256;
    curve_stroke_width = rand() % 11;
    fprintf(f, "Z\" fill=\"rgb(%d,%d,%d)\" stroke=\"rgb(%d,%d,%d)\" stroke-width=\"%d\"/>\n",
            curve_fill_r, curve_fill_g, curve_fill_b, curve_stroke_r, curve_stroke_g,
            curve_stroke_b, curve_stroke_width);
}

void MakeGradient(int width, int height, FILE * f)
{
    int gradient_id, gradient_x, gradient_y,gradient_r, gradient_fx, gradient_fy,gradient_color1_r, gradient_color1_g, gradient_color1_b, gradient_color2_r,gradient_color2_g, gradient_color2_b, gradient_fill_opacity,gradient_fill_opacity2;
    gradient_id = rand() % 100;
    gradient_x = rand() % 101;
    gradient_y = rand() % 101;
    gradient_r = rand() % 101;
    gradient_fx = rand() % 101;
    gradient_fy = rand() % 101;
    gradient_color1_r = rand() % 256;
    gradient_color1_g = rand() % 256;
    gradient_color1_b = rand() % 256;
    gradient_color2_r = rand() % 256;
    gradient_color2_g = rand() % 256;
    gradient_color2_b = rand() % 256;
    gradient_fill_opacity = rand() % 101;
    gradient_fill_opacity2 = rand() & 101;
    fprintf(f,
            "<defs>\n<radialGradient id=\"grad%d\" cx=\"%d%\" cy=\"%d%\" r=\"%d%\" fx=\"%d%\" fy=\"%d%\">\n<stop offset=\"0%\" style=\"stop-color:rgb(%d,%d,%d);stop-opacity:0\"/><stop offset=\"100%\" style=\"stop-color:rgb(%d,%d,%d);stop-opacity:1\"/>\n</radialGradient>\n</defs>\n<rect width=\"%d\" height=\"%d\" fill=\"url(#grad%d)\" fill-opacity=\"%d\%\"/>\n", gradient_id, gradient_x, gradient_y, gradient_r, gradient_fx, gradient_fy, gradient_color1_r, gradient_color1_g, gradient_color1_b, gradient_color2_r, gradient_color2_g, gradient_color2_b, width, height, gradient_id, gradient_fill_opacity,width, height, gradient_id, gradient_fill_opacity2);
}
