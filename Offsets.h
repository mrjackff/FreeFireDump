#pragma once

#include <workspace/types.hpp>

// ── Bones ────────────────────────────────────────────────────────────────────
enum class Bones : u32
{
    m_WeaponMountNode  = 0x454,
    Head               = 0x458,
    Hip                = 0x45C,
    m_BloodEffectNode  = 0x460,
    m_SkateboardNode   = 0x464,
    m_FlightNode       = 0x468,
    Root               = 0x46C,
    m_BoneRootNode     = 0x470,
    m_LeftAnkleNode    = 0x474,
    m_RightAnkleNode   = 0x478,
    m_LeftToeNode      = 0x47C,
    m_RightToeNode     = 0x480,
    m_LeftWeaponNode   = 0x484,
    m_LeftArmNode      = 0x48C,
    m_RightArmNode     = 0x490,
    m_RightHandNode    = 0x494,
    m_LeftHandNode     = 0x498,
    m_RightForeArmNode = 0x49C,
    m_LeftForeArmNode  = 0x4A0
};

// ── Offsets ──────────────────────────────────────────────────────────────────
namespace Offsets {
    // Game/Match pointer chains
    inline constexpr u32 GameFacadeBase       = 0xA986B7C;
    inline constexpr u32 StaticGameFacade     = 0x5C;
    inline constexpr u32 CurrentMatch         = 0x50;
    inline constexpr u32 MatchStatus          = 0x8C;
    inline constexpr u32 LocalPlayer          = 0x94;

    // Player status and details
    inline constexpr u32 Player_Firing        = 0x540;
    inline constexpr u32 Player_ActiveWeapon  = 0x3F4;
    inline constexpr u32 Player_ShadowBase    = 0x18B8;
    inline constexpr u32 Player_IsKnocked     = 0x78;
    inline constexpr u32 Player_IsDead        = 0x50;
    inline constexpr u32 Player_TransformType = 0xC4C;
    inline constexpr u32 Player_Name          = 0x2DC;
    inline constexpr u32 Player_Data          = 0x48; 

    // Weapon & Recoil
    inline constexpr u32 Weapon_Data          = 0x58;
    inline constexpr u32 WeaponData_Recoil    = 0xC;

    // Camera & Spectators
    inline constexpr u32 FollowCamera         = 0x450;
    inline constexpr u32 Camera               = 0x18;
    inline constexpr u32 ViewMatrix           = 0xE8;
    inline constexpr u32 MainCameraTransform  = 0x24C;
    inline constexpr u32 AimRotation          = 0x400;
    inline constexpr u32 m_LocalObserver      = 0xB4;
    inline constexpr u32 m_TargetPlayer       = 0x28;
    inline constexpr u32 m_LocalSpectator     = 0xB8;
    inline constexpr u32 TargeSpectPlayer     = 0x58;

    // Entities Dictionary
    inline constexpr u32 DictionaryEntities   = 0x68;

    // Avatar & Team
    inline constexpr u32 AvatarManager        = 0x4C0;
    inline constexpr u32 Avatar               = 0xA8;
    inline constexpr u32 Avatar_IsVisible     = 0x95;
    inline constexpr u32 Avatar_Data          = 0x14;
    inline constexpr u32 Avatar_Data_IsTeam   = 0x59;

    // Aimbot target / collider offsets
    inline constexpr u32 HeadCollider         = 0x4A4;
    inline constexpr u32 TargetHead           = 0x54;
}
