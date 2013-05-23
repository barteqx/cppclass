#!/bin/bash
files=`find *.c*`; 
for x in $files ; do
	ls -l "$x"
done