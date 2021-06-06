#include <RcppArmadillo.h>

/*
 * C functions can be exposed using the following template: 
 *
 * RET_TYPE FUNCNAME(ARGTYPE_1 ARGNAME 1, ARGTYPE_2 ARGNAME_2)
 * {
 *     static RET_TYPE(*fun)(ARGTYPE_1, ARGTYPE_2) = NULL;
 *     if (fun == NULL) fun = (RET_TYPE(*)(ARGTYPE_1, ARGTYPE_2)) R_GetCCallable("nloptr","FUNCNAME");
 *     return fun(ARGNAME_1, ARGNAME_2);
 * }
 * 
 * This file provides an API for calling internal expm code from C within
 * R packages. The C functions that are registered in expm/src/init.c can be
 * accessed by external R packages.
 * 
 * See. https://github.com/cran/expm/blob/master/src/init.c
 * 
 */

typedef enum
{
    Ward_2,
    Ward_1,
    Ward_buggy_octave
} precond_type;

void (*fun)(double *x, int n, double *z, precond_type precond_kind);

//' This function computes the exponential of a matrix.
//' @title Compute the exponential of a matrix
//' @param x An numeric matrix
//' @return A numeric matrix
//' @seealso The \pkg{expm} package and its documentation.
// [[Rcpp::export]]
arma::mat expm_rcpp(arma::mat x)
{
    arma::mat z(x.n_rows, x.n_cols);

    fun = (void (*)(double *, int, double *, precond_type))R_GetCCallable("expm", "expm");

    fun(x.begin(), x.n_rows, z.begin(), Ward_2);

    return z;
}