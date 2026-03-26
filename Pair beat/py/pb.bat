@echo off
:loop

set path=C:\Users\28633\AppData\Local\Programs\Python\Python311
python makedata.py >data.in

python std.py <data.in >std.out
python bruteforce.py <data.in >bruteforce.out

set path=C:\Windows\System32
fc std.out bruteforce.out
if errorlevel == 1 pause
goto loop

