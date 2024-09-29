/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   dataset.h
 * Author: ltsach
 *
 * Created on September 2, 2024, 3:59 PM
 */

#ifndef DATASET_H
#define DATASET_H
#include "ann/xtensor_lib.h"
using namespace std;

template<typename DType, typename LType>
class DataLabel{
private:
    xt::xarray<DType> data;
    xt::xarray<LType> label;
public:
    DataLabel(xt::xarray<DType> data,  xt::xarray<LType> label):
    data(data), label(label){
    }
    xt::xarray<DType> getData() const{ return data; }
    xt::xarray<LType> getLabel() const{ return label; }
};

template<typename DType, typename LType>
class Batch{
private:
    xt::xarray<DType> data;
    xt::xarray<LType> label;
public:
    Batch(xt::xarray<DType> data,  xt::xarray<LType> label):
    data(data), label(label){
    }
    virtual ~Batch(){}
    xt::xarray<DType>& getData(){return data; }
    xt::xarray<LType>& getLabel(){return label; }
};


template<typename DType, typename LType>
class Dataset{
private:
public:
    Dataset(){};
    virtual ~Dataset(){};
    
    virtual int len()=0;
    virtual DataLabel<DType, LType> getitem(int index)=0;
    virtual xt::svector<unsigned long> get_data_shape()=0;
    virtual xt::svector<unsigned long> get_label_shape()=0;
    
};

//////////////////////////////////////////////////////////////////////
template<typename DType, typename LType>
class TensorDataset: public Dataset<DType, LType>{
private:
    xt::xarray<DType> data;
    xt::xarray<LType> label;
    xt::svector<unsigned long> data_shape, label_shape;
    
public:
    /* TensorDataset: 
     * need to initialize:
     * 1. data, label;
     * 2. data_shape, label_shape
    */
    TensorDataset(xt::xarray<DType> data    , xt::xarray<LType> label){
        /* TODO: your code is here for the initialization
         */
        this->data = data;
        this->label = label;
        this->data_shape = xt::svector<long unsigned int>(data.shape().size());
        this->label_shape = xt::svector<long unsigned int>(label.shape().size());
        for (size_t i = 0; i < data.shape().size(); ++i) {
            this->data_shape[i] = data.shape()[i];
            this->label_shape[i] = label.shape()[i];
        }
    }
    /* len():
     *  return the size of dimension 0
    */
    int len(){
        /* TODO: your code is here to return the dataset's length
         */
        return data.shape(0);        
    }
    
    /* getitem:
     * return the data item (of type: DataLabel) that is specified by index
     */
    DataLabel<DType, LType> getitem(int index){
        /* TODO: your code is here
         */
        if(index < 0 || index >= data.shape(0)) throw std::out_of_range("index out of range");
        xt::xarray<DType> data_item = xt::xarray<DType>::from_shape({data.shape(1)});
        xt::xarray<LType> label_item = xt::xarray<LType>::from_shape({label.shape(1)});
        for(int i = 0; i < data.shape(1); i++){
            data_item(i) = data(index, i);
        }
        if(label.shape().size() == 1) label_item = label(index);
        else{
            for(int i = 0; i < label.shape(1); i++){
                label_item(i) = label(index, i);
            }
        }
        DataLabel<DType, LType> item(data_item, label_item);
        return item;
    }
    
    xt::svector<unsigned long> get_data_shape(){
        /* TODO: your code is here to return data_shape
         */
        // xt::svector<unsigned long> data_shape = xt::svector<unsigned long>(data.shape().size());
        return data_shape;
    }
    xt::svector<unsigned long> get_label_shape(){
        /* TODO: your code is here to return label_shape
         */
        return label_shape;
    }
};



#endif /* DATASET_H */

