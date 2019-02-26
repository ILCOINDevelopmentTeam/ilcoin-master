
Debian
====================
This directory contains files used to package ilcoind/ilcoin-qt
for Debian-based Linux systems. If you compile ilcoind/ilcoin-qt yourself, there are some useful files here.

## ilcoin: URI support ##


ilcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install ilcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your ilcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/ilcoin128.png` to `/usr/share/pixmaps`

ilcoin-qt.protocol (KDE)

