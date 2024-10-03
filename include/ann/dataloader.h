/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   dataloader.h
 * Author: ltsach
 *
 * Created on September 2, 2024, 4:01 PM
 */

#ifndef DATALOADER_H
#define DATALOADER_H
#include "ann/xtensor_lib.h"
#include "ann/dataset.h"

using namespace std;

template<typename DType, typename LType>
class DataLoader{
public:
    class Iterator;
private:
    Dataset<DType, LType>* ptr_dataset;
    int batch_size;
    bool shuffle;
    bool drop_last;
    /*TODO: add more member variables to support the iteration*/
public:
    DataLoader(Dataset<DType, LType>* ptr_dataset,
            int batch_size,
            bool shuffle=true,
            bool drop_last=false){
        /*TODO: Add your code to do the initialization */
        this->ptr_dataset = ptr_dataset;
        this->batch_size = batch_size;
        this->shuffle = shuffle;
        this->drop_last = drop_last;
    }
    virtual ~DataLoader(){}
    
    /////////////////////////////////////////////////////////////////////////
    // The section for supporting the iteration and for-each to DataLoader //
    /// START: Section                                                     //
    /////////////////////////////////////////////////////////////////////////

    Iterator begin(){
        return Iterator(*this, 0);
    }

    Iterator end(){
        return Iterator(*this, ptr_dataset->len());
    }
    class Iterator{
    private:
        int index;
        DataLoader<DType, LType>& loader;
        int current_index;
        bool end;
    public:
        Iterator(DataLoader<DType, LType>& loader, int index) : loader(loader), index(index), current_index(0), end(false) {}

        Iterator& operator=(const Iterator& r){
            if(this != &r){
                loader = r.loader;
                index = r.index;
            }
            return *this;
        }
        
        Iterator& operator++(){
            ++index;
            return *this;
        }

        Iterator operator++(int){
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }

        bool operator!=(const Iterator& o) const{
            return !end && index != o.index;
        }

        Batch<DType, LType>& operator*() {
            auto shape = loader.ptr_dataset->get_data_shape();
            // cout << shape.data()[0] << endl;
            int k = shape.data()[0];
            int batch_cuoi = 0;
            int co_du_khong = k%loader.batch_size;
            if(co_du_khong != 0){
                if(loader.drop_last == false){
                    batch_cuoi = co_du_khong;
                    batch_cuoi = loader.batch_size + co_du_khong;
                }
            }

            auto data_shape1 = loader.ptr_dataset->get_data_shape();
            cout << "asdasd : " << data_shape1.size() << endl;
            // data_shape1[0] = loader.batch_size;
            std::vector<size_t> data_shape2 = {static_cast<size_t>(loader.batch_size), static_cast<size_t>(data_shape1[1]), static_cast<size_t>(data_shape1[2])};
            cout << "Datashape2: " << xt::adapt(data_shape2) << endl;
            // cout << "Index: " << index << endl;
            cout << "Current index: " << current_index << endl;

            xt::xarray<DType> Batch_data = xt::zeros<DType>(data_shape2);


            for(int i = current_index ; i < current_index + loader.batch_size; i++){
                auto item = loader.ptr_dataset->getitem(i);
                // if(data_shape1.size() == 1){
                //     Batch_data(i - current_index) = item.getData()(0);
                // }else{
                //     xt::view(Batch_data, i - current_index, xt::all()) = item.getData();
                // }
            }
            current_index += loader.batch_size;
            if(current_index + loader.batch_size > k){
                end = true;
            }

            // int end_index = min(index + loader.batch_size, loader.ptr_dataset->len());
            // int batch_size_to_use = end_index - index;
            // auto data_shape = loader.ptr_dataset->get_data_shape();
            // std::vector<size_t> batch_data_shape = {static_cast<size_t>(batch_size_to_use)};
            // xt::xarray<DType> Batch_data = xt::zeros<DType>(batch_data_shape);
            xt::xarray<LType> Batch_label = xt::empty<LType>({static_cast<size_t>(loader.batch_size)});

            static Batch<DType, LType> batch(Batch_data, Batch_label);
            return batch;
        }
            
    };


    /*TODO: Add your code here to support iteration on batch*/
    
    /////////////////////////////////////////////////////////////////////////
    // The section for supporting the iteration and for-each to DataLoader //
    /// END: Section                                                       //
    /////////////////////////////////////////////////////////////////////////
};


#endif /* DATALOADER_H */

