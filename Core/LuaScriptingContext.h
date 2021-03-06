#pragma once
#include "stdafx.h"
#include "ScriptingContext.h"

struct lua_State;
class Debugger;

class LuaScriptingContext : public ScriptingContext
{
private:
	lua_State* _lua = nullptr;

public:
	LuaScriptingContext();
	~LuaScriptingContext();

	bool LoadScript(string scriptContent, Debugger* debugger);
	void CallMemoryCallback(uint16_t addr, uint8_t &value, CallbackType type);
	int InternalCallEventCallback(EventType type);
};
