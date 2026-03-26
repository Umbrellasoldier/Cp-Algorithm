@echo off
set path=C:\Users\28633\AppData\Local\Programs\Python\Python311
python C.py <sample1.in >C.out
set path=C:\Windows\System32
fc /N C.out sample1.out
pause