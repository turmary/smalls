#!/bin/bash

function is_ln_nativestrict() {
	local _old_MSYS tf r

	if [ "X${MSYS+set}" == "Xset" ]; then
		_old_MYS="$MSYS"
	else
		unset _old_MYS
	fi
	export MSYS="winsymlinks:nativestrict"

	tf="/tmp/$RANDOM";
	{
		rm -f $tf
		ln -s /bin/sh $tf
	} >/dev/null 2>&1
	file $tf | grep "symbolic link" > /dev/null; r=$?
	rm -f $tf

	if [ "X${_old_MSYS+set}" == "Xset" ]; then
		export MSYS="$_old_MYS"
	else
		unset MYS
	fi

	return $r
}

# allow to run the script file XXX.{vbs,js} directly
[ -f /usr/bin/cscript-wrap ] || {
	cp cscript-wrap /usr/bin
}

_newhome=$(./find-home.js)
if [ "X$_newhome" != "X" ]; then
	CONF="/etc/profile.d/overridehome.sh"
	[ -f "$CONF" ] || {
		cat > $CONF <<-\__EOF__
		export HOME=/home/$USERNAME
		cd $HOME
		__EOF__
	}
	mount | grep -E "^.* on */home +" >/dev/null || {
		type cygpath > /dev/null && {
echo "$_newhome /home none bind,posix=0,noacl,user 0 0" >> /etc/fstab;
		} || {
			echo "$_newhome /home" >> /etc/fstab;
		}
		mount $_newhome /home;
	}
fi

pushd . >/dev/null 2>&1
source $CONF
unset CONF
unset _newhome
popd    >/dev/null 2>&1

if is_ln_nativestrict; then
	### grep -E "^[ ]*(export)? *MSYS=" $CONF || {
	CONF="/etc/profile.d/winsymlinks.sh"
	[ -f "$CONF" ] || {
		cat > $CONF <<-\__EOF__

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
unset CONF

# enable git symbolic link
# https://www.joshkel.com/2018/01/18/symlinks-in-windows/
type git > /dev/null && git config --system core.symlinks true

echo "### Restart MSYS to take HOME EFFECT ###"
