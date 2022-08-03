#!/bin/bash

MONITOR_URL=${1:-"http://192.168.56.2:3142/deploy/NewApplication-vLatest.tar.gz"}
shift
CMD_A_ARGS="${@:-"./AppRun --debuglevel 3"}"

echo MONITOR_URL=$MONITOR_URL
LOCK_URL="${MONITOR_URL%/*}/lock"
PKG_NAME="${MONITOR_URL##*/}"
EXTT_DIR="extract"
LAST_SIZE=0

LAST_PID=

function appimage_run() {
    # kill the last program
    [ "$LAST_PID" ] && {
        kill -9 "$LAST_PID"
        while [ -d "/proc/$LAST_PID" ]; do
            echo -ne "@"
            sleep 1
        done
    }

    [ -d "$EXTT_DIR" ] || mkdir "$EXTT_DIR"

    (cd "$EXTT_DIR"; rm -rf $(ls -A1 ./) )
    tar --strip-components=1 -C "$EXTT_DIR" -xvf "$PKG_NAME"

    # RUN!!!
    pushd "$EXTT_DIR" &> /dev/null
    $CMD_A_ARGS & LAST_PID="$!"
    popd
}

while true; do
    sleep 1
    echo -ne "#"
    wget --spider $LOCK_URL &>/dev/null && {
        continue
    }
    NEW_SIZE=$(wget --spider $MONITOR_URL 2>&1 | sed -nr '/Length:/s,Length: ([0-9]+).*,\1,p')
    # file not exist
    [ ! "$NEW_SIZE" ] && continue
    # file not changed
    [ "$NEW_SIZE" -eq "$LAST_SIZE" ] && continue

    # download fail
    wget -O "$PKG_NAME" "$MONITOR_URL" || continue
    [ -s "$PKG_NAME" ] || continue

    appimage_run
    LAST_SIZE="$NEW_SIZE"
done

exit 0

