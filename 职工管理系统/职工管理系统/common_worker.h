#pragma once
#include<iostream>
#include <string>
#include"worker.h"
using namespace std;

class commom_worker : public Worker {
public:
    commom_worker(int m_Id, string m_Name, int m_DeptId);

    virtual void showInfo();

    virtual string getDeptName();

};
