#!/bin/bash

CUR_DIR=$(cd `dirname $0`;pwd)
BUILD_DIR=$CUR_DIR

mkdir -p $BUILD_DIR/tmp

cd $BUILD_DIR/tmp/

cmake ../
make
make install





