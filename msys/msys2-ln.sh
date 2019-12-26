#!/bin/bash

# https://stackoverflow.com/questions/12015348/msys-path-conversion-or-cygpath-for-msys
function winpath() {
    if [ ${#} -eq 0 ]; then
        : skip
    elif [ -f "$1" ]; then
        local dirname=$(dirname "$1")
        local basename=$(basename "$1")
        echo "$(cd "$dirname" && pwd -W)/$basename" \
        | sed \
          -e 's|/|\\|g';
    elif [ -d "$1" ]; then
        echo "$(cd "$1" && pwd -W)" \
        | sed \
          -e 's|/|\\|g';
    else
        echo "$1" \
        | sed \
          -e 's|^/\(.\)/|\1:\\|g' \
          -e 's|/|\\|g'
    fi
}

function unixpath() {
    echo "$1" \
    | sed -r \
      -e 's/\\/\//g' \
      -e 's/^([^:]+):/\/\1/'
}

## https://superuser.com/questions/550732/use-mklink-in-msys

if [ "$#" -eq 2 -a "$1" == "-s" ]; then
    TARGET="$2"
    LINK=$(basename "$TARGET")
elif [ "$#" -eq 3 -a "$1" == "-s" ]; then
    TARGET="$2"
    LINK="$3"
else
    echo "this weak implementation only supports \`ln -s\`"
    exit
fi

if [ -d "$TARGET" ]; then
    MKLINK_OPTS="//d"
fi

TARGET=$(winpath "$TARGET")
LINK=$(winpath "$LINK")

echo "$LINK => $TARGET"
cscript //nologo /usr/bin/run-elevated.js \
    cmd //c mklink $MKLINK_OPTS "$LINK" "$TARGET"
