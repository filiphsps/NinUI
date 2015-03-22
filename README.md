	  ____  _____   _____       _    _ _____ 
	 |___ \|  __ \ / ____|     | |  | |_   _|
	   __) | |  | | (___ ______| |  | | | |  
	  |__ <| |  | |\___ \______| |  | | | |  
	  ___) | |__| |____) |     | |__| |_| |_ 
	 |____/|_____/|_____/       \____/|_____|
![Build Status](http://build.filfatstudios.com:8080/buildStatus/icon?job=3DS_GUI) [![Donation Status](https://img.shields.io/gratipay/filfat.svg)](https://gratipay.com/filfat/)
==
An opensource graphical-user-interface library for the Nintendo 3DS

Usage
====
Start by cloning this repo and type ` make install ` (for both 3DS_UI & sf2dlib) then add the following `-l3DSGUI -lsf2d ` to the start of  ` LIBS	:=  ` (see the examples)

Documentation
===
See ` /doc ` and [filfatstudios.com](http://www.filfatstudios.com/3DS_UI)

Dependencies
====
* [devkitarm](http://devkitpro.org/wiki/Getting_Started/devkitARM)
* [libctru](https://github.com/smealum/ctrulib)
* [sf2dlib](https://github.com/xerpi/sf2dlib)

Credits
====
* Filiph Sandström (@filfat)
* WinterMute for devkitarm
* Smealum & C.O. for Ninjhax and CTRULIB
* Xerpi for sf2dlib
