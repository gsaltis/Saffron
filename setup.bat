@echo off
doskey m=make release $T make debug
doskey mr=pskill saffron $T make -j 8 release
doskey md=pskill saffron $T make -j 8 debug
doskey mc=make cleanall
doskey mq=qmake
doskey sa=release\saffron $*
doskey sad=debug\saffron $*
doskey gsp=gdb debug\saffron.exe
doskey sp=release\saffron -s SystemHome.json -p Test01
title Saffron
