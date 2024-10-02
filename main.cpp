#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "include/list/listheader.h"
#include "include/list/XArrayListDemo.h"
// #include "include/list/DLinkedListDemo.h"
#include "include/ann/dataset.h"
#include "include/ann/dataloader.h"



using namespace std;


int main(int argc, char const *argv[])
{
    // xt::xarray<float> data = {{1., 2.}, {3., 4.}, {5., 6.}};
    // xt::xarray<string> label = {"one", "two", "three"};

    // TensorDataset<float, string> dataset(data, label);
    // int len = dataset.len();
    // cout << len << endl;
    // for(int i = 0; i < len; ++i){
    //     DataLabel<float, string> item = dataset.getitem(i);
    //     cout << "Data: ";
    //     for(const auto& value : item.getData()){
    //         cout << value << " ";
    //     }
    //     cout << "Label: ";
    //     for(const auto& value : item.getLabel()){
    //         cout << value << " ";
    //     }
    //     cout << endl;
    // }
    // for(const auto& dim : dataset.get_data_shape()){
    //     cout << dim << " ";
    // }
    // cout << endl;
    // for(const auto& dim : dataset.get_label_shape()){
    //     cout << dim << " ";
    // }

    // xt::xarray<float> empty;
    // auto shape = empty.shape();
    // bool is_empty = any_of(shape.begin(), shape.end(), [](auto size) { return size != 0; });
    // if (!is_empty) {
    //     std::cout << "" << std::endl;
    // }



    //test dataloader
    int nsamples = 100;
    xt::xarray<double> X = xt::random::randn<double>({nsamples, 10});
    xt::xarray<double> T = xt::random::randn<double>({nsamples, 5});
    TensorDataset<double, double> ds(X, T);
    DataLoader<double, double> loader(&ds, 30, true, false);
    for(auto batch : loader){
        cout << shape2str(batch.getData().shape()) << endl;
        cout << shape2str(batch.getLabel().shape()) << endl;
    }




    return 0;
}
