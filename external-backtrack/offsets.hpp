#pragma once

namespace offsets
{
	ptrdiff_t dwClientState = 0x588FEC;
	ptrdiff_t dwEntityList = 0x4DA31EC;
	ptrdiff_t dwGlobalVars = 0x588CF0;
	ptrdiff_t dwbSendPackets = 0xD771A;
	ptrdiff_t clientstate_last_outgoing_command = 0x4D2C;
	ptrdiff_t dwInput = 0x51F47B0;
}

namespace netvars
{
	ptrdiff_t dwClientState_State = 0x108;
	ptrdiff_t m_Local = 0x2FBC;
	ptrdiff_t m_iHealth = 0x100;
	ptrdiff_t m_iTeamNum = 0xF4;
	ptrdiff_t m_nTickBase = 0x3430;

	ptrdiff_t m_bDormant = 0xED;

	ptrdiff_t m_flSimulationTime = 0x268;
	ptrdiff_t m_flNextPrimaryAttack = 0x3238;

	ptrdiff_t m_dwBoneMatrix = 0x26A8;
	ptrdiff_t m_hActiveWeapon = 0x2EF8;
	ptrdiff_t clientstate_net_channel = 0x9C;
	ptrdiff_t dw_next_cmd = 0x110;

	ptrdiff_t m_aimPunchAngle = 0x302C;
	ptrdiff_t m_vecOrigin = 0x138;
	ptrdiff_t m_vecViewOffset = 0x108;
	ptrdiff_t dwClientState_ViewAngles = 0x4D90;
}