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
        return Iterator(this, 0);
    }

    Iterator end(){
        return Iterator(this, batch_size);
    }
    class Iterator{
    public:
        Iterator(DataLoader* loader, int index) : loader(loader), index(index) {}
        Iterator& operator=(const Iterator& r){
            this->index = r.index;
            return *this;
        }
        
        Iterator& operator++(){
            index++;
            return *this;
        }

        Iterator& operator++(int){
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }

        bool operator!=(const Iterator& o){
            return index != o.index;
        }

        Batch<DType, LType>& operator*() const{
            return Batch<DType, LType>(xt::xarray<DType>{}, xt::xarray<LType>{});
        }
    private:
        int index;
        DataLoader* loader;
    };


    /*TODO: Add your code here to support iteration on batch*/
    
    /////////////////////////////////////////////////////////////////////////
    // The section for supporting the iteration and for-each to DataLoader //
    /// END: Section                                                       //
    /////////////////////////////////////////////////////////////////////////
};


#endif /* DATALOADER_H */

