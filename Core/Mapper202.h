#pragma once
#include "stdafx.h"
#include "BaseMapper.h"

class Mapper202 : public BaseMapper
{
private:
	bool _prgMode1;

protected:
	virtual uint16_t GetPRGPageSize() { return 0x4000; }
	virtual uint16_t GetCHRPageSize() { return 0x2000; }

	void InitMapper()
	{
		SelectPRGPage(0, 0);
		SelectPRGPage(1, 0);
		SelectCHRPage(0, 0);
	}

	virtual void StreamState(bool saving)
	{
		BaseMapper::StreamState(saving);
		Stream<bool>(_prgMode1);
	}

	void WriteRegister(uint16_t addr, uint8_t value)
	{
		_prgMode1 = (addr & 0x09) == 0x09;
		
		SelectCHRPage(0, (addr >> 1) & 0x07);
		if(_prgMode1) {
			SelectPRGPage(0, (addr >> 1) & 0x07);
			SelectPRGPage(1, ((addr >> 1) & 0x07) + 1);
		} else {
			SelectPRGPage(0, (addr >> 1) & 0x07);
			SelectPRGPage(1, (addr >> 1) & 0x07);
		}
		
		SetMirroringType(addr & 0x01 ? MirroringType::Horizontal : MirroringType::Vertical);
	}
};