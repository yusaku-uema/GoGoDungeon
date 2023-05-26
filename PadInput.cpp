#include "PadInput.h"

char PadInput::now_key[BUTTONS];
char PadInput::old_key[BUTTONS];
XINPUT_STATE PadInput::input;
Stick PadInput::r_stick;
Stick PadInput::l_stick;