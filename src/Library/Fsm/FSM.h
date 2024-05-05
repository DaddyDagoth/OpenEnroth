#pragma once

#include <Utility/String/TransparentFunctors.h>
#include <Library/Logger/LogCategory.h>

#include "FSMEventHandler.h"
#include "FSMTransitionHandler.h"
#include "FSMState.h"

#include <memory>
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>

struct FSMTransitionTarget {
    std::string stateName;
    std::function<bool()> condition{};
};

using FSMTransitions = std::unordered_map<TransparentString, std::vector<FSMTransitionTarget>, TransparentStringHash, TransparentStringEquals>;

class FSM : public FSMTransitionHandler, public FSMEventHandler {
 public:
    /**
     * @brief Updates the current state of the FSM or executes any pending transitions.
     */
    void update();

    /*
    * @brief Check if the FSM has reached its internal FSM::exitState.
    */
    [[nodiscard]] bool hasReachedExitState() const;

    /**
     * @brief Sets the next state to be reached in the FSM. The transition does not occur immediately but will be executed during the next FSM::update() call.
     * The jumpToState function allows unconditional transitions without requiring a previously defined transition connecting the current state to the target state.
     * Subsequent calls to FSM::jumpToState or FSM::executeTransition will overwrite the target state since the actual transition happens during the next FSM::update() call.
     * @param stateName The name of the state to transition to. This name must belong to a state that has been previously added through FSM::addState.
     */
    void jumpToState(std::string_view stateName);

    /**
     * Global string used to specify the state used to exit from the FSM.
     * When the FSM jumps to this state, FSM::hasReachedExitState() will return true.
     */
    static const std::string_view exitState;

    struct StateEntry {
        std::string name;
        std::unique_ptr<FSMState> state;
        FSMTransitions transitions;
    };

    void addState(std::unique_ptr<StateEntry> stateEntry);

    static const LogCategory fsmLogCategory;

 private:
    // FSMEventHandler implementation
    virtual bool keyPressEvent(const PlatformKeyEvent *event) override;
    virtual bool keyReleaseEvent(const PlatformKeyEvent *event) override;
    virtual bool mouseMoveEvent(const PlatformMouseEvent *event) override;
    virtual bool mousePressEvent(const PlatformMouseEvent *event) override;
    virtual bool mouseReleaseEvent(const PlatformMouseEvent *event) override;
    virtual bool wheelEvent(const PlatformWheelEvent *event) override;
    virtual bool moveEvent(const PlatformMoveEvent *event) override;
    virtual bool resizeEvent(const PlatformResizeEvent *event) override;
    virtual bool activationEvent(const PlatformWindowEvent *event) override;
    virtual bool closeEvent(const PlatformWindowEvent *event) override;
    virtual bool gamepadConnectionEvent(const PlatformGamepadEvent *event) override;
    virtual bool gamepadKeyPressEvent(const PlatformGamepadKeyEvent *event) override;
    virtual bool gamepadKeyReleaseEvent(const PlatformGamepadKeyEvent *event) override;
    virtual bool gamepadAxisEvent(const PlatformGamepadAxisEvent *event) override;
    virtual bool nativeEvent(const PlatformNativeEvent *event) override;
    virtual bool textInputEvent(const PlatformTextInputEvent *event) override;

    // FSMTransitionHandler implementation
    virtual void scheduleTransition(std::string_view transition) override;

    StateEntry *_getStateByName(std::string_view stateName);

    std::unordered_map<TransparentString, std::unique_ptr<StateEntry>, TransparentStringHash, TransparentStringEquals> _states;
    StateEntry *_currentState{};
    StateEntry *_nextState{};

    // By default, when the FSM has no states, it's treated as if it reached already the FSM::exitState state
    bool _hasReachedExitState{true};
};
