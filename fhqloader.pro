QT += gui core widgets

TARGET = fhqloader
CONFIG += console release app_bundle
TEMPLATE = app
OBJECTS_DIR = tmp/
MOC_DIR = tmp/

RESOURCES = \
	fhqloader.qrc

SOURCES += \
	main.cpp \
