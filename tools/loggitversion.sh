#!/bin/sh

UVG_BRANCH=`git branch --show-current`

if [ "${UVG_BRANCH}" = "main" ] ; then
	UVG_TAG=`git describe --tags --abbrev=0`

	if [ "${UVG_TAG}" == *"fatal"* ] ; then
		UVG_TAG="main"
	fi

	COMMIT_NUMBER=`git rev-list  `git rev-list --tags --no-walk --max-count=1`..HEAD --count`
	LAST_COMMIT_ID=`git log --format="%h" -n 1`

	if [ "${COMMIT_NUMBER}" = "0" ] ; then
		UVG_PACKAGE_VERSION="${UVG_TAG}"
	else
		UVG_PACKAGE_VERSION="${UVG_TAG}"."${COMMIT_NUMBER}"-"${LAST_COMMIT_ID}"
	fi
else
	LAST_COMMIT_ID=`git log --format="%h" -n 1`
	UVG_PACKAGE_VERSION="${UVG_BRANCH}"-"${LAST_COMMIT_ID}"
fi

echo "${UVG_PACKAGE_VERSION}"
