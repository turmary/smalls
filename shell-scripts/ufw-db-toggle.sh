#!/bin/bash

# enable UFW first

SRVIP=${1:-192.168.2.8}

SRVIPDOT=$(echo $SRVIP | sed -ne 's,\.,\\\.,gp')
[ "$SRVIPDOT" ] || exit 1

echo SRVIP=$SRVIP

while true; do
    # https://killcx.sourceforge.net/
    killcx $SRVIP:3306
    ufw deny out from any to $SRVIP || exit 2

    # nr=$(ufw status numbered | sed -nre "s,^\[ *([0-9]+)\] +$SRVIPDOT.*,\1,gp")
      nr=$(ufw status numbered | sed -ne  "s,^\[ *\([0-9]\+\)] \+$SRVIPDOT.*,\1,gp")
    sleep 20
    [ "$nr" ] && ufw --force delete $nr
    sleep 20
done

