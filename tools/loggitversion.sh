#!/bin/sh

UVG_BRANCH=`git branch --show-current`

if [ "${UVG_BRANCH}" = "main" ] ; then
	UVG_TAG=`git describe --tags --abbrev=0 2>/dev/null`
	COMMIT_NUMBER=$(git rev-list  `git rev-list --tags --no-walk --max-count=1`..HEAD --count 2>/dev/null)
	LAST_COMMIT_ID=`git log --format="%h" -n 1`

	if [ "${UVG_TAG}" = "" ] ; then
		UVG_TAG="main"
	fi

	if [ "${COMMIT_NUMBER}" = "" ] ; then
		UVG_PACKAGE_VERSION="${UVG_TAG}"-"${LAST_COMMIT_ID}"
	else
		COMMIT_NUMBER=."${COMMIT_NUMBER}"
		echo "${COMMIT_NUMBER}"
		UVG_PACKAGE_VERSION="${UVG_TAG}""${COMMIT_NUMBER}"-"${LAST_COMMIT_ID}"
	fi
else
	LAST_COMMIT_ID=`git log --format="%h" -n 1`
	UVG_PACKAGE_VERSION="${UVG_BRANCH}"-"${LAST_COMMIT_ID}"
fi

echo "${UVG_PACKAGE_VERSION}"
