#!/bin/sh

date=05/13/2007

month=${date%%/**}
dm=${date%/**}
day=${dm#*/}
let "year = `basename $date`"	# ${date##*/}

echo $month
echo $day
echo $year
