#!/bin/bash

function is_ln_nativestrict() {
	local _old_MSYS tf r

	if [ "X${MSYS+set}" == "Xset" ]; then
		_old_MYS="$MSYS"
	else
		unset _old_MYS
	fi
	export MSYS="winsymlinks:nativestrict"

	tf=`mktemp`; rm -f $tf
	ln -s /bin/sh $tf
	file $tf | grep "symbolic link" > /dev/null; r=$?

	if [ "X${_old_MSYS+set}" == "Xset" ]; then
		export MSYS="$_old_MYS"
	else
		unset MYS
	fi

	return $r
}

if is_ln_nativestrict; then
	### grep -E "^[ ]*(export)? *MSYS=" $CONF || {
	CONF="/etc/profile.d/winsymlinks.sh"
	[ -f "$CONF" ] || {
		cat >> $CONF <<-\__EOF__

		export MSYS="winsymlinks:nativestrict"

		__EOF__
	}
else
	CONF="$HOME/.profile"
	[ ! -f $CONF ] && touch $CONF

	[ -f /usr/bin/msys2-ln.sh ] || {
		cp msys2-ln.sh     /usr/bin
		cp run-elevated.js /usr/bin
		cat >> $CONF <<-\__EOF__

		alias ln='msys2-ln.sh'

		__EOF__
	}
fi

source $CONF

# enable git symbolic link
# https://www.joshkel.com/2018/01/18/symlinks-in-windows/
type git > /dev/null && git config --system core.symlinks true
