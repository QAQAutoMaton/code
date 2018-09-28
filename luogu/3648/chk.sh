#! /bin/sh
#
# chk.sh
# Copyright (C) 2018 lk <lk@lk-cnyali>
#
# Distributed under terms of the MIT license.
#

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color
BOLD=`tput bold`

i=0
for file in ./*.in;do
	let i=$i+1
	fullname=$(basename $file)
	filename=$(echo $fullname | cut -d . -f1)
	cp $fullname 3648.in
	./3648
	if ./checker $fullname 3648.out $filename.a ;then
		echo -e ${GREEN}${BOLD} ✔ Accepted${NC} on Test ${BOLD}\#$i${NC}; 
	else
		echo -e ${RED}${BOLD} ✘ Wrong Answer${NC} on Test ${BOLD}\#$i${NC} $fullname
	fi
done
