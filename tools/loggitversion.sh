#!/bin/sh

UVG_BRANCH=`git branch --show-current`

if [ x"${UVG_BRANCH}" = "main" ] ; then
	UVG_TAG=`git describe --tags --abbrev=0`
	echo "${UVG_TAG}"
else
	LAST_COMMIT_ID=`git log --format="%h" -n 1`
	echo "${LAST_COMMIT_ID}"
fi
