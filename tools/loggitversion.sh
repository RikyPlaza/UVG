#!/bin/sh

UVG_BRANCH=`git branch --show-current`

if [ "${UVG_BRANCH}" = "main" ] ; then
	UVG_TAG=`git describe --tags --abbrev=0`
	echo "${UVG_TAG}"
else
	LAST_COMMIT_ID=`git log --format="%h" -n 1`
	UVG_PACKAGE_VERSION="${UVG_BRANCH}"-"${LAST_COMMIT_ID}"
	echo "${UVG_PACKAGE_VERSION}"
fi
