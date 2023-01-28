#!/bin/python3

from PyQt5 import uic, QtCore, QtWidgets, QtGui
from PyQt5 import *
from PyQt5.QtCore import QCoreApplication, QObject, QThread
from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
import sys
from PyQt5.QtSvg import QSvgWidget, QSvgRenderer
from RandomSvgGenerator import RandomSvgGeneratorClass
import time
from PyQt5.QtGui import QPainterPath, QPainter, QBrush


class Ui(QtWidgets.QWidget):

	def __init__(self):
		super(Ui, self).__init__()
		uic.loadUi('svg_generator.ui', self)
		self.pushButton_generate.clicked.connect(self.generate_image)
		self.pushButton_save.clicked.connect(self.save_image)
		self.image_data_str = ''
		self.show()

	def save_image(self) -> None:
		if(self.image_data_str != ''):
			filename = str(round(time.time())) + '.svg'
			file_handle = open(filename, 'w')
			file_handle.write(self.image_data_str)
			file_handle.close()


	def generate_image(self) -> None:
		self.image_width = self.spinBox_width.value()
		self.image_height = self.spinBox_height.value()
		self.elements = self.spinBox_elements.value()
		self.stroke_min = self.spinBox_minstroke.value()
		self.stroke_max = self.spinBox_maxstroke.value()
		self.random_checked = self.radioButton_random.isChecked()
		self.rectangle_checked = self.radioButton_rectangle.isChecked()
		self.circle_checked = self.radioButton_circle.isChecked()
		self.ellipse_checked = self.radioButton_ellipse.isChecked()
		self.line_checked = self.radioButton_line.isChecked()
		self.polygon_checked = self.radioButton_polygon.isChecked()
		self.polyline_checked = self.radioButton_polyline.isChecked()
		self.curve_checked = self.radioButton_curve.isChecked()
		self.gradient_checked = self.radioButton_gradient.isChecked()

		#generating image
		randomSvgGeneratorClass = RandomSvgGeneratorClass()
		randomSvgGeneratorClass.set_width(self.image_width)
		randomSvgGeneratorClass.set_height(self.image_height)
		randomSvgGeneratorClass.set_elements(self.elements)
		randomSvgGeneratorClass.set_random_checked(self.random_checked)
		randomSvgGeneratorClass.set_rectangle_checked(self.rectangle_checked)
		randomSvgGeneratorClass.set_circle_checked(self.circle_checked)
		randomSvgGeneratorClass.set_ellipse_checked(self.ellipse_checked)
		randomSvgGeneratorClass.set_line_checked(self.line_checked)
		randomSvgGeneratorClass.set_polygon_checked(self.polygon_checked)
		randomSvgGeneratorClass.set_polyline_checked(self.polyline_checked)
		randomSvgGeneratorClass.set_curve_checked(self.curve_checked)
		randomSvgGeneratorClass.set_gradient_checked(self.gradient_checked)
		randomSvgGeneratorClass.set_strokes(self.stroke_min, self.stroke_max)		
		randomSvgGeneratorClass.generate_image()

		#drawing image
		self.image_data_str = randomSvgGeneratorClass.return_image()
		self.draw_svg(self.image_data_str)

	def draw_svg(self, svg_string) -> None:
		self.graphicsView.setGeometry(0,0, self.image_width, self.image_height)
		svg_raw = bytearray(svg_string, encoding="utf-8")
		svg_widget = QSvgWidget(self.graphicsView)
		svg_widget.load(svg_raw)
		svg_widget.show()


app = QtWidgets.QApplication(sys.argv)
window = Ui()
app.exec_()