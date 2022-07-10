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
	} &> /dev/null
	file $tf | grep "symbolic link" &> /dev/null; r=$?
	rm -f $tf

	if [ "X${_old_MSYS+set}" == "Xset" ]; then
		export MSYS="$_old_MYS"
	else
		unset MYS
	fi

	return $r
}

# https://stackoverflow.com/questions/36770716/mingw64-make-build-error-bash-make-command-not-found
function try_install_make() {
	local tf r make_url

	make_url="https://nchc.dl.sourceforge.net/project/ezwinports/make-4.3-without-guile-w32-bin.zip"
	if ! which make >& /dev/null && which unzip >& /dev/null; then
		tf="/tmp/make.zip"
		# this 4.3 version make also has problem:
		# \usr\bin\rm.exe: *** fatal error - Too many levels of nesting for ??????
		curl -L -o $tf $make_url
		if [ -f $tf ] && [ -s $tf ]; then
			unzip -n $tf -d /usr
			rm -f $tf
		fi
	fi
	which make >& /dev/null; r=$?
	return $r
}

# https://docs.github.com/cn/authentication/connecting-to-github-with-ssh/working-with-ssh-key-passphrases
function install_ssh_agent() {
	cat >> $CONF <<-\__EOF__


	env=~/.ssh/agent.env

	agent_load_env () { test -f "$env" && . "$env" >| /dev/null ; }

	agent_start () {
	    (umask 077; ssh-agent >| "$env")
	    . "$env" >| /dev/null ; }

	agent_load_env

	# agent_run_state: 0=agent running w/ key; 1=agent w/o key; 2=agent not running
	agent_run_state=$(ssh-add -l >| /dev/null 2>&1; echo $?)

	if [ ! "$SSH_AUTH_SOCK" ] || [ $agent_run_state = 2 ]; then
	    agent_start
	    ssh-add
	elif [ "$SSH_AUTH_SOCK" ] && [ $agent_run_state = 1 ]; then
	    ssh-add
	fi

	unset env
__EOF__
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
		_CUR_USER=$USERNAME
		if [ "X$_CUR_USER" = "X" ]; then
		    _CUR_USER=$(whoami)
		fi
		if [ "X$_CUR_USER" = "X" ]; then
		    _CUR_USER=$USER
		fi
		export HOME=/home/$_CUR_USER
		unset _CUR_USER
		cd $HOME
		__EOF__
	}
	mount | grep -E "^.* on */home +" &> /dev/null || {
		type cygpath &> /dev/null && {
echo "$_newhome /home none bind,posix=0,noacl,user 0 0" >> /etc/fstab;
		} || {
			echo "$_newhome /home" >> /etc/fstab;
		}
		mount $_newhome /home;
	}
fi

pushd . &> /dev/null
source $CONF
unset CONF
unset _newhome
popd    &>/dev/null

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

		[ "X$MSYSTEM" == "XMINGW32" ] && \
		alias ln='msys2-ln.sh'

		__EOF__
	}
fi

source $CONF
unset CONF

CONF="$HOME/.bash_profile"
[ ! -f $CONF ] && cat > $CONF <<-\__EOF__
	# ~/.profile: executed by the command interpreter for login shells.
	# This file is not read by bash(1), if ~/.bash_profile or ~/.bash_login
	# exists.

	test -f ~/.profile && . ~/.profile

__EOF__
source $CONF

grep -E "^ *(\.|source).*\.bashrc" $CONF &> /dev/null || cat >> $CONF <<-\__EOF__
	# if running bash
	if [ -n "$BASH_VERSION" ]; then
	    # include .bashrc if it exists
	    if [ -f "$HOME/.bashrc" ]; then
	        . "$HOME/.bashrc"
	    fi
	fi
__EOF__

CONF="$HOME/.bashrc"
[ ! -f $CONF ] && cat > $CONF <<-\__EOF__
	# ~/.bashrc: executed by bash(1) for non-login shells.

__EOF__

alias grep &> /dev/null || {
	echo "alias grep='grep --color'" >> $CONF
}
alias egrep &> /dev/null || {
	echo "alias egrep='egrep --color'" >> $CONF
}

[ "$SSH_AGENT_PID" ] || install_ssh_agent

source $CONF
unset CONF

# enable git symbolic link
# https://www.joshkel.com/2018/01/18/symlinks-in-windows/
type git &> /dev/null && git config --system core.symlinks true

# install make
try_install_make

echo "### Restart MSYS to take HOME EFFECT ###"
