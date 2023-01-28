import random


class RandomSvgGeneratorClass:

    def __init__(self) -> None:
        self.__svg_data = '<svg xmlns="http://www.w3.org/2000/svg" version="1.1" width="{}" height="{}">'
        self.width = 500
        self.height = 500
        self.elements_set = 1
        self.random_checked = True
        self.rectangle_checked = False
        self.circle_checked = False
        self.ellipse_checked = False
        self.line_checked = False
        self.polygon_checked = False
        self.polyline_checked = False
        self.curve_checked = False
        self.gradient_checked = False
        self.min_stroke = 1
        self.max_stroke = 100
    
    def __del__(self) -> None:
        del(self.__svg_data)
        del(self.width)
        del(self.height)
        del(self.elements_set)
        del(self.random_checked)
        del(self.rectangle_checked)
        del(self.circle_checked)
        del(self.ellipse_checked)
        del(self.line_checked)
        del(self.polygon_checked)
        del(self.polyline_checked)
        del(self.curve_checked)
        del(self.gradient_checked)
        del(self.min_stroke)
        del(self.max_stroke)

    def set_width(self, width) -> None:
        self.width = width

    def set_height(self, height) -> None:
        self.height = height

    def set_elements(self, elements_set) -> None:
        self.elements_set = elements_set

    def set_random_checked(self, random_checked_set) -> None:
        self.random_checked = random_checked_set

    def set_rectangle_checked(self, rectangle_checked_set) -> None:
        self.rectangle_checked = rectangle_checked_set

    def set_circle_checked(self, circle_checked_set) -> None:
        self.circle_checked = circle_checked_set

    def set_ellipse_checked(self, ellipse_checked_set) -> None:
        self.ellipse_checked = ellipse_checked_set

    def set_line_checked(self, line_checked_set) -> None:
        self.line_checked = line_checked_set

    def set_polygon_checked(self, polygon_checked_set) -> None:
        self.polygon_checked = polygon_checked_set

    def set_polyline_checked(self, polyline_checked_set) -> None:
        self.polyline_checked = polyline_checked_set

    def set_curve_checked(self, curve_checked_set) -> None:
        self.curve_checked = curve_checked_set

    def set_gradient_checked(self, gradient_checked_set) -> None:
        self.gradient_checked = gradient_checked_set

    def set_strokes(self, min_stroke, max_stroke) -> None:
        self.min_stroke = min_stroke
        self.max_stroke = max_stroke

    def generate_image(self) -> None:
        # setting the header
        self.__svg_data = self.__svg_data.format(
            str(self.width), str(self.height))

        # adding background
        self.__svg_data += self.__add_background_rectangle()
        # adding element
        for _ in range(0, self.elements_set):
            if (self.random_checked):
                choice = random.randint(0, 6)
                if (choice == 0):
                    self.__svg_data += self.__add_random_rectangle()
                elif (choice == 1):
                    self.__svg_data += self.__add_random_circle()
                elif (choice == 2):
                    self.__svg_data += self.__add_random_ellipse()
                elif (choice == 3):
                    self.__svg_data += self.__add_random_line()
                elif (choice == 4):
                    self.__svg_data += self.__add_random_polygon()
                elif (choice == 5):
                    self.__svg_data += self.__add_random_polyline()
                elif (choice == 6):
                    self.__svg_data += self.__add_random_curve()
                
                del(choice)

            if (self.rectangle_checked):
                self.__svg_data += self.__add_random_rectangle()

            if (self.circle_checked):
                self.__svg_data += self.__add_random_circle()

            if (self.ellipse_checked):
                self.__svg_data += self.__add_random_ellipse()

            if (self.line_checked):
                self.__svg_data += self.__add_random_line()

            if (self.polygon_checked):
                self.__svg_data += self.__add_random_polygon()

            if (self.polyline_checked):
                self.__svg_data += self.__add_random_polyline()

            if (self.curve_checked):
                self.__svg_data += self.__add_random_curve()

            if (self.gradient_checked):
                self.__svg_data += self.__add_random_gradient()

        # adding ending
        self.__svg_data += '</svg>'

    def return_image(self) -> str:
        return self.__svg_data

    def __add_background_rectangle(self) -> str:
        return '<rect x="0" y="0" width="{}" height="{}" fill="rgb({}, {}, {})"/>'.format(
            str(self.width),
            str(self.height),
            str(random.randint(0, 255)),  # red
            str(random.randint(0, 255)),  # green
            str(random.randint(0, 255))  # blue
        )

    def __add_random_rectangle(self) -> str:
        return '<rect x="{}" y="{}" rx="{}" ry="{}" width="{}" height="{}" fill="rgb({}, {}, {})" stroke="rgb({}, {}, {})" stroke-width="{}" fill-opacity="{}" stroke-opacity="{}"/>'.format(
            str(random.randint(1, self.width)),  # starting position x
            str(random.randint(1, self.height)),  # starting position y
            str(random.randint(1, 100)),  # radius x
            str(random.randint(1, 100)),  # radius y
            str(random.randint(1, self.width // 2)),  # width
            str(random.randint(1, self.height // 2)),  # height
            str(random.randint(0, 255)),  # fill red
            str(random.randint(0, 255)),  # fill green
            str(random.randint(0, 255)),  # fill blue
            str(random.randint(0, 255)),  # stroke red
            str(random.randint(0, 255)),  # stroke green
            str(random.randint(0, 255)),  # stroke blue
            str(random.randint(self.min_stroke, self.max_stroke)),  # stroke width
            str(random.randint(1, 1000) / 1000),  # fill opacity
            str(random.randint(1, 1000) / 1000)  # stroke opacity
        )

    def __add_random_circle(self) -> str:
        return '<circle cx="{}" cy="{}" r="{}" stroke="rgb({}, {}, {})" stroke-width="{}" fill="rgb({}, {}, {})"/>'.format(
            str(random.randint(0, self.width)),  # starting position x
            str(random.randint(0, self.height)),  # starting position y
            str(random.randint(1, 100)),  # radius x
            str(random.randint(1, 100)),  # radius y
            str(random.randint(0, 255)),  # stroke red
            str(random.randint(0, 255)),  # stroke green
            str(random.randint(0, 255)),  # stroke blue
            str(random.randint(self.min_stroke, self.max_stroke)),  # stroke width
            str(random.randint(0, 255)),  # fill red
            str(random.randint(0, 255)),  # fill green
            str(random.randint(0, 255))  # fill blue
        )

    def __add_random_ellipse(self) -> str:
        return '<ellipse cx="{}" cy="{}" rx="{}" ry="{}" fill="rgb({}, {}, {})" stroke="rgb({}, {}, {})" stroke-width="{}"/>'.format(
            str(random.randint(0, self.width)),  # starting position x
            str(random.randint(0, self.height)),  # starting position y
            str(random.randint(1, 100)),  # radius x
            str(random.randint(1, 100)),  # radius y
            str(random.randint(0, 255)),  # stroke red
            str(random.randint(0, 255)),  # stroke green
            str(random.randint(0, 255)),  # stroke blue
            str(random.randint(0, 255)),  # fill red
            str(random.randint(0, 255)),  # fill green
            str(random.randint(0, 255)),  # fill blue
            str(random.randint(self.min_stroke, self.max_stroke))  # stroke width
        )

    def __add_random_line(self) -> str:
        return '<line x1="{}" y1="{}" x2="{}" y2="{}" stroke="rgb({},{},{})" stroke-width="{}"/>%d'.format(
            str(random.randint(0, self.width)),  # starting position x1
            str(random.randint(0, self.height)),  # starting position y1
            str(random.randint(0, self.width)),  # starting position x2
            str(random.randint(0, self.height)),  # starting position y2
            str(random.randint(0, 255)),  # stroke red
            str(random.randint(0, 255)),  # stroke green
            str(random.randint(0, 255)),  # stroke blue
            str(random.randint(self.min_stroke, self.max_stroke))  # stroke width
        )

    def __add_random_polygon(self) -> str:
        string_to_return = '<polygon points="'
        number_of_sides = random.randint(2, 9)
        for _ in range(number_of_sides):
            string_to_return += '{},{} '.format(
                str(random.randint(0, self.width)),  # point x
                str(random.randint(0, self.height))  # point y
            )
        del(number_of_sides)
        string_to_return += '{},{}" fill="rgb({},{},{})" stroke="rgb({},{},{})" stroke-width="{}"/>'.format(
            str(random.randint(0, self.width)),  # end point x
            str(random.randint(0, self.height)),  # end point y
            str(random.randint(0, 255)),  # fill red
            str(random.randint(0, 255)),  # fill green
            str(random.randint(0, 255)),  # fill blue
            str(random.randint(0, 255)),  # stroke red
            str(random.randint(0, 255)),  # stroke green
            str(random.randint(0, 255)),  # stroke blue
            str(random.randint(self.min_stroke, self.max_stroke))  # stroke width
        )
        return string_to_return

    def __add_random_polyline(self) -> str:
        string_to_return = '<polyline points="'
        number_of_points = random.randint(2, 9)
        for _ in range(number_of_points):
            string_to_return += '{},{} '.format(
                str(random.randint(0, self.width)),  # point x
                str(random.randint(0, self.height))  # point y
            )
        del(number_of_points)
        string_to_return += '{},{}" fill="none" stroke="rgb({},{},{})" stroke-width="{}"/>'.format(
            str(random.randint(0, self.width)),  # end point x
            str(random.randint(0, self.height)),  # end point y
            str(random.randint(0, 255)),  # stroke red
            str(random.randint(0, 255)),  # stroke green
            str(random.randint(0, 255)),  # stroke blue
            str(random.randint(self.min_stroke, self.max_stroke))  # stroke width
        )
        return string_to_return

    def __add_random_curve(self) -> str:
        string_to_return = '<path d="M{} {} '.format(
            str(random.randint(0, self.width // 2)),  # point x
            str(random.randint(0, self.height // 2))  # point y
        )
        number_of_points = random.randint(2, 10)
        for _ in range(number_of_points):
            string_to_return += 'T{} {} '.format(
                str(random.randint(0, self.width//2)),  # point x
                str(random.randint(0, self.height//2))  # point y
            )
        del(number_of_points)
        string_to_return += 'Z" fill="rgb({},{},{})" stroke="rgb({},{},{})" stroke-width="{}"/>'.format(
            str(random.randint(0, 255)),  # fill red
            str(random.randint(0, 255)),  # fill green
            str(random.randint(0, 255)),  # fill blue
            str(random.randint(0, 255)),  # stroke red
            str(random.randint(0, 255)),  # stroke green
            str(random.randint(0, 255)),  # stroke blue
            str(random.randint(self.min_stroke, self.max_stroke))  # stroke width
        )
        return string_to_return

    def __add_random_gradient(self) -> str:
        gradient_id = random.randint(1000000, 99999999)
        string_to_return = '<defs><radialGradient id="grad{}" cx="{}%" cy="{}%" r="{}%" fx="{}%" fy="{}%"><stop offset="0%" style="stop-color:rgb({},{},{});stop-opacity:0"/>'.format(
            str(gradient_id),
            str(random.randint(0, 100)),  # starting position x
            str(random.randint(0, 100)),  # starting position y
            str(random.randint(0, 100)),
            str(random.randint(0, 100)),
            str(random.randint(0, 100)),
            str(random.randint(0, 255)),  # start red
            str(random.randint(0, 255)),  # start green
            str(random.randint(0, 255))  # start blue
        )

        string_to_return += '<stop offset="100%" style="stop-color:rgb({},{},{});stop-opacity:1"/></radialGradient></defs><rect width="{}" height="{}" fill="url(#grad{})" fill-opacity="{}%"/>'.format(
            str(random.randint(0, 255)),  # start red
            str(random.randint(0, 255)),  # start green
            str(random.randint(0, 255)),  # start blue
            str(self.width),
            str(self.height),
            str(gradient_id),
            str(random.randint(0, 100))
        )

        return string_to_return
