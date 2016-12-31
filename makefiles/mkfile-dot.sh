#!/bin/sh
# tary, 20:01 2016/12/19

awk -v FS="" '
	BEGIN {
		E_CHAR="'"'"'";
		print "digraph g{";
	}
	/ *File `/{
		gsub(/-/, "_");
		gsub(/\//, "_");
		gsub(/\./, "_");
		gsub(/@/, "_");
		gsub(/\\/, "_");

		for (c = 1; $c == " "; c++);
		level = c / 2 - 1;

		for (c = 1; $c != "`"; c++);
		b = c + 1;

		for (c = b; $c != E_CHAR; c++);
		l = c - b;

		nodes[level] = substr($0, b, l);

		if (level != 0) {
			printf("%s -> %s;\n",
				nodes[level - 1],
				      nodes[level]);
		}
	}
	END {
		print "}\n"
	}
';

