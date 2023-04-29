#!/bin/bash

function is_prime() {
	local nr=$1

	((nr < 2)) && return 1
	for ((i = 2; i * i <= nr; i++)); do
		((nr % i == 0)) && return 1
	done
	return 0
}

coproc PRIMES {
	while read nr; do
		[ "$nr" == "quit" ] && {
			echo $nr; break
		}
		is_prime $nr && echo $nr
	done
	echo "COPROC EXIT!" >&2
}

# set | grep "PRIMES"
echo "COPROC[] = ${PRIMES[@]}" >&2
# ${PRIMES} is not visible to subprocess/subshell
# effective
exec 32>&${PRIMES[1]}
# ls -al /dev/fd/

# :<<-\COMMENT
{
	for ((i = 900000000; i < 900000512; i++)); do
		# no effective
		# eval "echo $i >&${PRIMES[1]}"
		echo $i
		# sleep 0.001
	done
	echo "quit"
} >&32 &
# COMMENT

while read -u "${PRIMES[0]}" nr; do
	echo "#$nr"
	[ "$nr" == "quit" ] && break
done
