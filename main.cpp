#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "include/list/listheader.h"
// #include "include/list/XArrayListDemo.h"
// #include "include/list/DLinkedListDemo.h"
// #include "include/ann/dataset.h"
// #include "include/ann/dataloader.h"
// #include "include/ann/funtions.h"
// #include "include/ann/xtensor_lib.h"
#include "include/util/Point.h"




using namespace std;


int main(int argc, char const *argv[])
{

    string name = "array29";
    //! data
    XArrayList<Point> list(0, &Point::pointEQ_X);
    list.add(Point(3.f, 4.f));
    list.add(Point(4.f, 3.f));

    //! expect
    string expect = "Contains item 1: true";

    //! output
    bool contains = list.contains(Point(3.f, 5.f));
    string output = "Contains item 1: " + string(contains ? "true" : "false");
    cout << expect << endl;
    cout << output << endl;
    // //! expect
    // string expect = "[0]\nsize=1\nempty=0";

    // //! output
    // string output = list.toString() + "\nsize=" + to_string(list.size()) +
    //                 "\nempty=" + to_string(list.empty());
    
    // cout << expect << endl;
    // cout << output << endl;
    // DLinkedList<string>::Iterator it = list.bbegin();
    // --it;

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



    // test dataloader
    // int nsamples = 100;
    // xt::xarray<double> X = xt::random::randn<double>({nsamples, 10});
    // xt::xarray<double> T = xt::random::randn<double>({nsamples, 5});
    // TensorDataset<double, double> ds(X, T);
    // DataLoader<double, double> loader(&ds, 30, true, false);
    // for(auto batch : loader){
    //     cout << shape2str(batch.getData().shape()) << endl;
    //     cout << shape2str(batch.getLabel().shape()) << endl;
    // }

    // string name = "data20";
    // //! data
    // int nsamples = 120;
    // xt::xarray<double> X = xt::random::randn<double>({nsamples, 10, 5});
    // xt::xarray<double> T = xt::random::randn<double>({nsamples, 5, 5});
    // TensorDataset<double, double> ds(X, T);
    // DataLoader<double, double> loader(&ds, 30, true, true);
    // //! expect
    // string expect =
    //     "(30, 10, 5);(30, 5, 5) (30, 10, 5);(30, 5, 5) (30, 10, 5);(30, 5, 5) "
    //     "(30, 10, 5);(30, 5, 5) ";

    // ! output

    // stringstream output;
    // xt::svector<unsigned long>a;
    // xt::svector<unsigned long>b;
    // for (auto batch : loader) {
    //     // output << shape2str(xt::svector<unsigned long>(batch.getData().shape().begin(), batch.getData().shape().end())) << ";";
    //     // output << shape2str(xt::svector<unsigned long>(batch.getLabel().shape().begin(), batch.getLabel().shape().end())) << " ";
    //     // cout << xt::adapt(batch.getData().shape()) << ";";
    //     a = xt::svector<unsigned long>(batch.getData().shape().begin(), batch.getData().shape().end());
    //     cout << "(";
    //     for(int idx=0; idx < a.size(); idx++){
    //         cout << a[idx];
    //         if(idx != a.size() - 1) cout << ", ";
    //     }
    //     cout << ");";
    //     b = xt::svector<unsigned long>(batch.getLabel().shape().begin(), batch.getLabel().shape().end());
    //     cout << "(";
    //     for(int idx=0; idx < b.size(); idx++){
    //         cout << b[idx];
    //         if(idx != b.size() - 1) cout << ", ";
    //     }
    //     cout << ") ";
    // }

//     string name = "data26";
//   //! data
//   xt::xarray<float> data = {1., 2., 3.};
//   xt::xarray<string> label;
 
//   TensorDataset<float, string> tensor(data, label);
  
//   DataLabel<float, string> getitem = tensor.getitem(0);

//   xt::xarray<float> getData = getitem.getData();
//   xt::xarray<string> getLabel = getitem.getLabel();

//   //! expect
//   string expect = " 1.;";

//   //! output
//   stringstream output;
//   output << getData << ";";
//   output << getLabel;

  //! output

    // stringstream output;
    // xt::svector<unsigned long>a;
    // xt::svector<unsigned long>b;
    // for (auto batch : loader) {
    //     // output << shape2str(xt::svector<unsigned long>(batch.getData().shape().begin(), batch.getData().shape().end())) << ";";
    //     // output << shape2str(xt::svector<unsigned long>(batch.getLabel().shape().begin(), batch.getLabel().shape().end())) << " ";
    //     a = xt::svector<unsigned long>(batch.getData().shape().begin(), batch.getData().shape().end());
    //     output << "(";
    //     for(int idx=0; idx < a.size(); idx++){
    //         output << a[idx];
    //         if(idx != a.size() - 1) output << ", ";
    //     }
    //     output << ");";
    //     b = xt::svector<unsigned long>(batch.getLabel().shape().begin(), batch.getLabel().shape().end());
    //     output << "(";
    //     for(int idx=0; idx < b.size(); idx++){
    //         output << b[idx];
    //         if(idx != b.size() - 1) output << ", ";
    //     }
    //     output << ") ";
    // }
    // auto batch = loader.begin();
    // Batch<double, double> c = *(batch);
    // stringstream output;
    // xt::svector<unsigned long>a;
    // xt::svector<unsigned long>b;
    // for (auto batch : loader) {
    //     // output << shape2str(xt::svector<unsigned long>(batch.getData().shape().begin(), batch.getData().shape().end())) << ";";
    //     // output << shape2str(xt::svector<unsigned long>(batch.getLabel().shape().begin(), batch.getLabel().shape().end())) << " ";
    //     a = xt::svector<unsigned long>(c.getData().shape().begin(), c.getData().shape().end());
    //     output << "(";
    //     for(int idx=0; idx < a.size(); idx++){
    //         output << a[idx];
    //         if(idx != a.size() - 1) output << ", ";
    //     }
    //     output << ") ";
    //     b = xt::svector<unsigned long>(c.getLabel().shape().begin(), c.getLabel().shape().end());
    //     output << "(";
    //     for(int idx=0; idx < b.size(); idx++){
    //         output << b[idx];
    //         if(idx != b.size() - 1) output << ", ";
    //     }
    //     output << ")";
    // }




    // //! remove data

    //! print result
    // cout << "name=" << name << endl;
    // cout << "expect=" << expect << endl;
    // cout << "output=" << output.str() << endl;
    // if(expect == output.str())
    //     cout << "pass" << endl;
    // else
    //     cout << "fail" << endl;

    return 0;
}
