/*
** EPITECH PROJECT, 2019
** dlloader.hpp
** File description:
** dlloader
*/

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
            }
        }

        ~DLLoader()
        {
            dlclose(_handle);
        }

        T *getInstance() const
        {
            T *(*func_pointer)(void) = (T *(*)(void))dlsym(_handle, "entryPoint");
            T *instance = func_pointer();
            return (instance);
        }

    private:
        void *_handle;
};