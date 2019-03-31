/*
** EPITECH PROJECT, 2019
** dlloader.hpp
** File description:
** dlloader
*/

#pragma once

#include <dlfcn.h>
#include <iostream>

/*! \class DLLoader
* \brief Class representing DLLoader's logic
*
*  This class contains the fonctions that will return the entrypoints of our libraries and games
*/

template <typename T>
class DLLoader
{
    public:
        DLLoader(std::string lib_path)
        {
            _handle = dlopen(lib_path.c_str(), RTLD_NOW);
            if (_handle == NULL) {
                fprintf(stderr, "Error: %s\n", dlerror());
                exit(84);
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
