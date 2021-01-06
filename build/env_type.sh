#!/bin/sh
set -e

CUR_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd);

OUTPUT_DIR=$CUR_DIR/output
export LD_LIBRARY_PATH=$OUTPUT_DIR/lib:$LD_LIBRARY_PATH
export PATH=$$OUTPUT_DIR/bin:$PATH

set +e

