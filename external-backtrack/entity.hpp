#pragma once
#include "offsets.hpp"

class c_entity
{
public:
	c_entity( const int i, const ptrdiff_t base = NULL )
	{
		if (i == -1) { // allow to define a pseudo entity
			baseaddress_ = 0x0;
			index_ = -1;
		}
		else {

			if (base == NULL) {
				baseaddress_ = g_ptr_memory->read_memory<ptrdiff_t>(
					client_module->get_image_base() + offsets::dwEntityList + (i * 0x10));
				index_ = i;
			}
			else {
				baseaddress_ = base;
				index_ = 0;
			}
		}
	}
	int health() const
	{
		return g_ptr_memory->read_memory<int>( baseaddress_ + netvars::m_iHealth );
	}
	bool dormant() const 
	{
		return g_ptr_memory->read_memory<bool>( baseaddress_ + netvars::m_bDormant );
	}
	int team() const 
	{
		return g_ptr_memory->read_memory<int>( baseaddress_ + netvars::m_iTeamNum );
	}
	float simulation_time() const 
	{
		return g_ptr_memory->read_memory<float>( baseaddress_ + netvars::m_flSimulationTime );
	}
	Vector bone_position( const int bone ) const
	{
		Vector out;
		const auto temp = g_ptr_memory->read_memory<ptrdiff_t>( baseaddress_ + netvars::m_dwBoneMatrix );
		out.x = g_ptr_memory->read_memory<float>( temp + 0x30 * bone + 0xC );
		out.y = g_ptr_memory->read_memory<float>( temp + 0x30 * bone + 0x1C );
		out.z = g_ptr_memory->read_memory<float>( temp + 0x30 * bone + 0x2C );

		return out;
	}
	Vector punch_angles() const
	{
		return g_ptr_memory->read_memory<Vector>( baseaddress_ + netvars::m_aimPunchAngle );
	}
	Vector origin() const
	{
		return g_ptr_memory->read_memory<Vector>( baseaddress_ + netvars::m_vecOrigin );
	}
	Vector eye_postition() const
	{
		Vector eye = g_ptr_memory->read_memory<Vector>( baseaddress_ + netvars::m_vecViewOffset );
		eye += origin();

		return eye;
	}
	int tickbase() const
	{
		return g_ptr_memory->read_memory<int>( baseaddress_ + netvars::m_nTickBase );
	}
	ptrdiff_t current_weapon_base() const
	{
		const auto active_weapon = g_ptr_memory->read_memory<ptrdiff_t>( baseaddress_ + netvars::m_hActiveWeapon );
		return g_ptr_memory->read_memory<ptrdiff_t>( client_module->get_image_base() + offsets::dwEntityList + ( ( active_weapon & 0xFFF ) - 1 ) * 0x10 );
	}
private:
	ptrdiff_t baseaddress_;
	int index_;
};
