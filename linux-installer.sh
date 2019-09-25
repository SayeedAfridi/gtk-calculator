#!/bin/bash
if [ $EUID -ne 0 ]; then
	echo ERROR: You must run this as root
	exit
fi

DIR=executables
INSTALLDIR=/opt/gtk-calculator
SYM=/usr/bin/gtk-calculator
OP=/opt/gtk-calculator/executables/gtk-calculator

sudo mkdir -p INSTALLDIR


if [ -d ${INSTALLDIR} ]; then
	echo "Previously installed file found"
	echo "Updating..."
	rm -r ${INSTALLDIR}
	rm ${SYM}
else
	echo "No previous installation found"
	echo "configuring New installation..."
	sudo mkdir -p /opt/gtk-calculator
fi

if [ -d ${DIR} ]; then
	echo "Moving file to $INSTALLDIR"
	sudo cp design  /opt/gtk-calculator/ -R
	sudo cp -R executables /opt/gtk-calculator/
	echo "Symlining to $SYM"
	sudo ln -s ${OP} ${SYM}
	echo "Creating desktop entry..."
	sudo cp gtk-calculator.desktop /usr/share/applications/gtk-calculator.desktop
	echo "Installation Complete..."
	exit
else
	echo "No installation file found"
	echo "Installation Failed..."
fi
