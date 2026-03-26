@echo off
:loop

	set path=C:\Users\28633\AppData\Local\Programs\Python\Python311
	python makedata.py >data.in

	set path=C:\msys64\mingw64\bin
	cpp std.cpp <data.in >std.out
	cpp bf.cpp <data.in >bf.out

	set path=C:\Windows\System32
	fc std.out bf.out
	if errorlevel == 1 pause
goto loop

