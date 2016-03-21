echo off
fc /b SortedFile.txt my.txt&&(echo  They are the same.)||(echo They are different.)
pause