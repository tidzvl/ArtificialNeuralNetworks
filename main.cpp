#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "include/list/listheader.h"
// #include "include/list/XArrayListDemo.h"
// #include "include/list/DLinkedListDemo.h"
#include "include/ann/dataset.h"
#include "include/ann/dataloader.h"
// #include "include/ann/funtions.h"
// #include "include/ann/xtensor_lib.h"
// #include "include/util/Point.h"



int main() {
    xt::xarray<int> X = xt::arange<int>(10*4).reshape({10, 4});
    xt::xarray<int> t;
    //Show X and t
    cout << "############################################" << endl;
    cout << "#CASE: data WITHOUT label" << endl;
    cout << "############################################" << endl;
    cout << "ORIGINAL data and label:" << endl;
    cout << "X.shape: " << xt::adapt(X.shape()) << endl;
    cout << "X: " << endl << X << endl;
    cout << "t.shape: " << xt::adapt(t.shape()) << endl;
    cout << "t: " << endl << t << endl;
    cout << "=================================" << endl;

    //Create TensorDataset and DataLoader
    TensorDataset<int, int> ds(X, t);
    int batch_size = 3;
    bool shuffle = false, drop_last = false;
    int seed;
    DataLoader<int, int> *pLoader;

    cout << "Loading (1): with shuffle=false:" << endl;
    cout << "################################" << endl;
    shuffle = false;
    pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    int batch_idx = 1;
    for(auto batch: *pLoader){
        cout << "batch_idx:" << batch_idx++ << endl;
        // string dshape = shape2str(batch.getData().shape());
        // string lshape = shape2str(batch.getLabel().shape());
        // cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
        cout << "data:"  << endl << batch.getData() << endl;
        cout << "label:" << endl << batch.getLabel() << endl;
        // cout << "Asdas" << endl;
    }
    cout << endl << endl;
    delete pLoader;

    cout << "NOTE: Loading (2) and (3): DO NOT CALL seed; so results are different." << endl;
    cout << endl << endl;

    cout << "Loading (4): with shuffle=true + with seed (seed >= 0):" << endl;
    cout << "when seed >= 0: CALL xt::random:seed" << endl;
    cout << "################################" << endl;
    shuffle = true;
    seed = 100;
    pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    batch_idx = 1;
    for(auto batch: *pLoader){
        cout << "batch_idx:" << batch_idx++ << endl;
        // string dshape = shape2str(batch.getData().shape());
        // string lshape = shape2str(batch.getLabel().shape());
        // cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
        cout << "data:"  << endl << batch.getData() << endl;
        cout << "label:" << endl << batch.getLabel() << endl;
    }
    delete pLoader;

    cout << "Loading (5): with shuffle=true + with seed (seed >= 0):" << endl;
    cout << "when seed >= 0: CALL xt::random:seed" << endl;
    cout << "################################" << endl;
    shuffle = true;
    seed = 100;
    pLoader = new DataLoader<int, int>(&ds, batch_size, shuffle, drop_last, seed);
    batch_idx = 1;
    for(auto batch: *pLoader){
        cout << "batch_idx:" << batch_idx++ << endl;
        // string dshape = shape2str(batch.getData().shape());
        // string lshape = shape2str(batch.getLabel().shape());
        // cout << "(data.shape, label.shape): " << dshape + ", " + lshape << endl;
        cout << "data:"  << endl << batch.getData() << endl;
        cout << "label:" << endl << batch.getLabel() << endl;
    }
    delete pLoader;
    cout << "NOTE: Loading (4) and (5): CALL xt::random::seed and use SAME seed => same results." << endl;
    cout << endl << endl;
    return 0;
}