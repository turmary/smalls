#!/bin/bash

GUIDE=single-debian-guide.html

: > $GUIDE

# 1. manually generate cover.html and toc.html by dividing
#   https://www.debian.org/doc/manuals/debian-handbook/index.zh-cn.html
#
# 2. acquire missing resource files when running wkhtmltopdf firstly,
# png.list is the file with content of program error output
#   files=$(sed -nre 's,.*localhost/([^ ]+).*,\1,gp' png.list | sort | uniq)
#   for f in $files; do wget https://www.debian.org/doc/manuals/debian-handbook/$f -O $f; done
#
# 3. run this script to generate single-debian-guide.html
#
# 4. put all all resources & single-debian-guide.html into localhost HTTP server root directory
#
# 5. begin the generating, run wkhtmltopdf again
#   wkhtmltopdf cover http://localhost/cover.html toc http://localhost/single-debian-guide.html debian-handbook.zh-cn.pdf


# merged map
declare -A mm

first=yes

urls=$(sed -nre 's,.*<a +href="([^"]+)".*$,\1,gp' toc.html)
for u in ${urls}; do
	f=${u##*/}
	rl=${f%\#*}
	id=${rl//./-}
	# (echo $rl | tr '.' '-')
	# $id
	while [ ! -s $rl ]; do
		wget "https://www.debian.org/doc/manuals/debian-handbook/$rl" -O "$rl"
		sleep 1;
	done

	[ -z "${mm["$rl"]}" ] || continue

	echo ""
	echo "=========================="
	echo $rl
	echo "--------------------------"

	echo $rl --- $id

	hrefs=$(sed -nre 's,^|$,\n,g; s,href="([^"/@#]+#?[^"/@#]*)",\n=\1\n,g; s,\n[^=\n][^\n]*\n,\n,g; s,\n+=,\n,gp' $rl | sort | uniq)
	#echo $hrefs

	[ "$first" ] && {
		ss=" s,</body>|</html>,,g; s,<body>,<body><a id=\"$id\"></a>,;"
	} || {
		ss=' s,<\?xml[^>]*>,,g; s,<!DOCTYPE[^>]*>,,g; s,<html[^>]*>,,g; s,<head>.*</head>,,g; s,<body>|</body>|</html>,,g;'
	}
	# ss=' s,(href="[^"]*)#+,\1#,g;'
	for h in $hrefs; do
		[ "$h" == "#" ] && continue
		if [[ $h =~ [^#]*#[^#]* ]]; then
			tag=${h#*\#}
			ss="$ss s,\"$h\",\"#${tag}\",g;"
		else
			ss="$ss s,\"$h\",\"#${h//./-}\",g;"
		fi
	done

	echo Sed script: $ss
	{
		[ "$first" ] || echo "<a id=\"$id\"></a>"
		# echo "<iframe src=\"$rl\" width=\"100%\">"
		# echo "</iframe>"
		cat $rl | sed -re "$ss"
		echo -ne "\n\n\n"
	} >> $GUIDE
	mm["$rl"]="X"

	first=
done
echo "</body></html>" >> $GUIDE

