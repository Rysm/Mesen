#pragma once
#include "stdafx.h"

struct lua_State;
class ScriptingContext;
class Debugger;
class MemoryDumper;
struct ApuSquareState;
struct ApuEnvelopeState;
struct ApuLengthCounterState;

class LuaApi
{
public:
	static void SetContext(ScriptingContext *context);
	static void RegisterDebugger(Debugger* debugger);
	static int GetLibrary(lua_State *lua);

	static int ReadMemory(lua_State *lua);
	static int WriteMemory(lua_State *lua);
	static int DebugReadMemory(lua_State *lua);
	static int DebugWriteMemory(lua_State *lua);
	static int ReadMemoryWord(lua_State *lua);
	static int WriteMemoryWord(lua_State *lua);
	static int DebugReadMemoryWord(lua_State *lua);
	static int DebugWriteMemoryWord(lua_State *lua);
	static int RevertPrgChrChanges(lua_State *lua);

	static int RegisterMemoryCallback(lua_State *lua);
	static int UnregisterMemoryCallback(lua_State *lua);
	static int RegisterEventCallback(lua_State *lua);
	static int UnregisterEventCallback(lua_State *lua);
	
	static int DrawString(lua_State *lua);
	static int DrawLine(lua_State *lua);
	static int DrawPixel(lua_State *lua);
	static int DrawRectangle(lua_State *lua);
	static int ClearScreen(lua_State *lua);
	static int GetPixel(lua_State *lua);
	static int GetMouseState(lua_State *lua);

	static int Log(lua_State *lua);
	static int DisplayMessage(lua_State *lua);
	
	static int Reset(lua_State *lua);
	static int Break(lua_State *lua);
	static int Resume(lua_State *lua);
	static int Execute(lua_State *lua);
	static int Rewind(lua_State *lua);

	static int TakeScreenshot(lua_State *lua);
	static int SaveSavestate(lua_State *lua);
	static int LoadSavestate(lua_State *lua);

	static int GetInput(lua_State *lua);
	static int SetInput(lua_State *lua);

	static int AddCheat(lua_State *lua);
	static int ClearCheats(lua_State *lua);

	static int SetState(lua_State *lua);
	static int GetState(lua_State *lua);

private:
	static Debugger* _debugger;
	static MemoryDumper* _memoryDumper;
	static ScriptingContext* _context;

	static void PushSquareState(lua_State* lua, ApuSquareState &state);
	static void PushEnvelopeState(lua_State* lua, ApuEnvelopeState &state);
	static void PushLengthCounterState(lua_State* lua, ApuLengthCounterState &state);
};
