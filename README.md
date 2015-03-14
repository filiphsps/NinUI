# 3DS_GUI ![Build Status](http://build.filfatstudios.com:8080/buildStatus/icon?job=3DS_GUI) [![Donation Status](https://img.shields.io/gratipay/filfat.svg)](https://gratipay.com/filfat/)
An opensource graphical-user-interface library for the Nintendo 3DS

Usage
====
Start by cloning this repo and type ` make install ` then change the following line in your project's makefile ` LIBDIRS	:= $(CTRULIB) ` to ` LIBDIRS	:= $(CTRULIB) $(PORTLIBS) ` Also, add ` -l3DSGUI ` to the end of ` LIBS	:=  `

Documentation
===
See ` /doc `

Dependencies
====
* devkitarm
* libctru

Credits
====
* Filiph Sandström (@filfat)
