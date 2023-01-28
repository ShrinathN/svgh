# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file '/home/shinu/Documents/C/vg/svg_generator_qt/svg_generator.ui'
#
# Created by: PyQt5 UI code generator 5.15.6
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Form(object):
    def setupUi(self, Form):
        Form.setObjectName("Form")
        Form.resize(1789, 908)
        self.gridLayout = QtWidgets.QGridLayout(Form)
        self.gridLayout.setObjectName("gridLayout")
        self.spinBox_width = QtWidgets.QSpinBox(Form)
        self.spinBox_width.setMinimum(1)
        self.spinBox_width.setMaximum(10000)
        self.spinBox_width.setProperty("value", 3840)
        self.spinBox_width.setObjectName("spinBox_width")
        self.gridLayout.addWidget(self.spinBox_width, 2, 2, 1, 1)
        self.label_3 = QtWidgets.QLabel(Form)
        self.label_3.setObjectName("label_3")
        self.gridLayout.addWidget(self.label_3, 4, 1, 1, 1)
        self.graphicsView = QtWidgets.QGraphicsView(Form)
        self.graphicsView.setObjectName("graphicsView")
        self.gridLayout.addWidget(self.graphicsView, 2, 0, 10, 1)
        self.label = QtWidgets.QLabel(Form)
        self.label.setObjectName("label")
        self.gridLayout.addWidget(self.label, 2, 1, 1, 1)
        self.spinBox_maxstroke = QtWidgets.QSpinBox(Form)
        self.spinBox_maxstroke.setMinimum(1)
        self.spinBox_maxstroke.setMaximum(200)
        self.spinBox_maxstroke.setProperty("value", 100)
        self.spinBox_maxstroke.setObjectName("spinBox_maxstroke")
        self.gridLayout.addWidget(self.spinBox_maxstroke, 6, 2, 1, 1)
        self.label_2 = QtWidgets.QLabel(Form)
        self.label_2.setObjectName("label_2")
        self.gridLayout.addWidget(self.label_2, 3, 1, 1, 1)
        self.pushButton_save = QtWidgets.QPushButton(Form)
        self.pushButton_save.setObjectName("pushButton_save")
        self.gridLayout.addWidget(self.pushButton_save, 11, 1, 1, 2)
        self.spinBox_height = QtWidgets.QSpinBox(Form)
        self.spinBox_height.setMinimum(1)
        self.spinBox_height.setMaximum(10000)
        self.spinBox_height.setProperty("value", 2160)
        self.spinBox_height.setObjectName("spinBox_height")
        self.gridLayout.addWidget(self.spinBox_height, 3, 2, 1, 1)
        self.pushButton_generate = QtWidgets.QPushButton(Form)
        self.pushButton_generate.setObjectName("pushButton_generate")
        self.gridLayout.addWidget(self.pushButton_generate, 10, 1, 1, 2)
        self.label_4 = QtWidgets.QLabel(Form)
        self.label_4.setObjectName("label_4")
        self.gridLayout.addWidget(self.label_4, 6, 1, 1, 1)
        self.spinBox_elements = QtWidgets.QSpinBox(Form)
        self.spinBox_elements.setProperty("value", 2)
        self.spinBox_elements.setObjectName("spinBox_elements")
        self.gridLayout.addWidget(self.spinBox_elements, 4, 2, 1, 1)
        self.groupBox = QtWidgets.QGroupBox(Form)
        self.groupBox.setObjectName("groupBox")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.groupBox)
        self.verticalLayout.setObjectName("verticalLayout")
        self.radioButton_random = QtWidgets.QRadioButton(self.groupBox)
        self.radioButton_random.setObjectName("radioButton_random")
        self.verticalLayout.addWidget(self.radioButton_random)
        self.radioButton_rectangle = QtWidgets.QRadioButton(self.groupBox)
        self.radioButton_rectangle.setObjectName("radioButton_rectangle")
        self.verticalLayout.addWidget(self.radioButton_rectangle)
        self.radioButton_circle = QtWidgets.QRadioButton(self.groupBox)
        self.radioButton_circle.setObjectName("radioButton_circle")
        self.verticalLayout.addWidget(self.radioButton_circle)
        self.radioButton_ellipse = QtWidgets.QRadioButton(self.groupBox)
        self.radioButton_ellipse.setObjectName("radioButton_ellipse")
        self.verticalLayout.addWidget(self.radioButton_ellipse)
        self.radioButton_line = QtWidgets.QRadioButton(self.groupBox)
        self.radioButton_line.setObjectName("radioButton_line")
        self.verticalLayout.addWidget(self.radioButton_line)
        self.radioButton_polygon = QtWidgets.QRadioButton(self.groupBox)
        self.radioButton_polygon.setChecked(True)
        self.radioButton_polygon.setObjectName("radioButton_polygon")
        self.verticalLayout.addWidget(self.radioButton_polygon)
        self.radioButton_polyline = QtWidgets.QRadioButton(self.groupBox)
        self.radioButton_polyline.setChecked(False)
        self.radioButton_polyline.setObjectName("radioButton_polyline")
        self.verticalLayout.addWidget(self.radioButton_polyline)
        self.radioButton_curve = QtWidgets.QRadioButton(self.groupBox)
        self.radioButton_curve.setObjectName("radioButton_curve")
        self.verticalLayout.addWidget(self.radioButton_curve)
        self.radioButton_gradient = QtWidgets.QRadioButton(self.groupBox)
        self.radioButton_gradient.setObjectName("radioButton_gradient")
        self.verticalLayout.addWidget(self.radioButton_gradient)
        self.gridLayout.addWidget(self.groupBox, 7, 1, 1, 2)
        self.label_5 = QtWidgets.QLabel(Form)
        self.label_5.setObjectName("label_5")
        self.gridLayout.addWidget(self.label_5, 5, 1, 1, 1)
        self.spinBox_minstroke = QtWidgets.QSpinBox(Form)
        self.spinBox_minstroke.setMinimum(1)
        self.spinBox_minstroke.setMaximum(100)
        self.spinBox_minstroke.setObjectName("spinBox_minstroke")
        self.gridLayout.addWidget(self.spinBox_minstroke, 5, 2, 1, 1)

        self.retranslateUi(Form)
        QtCore.QMetaObject.connectSlotsByName(Form)
        Form.setTabOrder(self.spinBox_width, self.spinBox_height)
        Form.setTabOrder(self.spinBox_height, self.spinBox_elements)
        Form.setTabOrder(self.spinBox_elements, self.radioButton_random)
        Form.setTabOrder(self.radioButton_random, self.radioButton_rectangle)
        Form.setTabOrder(self.radioButton_rectangle, self.radioButton_circle)
        Form.setTabOrder(self.radioButton_circle, self.radioButton_ellipse)
        Form.setTabOrder(self.radioButton_ellipse, self.radioButton_line)
        Form.setTabOrder(self.radioButton_line, self.radioButton_polygon)
        Form.setTabOrder(self.radioButton_polygon, self.radioButton_polyline)
        Form.setTabOrder(self.radioButton_polyline, self.radioButton_curve)
        Form.setTabOrder(self.radioButton_curve, self.radioButton_gradient)
        Form.setTabOrder(self.radioButton_gradient, self.pushButton_generate)
        Form.setTabOrder(self.pushButton_generate, self.pushButton_save)
        Form.setTabOrder(self.pushButton_save, self.graphicsView)

    def retranslateUi(self, Form):
        _translate = QtCore.QCoreApplication.translate
        Form.setWindowTitle(_translate("Form", "SVG Generator"))
        self.label_3.setText(_translate("Form", "<html><head/><body><p>Number of </p><p>elements</p></body></html>"))
        self.label.setText(_translate("Form", "Width"))
        self.label_2.setText(_translate("Form", "Height"))
        self.pushButton_save.setText(_translate("Form", "Save"))
        self.pushButton_generate.setText(_translate("Form", "Generate"))
        self.label_4.setText(_translate("Form", "Max stroke"))
        self.groupBox.setTitle(_translate("Form", "Elements"))
        self.radioButton_random.setText(_translate("Form", "Randomized"))
        self.radioButton_rectangle.setText(_translate("Form", "Rectangle"))
        self.radioButton_circle.setText(_translate("Form", "Circle"))
        self.radioButton_ellipse.setText(_translate("Form", "Ellipse"))
        self.radioButton_line.setText(_translate("Form", "Line"))
        self.radioButton_polygon.setText(_translate("Form", "Polygon"))
        self.radioButton_polyline.setText(_translate("Form", "Polyline"))
        self.radioButton_curve.setText(_translate("Form", "Curve"))
        self.radioButton_gradient.setText(_translate("Form", "Gradient"))
        self.label_5.setText(_translate("Form", "Min Stroke"))