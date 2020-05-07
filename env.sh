#!/usr/bin/env -S /usr/bin/env -i /bin/bash

# export LIBRARY_PATH=/opt/ffmpeg-static/musl/musl-1.2.0/lib
# export LIBRARY_PATH=/usr/local/lib64:/usr/local/lib
# export PKG_CONFIG_PATH=/usr/local/lib64/pkgconfig

export PATH=/bin:/usr/bin
# export LDFLAGS="-static --sysroot=/opt/ffmpeg-static/deps --target=x86_64-pc-linux-musl"
ls
pwd
rm -rf *
export HUNTER_ROOT=../3rd
export HOME=/home/scott-hamilton
cmake \
	-DCMAKE_C_COMPILER=clang \
	-DCMAKE_CXX_COMPILER=clang++ \
	-DCMAKE_EXE_LINKER_FLAGS="-fuse-ld=lld" \
	-DCMAKE_LINKER=ld.lld \
	-G "Ninja" \
	.. -L
# --extra-libs=-lstdc++ \
