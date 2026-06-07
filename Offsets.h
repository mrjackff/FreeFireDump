#pragma once

#include <workspace/types.hpp>

// ── Bones ────────────────────────────────────────────────────────────────────
enum class Bones : u32
{
    m_WeaponMountNode  = 0x458,
    Head               = 0x45C,
    Hip                = 0x460,
    m_BloodEffectNode  = 0x464,
    m_SkateboardNode   = 0x468,
    m_FlightNode       = 0x46C,
    Root               = 0x470,
    m_BoneRootNode     = 0x474,
    m_LeftAnkleNode    = 0x478,
    m_RightAnkleNode   = 0x47C,
    m_LeftToeNode      = 0x480,
    m_RightToeNode     = 0x484,
    m_LeftWeaponNode   = 0x488,
    m_LeftArmNode      = 0x490,
    m_RightArmNode     = 0x494,
    m_RightHandNode    = 0x498,
    m_LeftHandNode     = 0x49C,
    m_RightForeArmNode = 0x4A0,
    m_LeftForeArmNode  = 0x4A4
};

// ── Offsets ──────────────────────────────────────────────────────────────────
namespace Offsets {
    // Game/Match pointer chains
    inline constexpr u32 GameFacadeBase       = 0x9EC1C48;
    inline constexpr u32 StaticGameFacade     = 0x5C;
    inline constexpr u32 CurrentMatch         = 0x50;
    inline constexpr u32 MatchStatus          = 0x8C;
    inline constexpr u32 LocalPlayer          = 0x94;

    // Player status and details
    inline constexpr u32 Player_Firing        = 0x544;
    inline constexpr u32 Player_ActiveWeapon  = 0x3F8;
    inline constexpr u32 Player_ShadowBase    = 0x16BC;
    inline constexpr u32 Player_IsKnocked     = 0x78;
    inline constexpr u32 Player_IsDead        = 0x50;
    inline constexpr u32 Player_TransformType = 0xC1C;
    inline constexpr u32 Player_Name          = 0x2E4;
    inline constexpr u32 Player_Data          = 0x48;

    // Weapon & Recoil
    inline constexpr u32 Weapon_Data          = 0x58;
    inline constexpr u32 WeaponData_Recoil    = 0xC;

    // Camera & Spectators
    inline constexpr u32 FollowCamera         = 0x454;
    inline constexpr u32 Camera               = 0x18;
    inline constexpr u32 ViewMatrix           = 0xE8;
    inline constexpr u32 MainCameraTransform  = 0x254;
    inline constexpr u32 AimRotation          = 0x404;

    // Entities Dictionary
    inline constexpr u32 DictionaryEntities   = 0x68;

    // Avatar & Team
    inline constexpr u32 AvatarManager        = 0x4C4;
    inline constexpr u32 Avatar               = 0xA0;
    inline constexpr u32 Avatar_IsVisible     = 0x95;
    inline constexpr u32 Avatar_Data          = 0x14;
    inline constexpr u32 Avatar_Data_IsTeam   = 0x59;

    // Aimbot target / collider offsets
    inline constexpr u32 HeadCollider         = 0x4A8;
    inline constexpr u32 TargetHead           = 0x54;
}
