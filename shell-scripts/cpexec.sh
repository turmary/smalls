#!/bin/sh

# usage:
#   copy files with specific attributes
#
# command  : cpattr [options] src target
#   src    : the root of file(s) tree be copy
#   target : the root of file(s) copy to
#
# options  :
#     -i interactive, if used, the program asks
#        if the file will be overwrite
#     -d display, only display the file in the operation set
#        don't copy them

print_usage()
{
	echo "usage:"
	echo "  copy files with specific attributes"
	echo
	echo "command  : $0 [options] src target"
	echo "  src    : the root of file(s) tree be copy"
	echo "  target : the root of file(s) copy to"
	echo
	echo "options  :"
	echo "    -i interactive, if used, the program asks"
	echo "       if the file will be overwrite"
	echo "    -d display, only display the file in the operation set"
	echo "       don't copy them"
	exit 1
}

# this is the name of target 
export target="$HOME"
export src=""

# if this flag is true then we need to do interactive processing.
iactive=$(false; echo $?)

# if this flag is true then we don't copy files
display=$(false; echo $?)


cpfile() {
	file="$1"
	if [ "$display" = "0" ]; then
		echo "$file copied"
	elif [ -f "${target}/${file}" -a "$iactive" = "0" ]; then
			echo "do you relly want to copy file $file ?(y/n)n\b\c"
			read doit
			if [ "${doit:-n}" = "n" ]; then
				return
			fi
	fi
	cp "$file" "${target}/${file}"
}

copynest() {
	for f in $(ls -a); do
		if [ -d "$f" -a "$f" != "." -a "$f" != ".." ]; then
			cd "$1"
			echo "pwd=$(pwd)"
			copynest "$f"
			cd ..
		else
			if [ -f "$f" -a -x "$f" ]; then
				cpfile "$f"
			fi
		fi
	done
}

# copynest $cur;
if [ $# -lt 2 ]; then
	print_usage;
fi


# Make sure the target directory exists before we go any further
if [ ! -d $target ]; then
	mkdir -p $target
fi

for arg in $*; do
	case $1 in
	-help)
		print_usage
		;;
	-d)
		display=$(true; echo $?)
		;;
	-i)
		iactive=$(true; echo $?)
		;;
	-*)
		print_usage
		;;
	*)
		src="$1"
		if test -n "$2"; then
			cur="$(pwd)"
			cd "$2"
			target="$(pwd)"
			cd "$cur"
		fi
		break
		;;
	esac
	shift
done

tmp="$(pwd)"
cd "$src"
copynest "$src"
cd "$tmp"

exit 0

