#!/bin/bash

CUR_DIR=$(cd `dirname $0`;pwd)
BUILD_DIR=$CUR_DIR/build/
OUTPUT_DIR=$CUR_DIR/output/

rm -rf $BUILD_DIR/**

mkdir -p $BUILD_DIR/tmp
mkdir -p $OUTPUT_DIR/bin
mkdir -p $OUTPUT_DIR/lib

cd $OUTPUT_DIR/tmp/
cmake ../../
make



