#pragma once

#include "MemoryReader.h"
#include "Offsets.h"
#include <cmath>

class Aimbot {
private:
    MemoryReader& memoryReader;

    struct Vector3 {
        float x, y, z;
    };

    struct PlayerData {
        uintptr_t address;
        Vector3 position;
        bool isEnemy;
    };

    float CalculatePitch(const Vector3& localPos, const Vector3& targetPos) {
        float dx = targetPos.x - localPos.x;
        float dy = targetPos.y - localPos.y;
        float dz = targetPos.z - localPos.z;
        float distance = sqrt(dx * dx + dy * dy + dz * dz);

        return -atan2(dz, distance) * (180 / M_PI);
    }

    float CalculateYaw(const Vector3& localPos, const Vector3& targetPos) {
        float dx = targetPos.x - localPos.x;
        float dz = targetPos.z - localPos.z;
        return atan2(dz, dx) * (180 / M_PI);
    }

    Vector3 GetBonePosition(uintptr_t playerAddress, int boneId) {
        uintptr_t boneMatrix = memoryReader.Read<uintptr_t>(playerAddress + Offsets::Bones::Head);
        Vector3 bonePosition;
        
        bonePosition.x = memoryReader.Read<float>(boneMatrix + 0x30);
        bonePosition.y = memoryReader.Read<float>(boneMatrix + 0x34);
        bonePosition.z = memoryReader.Read<float>(boneMatrix + 0x38);
        
        return bonePosition;
    }

public:
    Aimbot(MemoryReader& reader) : memoryReader(reader) {}

    void AimAtNearestEnemy() {
        uintptr_t facadeBase = memoryReader.Read<uintptr_t>(Offsets::Game::FacadeBase);
        uintptr_t playerList = memoryReader.Read<uintptr_t>(facadeBase + Offsets::Game::StaticFacade);
        int playerCount = memoryReader.Read<int>(playerList + 0x18);

        PlayerData closestEnemy;
        float closestDistance = FLT_MAX;

        uintptr_t localPlayer = memoryReader.Read<uintptr_t>(facadeBase + Offsets::Game::LocalPlayer);
        Vector3 localPosition = GetBonePosition(localPlayer, Offsets::Bones::Head);

        for (int i = 0; i < playerCount; i++) {
            uintptr_t player = memoryReader.Read<uintptr_t>(playerList + 0x20 + i * 0x8);
            if (player == localPlayer) continue;

            Vector3 position = GetBonePosition(player, Offsets::Bones::Head);
            float distance = sqrt(pow(position.x - localPosition.x, 2) +
                                pow(position.y - localPosition.y, 2) +
                                pow(position.z - localPosition.z, 2));

            if (distance < closestDistance) {
                closestEnemy.address = player;
                closestEnemy.position = position;
                closestDistance = distance;
            }
        }

        if (closestEnemy.address) {
            Vector3 targetPosition = GetBonePosition(closestEnemy.address, Offsets::Bones::Head);
            float pitch = CalculatePitch(localPosition, targetPosition);
            float yaw = CalculateYaw(localPosition, targetPosition);

            uintptr_t cameraBase = memoryReader.Read<uintptr_t>(facadeBase + Offsets::Camera::Base);
            memoryReader.Write<float>(cameraBase + Offsets::Camera::AimRotation, pitch);
            memoryReader.Write<float>(cameraBase + Offsets::Camera::AimRotation + 0x4, yaw);
        }
    }
};