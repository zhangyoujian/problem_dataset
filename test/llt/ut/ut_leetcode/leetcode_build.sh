#!/bin/bash
set -e
CUR_DIR=$(cd `dirname $0`;pwd)
BUILD_DIR=$CUR_DIR

rm -rf $BUILD_DIR/tmp
rm -rf ut_leetcode

mkdir -p $BUILD_DIR/tmp

cd $BUILD_DIR/tmp/

cmake ../
make

set +e






