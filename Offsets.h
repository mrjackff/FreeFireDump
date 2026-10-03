#pragma once

#include <workspace/types.hpp>
namespace Bones {
    enum : u32 {
        WeaponMountNode   = 0x454,
        Head              = 0x458,
        Hip               = 0x45C,
        BloodEffectNode   = 0x460,
        SkateboardNode    = 0x464,
        FlightNode        = 0x468,
        Root              = 0x46C,
        BoneRootNode      = 0x470,
        LeftAnkleNode     = 0x474,
        RightAnkleNode    = 0x478,
        LeftToeNode       = 0x47C,
        RightToeNode      = 0x480,
        LeftWeaponNode    = 0x484,
        LeftArmNode       = 0x48C,
        RightArmNode      = 0x490,
        RightHandNode     = 0x494,
        LeftHandNode      = 0x498,
        RightForeArmNode  = 0x49C,
        LeftForeArmNode   = 0x4A0
    };
}

namespace Offsets {
    // Category: Game Core
    namespace Game {
        inline constexpr u32 FacadeBase       = 0xA986E9C;
        inline constexpr u32 StaticFacade     = 0x5C;
        inline constexpr u32 CurrentMatch     = 0x50;
        inline constexpr u32 MatchStatus      = 0x8C;
        inline constexpr u32 LocalPlayer      = 0x94;
    }

    // Category: Player State
    namespace Player {
        inline constexpr u32 Firing          = 0x540;
        inline constexpr u32 ActiveWeapon    = 0x3F4;
        inline constexpr u32 ShadowBase      = 0x18B8;
        inline constexpr u32 IsKnocked       = 0x78;
        inline constexpr u32 IsDead          = 0x50;
        inline constexpr u32 TransformType   = 0xC4C;
        inline constexpr u32 Name            = 0x2DC;
        inline constexpr u32 Data            = 0x48;
    }

    // Category: Weapon System
    namespace Weapon {
        inline constexpr u32 Data            = 0x58;
        inline constexpr u32 RecoilData      = 0xC;
    }

    // Category: Camera System
    namespace Camera {
        inline constexpr u32 Follow          = 0x450;
        inline constexpr u32 Base            = 0x18;
        inline constexpr u32 ViewMatrix      = 0xE8;
        inline constexpr u32 MainTransform   = 0x24C;
        inline constexpr u32 AimRotation     = 0x400;
    }

    // Category: Spectator System
    namespace Spectator {
        inline constexpr u32 LocalObserver   = 0xB4;
        inline constexpr u32 TargetPlayer    = 0x28;
        inline constexpr u32 LocalSpectator  = 0xB8;
        inline constexpr u32 TargetSpectator = 0x58;
    }

    // Category: Entity Management
    namespace Entity {
        inline constexpr u32 Dictionary      = 0x68;
    }

    // Category: Avatar System
    namespace Avatar {
        inline constexpr u32 Manager         = 0x4C0;
        inline constexpr u32 Base            = 0xA8;
        inline constexpr u32 IsVisible       = 0x95;
        inline constexpr u32 Data            = 0x14;
        inline constexpr u32 IsTeamMember    = 0x59;
    }

    // Category: Targeting System
    namespace Collider {
        inline constexpr u32 Head            = 0x4A4;
        inline constexpr u32 TargetHead      = 0x54;
    }
}