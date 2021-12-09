//
// Created by there on 12/6/2021.
//

#include <string>
#include <iostream>

#ifndef MARCHW_GPU_H
#define MARCHW_GPU_H


#endif //MARCHW_GPU_H

/*
 * Virtual Graphics Adapter.
 * Vendor : MARCH Official.
 * Internal Memory : 256 Units
 * Output Resolution : (Line width) x (Line Count) [ 96 x 32 ]
 * Recommended to use : For Data Centers and Compute Engines.
 */


/**
    Class of our GPU, Initialize as much as you would.
    @return Initialized GPU Controller. Full GPU API Access.
    @author MARCH Project
    @class GPUs
    @example No Examples. You can just initialize this.
*/
class GPU {
    public:
        /**
         * @details GPU Core. Have 2 types, to render 2D and render 3D (3D in future.)
         */

        void GPUCharacter_EffectiveCore(char Character, int Index)
        {
            GPUMemory[Index] = Character;
        }
        void GPUCharacter_GuardCore(dt Character, int Index)
        {
            if (Index < sizeof(GPUMemory))
            {
                for (int x = 0; x < sizeof(Character); x++)
                {
                    const char* array = Character.get();
                    GPUMemory[Index + x] = array[x];
                }
            }
        }

    [[noreturn]] void GPURead()
        {
            for (int x = 0; x != char(0x257); x++)
            {
                std::cout << GPUMemory[x];
            }
        }
    protected:
         bool Technology_2D = true;
         bool Technology_3D = false;
         bool Technology_ML = false;
         /**
          * @author MARCH
          * @details GPU Protection from critical moments, GPUGuard will stop GPU in situation while GPU can die.
          */
         bool Technology_GPUGuard = true;

         std::string GPUName = "MARCH PlusView 0.5";
         std::string GPUModel = "PlusView 0.5 (KT8Y9A0)";
         std::string GPUVendor = "MARCH";
         char GPUMemory[96] = {
                 NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,NULL, NULL, NULL,
                 NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,NULL, NULL, NULL,
                 NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,NULL, NULL, NULL,
                 NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,NULL, NULL, NULL,
                 NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,NULL, NULL, NULL,
                 NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,NULL, NULL, NULL, NULL,NULL, NULL, char(0x257),
         };
};