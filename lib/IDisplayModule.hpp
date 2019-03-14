/*
** EPITECH PROJECT, 2019
** IDisplayModule.hpp
** File description:
** Idisplaymodule
*/

#ifndef IDISPLAYMODULE_HPP_
    #define IDISPLAYMODULE_HPP_

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = default;
        virtual void display_window() = 0;
        virtual void clear_window() = 0;
        virtual bool get_event() = 0;
        virtual bool run() = 0;
};

#endif /* !IDISPLAYMODULE_HPP_ */
