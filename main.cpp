#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "include/list/listheader.h"
#include "include/list/XArrayListDemo.h"
// #include "include/list/DLinkedListDemo.h"
#include "include/ann/dataset.h"


using namespace std;


int main(int argc, char const *argv[])
{
    xt::xarray<float> data = {{1., 2.}, {3., 4.}, {5., 6.}};
    xt::xarray<string> label = {"one", "two", "three"};

    TensorDataset<float, string> dataset(data, label);
    int len = dataset.len();
    cout << len << endl;
    for(int i = 0; i < len; ++i){
        DataLabel<float, string> item = dataset.getitem(i);
        cout << "Data: ";
        for(const auto& value : item.getData()){
            cout << value << " ";
        }
        cout << "Label: ";
        for(const auto& value : item.getLabel()){
            cout << value << " ";
        }
        cout << endl;
    }
    for(const auto& dim : dataset.get_data_shape()){
        cout << dim << " ";
    }
    cout << endl;
    for(const auto& dim : dataset.get_label_shape()){
        cout << dim << " ";
    }

    return 0;
}
