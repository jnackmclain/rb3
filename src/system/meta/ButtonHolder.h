#ifndef META_BUTTONHOLDER_H
#define META_BUTTONHOLDER_H
#include "obj/Msg.h"
#include "os/User.h"
#include "os/UserMgr.h"
#include "os/Joypad.h"
#include <vector>

BEGIN_MESSAGE(ProcessedButtonDownMsg, processed_button_down, LocalUser*, JoypadButton, JoypadAction, int, bool);
    LocalUser* GetUser() const;
END_MESSAGE;

struct PressRec {
    PressRec() : a(0), iUser(0), c(0), d(0), e(0) {}

    int a;
    User* iUser;
    int c, d, e;
};

// // RB2
// struct PressRec {
//     // total size: 0x18
//     int iUserNum; // offset 0x0, size 0x4
//     class User * iUser; // offset 0x4, size 0x4
//     enum JoypadButton iRawButton; // offset 0x8, size 0x4
//     enum JoypadAction iAction; // offset 0xC, size 0x4
//     float fPressTime; // offset 0x10, size 0x4
//     int iPadNum; // offset 0x14, size 0x4
// };

class ActionRec {
public:
    ActionRec(JoypadAction, float, UserMgr*);
    PressRec& GetPressRec(int);

    JoypadAction mAction;
    float mHoldTime;
    std::vector<PressRec> mPresses;
};

class ButtonHolder : public Hmx::Object {
public:
    ButtonHolder(Hmx::Object*, UserMgr*);

    Hmx::Object* mCallback;
    UserMgr* mUserMgr;
    std::vector<ActionRec> mActionRecs;
};

#endif