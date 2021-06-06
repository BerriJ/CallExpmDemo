# CallExpmDemo

======================

This RcppArmadillo package demonstrates how to import the `expm` C function from the expm R Package.

Note that the desired function has to be exposed using `R_RegisterCCallable` by the foreign package.

This is the case for [expm](https://github.com/cran/expm/blob/master/src/init.c) but is'n not for other functions.

Foreign RCPP packages may provide headers which can be much more easily imported into your own Rcpp Package. See [splines2](https://github.com/wenjie2wang/example-pkg-Rcpp-splines2) for example.

Installation
------------

### Install from Github

You can install the latest version from github with:

``` r
# install.packages("remotes")
remotes::install_github("BerriJ/CallExpmDemo")
```

License
-------

**CallExpmDemo** is licensed under [GPL-3](LICENSE)