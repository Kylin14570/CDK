mkdir build
cd build
cmake .. -DCDK_BUILD_TEST=ON
make
./TestThread 32
./TestThreadPool 32
./TestSort 10000