
#ifndef EKSAMENOOP_MYKEYLISTENER_HPP
#define EKSAMENOOP_MYKEYLISTENER_HPP

#include "threepp/threepp.hpp"
#include <sphere.hpp>

struct keyInput {  // a struct that describes the keyinput as a boolean with the name of direction
    bool left = false;
    bool right = false;
    bool up = false;
    bool down = false;
    bool reset = false;
};

class myKeyListener : public KeyListener {
public:
    void onKeyPressed(
            KeyEvent evt) { //keylistner that monitors button presses, and changes the boolean for direction accordingly
        if (evt.key == 87) {
            keyInput_.up = true;
        } else if (evt.key == 83) {
            keyInput_.down = true;
        } else if (evt.key == 68) {
            keyInput_.right = true;
        } else if (evt.key == 65) {
            keyInput_.left = true;
        } else if (evt.key == 82) {
            keyInput_.reset = true;

        }
    };

    void onKeyReleased(
            KeyEvent evt) { //keylistner that monitors if a button is released, and changes the boolean for direction accordingly
        if (evt.key == 87) {
            keyInput_.up = false;
        } else if (evt.key == 83) {
            keyInput_.down = false;
        } else if (evt.key == 68) {
            keyInput_.right = false;
        } else if (evt.key == 65) {
            keyInput_.left = false;
        } else if (evt.key == 82) {
            keyInput_.reset = false;
        }
    };
private:
    keyInput keyInput_;
};

#endif //EKSAMENOOP_MYKEYLISTENER_HPP
