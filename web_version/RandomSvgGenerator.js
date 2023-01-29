function download(data, filename, type) {
	var file = new Blob([data], { type: type });
	if (window.navigator.msSaveOrOpenBlob) // IE10+
		window.navigator.msSaveOrOpenBlob(file, filename);
	else { // Others
		var a = document.createElement("a"),
			url = URL.createObjectURL(file);
		a.href = url;
		a.download = filename;
		document.body.appendChild(a);
		a.click();
		setTimeout(function () {
			document.body.removeChild(a);
			window.URL.revokeObjectURL(url);
		}, 0);
	}
}

String.prototype.format = function () {
	// store arguments in an array
	var args = arguments;
	// use replace to iterate over the string
	// select the match and check if the related argument is present
	// if yes, replace the match with the argument
	return this.replace(/{([0-9]+)}/g, function (match, index) {
		// check if the argument is present
		return typeof args[index] == 'undefined' ? match : args[index];
	});
};

function randint(x, y) {
	// return Math.floor(((Math.random() * 100000000) % (y - x)) + x);
	var tmp = Math.round((Math.random() * 1000000) % (y - x)) + Number(x);
	return tmp;
}

class RandomSvgGeneratorClass {

	constructor() {
		this.width = 3840;
		this.height = 2160;
		this.elements_set = 1;
		this.random_checked = false;
		this.rectangle_checked = false;
		this.circle_checked = false;
		this.ellipse_checked = false;
		this.line_checked = false;
		this.polygon_checked = false;
		this.polyline_checked = false;
		this.curve_checked = false;
		this.gradient_checked = false;
		this.solid_background = true;
		this.min_stroke = 1;
		this.max_stroke = 100;
	}

	save_image() {
		download(this.__svg_data, "image.svg", "text/text");
	}

	generate_image() {
		//setting header
		this.set_header()
		// we only need a single gradient
		if (this.solid_background) {
			this.__svg_data += this.__add_background_rectangle();
		}

		if (this.gradient_checked) {
			this.__svg_data += this.__add_background_rectangle();
			this.__svg_data += this.__add_random_gradient();
		}
		// adding elements
		for (var i = 0; i < this.elements_set; i++) {
			
			if (this.random_checked) {

				var choice = randint(0, 6);

				if (choice == 0)
					this.__svg_data += this.__add_random_rectangle()
				else if (choice == 1)
					this.__svg_data += this.__add_random_circle()
				else if (choice == 2)
					this.__svg_data += this.__add_random_ellipse()
				else if (choice == 3)
					this.__svg_data += this.__add_random_line()
				else if (choice == 4)
					this.__svg_data += this.__add_random_polygon()
				else if (choice == 5)
					this.__svg_data += this.__add_random_polyline()
				else if (choice == 6)
					this.__svg_data += this.__add_random_curve()
			}


			if (this.rectangle_checked)
				this.__svg_data += this.__add_random_rectangle()

			if (this.circle_checked)
				this.__svg_data += this.__add_random_circle()

			if (this.ellipse_checked)
				this.__svg_data += this.__add_random_ellipse()

			if (this.line_checked)
				this.__svg_data += this.__add_random_line()

			if (this.polygon_checked)
				this.__svg_data += this.__add_random_polygon()

			if (this.polyline_checked)
				this.__svg_data += this.__add_random_polyline()

			if (this.curve_checked)
				this.__svg_data += this.__add_random_curve()
		}
		// adding ending
		this.__svg_data += '</svg>';
	}

	set_header() {
		this.__svg_data = '<svg xmlns="http://www.w3.org/2000/svg" version="1.1" width="{0}" height="{1}">'.format(
			Number(this.width).toString(),
			Number(this.height).toString()
		);
	}


	set_width(width) {
		this.width = width;
	}

	set_solid_background(solid_background) {
		this.solid_background = solid_background;
	}

	set_height(height) {
		this.height = height;
	}

	set_elements(elements_set) {
		this.elements_set = elements_set;
	}

	set_random_checked(random_checked_set) {
		this.random_checked = random_checked_set;
	}

	set_rectangle_checked(rectangle_checked_set) {
		this.rectangle_checked = rectangle_checked_set;
	}

	set_circle_checked(circle_checked_set) {
		this.circle_checked = circle_checked_set;
	}

	set_ellipse_checked(ellipse_checked_set) {
		this.ellipse_checked = ellipse_checked_set;
	}


	set_line_checked(line_checked_set) {
		this.line_checked = line_checked_set;
	}


	set_polygon_checked(polygon_checked_set) {
		this.polygon_checked = polygon_checked_set;
	}

	set_polyline_checked(polyline_checked_set) {
		this.polyline_checked = polyline_checked_set;
	}


	set_curve_checked(curve_checked_set) {
		this.curve_checked = curve_checked_set;
	}

	set_gradient_checked(gradient_checked_set) {
		this.gradient_checked = gradient_checked_set;
	}

	set_strokes(min_stroke, max_stroke) {
		this.min_stroke = min_stroke;
		this.max_stroke = max_stroke;
	}

	return_image() {
		console.log(this.min_stroke)
		console.log(this.max_stroke)
		console.log(randint(this.min_stroke, this.max_stroke).toString())
		return this.__svg_data;
	}


	__add_background_rectangle() {
		var string_to_return = '<rect x="0" y="0" width="{0}" height="{1}" fill="rgb({2}, {3}, {4})"/>'.format(
			this.width.toString(),
			this.height.toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString()
		);
		return string_to_return;
	}

