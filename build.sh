#!/bin/bash

set -e

CUR_DIR=$(cd `dirname $0`;pwd)
BUILD_DIR=$CUR_DIR/build/
OUTPUT_DIR=$CUR_DIR/output/

rm -rf $OUTPUT_DIR/**
echo 'clear'    $OUTPUT_DIR
rm -rf $BUILD_DIR/tmp
echo 'clear'    $OUTPUT_DIR/tmp

mkdir -p $BUILD_DIR/tmp
mkdir -p $OUTPUT_DIR/bin
mkdir -p $OUTPUT_DIR/lib

cd $BUILD_DIR/tmp/
cmake ../../
make && make install

set +e





