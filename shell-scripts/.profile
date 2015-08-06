# ~/.profile: executed by Bourne-compatible login shells.

if [ "$BASH" ]; then
    if [ -f ~/.bashrc ]; then
	. ~/.bashrc
    fi
fi

mesg n
# Installed by Debian Installer:
#  no localization for root because zh_CN.UTF-8
#  cannot be properly displayed at the Linux console
LANG=C
LANGUAGE=C

export PATH="${PATH}:~/shellprogs"