	__add_random_rectangle() {
		return '<rect x="{0}" y="{1}" rx="{2}" ry="{3}" width="{4}" height="{5}" fill="rgb({6}, {7}, {8})" stroke="rgb({9}, {10}, {11})" stroke-width="{12}" fill-opacity="{13}" stroke-opacity="{14}"/>'.format(
			Number(randint(1, this.width)).toString(),
			Number(randint(1, this.height)).toString(),
			Number(randint(1, 100)).toString(),
			Number(randint(1, 100)).toString(),
			Number(randint(1, this.width / 2)).toString(),
			Number(randint(1, this.height / 2)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(this.min_stroke, this.max_stroke)).toString(),
			(randint(1, 1000) / 1000).toString(),
			(randint(1, 1000) / 1000).toString()
		);
	}

	__add_random_circle() {
		return '<circle cx="{0}" cy="{1}" r="{2}" stroke="rgb({3}, {4}, {5})" stroke-width="{6}" fill="rgb({7}, {8}, {9})"/>'.format(
			Number(randint(0, this.width)).toString(),
			Number(randint(0, this.height)).toString(),
			Number(randint(1, 100)).toString(),
			Number(randint(1, 100)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(this.min_stroke, this.max_stroke)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString()
		);
	}

	__add_random_ellipse() {
		return '<ellipse cx="{0}" cy="{1}" rx="{2}" ry="{3}" fill="rgb({4}, {5}, {6})" stroke="rgb({7}, {8}, {9})" stroke-width="{10}"/>'.format(
			Number(randint(0, this.width)).toString(),
			Number(randint(0, this.height)).toString(),
			Number(randint(1, 100)).toString(),
			Number(randint(1, 100)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(this.min_stroke, this.max_stroke)).toString()
		);
	}

	__add_random_line() {
		return '<line x1="{0}" y1="{1}" x2="{2}" y2="{3}" stroke="rgb({4},{5},{6})" stroke-width="{7}"/>'.format(
			Number(randint(0, this.width)).toString(),
			Number(randint(0, this.height)).toString(),
			Number(randint(0, this.width)).toString(),
			Number(randint(0, this.height)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(this.min_stroke, this.max_stroke)).toString()
		);
	}

	__add_random_polygon() {
		var string_to_return = '<polygon points="';
		var number_of_sides = randint(2, 9);
		for (var i = 0; i < number_of_sides; i++) {
			string_to_return += '{0},{1} '.format(
				Number(randint(0, this.width)).toString(),
				Number(randint(0, this.height)).toString()
			);
		}
		string_to_return += '{0},{1}" fill="rgb({2},{3},{4})" stroke="rgb({5},{6},{7})" stroke-width="{8}"/>'.format(
			Number(randint(0, this.width)).toString(),
			Number(randint(0, this.height)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(this.min_stroke, this.max_stroke)).toString()
		);
		return string_to_return;
	}

	__add_random_polyline() {
		var string_to_return = '<polyline points="';
		var number_of_points = randint(2, 9);
		for (var i = 0; i < number_of_points; i++) {
			string_to_return += '{0},{1} '.format(
				Number(randint(0, this.width)).toString(),
				Number(randint(0, this.height)).toString()
			);
		}
		string_to_return += '{0},{1}" fill="none" stroke="rgb({2},{3},{4})" stroke-width="{5}"/>'.format(
			Number(randint(0, this.width)).toString(),
			Number(randint(0, this.height)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(this.min_stroke, this.max_stroke)).toString()
		);
		return string_to_return;
	}



	__add_random_curve() {
		var string_to_return = '<path d="M{0} {1} '.format(
			Number(randint(0, Math.round(this.width / 2))).toString(),
			Number(randint(0, Math.round(this.height / 2))).toString()
		);
		var number_of_points = randint(2, 10);
		for (var i = 0; i < number_of_points; i++) {
			string_to_return += 'T{0} {1} '.format(
				Number(randint(0, Math.round(this.width / 2))).toString(),
				Number(randint(0, Math.round(this.height / 2))).toString()
			);
		}
		string_to_return += 'Z" fill="rgb({0},{1},{2})" stroke="rgb({3},{4},{5})" stroke-width="{6}"/>'.format(
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(this.min_stroke, this.max_stroke)).toString()
		);
		return string_to_return;
	}

	__add_random_gradient() {
		var gradient_id = randint(1000000, 99999999);
		var string_to_return = '<defs><radialGradient id="grad{0}" cx="{1}%" cy="{2}%" r="{3}%" fx="{4}%" fy="{5}%"><stop offset="0%" style="stop-color:rgb({6},{7},{8});stop-opacity:0"/>'.format(
			Number(gradient_id).toString(),
			Number(randint(0, 100)).toString(),
			Number(randint(0, 100)).toString(),
			Number(randint(0, 100)).toString(),
			Number(randint(0, 100)).toString(),
			Number(randint(0, 100)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString()
		);

		string_to_return += '<stop offset="100%" style="stop-color:rgb({0},{1},{2});stop-opacity:1"/></radialGradient></defs><rect width="{3}" height="{4}" fill="url(#grad{5})" fill-opacity="{6}%"/>'.format(
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(randint(0, 255)).toString(),
			Number(this.width).toString(),
			Number(this.height).toString(),
			Number(gradient_id).toString(),
			Number(randint(0, 100)).toString()
		);

		return string_to_return;
	}
}