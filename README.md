	  ____  _____   _____       _    _ _____ 
	 |___ \|  __ \ / ____|     | |  | |_   _|
	   __) | |  | | (___ ______| |  | | | |  
	  |__ <| |  | |\___ \______| |  | | | |  
	  ___) | |__| |____) |     | |__| |_| |_ 
	 |____/|_____/|_____/       \____/|_____|
[![Build Status](http://build.filfatstudios.com:8080/job/3DS_UI/badge/icon)](http://build.filfatstudios.com:8080/job/3DS_UI/) [![Donation Status](https://img.shields.io/gratipay/filfat.svg)](https://gratipay.com/filfat/)
==
**THIS PROJECT IS STILL IN DEVELOPMENT; AND THEREFORE ISN'T READY FOR USE**

An opensource GPU driven graphical-user-interface library/framework for the Nintendo 3DS. See the [Roadmap](https://github.com/filfat/3DS_UI/wiki/Roadmap)

![](http://i.imgur.com/vZhM9Ff.png?1)

*screenshot of "Example 1" from commit 5cf72f0925*

Usage
====
Start by cloning this repo or download the latest release, then type ` make install ` in either cmd or a terminal followed by adding the following `-l3DSGUI -lsf2d ` to the start of  ` LIBS	:=  ` but after ` := ` (see the examples)

Documentation
===
See The [Wiki](https://github.com/filfat/3DS_UI/wiki/), [3DS-UI Documentation](http://www.filfatstudios.com/products/3DS_UI) and ` /doc `

Dependencies
====
* [devkitarm](http://devkitpro.org/wiki/Getting_Started/devkitARM)
* [libctru](https://github.com/smealum/ctrulib)
* [sf2dlib](https://github.com/xerpi/sf2dlib)
* [freetype2](https://github.com/mtheall/3ds_portlibs)
* [sftdlib](https://github.com/xerpi/sftdlib)
* [sfillib](https://github.com/xerpi/sfillib)

Credits
====
* Filiph Sandström (@filfat)
* WinterMute for devkitarm
* Smealum & C.o. for Ninjhax and CTRULIB
* Xerpi for sf2dlib
