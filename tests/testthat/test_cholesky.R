library(gpuRclblas)
context("amdMatrix magma linear algebra")

# set seed
set.seed(123)

# Base R objects
A <- matrix(c(5,1,1,3),2,2)

test_that("Single Precision Cholesky Decomposition Successful", {

	# has_gpu_skip()

	C <- chol(A)

	fgpuA <- amdMatrix(A, type="float")

	fgpuC <- amd_chol(fgpuA)

	expect_is(fgpuC, "famdMatrix")
	expect_equal(fgpuC[,], C, tolerance=1e-07,
				 info="float matrix elements not equivalent")
})


test_that("Double Precision Cholesky Decomposition Successful", {

	# has_gpu_skip()

	C <- chol(A)

	fgpuA <- amdMatrix(A, type="double")

	fgpuC <- amd_chol(fgpuA)

	expect_is(fgpuC, "damdMatrix")
	expect_equal(fgpuC[,], C, tolerance=.Machine$double.eps^0.5,
				 info="double matrix elements not equivalent")
})
