#!/bin/bash
# find -type d -name "\.git" -exec sh -c "cd {}/..; git remote get-url origin" \;

URL_PRE="https://ghproxy.com/"

pushd /var/lib/docker/volumes/armbian-cache/_data/sources &>/dev/null || {
	echo "No permission to access /var/lib/..., exiting"
	exit 1
}

repos="$(find . -type d -name "\.git")"
# echo "repos=$repos"

for rp in $repos; do
	rp=$(realpath --relative-to=$PWD $rp/..)
	url=$(cd $rp; git remote get-url origin)

	[[ "$url" =~ ^https://github.com/.* ]] || {
		printf "OMMIT: %-30s : %s\n" $rp $url
		continue
	}
	url="$URL_PRE$url"
	( cd $rp; git remote set-url origin $url )
	printf "OK   : %-30s : %s\n" $rp $url
done

popd &>/dev/null

exit 0
