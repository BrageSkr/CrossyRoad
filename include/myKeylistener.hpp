
#ifndef CROSSYROAD_MYKEYLISTENER_HPP
#define CROSSYROAD_MYKEYLISTENER_HPP

#include "threepp/threepp.hpp"


using namespace threepp;

struct keyInput {
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
        if (evt.key == 87 /*w*/ || evt.key == 265 /*uparrow*/) {
            keyInput_.up = true;
        } else if (evt.key == 83/*s*/ || evt.key == 264 /*downarrow*/) {
            keyInput_.down = true;
        } else if (evt.key == 68/*d*/ || evt.key == 262 /*rightarrow*/) {
            keyInput_.right = true;
        } else if (evt.key == 65/*a*/ || evt.key == 263 /*leftarrow*/) {
            keyInput_.left = true;
        } else if (evt.key == 82/*r*/) {
            keyInput_.reset = true;

        }
    };

    void onKeyReleased(
            KeyEvent evt) { //keylistner that monitors if a button is released, and changes the boolean for direction accordingly
        if (evt.key == 87/*w*/ || evt.key == 265 /*uparrow*/) {
            keyInput_.up = false;
        } else if (evt.key == 83/*s*/ || evt.key == 264 /*downarrow*/) {
            keyInput_.down = false;
        } else if (evt.key == 68/*d*/ || evt.key == 262 /*rightarrow*/) {
            keyInput_.right = false;
        } else if (evt.key == 65/*a*/ || evt.key == 263 /*leftarrow*/) {
            keyInput_.left = false;
        } else if (evt.key == 82/*r*/ || evt.key == 27 /*leftarrow*/) {
            keyInput_.reset = false;
        }
    };

    keyInput &getKeyInput() {
        return keyInput_;
    }

private:
    keyInput keyInput_;
};

#endif //CROSSYROAD_MYKEYLISTENER_HPP
