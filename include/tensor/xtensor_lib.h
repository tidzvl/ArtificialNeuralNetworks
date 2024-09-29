/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   xtensor_lib.h
 * Author: ltsach
 *
 * Created on September 2, 2024, 10:39 AM
 */

#ifndef XTENSOR_LIB_H
#define XTENSOR_LIB_H
#include <string>
#include <sstream>
using namespace std;

#include "tensor/xtensor/xio.hpp"
#include "tensor/xtensor/xview.hpp"
#include "tensor/xtensor/xslice.hpp"
#include "tensor/xtensor/xbuilder.hpp"
#include "tensor/xtensor-blas/xlinalg.hpp"
#include "tensor/xtensor/xrandom.hpp"
#include "tensor/xtensor/xindex_view.hpp"
#include "tensor/xtensor/xsort.hpp"
#include "tensor/xtensor/xarray.hpp"
#include "tensor/xtensor/xnpy.hpp"
#include <ctime>

string shape2str(xt::svector<unsigned long> vec);
int positive_index(int idx, int size);

#endif /* XTENSOR_LIB_H */

