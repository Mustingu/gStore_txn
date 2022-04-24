/*
    Copyright (c) 2005-2018 Intel Corporation

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.




*/

#include <cstdio>
#include <vector>
#include <math.h>
#include <iostream>

#include "tbb/atomic.h"
#include "tbb/tick_count.h"
#include "tbb/task_scheduler_init.h"
#include "tbb/task_group.h"
#include "tbb/concurrent_priority_queue.h"
#include "tbb/spin_mutex.h"
#include "tbb/parallel_for.h"
#include "tbb/blocked_range.h"
#include "tbb/concurrent_vector.h"


using namespace std;
using namespace tbb;

int main(int argc, char *argv[]) {
    concurrent_vector<int>orz;
    for(int i=1;i<=1000000;i++)
    {
//        pthread_rwlock_wrlock(&Lock);
            orz.push_back(i);
//        pthread_rwlock_unlock(&Lock);
    }
    cout << orz.size() << endl;
    return 1;

}
