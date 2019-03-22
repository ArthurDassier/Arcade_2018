/*
** EPITECH PROJECT, 2019
** dlloader.hpp
** File description:
** dlloader
*/

#include <dlfcn.h>
#include <iostream>

#ifndef DLL_HPP_
    #define DLL_HPP_


template <typename T>
class DLLoader
{
    public:
        DLLoader(std::string lib_path)
        {
            _handle = dlopen(lib_path.c_str(), RTLD_NOW);
            if (_handle == NULL) {
                std::cout << "FAIL\n";
                fprintf(stderr, "Error: %s\n", dlerror());
                exit(EXIT_FAILURE);
            }
        }

        ~DLLoader()
        {
            dlclose(_handle);
        }

        // Members
        T *getInstance() const
        {
            T *(*func_pointer)(void) = (T *(*)(void))dlsym(_handle, "entryPoint");
            T *instance = func_pointer();
            return (instance);
        }

    private:
        void *_handle;
};

#endif