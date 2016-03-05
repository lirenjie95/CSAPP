echo off
fc /b result.txt my.txt&&(echo  They are the same.)||(echo They are different.)
pause