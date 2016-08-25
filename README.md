# gpuRcuda: The Simple clMAGMA GPU Interface for R
[![Travis-CI Build Status](https://travis-ci.org/gpuRcore/gpuRclmagma.svg?branch=master)](https://travis-ci.org/gpuRcore/gpuRclmagma)

Test coverage: [![Coverage Status](https://coveralls.io/repos/github/gpuRcore/gpuRclmagma/badge.svg?branch=master)](https://coveralls.io/github/gpuRcore/gpuRclmagma?branch=master)

Welcome to gpuRcuda!  This package is designed to be an extension upon the
more general [gpuR](https://github.com/cdeterman/gpuR) package.  Essentially,
this package creates a secondary level of child classes that inherit from
gpuR and gpuRclblas classes.  As such, any functions defined in gpuR (i.e. OpenCL counterpart)
will also work on any of the objects defined herein.  The key aspect of this
package is to allow the user to use the clMAGMA library which may potentially 
improve overall performance depending upon the gpu architecture.

The syntax is designed to be identical to [gpuR](https://github.com/cdeterman/gpuR)

```r
# TO DO
```

### Dependencies
1. opencl-headers (shared library)
2. GPU Drivers & SDK (AMD, NVIDIA, etc.)

##### Note, you can theoretically use any Driver as clMAGMA is based on OpenCL
### AMD Driver and OpenCL
1. Purge existing fglrx drivers (`sudo sh /usr/share/ati/fglrx_uninstall.sh`)
2. Install current fglrx drivers (`sudo apt-get install fglrx-updates`)
3. Install opencl-headers (`sudo apt-get install opencl-headers`) -- needed
to install clMAGMA

# Install clMAGMA
```
git clone https://github.com/arrayfire/clBLAS.git
cd clBLAS
mkdir build && cd build
cmake ../src -DCMAKE_BUILD_TYPE=Release
make
sudo make install
```

# Install clMAGMA
To do ...

You should now be good to install and use gpuRclblas :)

