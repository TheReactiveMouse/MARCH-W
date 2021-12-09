//
// Created by there on 12/3/2021.
//

#ifndef MARCHW_THREADING_H
#define MARCHW_THREADING_H
#include <functional>
#include <thread>
#include <iostream>
#endif //MARCHW_THREADING_H

namespace Threading {
    class Core {
        public:

            std::thread threads[8];

            int ThreadUsed[8] {
                    0,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0,
                    0
            };

            int Launch(std::function<void()> Function)
            {
                int free = 0;
                for (int y = 0; ThreadUsed[y] != 0; y++)
                {
                    free = y;
                    break;
                }
                threads[free] = std::thread(Function);
                threads[free].detach();
            };

            int Destroy(int ThreadID)
            {
                ThreadUsed[ThreadID] = 1;
            }
    };
}