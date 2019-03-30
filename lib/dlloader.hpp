/*
** EPITECH PROJECT, 2019
** dlloader.hpp
** File description:
** dlloader
*/

#pragma once

#include <dlfcn.h>
#include <iostream>

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
            if (_handle != nullptr)
                dlclose(_handle);
        }

        // Members
        T getInstance() const
        {
            T (*func_pointer)(void) = (T (*)(void))dlsym(_handle, "entryPoint");
            if (func_pointer == nullptr) {
                std::cerr << dlerror() << " = error dlsym"<< std::endl;
                throw "error dlsym";
            }
            T instance = func_pointer();
            return (instance);
        }

    private:
        void *_handle;
};
